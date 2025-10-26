<<<<<<< HEAD
#include "FlashcardModule/flashcardmaker.h"
#include "Homepage/homepage.h"
#include "QuizModule/quizwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homePage homeWindow;
    flashCardMaker makeCardWindow;
    QuizWindow quizWindow;
    homeWindow.show();

    return a.exec();
}
=======
#include "flashcardmaker.h"
#include "homepage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homePage homeWindow;
    flashCardMaker makeCardWindow;
    homeWindow.show();
    return a.exec();
}
>>>>>>> 4fa1f49c4a7bcc63a39f2e2d187a685ad029aba4
