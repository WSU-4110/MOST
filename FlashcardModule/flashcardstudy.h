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
    Ui::FlashCardStudy *ui;
    explicit FlashCardStudy(QWidget *parent = nullptr);
    void selectSet(const QString &setName);
    ~FlashCardStudy();

signals:
    void homeButtonClicked();
    void setOpened(const QString &setName); // Signal to homepage which set was opened

private slots:
    void on_btnHome_clicked();
    void on_btnNext_clicked();
    void on_btnPrevious_clicked();
    void on_btnFlip_clicked();
    void on_btnShuffle_clicked();
    void on_setCombo_currentTextChanged(const QString &text);

private:

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
