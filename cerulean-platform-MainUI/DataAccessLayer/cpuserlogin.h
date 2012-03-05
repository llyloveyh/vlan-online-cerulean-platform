#ifndef CPUSERLOGIN_H
#define CPUSERLOGIN_H

#include "precompiled.h"

class CPUserLogin;



class CPUserLogin
{
public:

    CPUserLogin(){;}
    virtual ~CPUserLogin(){;}

public:

    bool ExistAccountID(QString userAccount);

    QSqlError CreateTable();

    QSqlError InsertAll(long accountID, long userID, QString userAccount, QString userPassword,QString userIP);

    QSqlError FetchPasswordByUserAccount(QString userAccount, QString &userPassword);
    QSqlError FetchAllByUserAccount(QString userAccount, QVariantList &userLoginInfo);


    QSqlError UpdateAllByUserAccount(QString userAccount, QString userPassword, QString userIP);
    QSqlError UpdateAllByAccountID(long accountID, QString userPassword, QString userIP);

    QSqlError DeleteUserByAccountID(long accountID);
    QSqlError DeleteUserByUserAccount(QString userAccount);

public:

    void RegisterClass(qx::QxClass<CPUserLogin> & t);

public :

    inline void SetAccountID(long accountID) { this->m_accountID=accountID; }
    inline void SetUserID(long userID) { this->m_userID=userID; }
    inline void SetUserAccount(QString userAccount) { this->m_userAccount=userAccount; }
    inline void SetUserPassword(QString userPassword) { this->m_userPassword=userPassword; }
    inline void SetUserIP(QString userIP) { this->m_userIP=userIP; }

    void SetAll(long accountID, long userID, QString userAccount, QString userPassword,QString userIP);

    inline long GetAccountID() { return m_accountID; }
    inline long GetUserId() { return m_userID; }
    inline QString GetUserAccount() { return m_userAccount; }
    inline QString GetUserPassword() { return m_userPassword; }
    inline QString GetUesrIP() { return m_userIP; }

private:

    long m_accountID;
    long m_userID;
    QString m_userAccount;
    QString m_userPassword;
    QString m_userIP;


};

typedef boost::shared_ptr<CPUserLogin> CPUserLogin_ptr;
typedef std::vector<CPUserLogin_ptr> type_lst_cpUserLogin;

QX_REGISTER_HPP_CP_EXE(CPUserLogin, qx::trait::no_base_class_defined, 1)


#endif // CPUSERLOGIN_H
