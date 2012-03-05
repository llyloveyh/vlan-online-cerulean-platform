#include "cplevelcaculator.h"

#include "precompiled.h"
#include <QxMemLeak.h>

QX_REGISTER_CPP_CP_EXE(CPLevelCaculator)


namespace qx {
    template <> void register_class(QxClass<CPLevelCaculator> & t)
    {
        CPLevelCaculator levelCaculator;
        levelCaculator.RegisterClass (t);
    }
}


void CPLevelCaculator::RegisterClass (qx::QxClass<CPLevelCaculator> &t)
{
    t.id(& CPLevelCaculator::m_levelCacuID, "LevelCacuID");

    t.data(& CPLevelCaculator::m_gameID, "GameID");

    t.data(& CPLevelCaculator::m_gameLevel, "GameLevel");

    t.data(& CPLevelCaculator::m_gameCredits, "GameCredits");
}

void CPLevelCaculator::SetAll (long levelCacuID, long gameID, long gameCredits, long gameLevel)
{
    this->m_levelCacuID=levelCacuID;
    this->m_gameID=gameID;
    this->m_gameCredits=gameCredits;
    this->m_gameLevel=gameLevel;
}

QSqlError CPLevelCaculator::CreateTable ()
{
    return qx::dao::create_table<CPLevelCaculator>();
}

QSqlError CPLevelCaculator::InsertAll(long levelCacuID, long gameID, long gameCredits, long gameLevel)
{
    this->SetAll (levelCacuID, gameID, gameCredits, gameLevel);
    QSqlError error=qx::dao::insert(*this);
    return error;
}

QSqlError CPLevelCaculator::FetchAllByCacuID (long levelCacuID, QVariantList &levelCaculator)
{
    this->SetLevelCacuID (levelCacuID);

    QSqlError error=qx::dao::fetch_by_id(*this);

    levelCaculator<<(int)this->GetLevelCacuID () << (int)this->GetGameID () << (int)this->GetGameCredits () << (int)this->GetGameLevel ();

    return error;
}

QSqlError CPLevelCaculator::FetchAllByGameID (long gameID, QVariantList &levelCaculator)
{
    this->SetGameID (gameID);

    qx::QxSqlQuery query("WHERE CPLevelCaculator.GameID=:GameID");
    query.bind (":GameID", (int)this->GetGameID ());
    QSqlError error=qx::dao::fetch_by_query(query,*this, NULL);

    levelCaculator<<(int)this->GetLevelCacuID () << (int)this->GetGameID () << (int)this->GetGameCredits () << (int)this->GetGameLevel ();


    return error;

}

QSqlError CPLevelCaculator::UpdateByCacuID(long levelCacuID, long gameID, long gameCredits, long gameLevel)
{
    this->SetLevelCacuID (levelCacuID);

    QStringList updateList;

    if(gameID != NULL)
    {
        updateList.append ("GameID");
        this->SetGameID (gameID);
    }
    if(gameCredits != NULL)
    {
        updateList.append ("GameCredits");
        this->SetGameCredits (gameCredits);
    }
    if(gameLevel != NULL)
    {
        updateList.append ("GameLevel");
        this->SetGameLevel (gameLevel);
    }

    QSqlError error=qx::dao::update(*this, NULL, updateList);

    return error;
}

QSqlError CPLevelCaculator::UpdateByGameID(long gameID, long gameCredits, long gameLevel)
{

    this->SetGameID (gameID);

    qx::QxSqlQuery query("WHERE CPLevelCaculator.GameID=:GameID");
    query.bind (":GameID", (int)this->GetGameID ());
    QSqlError error=qx::dao::fetch_by_query(query,*this, NULL);

    QStringList updateList;
    if(gameCredits != NULL)
    {
        updateList.append ("GameCredits");
        this->SetGameCredits (gameCredits);
    }
    if(gameLevel != NULL)
    {
        updateList.append ("GameLevel");
        this->SetGameLevel (gameLevel);
    }


    error=qx::dao::update(*this, NULL, updateList);

    return error;
}

QSqlError CPLevelCaculator::DeleteByCacuID(long levelCacuID)
{
    this->SetLevelCacuID (levelCacuID);

    QSqlError error=qx::dao::destroy_by_id(*this);

    return error;
}

QSqlError CPLevelCaculator::DeleteByGameID(long gameID)
{
    this->SetGameID (gameID);

    qx::QxSqlQuery query("WHERE CPLevelCaculator.GameID=:GameID");
    query.bind (":GameID", (int)this->GetGameID ());

    QSqlError error=qx::dao::destroy_by_query<CPLevelCaculator>(query);

    return error;
}
