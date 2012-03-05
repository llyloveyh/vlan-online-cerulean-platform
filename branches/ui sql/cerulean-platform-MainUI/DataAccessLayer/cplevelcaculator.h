#ifndef CPLEVELCACULATOR_H
#define CPLEVELCACULATOR_H

#include "precompiled.h"

class CPLevelCaculator
{
public:

    CPLevelCaculator(){;}
    virtual ~CPLevelCaculator() {;}

public:

    QSqlError CreateTable();

    QSqlError InsertAll(long levelCacuID, long gameID, long gameCredits, long gameLevel);

    QSqlError FetchAllByCacuID(long levelCacuID, QVariantList &levelCaculator);
    QSqlError FetchAllByGameID(long gameID,QVariantList &levelCaculator);

    QSqlError UpdateByCacuID(long levelCacuID, long gameID, long gameCredits, long gameLevel);
    QSqlError UpdateByGameID(long gameID, long gameCredits, long gameLevel);

    QSqlError DeleteByCacuID(long levelCacuID);
    QSqlError DeleteByGameID(long gameID);

public:

    void RegisterClass(qx::QxClass<CPLevelCaculator> & t);

public:

    inline void SetLevelCacuID(long levelCacuID) { this->m_levelCacuID=levelCacuID; }
    inline void SetGameID(long gameID) { this->m_gameID=gameID; }
    inline void SetGameCredits(long gameCredits) { this->m_gameCredits=gameCredits; }
    inline void SetGameLevel(long gameLevel) { this->m_gameLevel=gameLevel; }

    void SetAll(long levelCacuID, long gameID, long gameCredits, long gameLevel);

    inline long GetLevelCacuID() { return m_levelCacuID; }
    inline long GetGameID() { return m_gameID; }
    inline long GetGameCredits() { return m_gameCredits; }
    inline long GetGameLevel() { return m_gameLevel; }

private:

    long m_levelCacuID;
    long m_gameID;
    long m_gameCredits;
    long m_gameLevel;


};

typedef boost::shared_ptr<CPLevelCaculator> CPLevelCaculator_ptr;
typedef std::vector<CPLevelCaculator_ptr> type_lst_cpLevelCaculator;

QX_REGISTER_HPP_CP_EXE(CPLevelCaculator, qx::trait::no_base_class_defined, 1)

#endif // CPLEVELCACULATOR_H
