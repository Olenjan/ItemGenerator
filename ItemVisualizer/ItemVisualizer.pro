QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affixrollsviewer.cpp \
    baseitemviewer.cpp \
    characterviewer.cpp \
    data/AffixRoll.cpp \
    data/collapsed/CollapsedAffix.cpp \
    itemview.cpp \
    main.cpp \
    mainwindow.cpp \
    modifierviewer.cpp

HEADERS += \
    affixrollsviewer.h \
    baseitemviewer.h \
    characterviewer.h \
    data/AffixRoll.h \
    data/AffixRollEffetType.h \
    data/AffixTag.h \
    data/AffixType.h \
    data/BaseData.h \
    data/Character.h \
    data/collapsed/CollapsedAffix.h \
    data/collapsed/CollapsedItemState.h \
    data/database.h \
    data/ItemBase.h \
    data/ItemBaseSlotType.h \
    data/Modifier.h \
    data/ModifierType.h \
    data/Rarity.h \
    data/generator/ItemGenerator.h \
    itemview.h \
    mainwindow.h \
    modifierviewer.h \
    sql/SqlAffixTags.h \
    sql/SqlTable.h

FORMS += \
    affixrollsviewer.ui \
    baseitemviewer.ui \
    characterviewer.ui \
    itemview.ui \
    mainwindow.ui \
    modifierviewer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc
