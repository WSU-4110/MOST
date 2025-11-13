#ifndef FLASHCARDSTUDY_H
#define FLASHCARDSTUDY_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QComboBox>
#include <QDir>
#include <QLineEdit>
#include "../Database/databaseflashcard.h"


namespace Ui {
class FlashCardStudy;
}

class FlashCardStudy : public QWidget
{
    Q_OBJECT

public:
    explicit FlashCardStudy(QWidget *parent = nullptr);
    ~FlashCardStudy();

signals:
    void homeButtonClicked();

private slots:
    void on_btnHome_clicked();
    void on_btnNext_clicked();
    void on_btnPrevious_clicked();
    void on_btnFlip_clicked();

    void on_btnShuffle_clicked();
    void on_setCombo_currentTextChanged(const QString &text);

private:
    Ui::FlashCardStudy *ui;
    DatabaseFlashcard dbFlashcard;
    QVector<Flashcard> flashcards;
    QVector<Flashcard> filteredFlashcards;
    QString currentDbName;
    int currentIndex = 0;
    bool showingFront = true;

    void loadFlashcards(const QString &dbName);
    void updateDisplay();

    void setupSetSelection();
    void filterCards(const QString &text);
};


#endif // FLASHCARDSTUDY_H
