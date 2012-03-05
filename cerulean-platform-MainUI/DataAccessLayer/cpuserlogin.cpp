#include "cpuserlogin.h"

#include "precompiled.h"
#include <QxMemLeak.h>

QX_REGISTER_CPP_CP_EXE(CPUserLogin)

namespace qx {
    template <> void register_class(QxClass<CPUserLogin> & t)
    {
      CPUserLogin userLogin;
      userLogin.RegisterClass (t);

    }
}


void CPUserLogin::RegisterClass (qx::QxClass<CPUserLogin> &t)
{
    t.id (& CPUserLogin::m_accountID, "AccountID");

    t.data (& CPUserLogin::m_userID, "UserID");
    t.data (& CPUserLogin::m_userAccount, "UserAccount");
    t.data (& CPUserLogin::m_userPassword, "UserPassword");
    t.data (& CPUserLogin::m_userIP, "UserIP");
}

void CPUserLogin::SetAll (long accountID, long userID, QString userAccount, QString userPassword, QString userIP)
{
    this->m_accountID=accountID;
    this->m_userID=userID;
    this->m_userAccount=userAccount;
    this->m_userPassword=userPassword;
    this->m_userIP=userIP;
}

bool CPUserLogin::ExistAccountID (QString userAccount)
{
    this->SetUserAccount(userAccount);
    qx::QxSqlQuery query("WHERE CPUserLogin.UserAccount = :UserAccount");
    query.bind(":UserAccount", this->GetUserAccount ());
    qx::dao::fetch_by_query(query,*this);

    if(this->GetAccountID ())
    {
        return true;
    }

    return false;
}

QSqlError CPUserLogin::CreateTable ()
{
    return qx::dao::create_table<CPUserLogin>();
}

QSqlError CPUserLogin::InsertAll (long accountID, long userID, QString userAccount, QString userPassword, QString userIP)
{
    this->SetAll (accountID,userID,userAccount,userPassword,userIP);

    return qx::dao::insert(*this);
}

QSqlError CPUserLogin::FetchPasswordByUserAccount (QString userAccount, QString &userPassword)
{
    this->SetUserAccount(userAccount);
    qx::QxSqlQuery query("WHERE CPUserLogin.UserAccount = :UserAccount");
    query.bind(":UserAccount", this->GetUserAccount ());

    QStringList fetchList;
    fetchList<<"UserPassword";
    QSqlError error=qx::dao::fetch_by_query(query,*this,NULL,fetchList);

    userPassword=this->GetUserPassword ();

    return error;
}

QSqlError CPUserLogin::FetchAllByUserAccount (QString userAccount, QVariantList &userLoginInfo)
{
    this->SetUserAccount (userAccount);
    qx::QxSqlQuery query("WHERE CPUserLogin.UserAccount = :UserAccount");
    query.bind(":UserAccount", this->GetUserAccount ());
    QSqlError error=qx::dao::fetch_by_query(query,*this);

    userLoginInfo << (int)this->GetAccountID () << (int)this->GetUserId()
                   << this->GetUserAccount () << this->GetUserPassword () << this->GetUesrIP ();

    return error;
}



QSqlError CPUserLogin::UpdateAllByUserAccount (QString userAccount, QString userPassword, QString userIP)
{
    this->SetUserAccount (userAccount);
    qx::QxSqlQuery query("WHERE CPUserLogin.UserAccount = :UserAccount");
    query.bind(":UserAccount", this->GetUserAccount ());
    QSqlError error=qx::dao::fetch_by_query(query,*this);

    QStringList updateList;
    if(userIP!=NULL)
    {
        updateList<<"UserIP";
        this->SetUserIP (userIP);
    }
    if(userPassword!=NULL)
    {
        updateList<<"UserPassword";
        this->SetUserPassword (userPassword);
    }

    error=qx::dao::update(*this,NULL,updateList);

    return error;
}


QSqlError CPUserLogin::UpdateAllByAccountID (long accountID, QString userPassword, QString userIP)
{

    this->SetAccountID (accountID);

    QSqlError error=qx::dao::fetch_by_id(*this);

    QStringList updateList;
    if(userIP!=NULL)
    {
        updateList<<"UserIP";
        this->SetUserIP (userIP);
    }
    if(userPassword!=NULL)
    {
        updateList<<"UserPassword";
        this->SetUserPassword (userPassword);
    }

    error=qx::dao::update(*this,NULL,updateList);
    return error;
}


QSqlError CPUserLogin::DeleteUserByAccountID (long accountID)
{
    this->SetAccountID (accountID);

    QSqlError error=qx::dao::destroy_by_id(*this);

    return error;
}

QSqlError CPUserLogin::DeleteUserByUserAccount (QString userAccount)
{
    this->SetUserAccount (userAccount);
    qx::QxSqlQuery query("WHERE CPUserLogin.UserAccount = :UserAccount");
    query.bind(":UserAccount", this->GetUserAccount ());

    QSqlError error=qx::dao::destroy_by_query<CPUserLogin>(query);
    return error;
}


