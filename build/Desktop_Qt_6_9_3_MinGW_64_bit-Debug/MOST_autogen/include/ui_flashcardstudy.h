/********************************************************************************
** Form generated from reading UI file 'flashcardstudy.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHCARDSTUDY_H
#define UI_FLASHCARDSTUDY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlashCardStudy
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *homeButton_3;
    QPushButton *flipButton;
    QPushButton *pushButton_2;
    QLabel *questionLabel;

    void setupUi(QWidget *FlashCardStudy)
    {
        if (FlashCardStudy->objectName().isEmpty())
            FlashCardStudy->setObjectName("FlashCardStudy");
        FlashCardStudy->resize(400, 678);
        gridLayoutWidget = new QWidget(FlashCardStudy);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(39, 20, 341, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        homeButton_3 = new QPushButton(gridLayoutWidget);
        homeButton_3->setObjectName("homeButton_3");

        gridLayout->addWidget(homeButton_3, 0, 0, 1, 1);

        flipButton = new QPushButton(gridLayoutWidget);
        flipButton->setObjectName("flipButton");

        gridLayout->addWidget(flipButton, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        questionLabel = new QLabel(gridLayoutWidget);
        questionLabel->setObjectName("questionLabel");

        gridLayout->addWidget(questionLabel, 1, 0, 1, 1);


        retranslateUi(FlashCardStudy);

        QMetaObject::connectSlotsByName(FlashCardStudy);
    } // setupUi

    void retranslateUi(QWidget *FlashCardStudy)
    {
        FlashCardStudy->setWindowTitle(QCoreApplication::translate("FlashCardStudy", "Form", nullptr));
        homeButton_3->setText(QCoreApplication::translate("FlashCardStudy", "Home", nullptr));
        flipButton->setText(QCoreApplication::translate("FlashCardStudy", "flip", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FlashCardStudy", "Next", nullptr));
        questionLabel->setText(QCoreApplication::translate("FlashCardStudy", "Question", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlashCardStudy: public Ui_FlashCardStudy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHCARDSTUDY_H
