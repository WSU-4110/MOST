#include "homepage.h"
#include "ui_homepage.h"

homePage::homePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homePage)
    , flashCardCreatorWindow(nullptr)
    , quizWindow(nullptr)
{
    ui->setupUi(this);

    ui->lblQuizDescription->setWordWrap(true);
    ui->lblFlashCardDescription->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    connect(ui->createFlashCardButton, &QPushButton::clicked,
            this, &homePage::on_createFlashCardButton_clicked);
    connect(ui->studyMultipleChoiceButton, &QPushButton::clicked,
            this, &homePage::on_studyMultipleChoiceButton_clicked);
}

homePage::~homePage()
{
    delete ui;
    if (flashCardCreatorWindow)
        delete flashCardCreatorWindow;
    if (quizWindow)
        delete quizWindow;
}

void homePage::on_createFlashCardButton_clicked()
{
    if (!flashCardCreatorWindow) {
        flashCardCreatorWindow = new flashCardMaker();
    }
    connect(flashCardCreatorWindow, &flashCardMaker::goHome, this, &homePage::show);
    this->hide();
    flashCardCreatorWindow->show();
    flashCardCreatorWindow->raise();
    flashCardCreatorWindow->activateWindow();
}

void homePage::on_studyMultipleChoiceButton_clicked()
{
    if (!quizWindow) {
        quizWindow = new QuizWindow(this);
    }

    quizWindow->show();
    quizWindow->raise();
    quizWindow->activateWindow();
}

void homePage::on_btnStudyFlashCards_clicked()
{
    FlashCardStudy* flashCardStudy = new FlashCardStudy();

    // Connect signal to update recents
    connect(flashCardStudy, &FlashCardStudy::setOpened, this, &homePage::addToRecents);

    // Handle Home button
    connect(flashCardStudy, &FlashCardStudy::homeButtonClicked, this, &homePage::show);

    flashCardStudy->show();
    this->close();
}

void homePage::addToRecents(const QString &setName)
{
    // Strip "flashcards_" prefix and ".db" suffix
    QString displayName = setName;
    displayName.remove("flashcards_");
    displayName.chop(3);

    // Check if already exists
    QList<QListWidgetItem*> items = ui->listRecents->findItems(displayName, Qt::MatchExactly);
    if (items.isEmpty()) {
        QListWidgetItem* newItem = new QListWidgetItem(displayName);

        // Center text
        newItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        // Font adjustments
        QFont font = newItem->font();
        font.setPointSize(12);
        font.setBold(true);
        newItem->setFont(font);

        // Insert at the top of the list
        ui->listRecents->insertItem(0, newItem);

        // Limit to 10 items
        while (ui->listRecents->count() > 10) {
            delete ui->listRecents->takeItem(ui->listRecents->count() - 1); // remove last (oldest)
        }
    }
}





void homePage::on_listRecents_itemClicked(QListWidgetItem *item)
{
    QString displayName = item->text();

    // Convert back to actual DB filename
    QString fileName = "flashcards_" + displayName + ".db";

    FlashCardStudy* flashCardStudy = new FlashCardStudy();

    connect(flashCardStudy, &FlashCardStudy::setOpened, this, &homePage::addToRecents);
    connect(flashCardStudy, &FlashCardStudy::homeButtonClicked, this, &homePage::show);

    flashCardStudy->show();
    flashCardStudy->selectSet(fileName);

    this->close();
}

