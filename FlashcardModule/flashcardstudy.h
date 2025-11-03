#ifndef FLASHCARDSTUDY_H
#define FLASHCARDSTUDY_H

#include <QWidget>
#include <QVector>
#include "../Database/databaseflashcard.h"

namespace Ui {
class FlashCardStudy;
}

class FlashCardStudy : public QWidget
{
    Q_OBJECT

public:
    explicit FlashCardStudy(QString dbName, QWidget *parent = nullptr);
    ~FlashCardStudy();

signals:
    void homeButtonClicked();

private slots:
    void on_btnHome_clicked();
    void on_btnNext_clicked();
    void on_btnPrevious_clicked();
    void on_btnFlip_clicked();

    void on_btnShuffle_clicked();

private:
    Ui::FlashCardStudy *ui;
    DatabaseFlashcard dbFlashcard;
    QVector<Flashcard> flashcards;
    QString currentDbName;
    int currentIndex = 0;
    bool showingFront = true;

    void loadFlashcards();
    void updateDisplay();
};


#endif // FLASHCARDSTUDY_H
