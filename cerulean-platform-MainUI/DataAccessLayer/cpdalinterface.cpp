#include "cpdalinterface.h"

CPDALInterface::CPDALInterface()
{

    m_cpGameInfo.reset (new CPGameInfo);
    m_cpLevelCaculator.reset (new CPLevelCaculator);
    m_cpUserFriend.reset (new CPUserFriend);
    m_cpUserGameEXPInfo.reset (new CPUserGameEXPInfo);
    m_cpUserInfo.reset (new CPUserInfo);
    m_cpUserLogin.reset (new CPUserLogin);
    m_cpUserVIP.reset (new CPUserVIP);

}


bool CPDALInterface::ExistUserAccount (QString userAccount)
{
    return m_cpUserLogin->ExistAccountID (userAccount);
}

/*********************************************************************/

QSqlError CPDALInterface::CreateUserLogin()
{
    return m_cpUserLogin->CreateTable ();
}

QSqlError CPDALInterface::CreateGameInfo()
{
    return m_cpGameInfo->CreateTable ();
}

QSqlError CPDALInterface::CreateLevelCaculator()
{
    return m_cpLevelCaculator->CreateTable ();
}

QSqlError CPDALInterface::CreateUserFriend()
{
    return m_cpUserFriend->CreateTable ();
}

QSqlError CPDALInterface::CreateUserGameEXP()
{
    return m_cpUserGameEXPInfo->CreateTable ();
}

QSqlError CPDALInterface::CreateUserInfo()
{
    return m_cpUserInfo->CreateTable ();
}

QSqlError CPDALInterface::CreateUserVIP()
{
    return m_cpUserVIP->CreateTable ();
}


/*********************************************************************/

QSqlError CPDALInterface::InsertUserLogin (long accountID, long userID, QString userAccount, QString userPassword, QString userIP)
{
    return m_cpUserLogin->InsertAll (accountID, userID, userAccount,userPassword, userIP);
}

QSqlError CPDALInterface::InsertGameInfo(long gameID, QString gameName)
{
    return m_cpGameInfo->InserAll (gameID, gameName);
}

QSqlError CPDALInterface::InsertLevelCaculator(long levelCacuID, long gameID, long gameCredits, long gameLevel)
{
    return m_cpLevelCaculator->InsertAll (levelCacuID, gameID, gameCredits, gameLevel);
}

QSqlError CPDALInterface::InsertUserFriend(long friendID, long userID1st, long userID2nd)
{
    return m_cpUserFriend->InsertAll (friendID, userID1st, userID2nd);
}

QSqlError CPDALInterface::InsertUserGameEXP(long userID, long gameID, long credits)
{
    return m_cpUserGameEXPInfo->InsetAll (userID, gameID, credits);
}

QSqlError CPDALInterface::InsertUserInfo(long userID, QString userName, QString userAuthority)
{
    return m_cpUserInfo->InsertAll (userID, userName, userAuthority);
}

QSqlError CPDALInterface::InsertUserVIP(long userVIPID, long userID, QString vipTime)
{
    return m_cpUserVIP->InsertAll (userVIPID, userID, vipTime);
}


QSqlError CPDALInterface::FetchPasswordByUserAccount (QString userAccount, QString &userPassword)
{
    return m_cpUserLogin->FetchPasswordByUserAccount (userAccount, userPassword);
}

QSqlError CPDALInterface::FetchUserLoginByUserAccount (QString userAccount, QVariantList &userLoginInfo)
{
    return m_cpUserLogin->FetchAllByUserAccount (userAccount, userLoginInfo);
}

QSqlError CPDALInterface::FetchGameNameByGameID(long gameID, QString &gameName)
{
    return m_cpGameInfo->FetchGameName (gameID, gameName);
}

QSqlError CPDALInterface::FetchGameNameList(QVariantList &gameList)
{
    return m_cpGameInfo->FetchGameNameList (gameList);
}

QSqlError CPDALInterface::FetchLevelCacuByCacuID(long levelCacuID, QVariantList &levelCaculator)
{
    return m_cpLevelCaculator->FetchAllByCacuID (levelCacuID, levelCaculator);
}

QSqlError CPDALInterface::FetchLevelCacuByGameID(long gameID,QVariantList &levelCaculator)
{
    return m_cpLevelCaculator->FetchAllByGameID (gameID, levelCaculator);
}

QSqlError CPDALInterface::FetchUserFriendByFriendID(long friendID, long &userID1st, long &userID2nd)
{
    return m_cpUserFriend->FetchAllByFriendID (friendID, userID1st, userID2nd);
}

QSqlError CPDALInterface::FetchUser1stBy2nd(QVariantList &userID1stLst, long userID2nd)
{
    return m_cpUserFriend->Fetch1stBy2nd (userID1stLst, userID2nd);
}

QSqlError CPDALInterface::FetchUser2ndBy1st(long userID1st, QVariantList &userID2ndLst)
{
    return m_cpUserFriend->Fetch2ndBy1st (userID1st, userID2ndLst);
}

QSqlError CPDALInterface::FetchUserGameEXPByUserID(long userID, QVariantList &userGameExpInfo)
{
    return m_cpUserGameEXPInfo->FetchAllByUserID (userID, userGameExpInfo);
}

