#include "FlashcardModule/flashcardmaker.h"
#include "Homepage/homepage.h"
#include "QuizModule/quizwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homePage homeWindow;

    QuizWindow quizWindow;
    homeWindow.show();

    return a.exec();
}
