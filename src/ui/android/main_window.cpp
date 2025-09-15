// src/ui/android/main_window.cpp
#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Setup for Android
    
    // Create a horizontal layout for editor and a menu button
    QHBoxLayout* hLayout = new QHBoxLayout();
    
    TextEditor* editor = new TextEditor(this);
    hLayout->addWidget(editor);
    
    // Add a toolbar or menu button suitable for mobile
    QAction* menuAction = new QAction(QIcon(":/icons/menu.svg"), "Menu", this);
    connect(menuAction, &QAction::triggered, this, &MainWindow::openMobileMenu);
    
    QToolBar* toolbar = new QToolBar(this);
    toolbar->addAction(menuAction);
    
    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addWidget(toolbar);
    vLayout->addLayout(hLayout);
    
    // Set up the central widget
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(vLayout);
    setCentralWidget(centralWidget);
}
