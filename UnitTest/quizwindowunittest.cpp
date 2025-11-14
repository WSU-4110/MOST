#include "../QuizModule/quizwindow.h"
#include "quizwindowunittest.h"
#include "QuizModule/ui_quizwindow.h"
#include <QtTest>


void UnitTest::initTestCase() {
    qDebug() << "Starting QuizWindow unit tests...";
}

void UnitTest::cleanTestCase() {
    qDebug() << "Finished all tests.";
}

void UnitTest::testReadCreateForm() {
    QuizWindow window;
    QuizQuestion out;
    QString err;

    window.ui->lineEditQuestion->setText("What is 8+10?");
    window.ui->lineEditAnswer1->setText("21");
    window.ui->lineEditAnswer2->setText("18");
    window.ui->lineEditAnswer3->setText("25");
    window.ui->lineEditAnswer4->setText("16");
    window.ui->lineEditAnswer5->setText("19");
    window.ui->lineEditAnswer6->setText("23");
    window.ui->comboBoxCorrect->setCurrentIndex(2);

    bool check = window.readCreateForm(out, err);
    QVERIFY(check);
    QCOMPARE(out.prompt, QString("What is 8+10?"));
    QCOMPARE(out.answers[0], QString("21"));
    QCOMPARE(out.answers[1], QString("18"));
    QCOMPARE(out.answers[2], QString("25"));
    QCOMPARE(out.answers[3], QString("16"));
    QCOMPARE(out.answers[4], QString("19"));
    QCOMPARE(out.answers[5], QString("23"));
    QCOMPARE(out.correctIndex, 1);
}

void UnitTest::testWriteCreateForm() {
    QuizWindow window;
    QuizQuestion question;
    question.prompt = "What is 8+10?";
    question.answers[0] = "21";
    question.answers[1] = "18";
    question.answers[2] = "25";
    question.answers[3] = "16";
    question.answers[4] = "19";
    question.answers[5] = "23";
    question.correctIndex = 1;

    window.writeCreateForm(question);
    QCOMPARE(window.ui->lineEditQuestion->text(), QString("What is 8+10?"));
    QCOMPARE(window.ui->lineEditAnswer1->text(), QString("21"));
    QCOMPARE(window.ui->lineEditAnswer2->text(), QString("18"));
    QCOMPARE(window.ui->lineEditAnswer3->text(), QString("25"));
    QCOMPARE(window.ui->lineEditAnswer4->text(), QString("16"));
    QCOMPARE(window.ui->lineEditAnswer5->text(), QString("19"));
    QCOMPARE(window.ui->lineEditAnswer6->text(), QString("23"));
    QCOMPARE(window.ui->comboBoxCorrect->currentIndex(), 1);
}

void UnitTest::testClearCreateForm() {
    QuizWindow window;

    window.ui->lineEditQuestion->setText("What is 8+10?");
    window.ui->lineEditAnswer1->setText("21");
    window.ui->lineEditAnswer2->setText("18");
    window.ui->lineEditAnswer3->setText("25");
    window.ui->lineEditAnswer4->setText("16");
    window.ui->lineEditAnswer5->setText("19");
    window.ui->lineEditAnswer6->setText("23");
    window.ui->comboBoxCorrect->setCurrentIndex(1);

    window.clearCreateForm();

    QVERIFY(window.ui->lineEditQuestion->text().isEmpty());
    QVERIFY(window.ui->lineEditAnswer1->text().isEmpty());
    QVERIFY(window.ui->lineEditAnswer2->text().isEmpty());
    QVERIFY(window.ui->lineEditAnswer3->text().isEmpty());
    QVERIFY(window.ui->lineEditAnswer4->text().isEmpty());
    QCOMPARE(window.ui->comboBoxCorrect->currentIndex(), 0);

}

