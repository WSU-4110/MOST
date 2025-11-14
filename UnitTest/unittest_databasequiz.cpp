#include <QtTest/QtTest>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "../Database/databasequiz.h"

class DatabaseQuizTest : public QObject
{
    Q_OBJECT
public:
    DatabaseQuizTest() {}

private slots:
    void init();
    void clear();

    void testInsertQuestion();
    void testInsertAnswer();
    void testInsertCorrect();
    void testUpdateQuestion();
    void testUpdateAnswer();
    void testUpdateCorrect();

private:
    DatabaseQuiz* quiz;
};

void DatabaseQuizTest::init() {
    // Use in-memory database for testing and don't make an actual file
    quiz = new DatabaseQuiz("unittest", ":memory:");

    // make quiz tables for memory db
    QSqlQuery query(quiz->getDatabase());
    query.exec("CREATE TABLE IF NOT EXISTS questions (id INTEGER PRIMARY KEY, question TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS answers (id INTEGER PRIMARY KEY, question_id INTEGER, answer TEXT, FOREIGN KEY (question_id) REFERENCES questions(id) ON DELETE CASCADE)");
    query.exec("CREATE TABLE IF NOT EXISTS correct (question_id INTEGER, answer_id INTEGER, PRIMARY KEY (question_id, answer_id), FOREIGN KEY (question_id) REFERENCES questions(id) ON DELETE CASCADE, FOREIGN KEY (answer_id) REFERENCES answers(id) ON DELETE CASCADE)");
    qDebug() << "Created tables for in-memory database.";
}


void DatabaseQuizTest::testInsertQuestion() {
    QVERIFY(quiz->insertQuestion("Question inserted?"));
    QList<QString> questions = quiz->getAllQuestions();
    QVERIFY(questions.contains("Question inserted?"));
}

void DatabaseQuizTest::testInsertAnswer() {
    QVERIFY(quiz->insertQuestion("Question has answer?"));

    QSqlQuery query(quiz->getDatabase());
    query.exec("SELECT id FROM questions WHERE question='Question has answer?'");
    query.next();
    int questionID = query.value(0).toInt();

    QVERIFY(quiz->insertAnswer(questionID, "Yes"));
    QVERIFY(quiz->insertAnswer(questionID, "No"));
}

void DatabaseQuizTest::testInsertCorrect() {
    QSqlQuery query(quiz->getDatabase());
    query.exec("SELECT id FROM questions WHERE question='Question has answer?'");
    query.next();
    int questionID = query.value(0).toInt();

    query.exec("SELECT id FROM answers WHERE answer='Yes'");
    query.next();
    int answerID = query.value(0).toInt();

    QVERIFY(quiz->insertCorrect(questionID, answerID));
}

void DatabaseQuizTest::testUpdateQuestion() {
    QSqlQuery query(quiz->getDatabase());
    query.exec("SELECT id FROM questions WHERE question='Question has answer?'");
    query.next();
    int questionID = query.value(0).toInt();

    QVERIFY(quiz->updateQuestion(questionID, "Updated question?"));
}

void DatabaseQuizTest::testUpdateAnswer() {
    QSqlQuery query(quiz->getDatabase());
    query.exec("SELECT id FROM answers WHERE answer='No'");
    query.next();
    int answerID = query.value(0).toInt();

    QVERIFY(quiz->updateAnswer(answerID, "Maybe"));
}

void DatabaseQuizTest::testUpdateCorrect()
{
    QSqlQuery query(quiz->getDatabase());
    query.exec("SELECT id FROM questions WHERE question='Updated question?'");
    query.next();
    int questionID = query.value(0).toInt();

    query.exec("SELECT id FROM answers WHERE answer='Maybe'");
    query.next();
    int answerID = query.value(0).toInt();

    QVERIFY(quiz->updateCorrect(questionID, QList<int>{answerID}));
}

void DatabaseQuizTest::clear() {
    delete quiz;
}

QTEST_MAIN(DatabaseQuizTest);
#include "unittest_databasequiz.moc"
