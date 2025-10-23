/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homePage
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnHome;
    QPushButton *btnFlashcards;
    QPushButton *btnQuizzes;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblMost;
    QLabel *lblRecentlyViewd;
    QListWidget *listRecents;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *quizIcon;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *lblQuizDescription;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createMultipleChoiceButton;
    QPushButton *studyMultipleChoiceButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *flashcardIcon;
    QLabel *lbFlashcardModule;
    QLabel *lblFlashCardDescription;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *createFlashCardButton;
    QPushButton *studyFlashCardsButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *homePage)
    {
        if (homePage->objectName().isEmpty())
            homePage->setObjectName("homePage");
        homePage->resize(1223, 800);
        homePage->setMinimumSize(QSize(1223, 800));
        homePage->setMaximumSize(QSize(2560, 1440));
        homePage->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(\n"
"    x1: 0, y1: 1,   /* Start at bottom */\n"
"    x2: 0, y2: 0,   /* End at top */\n"
"    stop: 0 #454545,\n"
"    stop: 1 #100328\n"
");k\n"
"\n"
"border: 1px black;"));
        centralwidget = new QWidget(homePage);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(50, 16777215));
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(\n"
"    x1: 0, y1: 1,   /* Start at bottom */\n"
"    x2: 0, y2: 0,   /* End at top */\n"
"    stop: 0 #454545,\n"
"    stop: 1 #100328\n"
");"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        btnHome = new QPushButton(widget);
        btnHome->setObjectName("btnHome");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnHome->sizePolicy().hasHeightForWidth());
        btnHome->setSizePolicy(sizePolicy);
        btnHome->setMaximumSize(QSize(40, 160));
        btnHome->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"background-color: lightblue;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid #888;\n"
"border-radius: 6px;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/home.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnHome->setIcon(icon);
        btnHome->setIconSize(QSize(21, 21));

        verticalLayout->addWidget(btnHome);

        btnFlashcards = new QPushButton(widget);
        btnFlashcards->setObjectName("btnFlashcards");
        btnFlashcards->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"background-color: lightblue;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid #888;\n"
"border-radius: 6px;\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/flash-cards.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnFlashcards->setIcon(icon1);
        btnFlashcards->setIconSize(QSize(21, 21));

        verticalLayout->addWidget(btnFlashcards);

        btnQuizzes = new QPushButton(widget);
        btnQuizzes->setObjectName("btnQuizzes");
        btnQuizzes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white;\n"
