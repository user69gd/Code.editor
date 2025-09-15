// src/ui/desktop/main_window.cpp
#include "main_window.h"
#include "editor/text_editor.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Set up main layout and menu bar
    auto editor = new TextEditor(this);
    setCentralWidget(editor);
}
