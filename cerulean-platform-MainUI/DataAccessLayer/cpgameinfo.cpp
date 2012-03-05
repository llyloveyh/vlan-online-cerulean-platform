#include "cpgameinfo.h"

#include "precompiled.h"
#include <QxMemLeak.h>

QX_REGISTER_CPP_CP_EXE(CPGameInfo)


namespace qx {
    template <> void register_class(QxClass<CPGameInfo> & t)
    {
       CPGameInfo gameInfo;
       gameInfo.RegisterClass (t);
    }
}


void CPGameInfo::RegisterClass (qx::QxClass<CPGameInfo> &t)
{
    t.id(& CPGameInfo::m_gameID, "GameID");

    t.data(& CPGameInfo::m_gameName, "GameName");
}

void CPGameInfo::SetAll (long gameID, QString gameName)
{
    this->m_gameID=gameID;
    this->m_gameName=gameName;
}

QSqlError CPGameInfo::CreateTable ()
{
    return qx::dao::create_table<CPGameInfo>();
}

QSqlError CPGameInfo::InserAll(long gameID, const QString gameName)
{
    this->SetAll (gameID, gameName);

    return qx::dao::insert(this);

}

QSqlError CPGameInfo::FetchGameName(long gameID, QString &gameName)
{
    this->SetGameID (gameID);
    QStringList fetchList;
    fetchList<<"GameName";
    QSqlError error=qx::dao::fetch_by_id(*this,NULL,fetchList);
    gameName=this->GetGameName ();

    return error;
}

QSqlError CPGameInfo::FetchGameNameList(QVariantList &gameList)
{
    type_lst_cpGameInfo lstCPGameInfo;
    QStringList fetchList = QStringList() << "GameName";
    QSqlError error=qx::dao::fetch_all(lstCPGameInfo,NULL,fetchList);

    for(int i=0; i<lstCPGameInfo.size (); i++)
    {
        gameList.append (lstCPGameInfo[i]->GetGameName());
        lstCPGameInfo[i].reset();
    }

    lstCPGameInfo.clear ();

    return error;
}

QSqlError CPGameInfo::UpdateGameName(long gameID, QString gameName)
{
    this->SetGameName (gameName);
    this->SetGameID (gameID);

    QStringList updateList;
    updateList<<"GameName";
    QSqlError error=qx::dao::update(*this,NULL,updateList);

    return error;
}

QSqlError CPGameInfo::DeleteGameByID(long gameID)
{
    this->SetGameID (gameID);

    QSqlError error=qx::dao::destroy_by_id(*this);

    return error;
}

QSqlError CPGameInfo::DeleteGameByName(QString gameName)
{
    this->SetGameName (gameName);

    qx::QxSqlQuery query("WHERE CPGameInfo.GameName = :GameName");
    query.bind(":GameName", this->GetGameName ());

    QSqlError error=qx::dao::destroy_by_query<CPGameInfo>(query);

    return error;
}

