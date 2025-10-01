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