QSqlError CPDALInterface::FetchUserInfoByUserID(long userID, QVariantList &userInfo)
{
    return m_cpUserInfo->FetchAllByUserID (userID, userInfo);
}

QSqlError CPDALInterface::FetchUserVIPByUserVIPID(long userVIPID, QVariantList &userVIP)
{
    return m_cpUserVIP->FetchAllByUserVIPID (userVIPID, userVIP);
}

QSqlError CPDALInterface::FetchUserVIPByUserID(long userID, QVariantList &userVIP)
{
    return m_cpUserVIP->FetchAllByUserID (userID, userVIP);
}

/*********************************************************************/

QSqlError CPDALInterface::UpdateUserLoginByAccountID(long accountID, QString userPassword, QString userIP)
{
    return m_cpUserLogin->UpdateAllByAccountID (accountID, userPassword, userIP);
}

QSqlError CPDALInterface::UpdateUserLoginByUserAccount(QString userAccount, QString userPassword, QString userIP)
{
    return m_cpUserLogin->UpdateAllByUserAccount (userAccount, userPassword, userIP);
}

QSqlError CPDALInterface::UpdateGameNameByGameID(long gameID, QString gameName)
{
    return m_cpGameInfo->UpdateGameName (gameID, gameName);
}

QSqlError CPDALInterface::UpdateLevelCacuByCacuID(long levelCacuID, long gameID, long gameCredits, long gameLevel)
{
    return m_cpLevelCaculator->UpdateByCacuID (levelCacuID, gameID, gameCredits, gameLevel);
}

QSqlError CPDALInterface::UpdateLevelCacuByGameID(long gameID, long gameCredits, long gameLevel)
{
    return m_cpLevelCaculator->UpdateByGameID (gameID, gameCredits ,gameLevel);
}

QSqlError CPDALInterface::UpdateUserFriendByFriendID(long friendID, long userID1st, long userID2nd)
{
    return m_cpUserFriend->UpdateAllByFriendID (friendID, userID1st, userID2nd);
}

QSqlError CPDALInterface::UpdateUserGameEXPByUserID(long userID, long gameID, long credits)
{
    return m_cpUserGameEXPInfo->UpdateAllByUserID (userID, gameID, credits );

}

QSqlError CPDALInterface::UpdateUserInfoByUserID(long userID, QString userName, QString userAuthority)
{
    return m_cpUserInfo->UpdateByUserID (userID, userName, userAuthority);
}

QSqlError CPDALInterface::UpdateUserVIPByUserVIPID(long userVIPID, long userID, QString vipTime)
{
    return m_cpUserVIP->UpdateAllByUserVIPID (userVIPID, userID, vipTime);
}

QSqlError CPDALInterface::UpdateUserVIPByUserID(long userID, QString vipTime)
{
    return m_cpUserVIP->UpdateAllByUserID (userID, vipTime);
}

/*********************************************************************/


QSqlError CPDALInterface::DeleteUserLoginByAccountID (long accountID)
{
    return m_cpUserLogin->DeleteUserByAccountID (accountID);
}

QSqlError CPDALInterface::DeleteUserLoginByUserAccount (QString userAccount)
{
    return m_cpUserLogin->DeleteUserByUserAccount (userAccount);
}


QSqlError CPDALInterface::DeleteGameByID(long gameID)
{
    return m_cpGameInfo->DeleteGameByID (gameID);
}

QSqlError CPDALInterface::DeleteGameByName(const QString gameName)
{
    return m_cpGameInfo->DeleteGameByName (gameName);
}

QSqlError CPDALInterface::DeleteLevelCacuByCacuID(long levelCacuID)
{
    return m_cpLevelCaculator->DeleteByCacuID (levelCacuID);
}

QSqlError CPDALInterface::DeleteLevelCacuByGameID(long gameID)
{
    return m_cpLevelCaculator->DeleteByGameID (gameID);
}

QSqlError CPDALInterface::DeleteUserFriendByFriendID(long friendID)
{
    return m_cpUserFriend->DeleteByFriendID (friendID);
}

QSqlError CPDALInterface::DeleteUserFriendByUserID1st(long userID1st)
{
    return m_cpUserFriend->DeleteByUserID1st (userID1st);
}

QSqlError CPDALInterface::DeleteUserFriendByUserID2nd(long userID2nd)
{
    return m_cpUserFriend->DeleteByUserID2nd (userID2nd);
}

QSqlError CPDALInterface::DeleteUserGameEXPByUserID(long userID)
{
    return m_cpUserGameEXPInfo->DeleteAllByUserID (userID);
}

QSqlError CPDALInterface::DeleteUserInfoByUserID(long userID)
{
    return m_cpUserInfo->DeleteByUserID (userID);
}

QSqlError CPDALInterface::DeleteUserVIPByUserVIPID(long userVIPID)
{
    return m_cpUserVIP->DeleteAllByUserVIPID (userVIPID);
}

QSqlError CPDALInterface::DeleteUserVIPByUserID(long userID)
{
    return m_cpUserVIP->DeleteAllByUserID (userID);
}
