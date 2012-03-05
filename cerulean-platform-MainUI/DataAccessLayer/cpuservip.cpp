#include "cpuservip.h"

#include "precompiled.h"
#include <QxMemLeak.h>

QX_REGISTER_CPP_CP_EXE(CPUserVIP)

namespace qx {
    template <> void register_class(QxClass<CPUserVIP> & t)
    {
      CPUserVIP userVIP;
      userVIP.RegisterClass (t);

    }
}


void CPUserVIP::RegisterClass (qx::QxClass<CPUserVIP> &t)
{
    t.id (& CPUserVIP::m_userVIPID, "UserVIPID");

    t.data (& CPUserVIP::m_userID, "UserID");
    t.data (& CPUserVIP::m_vipTime, "VIPTime");
}

void CPUserVIP::SetAll (long userVIPID, long userID, QString vipTime)
{
    this->m_userVIPID=userVIPID;
    this->m_userID=userID;
    this->m_vipTime=vipTime;
}

QSqlError CPUserVIP::CreateTable ()
{
    return qx::dao::create_table<CPUserVIP>();
}

QSqlError CPUserVIP::InsertAll(long userVIPID, long userID, QString vipTime)
{
    this->SetAll (userVIPID, userID, vipTime);

    QSqlError error=qx::dao::insert(*this);

    return error;
}

QSqlError CPUserVIP::FetchAllByUserVIPID(long userVIPID, QVariantList &userVIP)
{
    this->SetUserVIPID (userVIPID);

    QSqlError error=qx::dao::fetch_by_id(*this);

    userVIP << (int)this->GetUserVIPID () << (int)this->GetUserID () << this->GetVIPTime ();

    return error;
}

QSqlError CPUserVIP::FetchAllByUserID(long userID, QVariantList &userVIP)
{
    this->SetUserID (userID);

    qx::QxSqlQuery query("WHERE CPUserVIP.UserID=:UserID");
    query.bind (":UserID", (int)this->GetUserID ());

    QSqlError error=qx::dao::fetch_by_query(query, *this, NULL);

    userVIP << (int)this->GetUserVIPID () << (int)this->GetUserID () << this->GetVIPTime ();

    return error;
}

QSqlError CPUserVIP::UpdateAllByUserVIPID(long userVIPID, long userID, QString vipTime)
{
    this->SetUserVIPID (userVIPID);

    QStringList updateList;
    if(userID != NULL)
    {
        updateList.append ("UserID");
        this->SetUserID (userID);
    }
    if(!vipTime.isNull ())
    {
        updateList.append ("VIPTime");
        this->SetVipTime (vipTime);
    }

    QSqlError error=qx::dao::update(*this,NULL,updateList);

    return error;
}
QSqlError CPUserVIP::UpdateAllByUserID(long userID, QString vipTime)
{
    this->SetUserID (userID);

    qx::QxSqlQuery query("WHERE CPUserVIP.UserID=:UserID");
    query.bind (":UserID", (int)this->GetUserID ());

    QSqlError error=qx::dao::fetch_by_query(query, *this, NULL);

    QStringList updateList;
    if(!vipTime.isNull ())
    {
        updateList.append ("VIPTime");
        this->SetVipTime (vipTime);
    }

    error=qx::dao::update(*this, NULL, updateList);

    return error;
}

QSqlError CPUserVIP::DeleteAllByUserVIPID(long userVIPID)
{
    this->SetUserVIPID (userVIPID);

    QSqlError error=qx::dao::destroy_by_id(*this);

    return error;
}

QSqlError CPUserVIP::DeleteAllByUserID (long userID)
{
    this->SetUserID (userID);
    qx::QxSqlQuery query("WHERE CPUserVIP.UserID=:UserID");
    query.bind (":UserID", (int)this->GetUserID ());

    QSqlError error=qx::dao::destroy_by_query<CPUserVIP>(query);

    return error;
}
