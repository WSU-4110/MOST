#include <QtTest/QTest>
#include <QLabel>
#include <QtTest/QSignalSpy>

#include "../Database/databaseflashcard.h"
#include "../FlashcardModule/flashcardstudy.h"

class tst_flashcardstudy : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();

    // updateDisplay()
    void testInitialDisplay_ShowFirstCard();

    // on_btnNext_clicked()
    void testNext_FromMiddleToNext_ShowFront();
    void testNext_LastCardDoesNotAdvance();

    // on_btnPrevious_clicked()
    void testPrevious_FromMiddleToPrevious_ShowFront();
    void testPrevious_FirstCardDoesNotDecrease();

    //on_btnFlip_clicked()
    void testFlip_TogglesFrontAndBack();

    //on_btnShuffle_clicked()
    void testShuffle_ResetsIndex_ShowFront();

    //on_btnHome_clicked()
    void testHomeButton_EmitsSignal_ClosesWidget();
};

// Sanity Check
void tst_flashcardstudy::initTestCase() {
    QVERIFY(true);
}

// Creates three sample flashcards in place of loading stored cards from a database
static QVector<Flashcard> makeSampleCards() {
    QVector<Flashcard> cards;

    Flashcard c1;
    c1.id = 0;
    c1.front = "Q1";
    c1.back = "A1";
    cards.append(c1);

    Flashcard c2;
    c2.id = 1;
    c2.front = "Q2";
    c2.back = "A2";
    cards.append(c2);

    Flashcard c3;
    c3.id = 2;
    c3.front = "Q3";
    c3.back = "A3";
    cards.append(c3);

    return cards;
}

// Update display -- updateDisplay() is called indirectly, it is called in the constructor
void tst_flashcardstudy::testInitialDisplay_ShowFirstCard() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);

    QLabel *lblCard = study.findChild<QLabel*>("lblCard");
    QLabel *lblCount = study.findChild<QLabel*>("lblNumberOfFlashcards"); // added for additional clarification of card position in deck

    QVERIFY(lblCard != nullptr);
    QVERIFY(lblCount != nullptr);

    //  Should show front of card
    QCOMPARE (lblCard->text(), QString("Q1"));
    QCOMPARE (lblCount->text(), QString("1 of 3"));
}

// Testing next button - Moving to next card
void tst_flashcardstudy::testNext_FromMiddleToNext_ShowFront() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);

    QLabel *lblCard = study.findChild<QLabel*>("lblCard");
    QLabel *lblCount = study.findChild<QLabel*>("lblNumberOfFlashcards");

    QVERIFY(lblCard != nullptr);
    QVERIFY(lblCount != nullptr);

    // Start at first card, showing front
    QCOMPARE(lblCard->text(), QString("Q1"));
    QCOMPARE(lblCount->text(), QString("1 of 3"));

    // Move to next card
    study.on_btnNext_clicked();         // move to Q2, showing front
    QCOMPARE(lblCard->text(), QString("Q2"));
    QCOMPARE(lblCount->text(), QString("2 of 3"));

    // Flip card
    study.on_btnFlip_clicked();
    QCOMPARE(lblCard->text(), QString("A2"));

    // Move to last card
    study.on_btnNext_clicked();         // move to Q3, showing front
    QCOMPARE(lblCard->text(), QString("Q3"));
    QCOMPARE(lblCount->text(), QString("3 of 3"));
}

// Testing next button - Cannot move forward from last card
void tst_flashcardstudy::testNext_LastCardDoesNotAdvance() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);

    QLabel *lblCard  = study.findChild<QLabel*>("lblCard");
    QLabel *lblCount = study.findChild<QLabel*>("lblNumberOfFlashcards");

    QVERIFY(lblCard  != nullptr);
    QVERIFY(lblCount != nullptr);

    // Start at first card, showing front
    QCOMPARE(lblCard->text(), QString("Q1"));
    QCOMPARE(lblCount->text(), QString("1 of 3"));

    // Move to last card
    study.on_btnNext_clicked(); // Q2
    study.on_btnNext_clicked(); // Q3
    QCOMPARE(lblCard->text(), QString("Q3"));
    QCOMPARE(lblCount->text(), QString("3 of 3"));

    // Try to go past last, should stay on Q3
    study.on_btnNext_clicked();
    QCOMPARE(lblCard->text(), QString("Q3"));
    QCOMPARE(lblCount->text(), QString("3 of 3"));
}

