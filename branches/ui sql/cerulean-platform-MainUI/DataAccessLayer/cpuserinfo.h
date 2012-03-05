#ifndef CPUSERINFO_H
#define CPUSERINFO_H
#include "precompiled.h"
#include <QString>


class CPUserInfo
{
public:

    CPUserInfo() {;}
    virtual ~CPUserInfo() {;}

public:

    QSqlError CreateTable();

    QSqlError InsertAll(long userID, QString userName, QString userAuthority);

    QSqlError FetchAllByUserID(long userID, QVariantList &userInfo);

    QSqlError UpdateByUserID(long userID, QString userName, QString userAuthority);

    QSqlError DeleteByUserID(long userID);

public:

    void RegisterClass(qx::QxClass<CPUserInfo> & t);


public:

    inline void SetUserID(long userID) { this->m_userID=userID;}
    inline void SetUserName(QString userName) { this->m_userName=userName; }
    inline void SetUserAuthority(QString userAuthority) { this->m_userAuthority=userAuthority; }

    void SetAll(long userID, QString userName, QString userAuthority) ;

    inline long GetUserID() { return m_userID; }
    inline QString GetUserName() { return m_userName; }
    inline QString GetUserAuthority() { return m_userAuthority; }

private:

    long m_userID;
    QString m_userName;
    QString m_userAuthority;

};

typedef boost::shared_ptr<CPUserInfo> CPUserInfo_ptr;
typedef std::vector<CPUserInfo_ptr> type_lst_cpUserInfo;

QX_REGISTER_HPP_CP_EXE(CPUserInfo, qx::trait::no_base_class_defined, 1)

#endif // CPUSERINFO_H

