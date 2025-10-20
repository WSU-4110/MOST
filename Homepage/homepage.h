#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "../FlashcardModule/flashcardmaker.h"
#include "../FlashcardModule/flashcardstudy.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class homePage; }
QT_END_NAMESPACE



class homePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit homePage(QWidget *parent = nullptr);
    ~homePage();

private slots:
    void on_createFlashCardButton_clicked();
    void on_studyMultipleChoiceButton_clicked();
    void on_studyFlashCardsButton_clicked();

private:
    Ui::homePage *ui;
    flashCardMaker *flashCardCreatorWindow;  // pointer to child window
    FlashCardStudy *flashCardStudyWindow;
    QMainWindow *quizWindow;
};

#endif // HOMEPAGE_H
