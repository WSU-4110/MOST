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

                QString newQuizName = fileName;
                newQuizName.chop(3); // chop ".db"
                newQuizName.remove(0,5); // remove "quiz_"
                quizWindow->getQuizBank()->setName(newQuizName);
                quizWindow->getUI()->labelMenuCurrentSet->setText(quizWindow->getQuizBank()->getName());

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

    // Will open if quiz_name.db exists, else will create quiz_name.db to save to
    DatabaseQuiz* newDB = new DatabaseQuiz(quizWindow->getQuizBank()->getName());

    for (int i = 0; i < bank->size(); ++i) {
        QuizQuestion q = bank->getQuestions(i);
        int questionID = q.dbID;

        // --- Insert or Update Question ---
        if (questionID == -1) {
            questionID = newDB->insertQuestion(q.prompt);
            if (questionID == -1) {
                qDebug() << "Failed to insert question:" << q.prompt;
                continue;
            }
            q.dbID = questionID; // Save ID back to the question
            qDebug() << "Inserted question with ID:" << questionID;
        } else {
            if (!newDB->updateQuestion(questionID, q.prompt)) {
                qDebug() << "Failed to update question ID:" << questionID;
            } else {
                qDebug() << "Updated question ID:" << questionID;
            }
        }

        // Insert or Update Answers
        for (int a = 0; a < 6; ++a) {
            QString text = q.answers[a];
            if (text.isEmpty()) continue;
            int answerID = newDB->getAnswerIdByIndex(questionID, a);
            if (answerID == -1) {
                answerID = newDB->insertAnswer(questionID, text);
                if (answerID == -1) {
                    qDebug() << "Failed to insert answer" << a << "for questionID =" << questionID;
                    continue;
                }
                qDebug() << "Inserted answer ID:" << answerID << "for questionID =" << questionID;
            } else {
                if (!newDB->updateAnswer(answerID, text)) {
                    qDebug() << "Failed to update answer ID:" << answerID;
                } else {
                    qDebug() << "Updated answer ID:" << answerID;
                }
            }
        }

        // Insert or Delete Corrects
        QSet<int> existingCorrect = newDB->getCorrectAnswerIDs(questionID);
        QSet<int> desiredCorrect;
        for (int idx : q.correctIndexes) {
            if (idx < 0 || idx >= 6) continue;
            int answerID = newDB->getAnswerIdByIndex(questionID, idx);
            if (answerID != -1)
                desiredCorrect.insert(answerID);
        }
        // Insert missing correct marks
        for (int answerID : desiredCorrect) {
            if (!existingCorrect.contains(answerID)) {
                if (!newDB->insertCorrect(questionID, answerID)) {
                    qDebug() << "Failed to INSERT correct answer_id =" << answerID;
                } else {
                    qDebug() << "Inserted correct for answer_id =" << answerID;
                }
            }
        }
        // Delete obsolete correct marks
        for (int answerID : existingCorrect) {
            if (!desiredCorrect.contains(answerID)) {
                if (!newDB->deleteCorrect(questionID, answerID)) {
                    qDebug() << "Failed to DELETE correct answer_id =" << answerID;
                } else {
                    qDebug() << "Deleted obsolete correct answer_id =" << answerID;
                }
            }
        }
    }
    quizWindow->getQuizBank()->setName(newDB->getName());
    delete newDB;
    QMessageBox::information(this, tr("Success"), tr("Quiz saved successfully!"));
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
        question.dbID = qID;
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

