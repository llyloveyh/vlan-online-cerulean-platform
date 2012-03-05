#ifndef CPUSERFRIEND_H
#define CPUSERFRIEND_H

#include "precompiled.h"

class CPUserFriend
{
public:

    CPUserFriend(){;}
    virtual ~CPUserFriend() {;}

public:

    QSqlError CreateTable();

    QSqlError InsertAll(long friendID, long userID1st, long userID2nd);

    QSqlError FetchAllByFriendID(long friendID, long &userID1st, long &userID2nd);
    QSqlError Fetch1stBy2nd(QVariantList &userID1stLst, long userID2nd);
    QSqlError Fetch2ndBy1st(long userID1st, QVariantList &userID2ndLst);

    QSqlError UpdateAllByFriendID(long friendID, long userID1st, long userID2nd);

    QSqlError DeleteByFriendID(long friendID);
    QSqlError DeleteByUserID1st(long userID1st);
    QSqlError DeleteByUserID2nd(long userID2nd);

public:

    void RegisterClass(qx::QxClass<CPUserFriend> & t);

public:

    inline void SetFriendID(long friendID) { this->m_friendID=friendID; }
    inline void SetUserID1st(long userID1st) { this->m_userID1st=userID1st; }
    inline void SetUserID2nd(long userID2nd) { this->m_userID2nd=userID2nd; }

    void SetALL(long friendID, long userID1st, long userID2nd);

    inline long GetFriendID() { return m_friendID; }
    inline long GetUserID1st() { return m_userID1st; }
    inline long GetUserID2nd() { return m_userID2nd; }

private:

    long m_friendID;
    long m_userID1st;
    long m_userID2nd;


};

typedef boost::shared_ptr<CPUserFriend> CPUserFriend_ptr;
typedef std::vector<CPUserFriend_ptr> type_lst_cpUserFriend;

QX_REGISTER_HPP_CP_EXE(CPUserFriend, qx::trait::no_base_class_defined, 1)


#endif // CPUSERFRIEND_H
