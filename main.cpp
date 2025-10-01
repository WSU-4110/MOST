#include "flashcardmaker.h"
#include "homepage.h"
#include "SampleQuizTemplate/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homePage homeWindow;
    flashCardMaker makeCardWindow;
    MainWindow quizWindow;
    homeWindow.show();
    return a.exec();
}
