// src/core/main_app.h
#pragma once

#include <QApplication>
#include "ui/desktop/main_window.h"

class MainApp : public QApplication {
public:
    MainApp(int argc, char *argv[]);
    int run();

private:
    MainWindow* m_mainWindow;
};
