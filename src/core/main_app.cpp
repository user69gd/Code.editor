// src/core/main_app.cpp
#include "main_app.h"

MainApp::MainApp(int argc, char *argv[]) : QApplication(argc, argv) {
    m_mainWindow = new MainWindow();
}

int MainApp::run() {
    m_mainWindow->show();
    return exec();
}
