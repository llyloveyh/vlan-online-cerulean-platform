#-------------------------------------------------
#
# Project created by QtCreator 2011-10-20T16:28:08
#
#-------------------------------------------------

QT       += core gui

TARGET = cerulean-platform-MainUI
TEMPLATE = app


SOURCES += main.cpp\
    mainui.cpp \
    DataAccessLayer/cpuservip.cpp \
    DataAccessLayer/cpuserlogin.cpp \
    DataAccessLayer/cpuserinfo.cpp \
    DataAccessLayer/cpusergameexpinfo.cpp \
    DataAccessLayer/cpuserfriend.cpp \
    DataAccessLayer/cplevelcaculator.cpp \
    DataAccessLayer/cpgameinfo.cpp \
    DataAccessLayer/cpdalinterface.cpp


HEADERS  += mainui.h \
    DataAccessLayer/precompiled.h \
    DataAccessLayer/export.h \
    DataAccessLayer/cpuservip.h \
    DataAccessLayer/cpuserlogin.h \
    DataAccessLayer/cpuserinfo.h \
    DataAccessLayer/cpusergameexpinfo.h \
    DataAccessLayer/cpuserfriend.h \
    DataAccessLayer/cplevelcaculator.h \
    DataAccessLayer/cpgameinfo.h \
    DataAccessLayer/cpdalinterface.h


FORMS    += mainui.ui \
    roomUI.ui

include(D:/Qt/Qt_extend/QxOrm_1.1.9/QxOrm/QxOrm.pri)

PRECOMPILED_HEADER = ./DataAccessLayer/precompiled.h

DEFINES +=_BUILDING_QX_CP























