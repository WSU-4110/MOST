#include "quizwindow.h"
#include <QFileDialog>
#include <QMessageBox>

// For pageQuizMenu in quizwindow.ui
// Can be moved/merged later if needed

// Load Button - Loading quiz: Opens a file dialog to select existing .db file
void QuizWindow::on_pushButtonLoad_clicked() {
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Quiz File"),   // Dialog title
        QCoreApplication::applicationDirPath() + "/Saves/Quiz", // Open the saved quiz directory
        tr("Quiz Files (*.db)") // Only .db files
        );

    if (!fileName.isEmpty()) {
        // Get fileName only (not the entire path)
        QFileInfo fileInfo(fileName);
        fileName = fileInfo.fileName();
        quizDB = new DatabaseQuiz();
        if (quizDB) {
            quizDB->loadQuiz(fileName);
            QMessageBox::information(this, tr("Success"), tr("Quiz loaded successfully!"));
        } else {
            qDebug() << "quizDB is not initialized";
        }
    } else {
        QMessageBox::warning(this, tr("No file selected"), tr("Please select a valid quiz file."));
    }
}
