#include "cpuserinfo.h"
#include "precompiled.h"
#include <QxMemLeak.h>
#include <QxRegister/QxClass.h>
QX_REGISTER_CPP_CP_EXE(CPUserInfo)


namespace qx {
    template <> void register_class(QxClass<CPUserInfo> & t)
    {
      CPUserInfo userInfo;
      userInfo.RegisterClass (t);
    }
}


void CPUserInfo::RegisterClass (qx::QxClass<CPUserInfo> & t)
{

    t.id(& CPUserInfo::m_userID, "UserID");

    t.data(& CPUserInfo::m_userAuthority, "UserAuthority");

    t.data(& CPUserInfo::m_userName, "UserName");
}

void CPUserInfo::SetAll (long userID, QString userName, QString userAuthority)
{
    this->m_userID=userID;
    this->m_userAuthority=userAuthority;
    this->m_userName=userName;

}

QSqlError CPUserInfo::CreateTable ()
{
    return qx::dao::create_table<CPUserInfo>();
}

QSqlError CPUserInfo::InsertAll(long userID, QString userName, QString userAuthority)
{
    this->SetAll (userID, userName, userAuthority);

    QSqlError error=qx::dao::insert(*this);

    return error;
}

QSqlError CPUserInfo::FetchAllByUserID(long userID, QVariantList &userInfo)
{
    this->SetUserID (userID);

    QSqlError error=qx::dao::fetch_by_id(*this);

    userInfo << (int)this->GetUserID () << this->GetUserName () <<this->GetUserAuthority ();

    return error;
}

QSqlError CPUserInfo::UpdateByUserID(long userID, QString userName, QString userAuthority)
{
    this->SetUserID (userID);

    QStringList updateList;
    if(userName != NULL)
    {
        updateList.append ("UserName");
        this->SetUserName (userName);
    }
    if(userAuthority!=NULL)
    {
        updateList.append ("UserAuthority");
        this->SetUserAuthority (userAuthority);
    }

    QSqlError error=qx::dao::update(*this, NULL, updateList);

    return error;
}

QSqlError CPUserInfo::DeleteByUserID(long userID)
{
    this->SetUserID (userID);

    QSqlError error=qx::dao::destroy_by_id(*this);

    return error;
}
