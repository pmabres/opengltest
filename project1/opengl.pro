
QT       += core gui opengl

TARGET = openglTest
TEMPLATE = app

SOURCES +=  \
            main.cpp \
            glwidget.cpp

HEADERS  += \
            glwidget.h

OTHER_FILES +=  \
                vertex.shader \
                fragment.shader

RESOURCES +=    \
                core-profile.qrc
