#include "quizmenu.h"
#include "quizwindow.h"
#include <QPushButton>

// For pageQuizMenu in quizwindow.ui

QuizMenu::QuizMenu(QuizWindow* quizWin, QWidget *parent)
    : QWidget(parent), quizWindow(quizWin)
{
    // Connect the load button from pageQuizMenu in quizwindow.ui
    connect(quizWindow->getLoadButton(), &QPushButton::clicked,
            this, &QuizMenu::onLoadButtonClicked);
}

// Load Button clicked: Loading quiz, Opens a file dialog to select existing .db file
void QuizMenu::onLoadButtonClicked() {
    qDebug() << "load button clicked";
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

        // Create new DatabaseQuiz temporary
        DatabaseQuiz* db = new DatabaseQuiz();
        if (db) {
            if (db->loadQuiz(fileName)) {
                // Store it in quiz window
                quizWindow->setQuizDB(db);

                QMessageBox::information(this, tr("Success"), tr("Quiz loaded successfully!"));
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Failed to load quiz."));
                delete db; // cleanup the temporary
            }
        } else {
            qDebug() << "DatabaseQuiz allocation failed";
        }
    } else {
        QMessageBox::warning(this, tr("No file selected"), tr("Please select a valid quiz file."));
    }
}
