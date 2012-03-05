#include <QtGui/QApplication>
#include "mainui.h"

#include "DataAccessLayer/cpdalinterface.h"

#include <QxMemLeak.h>
#include <QxDao/QxSqlDatabase.h>

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);

    MainUI ui;
    ui.show();

    qx::QxSqlDatabase::getSingleton()->setDriverName("QODBC");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("DRIVER={SQL SERVER};SERVER=(local);DATABASE=CeruleanPlantform");
    qx::QxSqlDatabase::getSingleton()->setUserName("");
    qx::QxSqlDatabase::getSingleton()->setPassword("");

    CPDALInterface_ptr interface(new CPDALInterface);


    QVariantList list2;
    interface->DeleteGameByID (1);
    interface->DeleteGameByName ("war");
    interface->DeleteLevelCacuByCacuID (1);
    interface->DeleteUserFriendByFriendID (1);
    interface->DeleteUserFriendByUserID1st (2);
    interface->DeleteUserGameEXPByUserID (1);
    interface->DeleteUserLoginByUserAccount ("ykl");
    interface->DeleteUserVIPByUserVIPID (20);

    return app.exec ();

}
