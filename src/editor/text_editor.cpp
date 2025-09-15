#include "text_editor.h"
#include "utils/file_io.h"

TextEditor::TextEditor(QWidget *parent) : QPlainTextEdit(parent) {
    // Set up auto-save timer
    m_autoSaveTimer.setInterval(5000); // 5 seconds
    connect(&m_autoSaveTimer, &QTimer::timeout, this, &TextEditor::autoSave);
    m_autoSaveTimer.start();
}

void TextEditor::autoSave() {
    // Check if the document has been modified
    if (document()->isModified()) {
        QString filePath = this->property("filePath").toString();
        if (!filePath.isEmpty()) {
            // Create a temporary file path
            QString tempFilePath = filePath + ".autosave";
            
            // Call the utility function to save the file
            FileIO::saveFile(tempFilePath, toPlainText());
            
            // Optional: Provide visual feedback to the user
            qDebug() << "Auto-saved to " << tempFilePath;
        }
    }
}
