QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    flight_info.cpp \
    frm_admin.cpp \
    frm_register.cpp \
    frm_user.cpp \
    frm_user_changepwd.cpp \
    frm_user_delete.cpp \
    main.cpp \
    frm_login.cpp

HEADERS += \
    flight_info.h \
    frm_admin.h \
    frm_login.h \
    frm_register.h \
    frm_user.h \
    frm_user_changepwd.h \
    frm_user_delete.h

FORMS += \
    frm_admin.ui \
    frm_login.ui \
    frm_register.ui \
    frm_user.ui \
    frm_user_changepwd.ui \
    frm_user_delete.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
