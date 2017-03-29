TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_LFLAGS += -static-libgcc

QMAKE_CFLAGS += -std=c11

QT   += opengl
LIBS += -lopengl32

INCLUDEPATH += $$PWD/../../external_libs/glfw/include/
INCLUDEPATH += $$PWD/../../external_libs/glut/include/
INCLUDEPATH += $$PWD/../../external_libs/soil/
DEPENDPATH  += $$PWD/../../external_libs/soil/

win32: LIBS += -L$$PWD/../../external_libs/glfw/lib/ -lglfw3
win32: LIBS += -L$$PWD/../../external_libs/glut/lib/ -lglut32
win32: LIBS += -lgdi32

SOURCES += main.c \
    ../../external_libs/soil/image_DXT.c \
    ../../external_libs/soil/image_helper.c \
    ../../external_libs/soil/SOIL.c \
    ../../external_libs/soil/stb_image_aug.c

HEADERS += \
    ../../external_libs/soil/image_DXT.h \
    ../../external_libs/soil/image_helper.h \
    ../../external_libs/soil/SOIL.h \
    ../../external_libs/soil/stb_image_aug.h \
    ../../external_libs/soil/stbi_DDS_aug.h \
    ../../external_libs/soil/stbi_DDS_aug_c.h

