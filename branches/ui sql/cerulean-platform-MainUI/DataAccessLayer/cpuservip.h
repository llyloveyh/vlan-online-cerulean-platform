#ifndef CPUSERVIP_H
#define CPUSERVIP_H

#include "precompiled.h"
#include <QString>

class CPUserVIP
{
public:

    CPUserVIP(){;}
    virtual ~CPUserVIP() {;}

public:

    QSqlError CreateTable();

    QSqlError InsertAll(long userVIPID, long userID, QString vipTime);

    QSqlError FetchAllByUserVIPID(long userVIPID, QVariantList &userVIP);
    QSqlError FetchAllByUserID(long userID, QVariantList &userVIP);

    QSqlError UpdateAllByUserVIPID(long userVIPID, long userID, QString vipTime);
    QSqlError UpdateAllByUserID(long userID, QString vipTime);

    QSqlError DeleteAllByUserVIPID(long userVIPID);
    QSqlError DeleteAllByUserID(long userID);

public:
    void RegisterClass(qx::QxClass<CPUserVIP> & t);

public:

    inline void SetUserVIPID(long userVIPID) { this->m_userVIPID=userVIPID; }
    inline void SetUserID(long userID) { this->m_userID=userID; }
    inline void SetVipTime(QString vipTime) { this->m_vipTime=vipTime; }

    void SetAll(long userVIPID, long userID, QString vipTime);

    inline long GetUserVIPID() { return this->m_userVIPID; }
    inline long GetUserID() { return this->m_userID; }
    inline QString GetVIPTime() { return this->m_vipTime; }

private:

    long m_userVIPID;
    long m_userID;
    QString m_vipTime;

};

typedef boost::shared_ptr<CPUserVIP> CPUserVIP_ptr;
typedef std::vector<CPUserVIP_ptr> type_lst_cpUserVIP;

QX_REGISTER_HPP_CP_EXE(CPUserVIP, qx::trait::no_base_class_defined, 1)

#endif // CPUSERVIP_H