"background-color: lightblue;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid #888;\n"
"border-radius: 6px;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/quiz.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnQuizzes->setIcon(icon2);
        btnQuizzes->setIconSize(QSize(21, 21));

        verticalLayout->addWidget(btnQuizzes);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lblMost = new QLabel(centralwidget);
        lblMost->setObjectName("lblMost");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblMost->sizePolicy().hasHeightForWidth());
        lblMost->setSizePolicy(sizePolicy1);
        lblMost->setMaximumSize(QSize(350, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Freestyle Script")});
        font.setPointSize(57);
        lblMost->setFont(font);
        lblMost->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color: #91a3b0;"));
        lblMost->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(lblMost);

        lblRecentlyViewd = new QLabel(centralwidget);
        lblRecentlyViewd->setObjectName("lblRecentlyViewd");
        sizePolicy.setHeightForWidth(lblRecentlyViewd->sizePolicy().hasHeightForWidth());
        lblRecentlyViewd->setSizePolicy(sizePolicy);
        lblRecentlyViewd->setMaximumSize(QSize(350, 30));
        QFont font1;
        font1.setPointSize(16);
        lblRecentlyViewd->setFont(font1);
        lblRecentlyViewd->setStyleSheet(QString::fromUtf8("\n"
"background-color: #91a3b0;\n"
"border-radius: 8px;"));
        lblRecentlyViewd->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(lblRecentlyViewd);

        listRecents = new QListWidget(centralwidget);
        QFont font2;
        font2.setPointSize(15);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listRecents);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font2);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listRecents);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font2);
        listRecents->setObjectName("listRecents");
        sizePolicy.setHeightForWidth(listRecents->sizePolicy().hasHeightForWidth());
        listRecents->setSizePolicy(sizePolicy);
        listRecents->setMinimumSize(QSize(280, 0));
        listRecents->setMaximumSize(QSize(350, 1500));
        listRecents->setStyleSheet(QString::fromUtf8("\n"
"QListWidget {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0,\n"
"        x2: 0, y2: 1,\n"
"        stop: 0 #91a3b0,\n"
"        stop: 1 #68228b\n"
"    );\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"/* Style individual list items */\n"
"QListWidget::item {\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/* Hover effect for items */\n"
"QListWidget::item:hover {\n"
"    background-color: #7a3dad; /* Solid color or gradient \342\200\224 your choice */\n"
"}\n"
""));

        verticalLayout_4->addWidget(listRecents);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_4->addWidget(line);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(0, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        widget_2->setMinimumSize(QSize(350, 0));
        widget_2->setMaximumSize(QSize(2000, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(\n"
"    x1: 0, y1: 0,   \n"
"    x2: 0, y2: 1   \n"
"    stop: 0 #91a3b0,\n"
"    stop: 1 #68228b\n"
");\n"
"border-radius: 20px;\n"
"margin-top: 25px;\n"
"margin-bottom: 25px;"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        quizIcon = new QPushButton(widget_2);
        quizIcon->setObjectName("quizIcon");
        sizePolicy.setHeightForWidth(quizIcon->sizePolicy().hasHeightForWidth());
        quizIcon->setSizePolicy(sizePolicy);
        quizIcon->setStyleSheet(QString::fromUtf8("padding-left: 40px;\n"
"border: none;\n"
"background: transparent;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/quiz-color.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        quizIcon->setIcon(icon3);
        quizIcon->setIconSize(QSize(256, 256));

        verticalLayout_2->addWidget(quizIcon, 0, Qt::AlignmentFlag::AlignVCenter);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 100));
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        lblQuizDescription = new QLabel(widget_2);
        lblQuizDescription->setObjectName("lblQuizDescription");
        sizePolicy.setHeightForWidth(lblQuizDescription->sizePolicy().hasHeightForWidth());
        lblQuizDescription->setSizePolicy(sizePolicy);
        lblQuizDescription->setMaximumSize(QSize(16777215, 800));
        lblQuizDescription->setFont(font1);
        lblQuizDescription->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));

        verticalLayout_2->addWidget(lblQuizDescription);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        createMultipleChoiceButton = new QPushButton(widget_4);
        createMultipleChoiceButton->setObjectName("createMultipleChoiceButton");
        sizePolicy.setHeightForWidth(createMultipleChoiceButton->sizePolicy().hasHeightForWidth());
        createMultipleChoiceButton->setSizePolicy(sizePolicy);
        createMultipleChoiceButton->setMinimumSize(QSize(0, 0));
        createMultipleChoiceButton->setMaximumSize(QSize(200, 100));
        QFont font4;
        font4.setPointSize(13);
        createMultipleChoiceButton->setFont(font4);
        createMultipleChoiceButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid rgba(255, 255, 255, 80);  /* subtle white border */\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);  /* light white overlay */\n"
"    border: 1px solid rgba(255, 255, 255, 120); /* stronger border on hover */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(createMultipleChoiceButton);

        studyMultipleChoiceButton = new QPushButton(widget_4);
        studyMultipleChoiceButton->setObjectName("studyMultipleChoiceButton");
        sizePolicy.setHeightForWidth(studyMultipleChoiceButton->sizePolicy().hasHeightForWidth());
        studyMultipleChoiceButton->setSizePolicy(sizePolicy);
        studyMultipleChoiceButton->setMaximumSize(QSize(200, 100));
        studyMultipleChoiceButton->setFont(font4);
        studyMultipleChoiceButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid rgba(255, 255, 255, 80);  /* subtle white border */\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);  /* light white overlay */\n"
"    border: 1px solid rgba(255, 255, 255, 120); /* stronger border on hover */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(studyMultipleChoiceButton);


        verticalLayout_2->addWidget(widget_4);


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        widget_3->setMinimumSize(QSize(350, 0));
        widget_3->setMaximumSize(QSize(2000, 16777215));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(\n"
"    x1: 0, y1: 0,   /* Start at bottom */\n"
"    x2: 0, y2: 1   /* End at top */\n"
"    stop: 0 #91a3b0,\n"
"    stop: 1 #68228b\n"
");\n"
"border-radius: 20px;\n"
"margin-top: 25px;\n"
"margin-bottom: 25px;"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        flashcardIcon = new QPushButton(widget_3);
        flashcardIcon->setObjectName("flashcardIcon");
        sizePolicy2.setHeightForWidth(flashcardIcon->sizePolicy().hasHeightForWidth());
        flashcardIcon->setSizePolicy(sizePolicy2);
        flashcardIcon->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: transparent;\n"
"border-radius: 12px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/images/flash-card.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        flashcardIcon->setIcon(icon4);
        flashcardIcon->setIconSize(QSize(256, 256));

        verticalLayout_3->addWidget(flashcardIcon);

        lbFlashcardModule = new QLabel(widget_3);
        lbFlashcardModule->setObjectName("lbFlashcardModule");
        sizePolicy.setHeightForWidth(lbFlashcardModule->sizePolicy().hasHeightForWidth());
        lbFlashcardModule->setSizePolicy(sizePolicy);
        lbFlashcardModule->setMaximumSize(QSize(16777215, 100));
        lbFlashcardModule->setFont(font3);
        lbFlashcardModule->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        lbFlashcardModule->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(lbFlashcardModule);

        lblFlashCardDescription = new QLabel(widget_3);
        lblFlashCardDescription->setObjectName("lblFlashCardDescription");
        sizePolicy.setHeightForWidth(lblFlashCardDescription->sizePolicy().hasHeightForWidth());
        lblFlashCardDescription->setSizePolicy(sizePolicy);
        lblFlashCardDescription->setFont(font1);
        lblFlashCardDescription->setStyleSheet(QString::fromUtf8("background: transparent;"));

        verticalLayout_3->addWidget(lblFlashCardDescription);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName("widget_5");
        widget_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        createFlashCardButton = new QPushButton(widget_5);
        createFlashCardButton->setObjectName("createFlashCardButton");
        sizePolicy.setHeightForWidth(createFlashCardButton->sizePolicy().hasHeightForWidth());
        createFlashCardButton->setSizePolicy(sizePolicy);
        createFlashCardButton->setMaximumSize(QSize(300, 100));
        createFlashCardButton->setFont(font4);
        createFlashCardButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid rgba(255, 255, 255, 80);  /* subtle white border */\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);  /* light white overlay */\n"