// Testing previous button - moving to previous card
void tst_flashcardstudy::testPrevious_FromMiddleToPrevious_ShowFront() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);

    QLabel *lblCard  = study.findChild<QLabel*>("lblCard");
    QLabel *lblCount = study.findChild<QLabel*>("lblNumberOfFlashcards");

    QVERIFY(lblCard  != nullptr);
    QVERIFY(lblCount != nullptr);

    // Start at first card, showing front
    QCOMPARE(lblCard->text(), QString("Q1"));
    QCOMPARE(lblCount->text(), QString("1 of 3"));

    // Move to middle card
    study.on_btnNext_clicked(); // move to Q2, showing front
    QCOMPARE(lblCard->text(), QString("Q2"));
    QCOMPARE(lblCount->text(), QString("2 of 3"));

    // Flip card
    study.on_btnFlip_clicked();         // A2
    QCOMPARE(lblCard->text(), QString("A2"));

    // Move to previous card
    study.on_btnPrevious_clicked();     // move to Q1, showing front
    QCOMPARE(lblCard->text(), QString("Q1"));
    QCOMPARE(lblCount->text(), QString("1 of 3"));
}

// Testing previous button - cannot move backwards from first card
void tst_flashcardstudy::testPrevious_FirstCardDoesNotDecrease() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);

    QLabel *lblCard  = study.findChild<QLabel*>("lblCard");
    QLabel *lblCount = study.findChild<QLabel*>("lblNumberOfFlashcards");

    QVERIFY(lblCard  != nullptr);
    QVERIFY(lblCount != nullptr);

    // Start at first card, showing front
    QCOMPARE(lblCard->text(), QString("Q1"));
    QCOMPARE(lblCount->text(), QString("1 of 3"));

    // Try to go previous, should remain on Q1
    study.on_btnPrevious_clicked();
    QCOMPARE(lblCard->text(), QString("Q1"));
    QCOMPARE(lblCount->text(), QString("1 of 3"));
}

// Testing flipping feature
void tst_flashcardstudy::testFlip_TogglesFrontAndBack() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);

    QLabel *lblCard = study.findChild<QLabel*>("lblCard");

    QVERIFY(lblCard != nullptr);

    // Start on front Q1
    QCOMPARE(lblCard->text(), QString("Q1"));

    // Flip card, showing back
    study.on_btnFlip_clicked();
    QCOMPARE(lblCard->text(), QString("A1"));

    // Flip card again, showing front
    study.on_btnFlip_clicked();
    QCOMPARE(lblCard->text(), QString("Q1"));
}

// Testing shuffle feature
void tst_flashcardstudy::testShuffle_ResetsIndex_ShowFront() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);

    QLabel *lblCard  = study.findChild<QLabel*>("lblCard");
    QLabel *lblCount = study.findChild<QLabel*>("lblNumberOfFlashcards");

    QVERIFY(lblCard  != nullptr);
    QVERIFY(lblCount != nullptr);

    // Move to middle card
    study.on_btnNext_clicked(); // move to Q2, showing front
    QCOMPARE(lblCard->text(), QString("Q2"));
    QCOMPARE(lblCount->text(), QString("2 of 3"));

    // Shuffle
    study.on_btnShuffle_clicked();

    // Counter must go to "1 of 3"
    QCOMPARE(lblCount->text(), QString("1 of 3"));

    // Showing front of some card
    QString firstAfterShuffle = lblCard->text();
    QVERIFY(firstAfterShuffle == "Q1" || firstAfterShuffle == "Q2" || firstAfterShuffle == "Q3");

    // Move through all cards after shufle
    QStringList shuffledOrder;
    shuffledOrder << lblCard->text();         // current (index 0)
    study.on_btnNext_clicked();               // index 1
    shuffledOrder << lblCard->text();
    study.on_btnNext_clicked();               // index 2
    shuffledOrder << lblCard->text();

    qDebug() << "Shuffled order:";
    for (const QString &s : shuffledOrder) {
        qDebug() << "Card: " << s;
    }
}

// Testing home button
void tst_flashcardstudy::testHomeButton_EmitsSignal_ClosesWidget() {
    QVector<Flashcard> cards = makeSampleCards();
    FlashCardStudy study(cards);
    study.show();  // so close() changes visibility

    QSignalSpy spy(&study, &FlashCardStudy::homeButtonClicked);

    study.on_btnHome_clicked();

    // Signal should be emitted exactly once
    QCOMPARE(spy.count(), 1);

    // Widget should be hidden/closed
    QVERIFY(!study.isVisible());
}

QTEST_MAIN(tst_flashcardstudy)
#include "tst_flashcardstudy.moc"
