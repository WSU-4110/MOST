#ifndef FLASHCARDS_H
#define FLASHCARDS_H
#include <Qstring.h>

struct FlashCard {
    int id;
    QString question;
    QString answer;
};

#endif // FLASHCARDS_H
