#include "cpuserfriend.h"

#include "precompiled.h"
#include <QxMemLeak.h>

QX_REGISTER_CPP_CP_EXE(CPUserFriend)


namespace qx {
    template <> void register_class(QxClass<CPUserFriend> & t)
    {
        CPUserFriend userFriend;
        userFriend.RegisterClass (t);
    }
}


void CPUserFriend::RegisterClass (qx::QxClass<CPUserFriend> &t)
{
    t.id(& CPUserFriend::m_friendID, "FriendID");

    t.data(& CPUserFriend::m_userID1st, "UserID1st");

    t.data(& CPUserFriend::m_userID2nd, "UserID2nd");
}

void CPUserFriend::SetALL (long friendID, long userID1st, long userID2nd)
{
    this->m_friendID=friendID;
    this->m_userID1st=userID1st;
    this->m_userID2nd=userID2nd;
}

QSqlError CPUserFriend::CreateTable ()
{
    return qx::dao::create_table<CPUserFriend>();
}

QSqlError CPUserFriend::InsertAll(long friendID, long userID1st, long userID2nd)
{
    this->SetALL (friendID, userID1st, userID2nd);

    QSqlError error=qx::dao::insert(*this);

    return error;
}

QSqlError CPUserFriend::FetchAllByFriendID(long friendID, long &userID1st, long &userID2nd)
{
    this->SetFriendID(friendID);

    QSqlError error=qx::dao::fetch_by_id(*this);

    userID1st=this->GetUserID1st();
    userID2nd=this->GetUserID2nd();

    return error;
}

QSqlError CPUserFriend::Fetch1stBy2nd(QVariantList &userID1stLst, long userID2nd)
{
    this->SetUserID2nd (userID2nd);

    qx::QxSqlQuery query("WHERE CPUserFriend.UserID2nd=:UserID2nd");
    query.bind (":UserID2nd", (int)this->GetUserID2nd ());

    type_lst_cpUserFriend lstCPUserFriend;
    QSqlError error=qx::dao::fetch_by_query(query,lstCPUserFriend);

    for(int i=0 ; i<lstCPUserFriend.size () ; i++)
    {
        userID1stLst.append ( (int)lstCPUserFriend[i]->GetUserID1st() );
        lstCPUserFriend[i].reset();
    }

    lstCPUserFriend.clear ();

    return error;
}

QSqlError CPUserFriend::Fetch2ndBy1st(long userID1st, QVariantList &userID2ndLst)
{
    this->SetUserID1st (userID1st);

    qx::QxSqlQuery query("WHERE CPUserFriend.UserID1st=:UserID1st");
    query.bind (":UserID1st", (int)this->GetUserID1st ());

    type_lst_cpUserFriend lstCPUserFriend;
    QSqlError error=qx::dao::fetch_by_query(query,lstCPUserFriend);

    for(int i=0 ; i<lstCPUserFriend.size () ; i++)
    {
        userID2ndLst.append ( (int)lstCPUserFriend[i]->GetUserID2nd() );
        lstCPUserFriend[i].reset();
    }

    lstCPUserFriend.clear ();

    return error;
}

QSqlError CPUserFriend::UpdateAllByFriendID(long friendID, long userID1st, long userID2nd)
{
    this->SetALL (friendID, userID1st, userID2nd);

    QStringList updateList;

    if(userID1st!=NULL)
    {
        updateList<<"UserID1st";
    }
    if(userID2nd!=NULL)
    {
        updateList<<"UserID2nd";
    }

    QSqlError error=qx::dao::update(*this,NULL,updateList);

    return error;

}

QSqlError CPUserFriend::DeleteByFriendID(long friendID)
{
    this->SetFriendID (friendID);

    QSqlError error=qx::dao::destroy_by_id(*this);

    return error;
}

QSqlError CPUserFriend::DeleteByUserID1st(long userID1st)
{
    this->SetUserID1st (userID1st);

    qx::QxSqlQuery query("WHERE CPUserFriend.UserID1st=:UserID1st");
    query.bind (":UserID1st", (int)this->GetUserID1st ());

    QSqlError error=qx::dao::destroy_by_query<CPUserFriend>(query);
    return error;
}

QSqlError CPUserFriend::DeleteByUserID2nd(long userID2nd)
{
    this->SetUserID2nd (userID2nd);
    qx::QxSqlQuery query("WHERE CPUserFriend.UserID2nd=:UserID2nd");
    query.bind (":UserID2nd", (int)this->GetUserID2nd ());

    QSqlError error=qx::dao::destroy_by_query<CPUserFriend>(query);

    return error;
}
