/********************************************************************************
** Form generated from reading UI file 'quizwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZWINDOW_H
#define UI_QUIZWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedQuizWidget;
    QWidget *pageQuizMenu;
    QWidget *widget_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QLabel *label_2;
    QWidget *widget_3;
    QPushButton *pushButtonCreatePage;
    QLabel *label_3;
    QWidget *widget_4;
    QPushButton *pushButtonStudyPage;
    QLabel *label_4;
    QWidget *widget;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QWidget *pageQuizCreate;
    QPushButton *pushButtonCreateQuestion;
    QPushButton *pushButtonOverwriteQuestion;
    QPushButton *pushButtonDeleteQuestion;
    QPushButton *pushButtonPreviousQuestion;
    QPushButton *pushButtonNextQuestion;
    QPushButton *pushButtonReturn;
    QFrame *quizCreateFrame;
    QLineEdit *lineEditAnswer3;
    QLabel *labelAnswer3;
    QLabel *labelAnswer6;
    QLabel *labelAnswer2;
    QComboBox *comboBoxCorrect;
    QLabel *labelCorrectAnswer;
    QLineEdit *lineEditAnswer4;
    QLabel *labelAnswer1;
    QLabel *labelAnswer4;
    QLabel *labelAnswer5;
    QLineEdit *lineEditAnswer6;
    QLabel *labelQuestion;
    QLineEdit *lineEditAnswer1;
    QLineEdit *lineEditAnswer2;
    QLineEdit *lineEditQuestion;
    QLineEdit *lineEditAnswer5;
    QComboBox *comboBoxCorrect_2;
    QComboBox *comboBoxCorrect_3;
    QComboBox *comboBoxCorrect_4;
    QComboBox *comboBoxCorrect_5;
    QComboBox *comboBoxCorrect_6;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_5;
    QWidget *pageQuizStudy;
    QPushButton *pushButtonReturn_2;
    QPushButton *pushButtonPreviousQuestion_2;
    QPushButton *pushButtonNextQuestion_2;
    QPushButton *pushButtonSubmitQuiz;
    QFrame *frame;
    QRadioButton *radioButtonAnswer5;
    QPlainTextEdit *textDisplayAnswer6;
    QRadioButton *radioButtonAnswer4;
    QPlainTextEdit *textDisplayAnswer5;
    QRadioButton *radioButtonAnswer1;
    QPlainTextEdit *textDisplayAnswer2;
    QPlainTextEdit *textDisplayAnswer3;
    QRadioButton *radioButtonAnswer6;
    QPlainTextEdit *textDisplayAnswer4;
    QRadioButton *radioButtonAnswer2;
    QPlainTextEdit *textDisplayAnswer1;
    QRadioButton *radioButtonAnswer3;
    QPlainTextEdit *textDisplayQuestion;
    QLabel *label_6;
    QPlainTextEdit *plainTextEdit_3;
    QWidget *pageQuizResults;
    QPushButton *pushButtonReturn_3;
    QFrame *frame_2;
    QLabel *labelFractionSign;
    QPlainTextEdit *textResultNum;
    QPlainTextEdit *textResultDen;
    QLabel *labelPercentSign;
    QPlainTextEdit *textResultPer;
    QLabel *labelResult;
    QPushButton *pushButtonReview;
    QLabel *label_7;
    QPlainTextEdit *plainTextEdit_4;
    QWidget *pageQuizReview;
    QPushButton *pushButtonReturn_4;
    QPlainTextEdit *plainTextEdit_5;
    QLabel *label_8;
    QFrame *frame_3;
    QPlainTextEdit *textDisplayAnswer6_2;
    QPlainTextEdit *textDisplayAnswer5_2;
    QPlainTextEdit *textDisplayAnswer2_2;
    QPlainTextEdit *textDisplayAnswer3_2;
    QPlainTextEdit *textDisplayAnswer4_2;
    QPlainTextEdit *textDisplayAnswer1_2;
    QPlainTextEdit *textDisplayQuestion_2;
    QLabel *labelCheck1;
    QLabel *labelCheck2;
    QLabel *labelCheck3;
    QLabel *labelCheck4;
    QLabel *labelCheck5;
    QLabel *labelCheck6;
    QPushButton *pushButtonNextQuestion_3;
    QPushButton *pushButtonPreviousQuestion_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(927, 615);
        MainWindow->setMinimumSize(QSize(927, 615));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(9, 2, 17, 64);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedQuizWidget = new QStackedWidget(centralwidget);
        stackedQuizWidget->setObjectName("stackedQuizWidget");
        stackedQuizWidget->setGeometry(QRect(9, 9, 909, 597));
        stackedQuizWidget->setAutoFillBackground(false);
        stackedQuizWidget->setStyleSheet(QString::fromUtf8("border-radius: 10px"));
        pageQuizMenu = new QWidget();
        pageQuizMenu->setObjectName("pageQuizMenu");
        widget_2 = new QWidget(pageQuizMenu);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(80, 170, 231, 251));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;"));
        pushButtonSave = new QPushButton(widget_2);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setGeometry(QRect(120, 190, 80, 24));
        pushButtonLoad = new QPushButton(widget_2);
        pushButtonLoad->setObjectName("pushButtonLoad");
        pushButtonLoad->setGeometry(QRect(30, 190, 80, 24));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 20, 131, 151));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/icons/images/save-file-icon-14.png);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_3 = new QWidget(pageQuizMenu);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(340, 170, 231, 251));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;"));
        pushButtonCreatePage = new QPushButton(widget_3);
        pushButtonCreatePage->setObjectName("pushButtonCreatePage");
        pushButtonCreatePage->setGeometry(QRect(70, 190, 80, 24));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 20, 131, 151));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/icons/images/pngfind.com-phone-symbol-png-2755033.png);"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_4 = new QWidget(pageQuizMenu);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(600, 170, 231, 251));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        pushButtonStudyPage = new QPushButton(widget_4);
        pushButtonStudyPage->setObjectName("pushButtonStudyPage");
        pushButtonStudyPage->setGeometry(QRect(79, 190, 81, 24));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 20, 131, 151));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/icons/images/open-book-icon-19.png);"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(pageQuizMenu);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 129, 751, 21));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 71, 21));
        plainTextEdit = new QPlainTextEdit(widget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(80, 0, 661, 21));
        stackedQuizWidget->addWidget(pageQuizMenu);
        pageQuizCreate = new QWidget();
        pageQuizCreate->setObjectName("pageQuizCreate");
        pushButtonCreateQuestion = new QPushButton(pageQuizCreate);
        pushButtonCreateQuestion->setObjectName("pushButtonCreateQuestion");
        pushButtonCreateQuestion->setGeometry(QRect(160, 500, 80, 24));
        pushButtonCreateQuestion->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonOverwriteQuestion = new QPushButton(pageQuizCreate);
        pushButtonOverwriteQuestion->setObjectName("pushButtonOverwriteQuestion");
        pushButtonOverwriteQuestion->setGeometry(QRect(270, 500, 80, 24));
        pushButtonOverwriteQuestion->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonDeleteQuestion = new QPushButton(pageQuizCreate);
        pushButtonDeleteQuestion->setObjectName("pushButtonDeleteQuestion");
        pushButtonDeleteQuestion->setGeometry(QRect(380, 500, 80, 24));
        pushButtonDeleteQuestion->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonPreviousQuestion = new QPushButton(pageQuizCreate);
        pushButtonPreviousQuestion->setObjectName("pushButtonPreviousQuestion");
        pushButtonPreviousQuestion->setGeometry(QRect(550, 500, 80, 24));
        pushButtonPreviousQuestion->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonNextQuestion = new QPushButton(pageQuizCreate);
        pushButtonNextQuestion->setObjectName("pushButtonNextQuestion");
        pushButtonNextQuestion->setGeometry(QRect(660, 500, 80, 24));
        pushButtonNextQuestion->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonReturn = new QPushButton(pageQuizCreate);
        pushButtonReturn->setObjectName("pushButtonReturn");
        pushButtonReturn->setGeometry(QRect(160, 70, 80, 24));
        pushButtonReturn->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        quizCreateFrame = new QFrame(pageQuizCreate);
        quizCreateFrame->setObjectName("quizCreateFrame");
        quizCreateFrame->setGeometry(QRect(160, 100, 581, 391));
        quizCreateFrame->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        quizCreateFrame->setFrameShape(QFrame::Shape::StyledPanel);
        quizCreateFrame->setFrameShadow(QFrame::Shadow::Raised);
        lineEditAnswer3 = new QLineEdit(quizCreateFrame);
        lineEditAnswer3->setObjectName("lineEditAnswer3");
        lineEditAnswer3->setGeometry(QRect(100, 160, 471, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font.setPointSize(12);
        lineEditAnswer3->setFont(font);
        labelAnswer3 = new QLabel(quizCreateFrame);
        labelAnswer3->setObjectName("labelAnswer3");
        labelAnswer3->setGeometry(QRect(10, 170, 81, 21));
        labelAnswer6 = new QLabel(quizCreateFrame);
        labelAnswer6->setObjectName("labelAnswer6");
        labelAnswer6->setGeometry(QRect(10, 320, 81, 21));
        labelAnswer2 = new QLabel(quizCreateFrame);
        labelAnswer2->setObjectName("labelAnswer2");
        labelAnswer2->setGeometry(QRect(10, 120, 81, 21));
        comboBoxCorrect = new QComboBox(quizCreateFrame);
        comboBoxCorrect->addItem(QString());
        comboBoxCorrect->addItem(QString());
        comboBoxCorrect->addItem(QString());
        comboBoxCorrect->addItem(QString());
        comboBoxCorrect->addItem(QString());
        comboBoxCorrect->addItem(QString());
        comboBoxCorrect->addItem(QString());
        comboBoxCorrect->setObjectName("comboBoxCorrect");
        comboBoxCorrect->setGeometry(QRect(100, 360, 72, 24));
        labelCorrectAnswer = new QLabel(quizCreateFrame);
        labelCorrectAnswer->setObjectName("labelCorrectAnswer");
        labelCorrectAnswer->setGeometry(QRect(10, 360, 81, 20));
        lineEditAnswer4 = new QLineEdit(quizCreateFrame);
        lineEditAnswer4->setObjectName("lineEditAnswer4");
        lineEditAnswer4->setGeometry(QRect(100, 210, 471, 41));
        lineEditAnswer4->setFont(font);
        labelAnswer1 = new QLabel(quizCreateFrame);
        labelAnswer1->setObjectName("labelAnswer1");
        labelAnswer1->setGeometry(QRect(10, 70, 81, 21));
        labelAnswer4 = new QLabel(quizCreateFrame);
        labelAnswer4->setObjectName("labelAnswer4");
        labelAnswer4->setGeometry(QRect(10, 220, 81, 21));
        labelAnswer5 = new QLabel(quizCreateFrame);
        labelAnswer5->setObjectName("labelAnswer5");
        labelAnswer5->setGeometry(QRect(10, 270, 81, 21));
        lineEditAnswer6 = new QLineEdit(quizCreateFrame);
        lineEditAnswer6->setObjectName("lineEditAnswer6");
        lineEditAnswer6->setGeometry(QRect(100, 310, 471, 41));
        lineEditAnswer6->setFont(font);
        labelQuestion = new QLabel(quizCreateFrame);
        labelQuestion->setObjectName("labelQuestion");
        labelQuestion->setGeometry(QRect(10, 20, 81, 21));
        lineEditAnswer1 = new QLineEdit(quizCreateFrame);
        lineEditAnswer1->setObjectName("lineEditAnswer1");
        lineEditAnswer1->setGeometry(QRect(100, 60, 471, 41));
        lineEditAnswer1->setFont(font);
        lineEditAnswer2 = new QLineEdit(quizCreateFrame);
        lineEditAnswer2->setObjectName("lineEditAnswer2");
        lineEditAnswer2->setGeometry(QRect(100, 110, 471, 41));
        lineEditAnswer2->setFont(font);
        lineEditQuestion = new QLineEdit(quizCreateFrame);
        lineEditQuestion->setObjectName("lineEditQuestion");
        lineEditQuestion->setGeometry(QRect(100, 10, 471, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font1.setPointSize(12);
        font1.setBold(true);
        lineEditQuestion->setFont(font1);
        lineEditAnswer5 = new QLineEdit(quizCreateFrame);
        lineEditAnswer5->setObjectName("lineEditAnswer5");
        lineEditAnswer5->setGeometry(QRect(100, 260, 471, 41));
        lineEditAnswer5->setFont(font);
        comboBoxCorrect_2 = new QComboBox(quizCreateFrame);
        comboBoxCorrect_2->addItem(QString());
        comboBoxCorrect_2->addItem(QString());
        comboBoxCorrect_2->addItem(QString());
        comboBoxCorrect_2->addItem(QString());
        comboBoxCorrect_2->addItem(QString());
        comboBoxCorrect_2->addItem(QString());
        comboBoxCorrect_2->addItem(QString());
        comboBoxCorrect_2->setObjectName("comboBoxCorrect_2");
        comboBoxCorrect_2->setGeometry(QRect(180, 360, 72, 24));
        comboBoxCorrect_3 = new QComboBox(quizCreateFrame);
        comboBoxCorrect_3->addItem(QString());
        comboBoxCorrect_3->addItem(QString());
        comboBoxCorrect_3->addItem(QString());
        comboBoxCorrect_3->addItem(QString());
        comboBoxCorrect_3->addItem(QString());
        comboBoxCorrect_3->addItem(QString());
        comboBoxCorrect_3->addItem(QString());
        comboBoxCorrect_3->setObjectName("comboBoxCorrect_3");
        comboBoxCorrect_3->setGeometry(QRect(260, 360, 72, 24));
        comboBoxCorrect_4 = new QComboBox(quizCreateFrame);
        comboBoxCorrect_4->addItem(QString());
        comboBoxCorrect_4->addItem(QString());
        comboBoxCorrect_4->addItem(QString());
        comboBoxCorrect_4->addItem(QString());
        comboBoxCorrect_4->addItem(QString());
        comboBoxCorrect_4->addItem(QString());
        comboBoxCorrect_4->addItem(QString());
        comboBoxCorrect_4->setObjectName("comboBoxCorrect_4");
        comboBoxCorrect_4->setGeometry(QRect(340, 360, 72, 24));
        comboBoxCorrect_5 = new QComboBox(quizCreateFrame);
        comboBoxCorrect_5->addItem(QString());
        comboBoxCorrect_5->addItem(QString());
        comboBoxCorrect_5->addItem(QString());
        comboBoxCorrect_5->addItem(QString());
        comboBoxCorrect_5->addItem(QString());
        comboBoxCorrect_5->addItem(QString());
        comboBoxCorrect_5->addItem(QString());
        comboBoxCorrect_5->setObjectName("comboBoxCorrect_5");
        comboBoxCorrect_5->setGeometry(QRect(420, 360, 72, 24));
        comboBoxCorrect_6 = new QComboBox(quizCreateFrame);
        comboBoxCorrect_6->addItem(QString());
        comboBoxCorrect_6->addItem(QString());
        comboBoxCorrect_6->addItem(QString());
        comboBoxCorrect_6->addItem(QString());
        comboBoxCorrect_6->addItem(QString());
        comboBoxCorrect_6->addItem(QString());
        comboBoxCorrect_6->addItem(QString());
        comboBoxCorrect_6->setObjectName("comboBoxCorrect_6");
        comboBoxCorrect_6->setGeometry(QRect(500, 360, 72, 24));
        plainTextEdit_2 = new QPlainTextEdit(pageQuizCreate);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(310, 70, 431, 21));
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        label_5 = new QLabel(pageQuizCreate);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(260, 70, 41, 21));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedQuizWidget->addWidget(pageQuizCreate);
        quizCreateFrame->raise();
        pushButtonCreateQuestion->raise();
        pushButtonOverwriteQuestion->raise();
        pushButtonDeleteQuestion->raise();
        pushButtonPreviousQuestion->raise();
        pushButtonNextQuestion->raise();
        pushButtonReturn->raise();
        plainTextEdit_2->raise();
        label_5->raise();
        pageQuizStudy = new QWidget();
        pageQuizStudy->setObjectName("pageQuizStudy");
        pushButtonReturn_2 = new QPushButton(pageQuizStudy);
        pushButtonReturn_2->setObjectName("pushButtonReturn_2");
        pushButtonReturn_2->setGeometry(QRect(160, 70, 80, 24));
        pushButtonReturn_2->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonPreviousQuestion_2 = new QPushButton(pageQuizStudy);
        pushButtonPreviousQuestion_2->setObjectName("pushButtonPreviousQuestion_2");
        pushButtonPreviousQuestion_2->setGeometry(QRect(300, 490, 80, 24));
        pushButtonPreviousQuestion_2->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonNextQuestion_2 = new QPushButton(pageQuizStudy);
        pushButtonNextQuestion_2->setObjectName("pushButtonNextQuestion_2");
        pushButtonNextQuestion_2->setGeometry(QRect(520, 490, 80, 24));
        pushButtonNextQuestion_2->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonSubmitQuiz = new QPushButton(pageQuizStudy);
        pushButtonSubmitQuiz->setObjectName("pushButtonSubmitQuiz");
        pushButtonSubmitQuiz->setGeometry(QRect(410, 490, 80, 24));
        pushButtonSubmitQuiz->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        frame = new QFrame(pageQuizStudy);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(160, 100, 581, 381));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        radioButtonAnswer5 = new QRadioButton(frame);
        radioButtonAnswer5->setObjectName("radioButtonAnswer5");
        radioButtonAnswer5->setGeometry(QRect(10, 290, 21, 21));
        radioButtonAnswer5->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);"));
        textDisplayAnswer6 = new QPlainTextEdit(frame);
        textDisplayAnswer6->setObjectName("textDisplayAnswer6");
        textDisplayAnswer6->setGeometry(QRect(40, 330, 531, 41));
        textDisplayAnswer6->setFont(font);
        radioButtonAnswer4 = new QRadioButton(frame);
        radioButtonAnswer4->setObjectName("radioButtonAnswer4");
        radioButtonAnswer4->setGeometry(QRect(10, 240, 21, 21));
        radioButtonAnswer4->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);"));
        textDisplayAnswer5 = new QPlainTextEdit(frame);
        textDisplayAnswer5->setObjectName("textDisplayAnswer5");
        textDisplayAnswer5->setGeometry(QRect(40, 280, 531, 41));
        textDisplayAnswer5->setFont(font);
        radioButtonAnswer1 = new QRadioButton(frame);
        radioButtonAnswer1->setObjectName("radioButtonAnswer1");
        radioButtonAnswer1->setGeometry(QRect(10, 90, 21, 21));
        radioButtonAnswer1->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);"));
        textDisplayAnswer2 = new QPlainTextEdit(frame);
        textDisplayAnswer2->setObjectName("textDisplayAnswer2");
        textDisplayAnswer2->setGeometry(QRect(40, 130, 531, 41));
        textDisplayAnswer2->setFont(font);
        textDisplayAnswer3 = new QPlainTextEdit(frame);
        textDisplayAnswer3->setObjectName("textDisplayAnswer3");
        textDisplayAnswer3->setGeometry(QRect(40, 180, 531, 41));
        textDisplayAnswer3->setFont(font);
        radioButtonAnswer6 = new QRadioButton(frame);
        radioButtonAnswer6->setObjectName("radioButtonAnswer6");
        radioButtonAnswer6->setGeometry(QRect(10, 340, 21, 21));
        radioButtonAnswer6->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);"));
        textDisplayAnswer4 = new QPlainTextEdit(frame);
        textDisplayAnswer4->setObjectName("textDisplayAnswer4");
        textDisplayAnswer4->setGeometry(QRect(40, 230, 531, 41));
        textDisplayAnswer4->setFont(font);
        radioButtonAnswer2 = new QRadioButton(frame);
        radioButtonAnswer2->setObjectName("radioButtonAnswer2");
        radioButtonAnswer2->setGeometry(QRect(10, 140, 21, 21));
        radioButtonAnswer2->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);"));
        textDisplayAnswer1 = new QPlainTextEdit(frame);
        textDisplayAnswer1->setObjectName("textDisplayAnswer1");
        textDisplayAnswer1->setGeometry(QRect(40, 80, 531, 41));
        textDisplayAnswer1->setFont(font);
        radioButtonAnswer3 = new QRadioButton(frame);
        radioButtonAnswer3->setObjectName("radioButtonAnswer3");
        radioButtonAnswer3->setGeometry(QRect(10, 190, 21, 21));
        radioButtonAnswer3->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);"));
        textDisplayQuestion = new QPlainTextEdit(frame);
        textDisplayQuestion->setObjectName("textDisplayQuestion");
        textDisplayQuestion->setGeometry(QRect(10, 10, 561, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font2.setPointSize(16);
        font2.setBold(true);
        textDisplayQuestion->setFont(font2);
        label_6 = new QLabel(pageQuizStudy);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 70, 41, 21));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        plainTextEdit_3 = new QPlainTextEdit(pageQuizStudy);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(310, 70, 431, 21));
        plainTextEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        stackedQuizWidget->addWidget(pageQuizStudy);
        pageQuizResults = new QWidget();
        pageQuizResults->setObjectName("pageQuizResults");
        pushButtonReturn_3 = new QPushButton(pageQuizResults);
        pushButtonReturn_3->setObjectName("pushButtonReturn_3");
        pushButtonReturn_3->setGeometry(QRect(160, 70, 80, 24));
        pushButtonReturn_3->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        frame_2 = new QFrame(pageQuizResults);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(160, 100, 581, 381));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        labelFractionSign = new QLabel(frame_2);
        labelFractionSign->setObjectName("labelFractionSign");
        labelFractionSign->setGeometry(QRect(290, 130, 16, 16));
        textResultNum = new QPlainTextEdit(frame_2);
        textResultNum->setObjectName("textResultNum");
        textResultNum->setGeometry(QRect(180, 120, 104, 31));
        textResultDen = new QPlainTextEdit(frame_2);
        textResultDen->setObjectName("textResultDen");
        textResultDen->setGeometry(QRect(300, 120, 104, 31));
        labelPercentSign = new QLabel(frame_2);
        labelPercentSign->setObjectName("labelPercentSign");
        labelPercentSign->setGeometry(QRect(290, 170, 16, 16));
        textResultPer = new QPlainTextEdit(frame_2);
        textResultPer->setObjectName("textResultPer");
        textResultPer->setGeometry(QRect(180, 160, 104, 31));
        labelResult = new QLabel(frame_2);
        labelResult->setObjectName("labelResult");
        labelResult->setGeometry(QRect(140, 130, 41, 16));
        pushButtonReview = new QPushButton(frame_2);
        pushButtonReview->setObjectName("pushButtonReview");
        pushButtonReview->setGeometry(QRect(230, 320, 131, 24));
        label_7 = new QLabel(pageQuizResults);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(260, 70, 41, 21));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        plainTextEdit_4 = new QPlainTextEdit(pageQuizResults);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(310, 70, 431, 21));
        plainTextEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        stackedQuizWidget->addWidget(pageQuizResults);
        pageQuizReview = new QWidget();
        pageQuizReview->setObjectName("pageQuizReview");
        pushButtonReturn_4 = new QPushButton(pageQuizReview);
        pushButtonReturn_4->setObjectName("pushButtonReturn_4");
        pushButtonReturn_4->setGeometry(QRect(170, 50, 80, 24));
        pushButtonReturn_4->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        plainTextEdit_5 = new QPlainTextEdit(pageQuizReview);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setGeometry(QRect(310, 50, 431, 21));
        plainTextEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        label_8 = new QLabel(pageQuizReview);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(260, 50, 41, 21));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 150);\n"
"border-radius: 10px;\n"
""));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_3 = new QFrame(pageQuizReview);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(160, 90, 581, 381));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        textDisplayAnswer6_2 = new QPlainTextEdit(frame_3);
        textDisplayAnswer6_2->setObjectName("textDisplayAnswer6_2");
        textDisplayAnswer6_2->setGeometry(QRect(40, 330, 531, 41));
        textDisplayAnswer6_2->setFont(font);
        textDisplayAnswer5_2 = new QPlainTextEdit(frame_3);
        textDisplayAnswer5_2->setObjectName("textDisplayAnswer5_2");
        textDisplayAnswer5_2->setGeometry(QRect(40, 280, 531, 41));
        textDisplayAnswer5_2->setFont(font);
        textDisplayAnswer2_2 = new QPlainTextEdit(frame_3);
        textDisplayAnswer2_2->setObjectName("textDisplayAnswer2_2");
        textDisplayAnswer2_2->setGeometry(QRect(40, 130, 531, 41));
        textDisplayAnswer2_2->setFont(font);
        textDisplayAnswer3_2 = new QPlainTextEdit(frame_3);
        textDisplayAnswer3_2->setObjectName("textDisplayAnswer3_2");
        textDisplayAnswer3_2->setGeometry(QRect(40, 180, 531, 41));
        textDisplayAnswer3_2->setFont(font);
        textDisplayAnswer4_2 = new QPlainTextEdit(frame_3);
        textDisplayAnswer4_2->setObjectName("textDisplayAnswer4_2");
        textDisplayAnswer4_2->setGeometry(QRect(40, 230, 531, 41));
        textDisplayAnswer4_2->setFont(font);
        textDisplayAnswer1_2 = new QPlainTextEdit(frame_3);
        textDisplayAnswer1_2->setObjectName("textDisplayAnswer1_2");
        textDisplayAnswer1_2->setGeometry(QRect(40, 80, 531, 41));
        textDisplayAnswer1_2->setFont(font);
        textDisplayQuestion_2 = new QPlainTextEdit(frame_3);
        textDisplayQuestion_2->setObjectName("textDisplayQuestion_2");
        textDisplayQuestion_2->setGeometry(QRect(10, 10, 561, 61));
        textDisplayQuestion_2->setFont(font2);
        labelCheck1 = new QLabel(frame_3);
        labelCheck1->setObjectName("labelCheck1");
        labelCheck1->setGeometry(QRect(10, 90, 21, 20));
        labelCheck2 = new QLabel(frame_3);
        labelCheck2->setObjectName("labelCheck2");
        labelCheck2->setGeometry(QRect(10, 140, 21, 20));
        labelCheck3 = new QLabel(frame_3);
        labelCheck3->setObjectName("labelCheck3");
        labelCheck3->setGeometry(QRect(10, 190, 21, 20));
        labelCheck4 = new QLabel(frame_3);
        labelCheck4->setObjectName("labelCheck4");
        labelCheck4->setGeometry(QRect(10, 240, 21, 20));
        labelCheck5 = new QLabel(frame_3);
        labelCheck5->setObjectName("labelCheck5");
        labelCheck5->setGeometry(QRect(10, 290, 21, 20));
        labelCheck6 = new QLabel(frame_3);
        labelCheck6->setObjectName("labelCheck6");
        labelCheck6->setGeometry(QRect(10, 340, 21, 20));
        pushButtonNextQuestion_3 = new QPushButton(pageQuizReview);
        pushButtonNextQuestion_3->setObjectName("pushButtonNextQuestion_3");
        pushButtonNextQuestion_3->setGeometry(QRect(470, 480, 80, 24));
        pushButtonNextQuestion_3->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        pushButtonPreviousQuestion_3 = new QPushButton(pageQuizReview);
        pushButtonPreviousQuestion_3->setObjectName("pushButtonPreviousQuestion_3");
        pushButtonPreviousQuestion_3->setGeometry(QRect(360, 480, 80, 24));
        pushButtonPreviousQuestion_3->setStyleSheet(QString::fromUtf8("background-color: rgba(75, 58, 108, 100);\n"
"border-radius: 10px;"));
        stackedQuizWidget->addWidget(pageQuizReview);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedQuizWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label_2->setText(QString());
        pushButtonCreatePage->setText(QCoreApplication::translate("MainWindow", "Create/Edit", nullptr));
        label_3->setText(QString());
        pushButtonStudyPage->setText(QCoreApplication::translate("MainWindow", "Study", nullptr));
        label_4->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Current Set:", nullptr));
        pushButtonCreateQuestion->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        pushButtonOverwriteQuestion->setText(QCoreApplication::translate("MainWindow", "Overwrite", nullptr));
        pushButtonDeleteQuestion->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButtonPreviousQuestion->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButtonNextQuestion->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        pushButtonReturn->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        labelAnswer3->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelAnswer3->setText(QCoreApplication::translate("MainWindow", "Insert Answer 3", nullptr));
        labelAnswer6->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelAnswer6->setText(QCoreApplication::translate("MainWindow", "Insert Answer 6", nullptr));
        labelAnswer2->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelAnswer2->setText(QCoreApplication::translate("MainWindow", "Insert Answer 2", nullptr));
        comboBoxCorrect->setItemText(0, QCoreApplication::translate("MainWindow", "N/A", nullptr));
        comboBoxCorrect->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxCorrect->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxCorrect->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxCorrect->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxCorrect->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxCorrect->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        comboBoxCorrect->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelCorrectAnswer->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelCorrectAnswer->setText(QCoreApplication::translate("MainWindow", "Correct Answer", nullptr));
        labelAnswer1->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelAnswer1->setText(QCoreApplication::translate("MainWindow", "Insert Answer 1", nullptr));
        labelAnswer4->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelAnswer4->setText(QCoreApplication::translate("MainWindow", "Insert Answer 4", nullptr));
        labelAnswer5->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelAnswer5->setText(QCoreApplication::translate("MainWindow", "Insert Answer 5", nullptr));
        labelQuestion->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        labelQuestion->setText(QCoreApplication::translate("MainWindow", "Insert Question", nullptr));
        comboBoxCorrect_2->setItemText(0, QCoreApplication::translate("MainWindow", "N/A", nullptr));
        comboBoxCorrect_2->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxCorrect_2->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxCorrect_2->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxCorrect_2->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxCorrect_2->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxCorrect_2->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        comboBoxCorrect_2->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        comboBoxCorrect_3->setItemText(0, QCoreApplication::translate("MainWindow", "N/A", nullptr));
        comboBoxCorrect_3->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxCorrect_3->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxCorrect_3->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxCorrect_3->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxCorrect_3->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxCorrect_3->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        comboBoxCorrect_3->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        comboBoxCorrect_4->setItemText(0, QCoreApplication::translate("MainWindow", "N/A", nullptr));
        comboBoxCorrect_4->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxCorrect_4->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxCorrect_4->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxCorrect_4->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxCorrect_4->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxCorrect_4->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        comboBoxCorrect_4->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        comboBoxCorrect_5->setItemText(0, QCoreApplication::translate("MainWindow", "N/A", nullptr));
        comboBoxCorrect_5->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxCorrect_5->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxCorrect_5->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxCorrect_5->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxCorrect_5->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxCorrect_5->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        comboBoxCorrect_5->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        comboBoxCorrect_6->setItemText(0, QCoreApplication::translate("MainWindow", "N/A", nullptr));
        comboBoxCorrect_6->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxCorrect_6->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxCorrect_6->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxCorrect_6->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxCorrect_6->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxCorrect_6->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        comboBoxCorrect_6->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: rgba(75, 58, 108, 100);", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        pushButtonReturn_2->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        pushButtonPreviousQuestion_2->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        pushButtonNextQuestion_2->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        pushButtonSubmitQuiz->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        radioButtonAnswer5->setText(QString());
        radioButtonAnswer4->setText(QString());
        radioButtonAnswer1->setText(QString());
        radioButtonAnswer6->setText(QString());
        radioButtonAnswer2->setText(QString());
        radioButtonAnswer3->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        pushButtonReturn_3->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        labelFractionSign->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        labelPercentSign->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        labelResult->setText(QCoreApplication::translate("MainWindow", "Result:", nullptr));
        pushButtonReview->setText(QCoreApplication::translate("MainWindow", "Review Questions", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        pushButtonReturn_4->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        labelCheck1->setText(QString());
        labelCheck2->setText(QString());
        labelCheck3->setText(QString());
        labelCheck4->setText(QString());
        labelCheck5->setText(QString());
        labelCheck6->setText(QString());
        pushButtonNextQuestion_3->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        pushButtonPreviousQuestion_3->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZWINDOW_H
