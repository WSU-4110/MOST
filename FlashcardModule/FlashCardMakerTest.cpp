#include <QtTest/QtTest>
#include "../FlashcardModule/flashcardmaker.h"
#include "../Database/flashCardData.h"
#include "FlashcardModule/ui_flashcardmaker.h"



class fakeFlashCardData: public flashCardData{
public:
    fakeFlashCardData():flashCardData("testingData"){};
    QList<QPair<QString,QString>> addedCard;
    bool addCard(const QString &question,const QString &answer){
        addedCard.append(qMakePair(question,answer));
        return true;
    }

};

class flashCardMakerTest: public QObject{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testAddGoodCard();
    void testAddBadCard();
    void testSaveCard();
};

void flashCardMakerTest::initTestCase(){
    qDebug()<<"starting flashCard test";
}
void flashCardMakerTest::cleanupTestCase(){
    qDebug()<<"testing complete";
}
void flashCardMakerTest::testAddGoodCard(){
    flashCardMaker testObject("testCase");
    testObject.show();
    testObject.ui->questionEdit->setPlainText("testQuestion");
    testObject.ui->answerEdit->setPlainText("testAnswer");
    testObject.on_nextQuestionButton_clicked();
    QCOMPARE(testObject.flashcards.size(),1);
    QCOMPARE(testObject.flashcards.first().first,QString("testQuestion"));
    QCOMPARE(testObject.flashcards.first().second,QString("testAnswer"));
}
void flashCardMakerTest::testAddBadCard(){
    flashCardMaker testObject("testCase");
    testObject.show();
    testObject.ui->questionEdit->setPlainText("");
    testObject.ui->answerEdit->setPlainText("");
    testObject.on_nextQuestionButton_clicked();
    QCOMPARE(testObject.flashcards.size(),0);
}
void flashCardMakerTest::testSaveCard(){
    flashCardMaker testObject("testCase");
    auto fakeData = new fakeFlashCardData();
    testObject.flashcards.append(qMakePair(QString("question"),QString("answer")));
    testObject.on_saveButton_clicked();
    QCOMPARE(fakeData->addedCard.size(),1);
    QCOMPARE(fakeData->addedCard.first().first, QString("question"));
    QCOMPARE(fakeData->addedCard.first().second, QString("answer"));
}

QTEST_MAIN(flashCardMakerTest);
#include "FlashCardMakerTest.moc"
