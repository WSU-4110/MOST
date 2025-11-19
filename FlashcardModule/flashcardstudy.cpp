#include "flashcardstudy.h"
#include "ui_flashcardstudy.h"
#include "../Homepage/homepage.h"
#include <QDebug>
#include <algorithm>
#include <random>
#include <QDir>

FlashCardStudy::FlashCardStudy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlashCardStudy)
{
    ui->setupUi(this);
    setupSetSelection();
}

FlashCardStudy::~FlashCardStudy()
{
    delete ui;
}

void FlashCardStudy::setupSetSelection() {
    QDir dir("Saves/Cards");
    QStringList filters = QStringList() << "flashcards_*.db";
    QStringList fileList = dir.entryList(filters, QDir::Files);

    ui->setCombo->clear();
    ui->setCombo->addItem("Select a set...");

    for (const QString &file : fileList) {
        QFileInfo fi(file);
        QString realName = fi.baseName();
        int indexUserFriendlyName = realName.indexOf("_");
        realName=realName.mid(indexUserFriendlyName+1);
        ui->setCombo->addItem(realName,file);

    }

    connect(ui->setCombo, &QComboBox::currentTextChanged,
            this, &FlashCardStudy::on_setCombo_currentTextChanged);
}

void FlashCardStudy::on_setCombo_currentTextChanged(const QString &text) {
    if (text.isEmpty() || text == "Select a set...") return;
    QString realName= ui->setCombo->currentData().toString();
    currentDbName = realName;
    ui->lblSetName->setText(text);
    loadFlashcards(currentDbName);

    emit setOpened(currentDbName); // Emit signal for homepage
}

void FlashCardStudy::on_btnHome_clicked()
{
    emit homeButtonClicked();
    this->close();
}

void FlashCardStudy::loadFlashcards(const QString &dbName)
{
    flashcards.clear();
    filteredFlashcards.clear();

    flashcards = dbFlashcard.getAllFlashcards(dbName);

    if (flashcards.isEmpty()) {
        ui->lblCard->setText("No flashcards found.");
        return;
    }

    currentIndex = 0;
    showingFront = true;
    updateDisplay();
}

void FlashCardStudy::updateDisplay()
{
    QVector<Flashcard> *vec = filteredFlashcards.isEmpty() ? &flashcards : &filteredFlashcards;
    if (vec->isEmpty()) return;

    const Flashcard &card = (*vec)[currentIndex];
    ui->lblCard->setText(showingFront ? card.front : card.back);
    ui->lblNumberOfFlashcards->setText(
        QString("%1 of %2").arg(currentIndex + 1).arg(vec->size())
        );

    int progressValue = static_cast<int>(((currentIndex + 1) / static_cast<double>(vec->size())) * 100);
    ui->progressBar->setValue(progressValue);
}

void FlashCardStudy::on_btnNext_clicked()
{
    QVector<Flashcard> &vec = filteredFlashcards.isEmpty() ? flashcards : filteredFlashcards;
    if (currentIndex < vec.size() - 1) {
        currentIndex++;
        showingFront = true;
        updateDisplay();
    }
}

void FlashCardStudy::on_btnPrevious_clicked()
{
    QVector<Flashcard> &vec = filteredFlashcards.isEmpty() ? flashcards : filteredFlashcards;
    if (currentIndex > 0) {
        currentIndex--;
        showingFront = true;
        updateDisplay();
    }
}

void FlashCardStudy::on_btnFlip_clicked()
{
    showingFront = !showingFront;
    updateDisplay();
}

void FlashCardStudy::on_btnShuffle_clicked()
{
    QVector<Flashcard> &vec = filteredFlashcards.isEmpty() ? flashcards : filteredFlashcards;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(flashcards.begin(), flashcards.end(), g);

    currentIndex = 0;
    showingFront = true;
    updateDisplay();
}

void FlashCardStudy::selectSet(const QString &setName)
{
    int index = ui->setCombo->findText(setName);
    if (index != -1) {
        ui->setCombo->setCurrentIndex(index); // trigger on_setCombo_currentTextChanged
    }
}
