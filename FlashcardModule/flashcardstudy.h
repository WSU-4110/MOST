#ifndef FLASHCARDSTUDY_H
#define FLASHCARDSTUDY_H

#include <QWidget>
#include <QVector>
#include "../Database/databaseflashcard.h"

namespace Ui {
class FlashCardStudy;
}

// For the purpose of the unit test, in order to access the methods from the private slots, the test will be set as a friendly class (Khaliph Page - 11/5/2025)
class tst_flashcardstudy;

class FlashCardStudy : public QWidget
{
    Q_OBJECT

    // For the purpose of the unit test, in order to access the methods from the private slots, the test will be set as a friendly class (Khaliph Page - 11/5/2025)
    friend class tst_flashcardstudy;

public:
    explicit FlashCardStudy(QString dbName, QWidget *parent = nullptr);

    // For the purpose of the unit test, in order to create static cards in the unit test file, this new constructor was added (Khaliph Page - 11/5/2025)
    explicit FlashCardStudy(const QVector<Flashcard> &cards, QWidget *parent = nullptr);

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
