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
    connect(quizWindow->getSaveButton(), &QPushButton::clicked,
            this, &QuizMenu::onSaveButtonClicked);
}

// Load Button clicked: Opens a file dialog to select existing .db file
// After selecting .db file, sets quizDB in QuizWindow to the .db file
// Then loads contents of .db file to QuizBank
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
                // Store db to quizwindow
                quizWindow->setQuizDB(db);

                // Load Quiz Database to Quiz Bank
                loadDbToQuizBank(quizWindow->getQuizBank());

                quizWindow->getQuizBank()->debugAll();
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

// Save Button clicked: Write contents of quizBank to .db file
void QuizMenu::onSaveButtonClicked() {
    qDebug() << "quizmenu.cpp / Save button clicked";

    QuizBank* bank = quizWindow->getQuizBank();
    if (!bank || !bank->hasQuestions()) {
        qDebug() << "There are no questions to save.";
        return;
    }

    // Need to pass custom inputted quiz name
    DatabaseQuiz* newDB = new DatabaseQuiz("TestingSave");

    for (int i = 0; i < bank->size(); ++i) {
        const QuizQuestion& q = bank->getQuestions(i);

        // Need to differentiate between insert or update
        if (!newDB->insertQuestion(q.prompt)) {
            qDebug() << "Failed to insert question:" << q.prompt;
        } else {
            qDebug() << "Inserted question:" << q.prompt;
        }
        // Need to retrieve: answers text, corresponding question id
        qDebug() << q.answers;
        // Need to retrieve: corresponding answerid and questionid
        qDebug() << q.correctIndexes;
    }
}

// Helper to load .db file contents into QuizBank
void QuizMenu::loadDbToQuizBank(QuizBank* bank) {
    if (!bank || !quizWindow->getQuizDB()) {
        qDebug() << "No QuizBank or DatabaseQuiz available";
        return;
    }
    // Clear the current bank
    bank->clear();

    auto DBquestions = quizWindow->getQuizDB()->getAllQuestions();
    for (const auto& qPair : DBquestions) {
        int qID = qPair.first;
        QString prompt = qPair.second;
        QuizQuestion question;
        question.prompt = prompt;
        auto answers = quizWindow->getQuizDB()->getQuestionAnswers(qID);
        for (int i = 0; i < answers.size() && i < 6; ++i) {
            question.answers[i] = answers[i].first;
            if (answers[i].second) {
                question.correctIndexes.append(i);
            }
        }
        quizWindow->getQuizBank()->addQuestion(question);
    }
    qDebug() << "Loaded" << bank->size() << "questions into QuizBank";
}

