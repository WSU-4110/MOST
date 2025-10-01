#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "flashcardmaker.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class homePage; }
QT_END_NAMESPACE



class homePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit homePage(QWidget *parent = nullptr);
    ~homePage();

private slots:
    void on_createFlashCardButton_clicked();

private:
    Ui::homePage *ui;
    flashCardMaker *flashCardCreatorWindow;  // pointer to child window
};

#endif // HOMEPAGE_H
