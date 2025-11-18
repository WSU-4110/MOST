#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "../FlashcardModule/flashcardmaker.h"
#include "../FlashcardModule/flashcardstudy.h"
#include "../QuizModule/quizwindow.h"
#include <QMainWindow>
#include <QListWidgetItem>

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
    void on_btnStudyFlashCards_clicked();
    void on_listRecents_itemClicked(QListWidgetItem *item);

    void addToRecents(const QString &setName); // New slot to handle recents

private:
    Ui::homePage *ui;
    flashCardMaker *flashCardCreatorWindow;
    QMainWindow *quizWindow;
};

#endif // HOMEPAGE_H
