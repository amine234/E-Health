QT       += core gui network printsupport multimedia charts
QT+= sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Facture.cpp \
    RDV.cpp \
    conge.cpp \
    connection.cpp \
    dialogamine.cpp \
    dialogimen.cpp \
    dialogoussema.cpp \
    dialogyosr.cpp \
    dialogzac.cpp \
    dossier_medical.cpp \
    employe.cpp \
    fiche_patient.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    medecin.cpp \
    menu.cpp \
    ordon.cpp \
    service.cpp \
    statis.cpp

HEADERS += \
    Facture.h \
    RDV.h \
    conge.h \
    connection.h \
    dialogamine.h \
    dialogimen.h \
    dialogoussema.h \
    dialogyosr.h \
    dialogzac.h \
    dossier_medical.h \
    employe.h \
    fiche_patient.h \
    mail.h \
    mainwindow.h \
    materiel.h \
    medecin.h \
    menu.h \
    ordon.h \
    service.h \
    statis.h

FORMS += \
    dialogamine.ui \
    dialogimen.ui \
    dialogoussema.ui \
    dialogyosr.ui \
    dialogzac.ui \
    mainwindow.ui \
    menu.ui \
    statis.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
