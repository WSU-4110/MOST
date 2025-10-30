#ifndef FLASHCARDMAKER_H
#define FLASHCARDMAKER_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include "flashCardData.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class flashCardMaker;
}
QT_END_NAMESPACE

class flashCardMaker : public QWidget
{
    Q_OBJECT

public:
    explicit flashCardMaker(const QString &setName, QWidget *parent = nullptr); 
    ~flashCardMaker();
private slots:
    void on_nextQuestionButton_clicked();
    void on_saveButton_clicked();
    void on_homeButton_clicked();
private:
    Ui::flashCardMaker *ui;
    int cardCount=0; 
    QVector<QPair<QString, QString>> flashcards; 
    flashCardData *cardData;
signals:
    void goHome();
};
#endif // FLASHCARDMAKER_H
