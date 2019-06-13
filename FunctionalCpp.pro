TEMPLATE = app

CONFIG += console
CONFIG += c++1z
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -pthread
#QMAKE_CXXFLAGS += -std=c++17

LIBS += -pthread
LIBS +=  -lstdc++fs


HEADERS += $$files(*.hpp, true)

SOURCES += \
  main.cpp
