#ifndef CPGAMEINFO_H
#define CPGAMEINFO_H

#include "precompiled.h"

class CPGameInfo
{
public :

    CPGameInfo(){;}
    virtual ~CPGameInfo() {;}

public:

    QSqlError CreateTable();

    QSqlError InserAll(long gameID, QString gameName);

    QSqlError FetchGameName(long gameID, QString &gameName);
    QSqlError FetchGameNameList(QVariantList &gameList);

    QSqlError UpdateGameName(long gameID, QString gameName);

    QSqlError DeleteGameByID(long gameID);
    QSqlError DeleteGameByName(const QString gameName);

public:

    void RegisterClass(qx::QxClass<CPGameInfo> & t);

public :

    inline void SetGameID(long gameID) { this->m_gameID=gameID; }
    inline void SetGameName(QString gameName) {this->m_gameName=gameName; }

    void SetAll(long gameID, QString gameName);

    inline long GetGameID() { return m_gameID; }
    inline QString GetGameName() {return m_gameName; }

private :

    long m_gameID;
    QString m_gameName;

};

typedef boost::shared_ptr<CPGameInfo> CPGameInfo_ptr;
typedef std::vector<CPGameInfo_ptr> type_lst_cpGameInfo;

QX_REGISTER_HPP_CP_EXE(CPGameInfo, qx::trait::no_base_class_defined, 1)

#endif // CPGAMEINFO_H
