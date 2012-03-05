#include "cpusergameexpinfo.h"

#include "precompiled.h"
#include <QxMemLeak.h>

QX_REGISTER_CPP_CP_EXE(CPUserGameEXPInfo)


namespace qx {
    template <> void register_class(QxClass<CPUserGameEXPInfo> & t)
    {
      CPUserGameEXPInfo userGameEXPInfo;
      userGameEXPInfo.RegisterClass (t);

    }
}


void CPUserGameEXPInfo::RegisterClass (qx::QxClass<CPUserGameEXPInfo> &t)
{
    t.id(& CPUserGameEXPInfo::m_userID, "UserID");

    t.data(& CPUserGameEXPInfo::m_gameID, "GameID");

    t.data(& CPUserGameEXPInfo::m_credits, "Credits");
}

void CPUserGameEXPInfo::SetAll (long userID, long gameID, long credits)
{
    this->m_userID=userID;
    this->m_gameID=gameID;
    this->m_credits=credits;
}

QSqlError CPUserGameEXPInfo::CreateTable ()
{
    return qx::dao::create_table<CPUserGameEXPInfo>();
}

QSqlError CPUserGameEXPInfo::InsetAll(long userID, long gameID, long credits)
{
    this->SetAll (userID, gameID, credits);
    QSqlError error=qx::dao::insert(*this);

    return error;

}

QSqlError CPUserGameEXPInfo::FetchAllByUserID(long userID, QVariantList &userGameExpInfo)
{
    this->SetUserID (userID);

    QSqlError error=qx::dao::fetch_by_id(*this);

    userGameExpInfo << (int)this->GetUserID () << (int)this->GetGameID () << (int)this->GetCredits ();

    return error;
}

QSqlError CPUserGameEXPInfo::UpdateAllByUserID(long userID, long gameID, long credits)
{
    this->SetUserID (userID);

    QStringList updateList;

    if(gameID != NULL)
    {
        updateList.append ("GameID");
        this->SetGameID (gameID);
    }
    if(credits != NULL)
    {
        updateList.append ("Credits");
        this->SetCredits (credits);
    }

    QSqlError error=qx::dao::update(*this, NULL, updateList);
    return error;
}

QSqlError CPUserGameEXPInfo::DeleteAllByUserID(long userID)
{
    this->SetUserID (userID);

    QSqlError error=qx::dao::destroy_by_id(*this);
    return error;
}
