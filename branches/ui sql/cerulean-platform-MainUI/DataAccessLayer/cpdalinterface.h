#ifndef CPDALINTERFACE_H
#define CPDALINTERFACE_H

#include "cpgameinfo.h"
#include "cplevelcaculator.h"
#include "cpuserfriend.h"
#include "cpusergameexpinfo.h"
#include "cpuserinfo.h"
#include "cpuserlogin.h"
#include "cpuservip.h"


class CPDALInterface
{
public:
    CPDALInterface();

public:

    bool ExistUserAccount(QString userAccount);

    QSqlError CreateUserLogin();
    QSqlError CreateGameInfo();
    QSqlError CreateLevelCaculator();
    QSqlError CreateUserFriend();
    QSqlError CreateUserGameEXP();
    QSqlError CreateUserInfo();
    QSqlError CreateUserVIP();

/***************************************************************************/


    QSqlError InsertUserLogin(long accountID, long userID, QString userAccount, QString userPassword,QString userIP);
    QSqlError InsertGameInfo(long gameID, QString gameName);
    QSqlError InsertLevelCaculator(long levelCacuID, long gameID, long gameCredits, long gameLevel);
    QSqlError InsertUserFriend(long friendID, long userID1st, long userID2nd);
    QSqlError InsertUserGameEXP(long userID, long gameID, long credits);
    QSqlError InsertUserInfo(long userID, QString userName, QString userAuthority);
    QSqlError InsertUserVIP(long userVIPID, long userID, QString vipTime);


/***************************************************************************/

    QSqlError FetchPasswordByUserAccount(QString userAccount, QString &userPassword);
    QSqlError FetchUserLoginByUserAccount(QString userAccount, QVariantList &userLoginInfo );

    QSqlError FetchGameNameByGameID(long gameID, QString &gameName);
    QSqlError FetchGameNameList(QVariantList &gameList);

    QSqlError FetchLevelCacuByCacuID(long levelCacuID, QVariantList &levelCaculator);
    QSqlError FetchLevelCacuByGameID(long gameID,QVariantList &levelCaculator);

    QSqlError FetchUserFriendByFriendID(long friendID, long &userID1st, long &userID2nd);
    QSqlError FetchUser1stBy2nd(QVariantList &userID1stLst, long userID2nd);
    QSqlError FetchUser2ndBy1st(long userID1st, QVariantList &userID2ndLst);

    QSqlError FetchUserGameEXPByUserID(long userID, QVariantList &userGameExpInfo);

    QSqlError FetchUserInfoByUserID(long userID, QVariantList &userInfo);

    QSqlError FetchUserVIPByUserVIPID(long userVIPID, QVariantList &userVIP);
    QSqlError FetchUserVIPByUserID(long userID, QVariantList &userVIP);
 /***************************************************************************/

    QSqlError UpdateUserLoginByAccountID(long accountID, QString userPassword, QString userIP);
    QSqlError UpdateUserLoginByUserAccount(QString userAccount, QString userPassword, QString userIP);

    QSqlError UpdateGameNameByGameID(long gameID, QString gameName);

    QSqlError UpdateLevelCacuByCacuID(long levelCacuID, long gameID, long gameCredits, long gameLevel);
    QSqlError UpdateLevelCacuByGameID(long gameID, long gameCredits, long gameLevel);

    QSqlError UpdateUserFriendByFriendID(long friendID, long userID1st, long userID2nd);

    QSqlError UpdateUserGameEXPByUserID(long userID, long gameID, long credits);

    QSqlError UpdateUserInfoByUserID(long userID, QString userName, QString userAuthority);

    QSqlError UpdateUserVIPByUserVIPID(long userVIPID, long userID, QString vipTime);
    QSqlError UpdateUserVIPByUserID(long userID, QString vipTime);


/***************************************************************************/

    QSqlError DeleteUserLoginByAccountID(long accountID);
    QSqlError DeleteUserLoginByUserAccount(QString userAccount);

    QSqlError DeleteGameByID(long gameID);
    QSqlError DeleteGameByName(const QString gameName);

    QSqlError DeleteLevelCacuByCacuID(long levelCacuID);
    QSqlError DeleteLevelCacuByGameID(long gameID);

    QSqlError DeleteUserFriendByFriendID(long friendID);
    QSqlError DeleteUserFriendByUserID1st(long userID1st);
    QSqlError DeleteUserFriendByUserID2nd(long userID2nd);

    QSqlError DeleteUserGameEXPByUserID(long userID);

    QSqlError DeleteUserInfoByUserID(long userID);

    QSqlError DeleteUserVIPByUserVIPID(long userVIPID);
    QSqlError DeleteUserVIPByUserID(long userID);

private:

    CPGameInfo_ptr m_cpGameInfo;
    CPLevelCaculator_ptr m_cpLevelCaculator;
    CPUserFriend_ptr m_cpUserFriend;
    CPUserGameEXPInfo_ptr m_cpUserGameEXPInfo;
    CPUserInfo_ptr m_cpUserInfo;
    CPUserLogin_ptr m_cpUserLogin;
    CPUserVIP_ptr m_cpUserVIP;

    type_lst_cpGameInfo lst_CPGameInfo;
    type_lst_cpLevelCaculator lst_CPLevelCaculator;
    type_lst_cpUserFriend lst_CPUserFriend;
    type_lst_cpUserGameEXPInfo lst_CPUserGameEXPInfo;
    type_lst_cpUserInfo lst_CPUserInfo;
    type_lst_cpUserLogin lst_CPUserLogin;
    type_lst_cpUserVIP lst_CPUserVIP;

};

typedef boost::shared_ptr<CPDALInterface> CPDALInterface_ptr;
typedef std::vector<CPDALInterface_ptr> type_lst_cpDALInterface;

#endif // CPDALINTERFACE_H
