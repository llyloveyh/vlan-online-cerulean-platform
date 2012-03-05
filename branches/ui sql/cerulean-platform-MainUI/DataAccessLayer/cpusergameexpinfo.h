#ifndef CPUSERGAMEEXPINFO_H
#define CPUSERGAMEEXPINFO_H

#include "precompiled.h"

class CPUserGameEXPInfo
{
public:

    CPUserGameEXPInfo(){;}
    virtual ~CPUserGameEXPInfo() {;}

public:

    QSqlError CreateTable();

    QSqlError InsetAll(long userID, long gameID, long credits);

    QSqlError FetchAllByUserID(long userID, QVariantList &userGameExpInfo);

    QSqlError UpdateAllByUserID(long userID, long gameID, long credits);

    QSqlError DeleteAllByUserID(long userID);
public:

    void RegisterClass(qx::QxClass<CPUserGameEXPInfo> & t);


public:

    inline void SetUserID(long userID) { this->m_userID=userID; }
    inline void SetGameID(long gameID) { this->m_gameID=gameID; }
    inline void SetCredits(long credits) { this->m_credits=credits; }

    void SetAll(long userID, long gameID, long credits);

    inline long GetUserID() { return m_userID; }
    inline long GetGameID() { return m_gameID; }
    inline long GetCredits() { return m_credits; }

private:

    long m_userID;
    long m_gameID;
    long m_credits;


};

typedef boost::shared_ptr<CPUserGameEXPInfo> CPUserGameEXPInfo_ptr;
typedef std::vector<CPUserGameEXPInfo_ptr> type_lst_cpUserGameEXPInfo;

QX_REGISTER_HPP_CP_EXE(CPUserGameEXPInfo, qx::trait::no_base_class_defined, 1)

#endif // CPUSERGAMEEXPINFO_H
