#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T19:46:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = time
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    popup.cpp

HEADERS  += widget.h \
    popup.h

FORMS    += widget.ui


# в зависимости от режима сборки проекта
# запускаем win deploy приложения в целевой директории, то есть собираем все dll

#QMAKE_POST_LINK = $(COPY_FILE) "$(DESTDIR_TARGET)" debug
#QMAKE_POST_LINK += $$(QTDIR)/bin/windeployqt "$(DESTDIR_TARGET)"
