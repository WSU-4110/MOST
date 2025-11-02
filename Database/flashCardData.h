#ifndef FLASHCARDDATA_H
#define FLASHCARDDATA_H
#include "database2.h"
#include <QString>
#include <QList>

class flashCardData: public Database2 {
public:
    flashCardData(QString dbName);

    void testing();
    bool addCard(QString question, QString answer);

    QList<QList<QVariant>> getAllCardEntries();
    QList<QVariant> getCardEntry(int id);

    bool editCardEntry(int id, QString question, QString answer);

    QString getName();
private:
    QString CardSetName;
};

#endif // FLASHCARDDATA_H
