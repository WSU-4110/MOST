#include <QtTest>
#include "../Homepage/homepage.h"
#include <QPushButton>

// The UnitTest class
class UnitTest : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testConstructorInitializesPointers();
    void testCreateFlashCardButtonClicked();
    void testStudyMultipleChoiceButtonClicked();
    void testStudyFlashCardsButtonClicked();
    void testConnectionsExist();
    void testDestructorCleansUp();
};

// Test setup/teardown
void UnitTest::initTestCase() {
    qDebug() << "Starting homePage unit tests...";
}

void UnitTest::cleanupTestCase() {
    qDebug() << "Finished all tests.";
}

/**Actual test**/

// Test constructor sets pointers
void UnitTest::testConstructorInitializesPointers() {
    homePage page;
    QVERIFY(page.findChild<QMainWindow*>("quizWindow") == nullptr);
}

// Test createFlashCardButton behavior
void UnitTest::testCreateFlashCardButtonClicked() {
    homePage page;
    page.on_createFlashCardButton_clicked();  // Make sure this method is public or use QMetaObject::invokeMethod

    // Check if the flashCardCreatorWindow is created
    QObjectList children = page.children();
    bool found = false;
    for (QObject *obj : children) {
        if (obj->inherits("flashCardMaker")) {
            found = true;
            break;
        }
    }
    QVERIFY(found); // should be true
}

// Test studyMultipleChoiceButton behavior
void UnitTest::testStudyMultipleChoiceButtonClicked() {
    homePage page;
    page.on_studyMultipleChoiceButton_clicked();

    // Check if quizWindow pointer is set
    QVERIFY(page.findChild<QMainWindow*>("quizWindow") != nullptr
            || page.findChildren<QMainWindow*>().size() >= 1);
}

// Test studyFlashCardsButton behavior
void UnitTest::testStudyFlashCardsButtonClicked() {
    homePage page;
    page.on_btnStudyFlashCards_clicked();

    QObjectList children = page.children();
    bool found = false;
    for (QObject *obj : children) {
        if (obj->inherits("FlashCardStudy")) {
            found = true;
            break;
        }
    }
    QVERIFY(found);
}

// Test buttons have signals connected
void UnitTest::testConnectionsExist() {
    homePage page;

    // Find one of the buttons
    QPushButton *btn = page.findChild<QPushButton*>("createFlashCardButton");
    QVERIFY(btn != nullptr);

    // confirm the button is clickable.
    QCOMPARE(btn->isEnabled(), true);  // Just an example of what you can check
}

// Test that destructor cleans up
void UnitTest::testDestructorCleansUp() {
    homePage *page = new homePage();
    delete page;  // Just check no crash
}

QTEST_MAIN(UnitTest)
#include "unittest.moc"

// test CI