"    border: 1px solid rgba(255, 255, 255, 120); /* stronger border on hover */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"}\n"
""));

        horizontalLayout_3->addWidget(createFlashCardButton);

        studyFlashCardsButton = new QPushButton(widget_5);
        studyFlashCardsButton->setObjectName("studyFlashCardsButton");
        sizePolicy.setHeightForWidth(studyFlashCardsButton->sizePolicy().hasHeightForWidth());
        studyFlashCardsButton->setSizePolicy(sizePolicy);
        studyFlashCardsButton->setMaximumSize(QSize(400, 100));
        QFont font5;
        font5.setPointSize(14);
        studyFlashCardsButton->setFont(font5);
        studyFlashCardsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: 1px solid rgba(255, 255, 255, 80);  /* subtle white border */\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);  /* light white overlay */\n"
"    border: 1px solid rgba(255, 255, 255, 120); /* stronger border on hover */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"}\n"
""));

        horizontalLayout_3->addWidget(studyFlashCardsButton);


        verticalLayout_3->addWidget(widget_5);


        horizontalLayout->addWidget(widget_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        homePage->setCentralWidget(centralwidget);

        retranslateUi(homePage);

        QMetaObject::connectSlotsByName(homePage);
    } // setupUi

    void retranslateUi(QMainWindow *homePage)
    {
        homePage->setWindowTitle(QCoreApplication::translate("homePage", "MainWindow", nullptr));
        btnHome->setText(QString());
        btnFlashcards->setText(QString());
        btnQuizzes->setText(QString());
        lblMost->setText(QCoreApplication::translate("homePage", "MOST", nullptr));
        lblRecentlyViewd->setText(QCoreApplication::translate("homePage", "Recently Viewed", nullptr));

        const bool __sortingEnabled = listRecents->isSortingEnabled();
        listRecents->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listRecents->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("homePage", "Chem 101: Biology", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listRecents->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("homePage", "HIST 113: American Civil War", nullptr));
        listRecents->setSortingEnabled(__sortingEnabled);

        quizIcon->setText(QString());
        label_3->setText(QCoreApplication::translate("homePage", "Quiz Module", nullptr));
        lblQuizDescription->setText(QCoreApplication::translate("homePage", "<html><head/><body><p>-Create multiple choice quizzes</p><p>-Study questions in random order</p><p>-Save multiple sets</p></body></html>", nullptr));
        createMultipleChoiceButton->setText(QCoreApplication::translate("homePage", "Create Quiz", nullptr));
        studyMultipleChoiceButton->setText(QCoreApplication::translate("homePage", "Study Quizzes", nullptr));
        flashcardIcon->setText(QString());
        lbFlashcardModule->setText(QCoreApplication::translate("homePage", "Flashcard Module", nullptr));
        lblFlashCardDescription->setText(QCoreApplication::translate("homePage", "<html><head/><body><p>-Create multiple flashcards</p><p>-Study in random order</p><p>-Save multiple sets</p></body></html>", nullptr));
        createFlashCardButton->setText(QCoreApplication::translate("homePage", "Create Flashcard Set", nullptr));
        studyFlashCardsButton->setText(QCoreApplication::translate("homePage", "Study Flashcards", nullptr));
    } // retranslateUi

};

namespace Ui {
    class homePage: public Ui_homePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
