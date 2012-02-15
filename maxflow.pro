CONFIG += qt debug
TEMPLATE = app
TARGET = maxflow
DEPENDPATH += . src
INCLUDEPATH += .
HEADERS += src/MainWidget.hpp src/Context.hpp src/Node.hpp src/Edge.hpp src/Graph.hpp src/NodeDialog.hpp
SOURCES += src/main.cpp src/MainWidget.cpp src/Context.cpp src/Node.cpp src/Edge.cpp src/Graph.cpp src/NodeDialog.cpp