void UnitTest::testShowStudyQuestion() {
    QuizWindow window;

    QuizQuestion q1;
    q1.prompt = "Question 1";
    q1.answers[0] = "21";
    q1.answers[1] = "18";
    q1.userIndex = 1;

    QuizQuestion q2;
    q2.prompt = "Question 2";
    q2.answers[0] = "25";
    q2.answers[1] = "16";
    q2.userIndex = 0;

    window.questionBank = {q1, q2};

    window.showStudyQuestion(0);
    QCOMPARE(window.ui->textDisplayQuestion->toPlainText(), QString("Question 1"));
    QCOMPARE(window.ui->textDisplayAnswer1->toPlainText(), QString("21"));
    QCOMPARE(window.ui->textDisplayAnswer2->toPlainText(), QString("18"));
    QVERIFY(!window.ui->radioButtonAnswer1->isChecked());
    QVERIFY(window.ui->radioButtonAnswer2->isChecked());

    window.showStudyQuestion(1);
    QCOMPARE(window.ui->textDisplayQuestion->toPlainText(), QString("Question 2"));
    QCOMPARE(window.ui->textDisplayAnswer1->toPlainText(), QString("25"));
    QCOMPARE(window.ui->textDisplayAnswer2->toPlainText(), QString("16"));
    QVERIFY(window.ui->radioButtonAnswer1->isChecked());
    QVERIFY(!window.ui->radioButtonAnswer2->isChecked());

    window.showStudyQuestion(-1);
    QCOMPARE(window.ui->textDisplayQuestion->toPlainText(), QString("Question 1"));

    window.showStudyQuestion(100);
    QCOMPARE(window.ui->textDisplayQuestion->toPlainText(), QString("Question 2"));
}

void UnitTest::testCurrentStudySelection() {
    QuizWindow window;

    window.ui->radioButtonAnswer1->setChecked(false);
    window.ui->radioButtonAnswer2->setChecked(false);
    window.ui->radioButtonAnswer3->setChecked(false);
    window.ui->radioButtonAnswer4->setChecked(false);
    window.ui->radioButtonAnswer5->setChecked(false);
    window.ui->radioButtonAnswer6->setChecked(false);
    QCOMPARE(window.currentStudySelection(), -1);

    window.ui->radioButtonAnswer1->setChecked(true);
    QCOMPARE(window.currentStudySelection(), 0);
    window.ui->radioButtonAnswer1->setChecked(false);

    window.ui->radioButtonAnswer2->setChecked(true);
    QCOMPARE(window.currentStudySelection(), 1);
    window.ui->radioButtonAnswer2->setChecked(false);

    window.ui->radioButtonAnswer3->setChecked(true);
    QCOMPARE(window.currentStudySelection(), 2);
    window.ui->radioButtonAnswer3->setChecked(false);

    window.ui->radioButtonAnswer4->setChecked(true);
    QCOMPARE(window.currentStudySelection(), 3);
    window.ui->radioButtonAnswer4->setChecked(false);

    window.ui->radioButtonAnswer5->setChecked(true);
    QCOMPARE(window.currentStudySelection(), 4);
    window.ui->radioButtonAnswer5->setChecked(false);

    window.ui->radioButtonAnswer6->setChecked(true);
    QCOMPARE(window.currentStudySelection(), 5);
    window.ui->radioButtonAnswer6->setChecked(false);
}

void UnitTest::testOnPushButtonNextQuestion_clicked() {
    QuizWindow window;

    QuizQuestion q1;
    q1.prompt = "Question 1";
    q1.answers[0] = "21";
    q1.answers[1] = "18";

    QuizQuestion q2;
    q2.prompt = "Question 2";
    q2.answers[0] = "25";
    q2.answers[1] = "16";

    window.questionBank = {q1, q2};
    window.questionCurrent = 0;

    window.on_pushButtonNextQuestion_clicked();
    QCOMPARE(window.ui->lineEditQuestion->text(), QString("Question 2"));
    QCOMPARE(window.questionCurrent, 1);
    window.on_pushButtonNextQuestion_clicked();
    QCOMPARE(window.ui->lineEditQuestion->text(), QString("Question 2"));
    QCOMPARE(window.questionCurrent, 1);
}

QTEST_MAIN(UnitTest)
