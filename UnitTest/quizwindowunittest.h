#ifndef UNITTEST_H
#define UNITTEST_H
#include <QObject>

class UnitTest : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanTestCase();
    void testReadCreateForm();
    void testWriteCreateForm();
    void testClearCreateForm();
    void testShowStudyQuestion();
    void testCurrentStudySelection();
    void testOnPushButtonNextQuestion_clicked();
};

#endif // UNITTEST_H
