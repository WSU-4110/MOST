/********************************************************************************
** Form generated from reading UI file 'flashcardmaker.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHCARDMAKER_H
#define UI_FLASHCARDMAKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flashCardMaker
{
public:
    QGridLayout *gridLayout;
    QLabel *pageLabel;
    QPushButton *nextQuestionButton;
    QPushButton *homeButton;
    QPushButton *saveButton;
    QTextEdit *questionEdit;
    QLabel *cardCount;
    QTextEdit *setNameEdit;
    QTextEdit *answerEdit;

    void setupUi(QWidget *flashCardMaker)
    {
        if (flashCardMaker->objectName().isEmpty())
            flashCardMaker->setObjectName("flashCardMaker");
        flashCardMaker->resize(645, 444);
        flashCardMaker->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        gridLayout = new QGridLayout(flashCardMaker);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        gridLayout->setHorizontalSpacing(2);
        pageLabel = new QLabel(flashCardMaker);
        pageLabel->setObjectName("pageLabel");

        gridLayout->addWidget(pageLabel, 0, 2, 1, 1);

        nextQuestionButton = new QPushButton(flashCardMaker);
        nextQuestionButton->setObjectName("nextQuestionButton");

        gridLayout->addWidget(nextQuestionButton, 7, 2, 1, 1);

        homeButton = new QPushButton(flashCardMaker);
        homeButton->setObjectName("homeButton");
        homeButton->setEnabled(true);

        gridLayout->addWidget(homeButton, 0, 1, 1, 1);

        saveButton = new QPushButton(flashCardMaker);
        saveButton->setObjectName("saveButton");

        gridLayout->addWidget(saveButton, 1, 2, 1, 1);

        questionEdit = new QTextEdit(flashCardMaker);
        questionEdit->setObjectName("questionEdit");

        gridLayout->addWidget(questionEdit, 6, 1, 1, 1);

        cardCount = new QLabel(flashCardMaker);
        cardCount->setObjectName("cardCount");

        gridLayout->addWidget(cardCount, 2, 2, 1, 1);

        setNameEdit = new QTextEdit(flashCardMaker);
        setNameEdit->setObjectName("setNameEdit");

        gridLayout->addWidget(setNameEdit, 3, 2, 1, 1);

        answerEdit = new QTextEdit(flashCardMaker);
        answerEdit->setObjectName("answerEdit");

        gridLayout->addWidget(answerEdit, 6, 2, 1, 1);


        retranslateUi(flashCardMaker);

        QMetaObject::connectSlotsByName(flashCardMaker);
    } // setupUi

    void retranslateUi(QWidget *flashCardMaker)
    {
        flashCardMaker->setWindowTitle(QCoreApplication::translate("flashCardMaker", "flashCardMaker", nullptr));
        pageLabel->setText(QCoreApplication::translate("flashCardMaker", "Flash Card Creator", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("flashCardMaker", "Next Question", nullptr));
        homeButton->setText(QCoreApplication::translate("flashCardMaker", "Home", nullptr));
        saveButton->setText(QCoreApplication::translate("flashCardMaker", "Save", nullptr));
        questionEdit->setHtml(QCoreApplication::translate("flashCardMaker", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter question...</p></body></html>", nullptr));
        cardCount->setText(QCoreApplication::translate("flashCardMaker", "Card Count #", nullptr));
        setNameEdit->setHtml(QCoreApplication::translate("flashCardMaker", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter Study Card Set Name...</p></body></html>", nullptr));
        answerEdit->setHtml(QCoreApplication::translate("flashCardMaker", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Enter answer...</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class flashCardMaker: public Ui_flashCardMaker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHCARDMAKER_H
