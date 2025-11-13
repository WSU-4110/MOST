#ifndef QUIZQBUILDER_H
#define QUIZQBUILDER_H

#include "quizquestion.h"

// This builder class seperates the responsibility of constructing the objects from the rest of the UI logic
// In addition to that, also adds some minor validation logic
class QuizQBuilder {
public:
    QuizQBuilder& prompt (const QString& p);
    QuizQBuilder& answer(int index, const QString& a);
    QuizQBuilder& correctIndex(int index);

    // this will be used to perform a validation
    bool build(QuizQuestion& out, QString& err) const;
private:
    QuizQuestion q;
};

#endif // QUIZQBUILDER_H
