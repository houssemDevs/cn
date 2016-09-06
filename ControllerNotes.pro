QT += qml quick sql widgets

CONFIG += c++11

SOURCES += \
    file.cpp \
    main.cpp \
    note.cpp \
    notesmodel.cpp \
    project.cpp \
    projectsmodel.cpp \
    filesmodel.cpp \
    notesviewmodel.cpp \
    projectsviewmodel.cpp \
    filesviewmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    file.h \
    note.h \
    notesmodel.h \
    project.h \
    projectsmodel.h \
    filesmodel.h \
    notesviewmodel.h \
    projectsviewmodel.h \
    filesviewmodel.h