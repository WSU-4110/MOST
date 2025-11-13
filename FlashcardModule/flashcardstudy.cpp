#include "flashcardstudy.h"
#include "ui_flashcardstudy.h"
#include "../Homepage/homepage.h"
#include <QDebug>
#include <algorithm>
#include <random>
#include <QDir>


FlashCardStudy::FlashCardStudy( QWidget *parent)
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
    // Populate combo box with available set files
    QDir dir("Saves/Cards");
    QStringList filters = QStringList() << "flashcards_*.db";
    QStringList fileList = dir.entryList(filters, QDir::Files);
    if (!dir.exists()) {
        qDebug() << "Cards directory not found:";
        return;
    }
    ui->setCombo->clear();
    ui->setCombo->addItem("Select a set...");
    for (const QString &file : fileList) {
        ui->setCombo->addItem(file);
    }

    connect(ui->setCombo, &QComboBox::currentTextChanged,
            this, &FlashCardStudy::on_setCombo_currentTextChanged);

}
void FlashCardStudy::on_setCombo_currentTextChanged(const QString &text) {
    if (text.isEmpty() || text == "Select a set...") return;
    currentDbName = text;
    ui->lblSetName->setText(text);
    loadFlashcards(currentDbName);
}
// Home button
void FlashCardStudy::on_btnHome_clicked()
{
    homePage* home = new homePage();
    home->show();
    this->close();
}


// Load all flashcards from database
void FlashCardStudy::loadFlashcards(const QString &dbName)
{
    flashcards.clear();
    filteredFlashcards.clear();

    // Get all flashcards from the database
    flashcards = dbFlashcard.getAllFlashcards(dbName);

    if (flashcards.isEmpty()) {
        ui->lblCard->setText("No flashcards found.");
        return;
    }

    // Start at the first card and show the front
    currentIndex = 0;
    showingFront = true;

    // Display the first card
    updateDisplay();
}



// Show current card
void FlashCardStudy::updateDisplay()
{
    QVector<Flashcard> *vec = nullptr;
    if (!filteredFlashcards.isEmpty())
        vec = &filteredFlashcards;
    else{
        vec = &flashcards;
    }

    if (vec->isEmpty()) return;

    const Flashcard &card = (*vec)[currentIndex];

    // Update lblCard depending on showingFront
    ui->lblCard->setText(showingFront ? card.front : card.back);

    // Update flashcard counter label
    ui->lblNumberOfFlashcards->setText(
        QString("%1 of %2").arg(currentIndex + 1).arg(vec->size())
        );

    // Update progress bar
    if (vec->size() > 0) {
        int progressValue = static_cast<int>(
            ((currentIndex + 1) / static_cast<double>(vec->size())) * 100
            );
        ui->progressBar->setValue(progressValue);
    }
}


// Next button
void FlashCardStudy::on_btnNext_clicked()
{
    QVector<Flashcard> &vec = filteredFlashcards.isEmpty() ? flashcards : filteredFlashcards;
    if (currentIndex < vec.size() - 1) {
        currentIndex++;
        showingFront = true;  // reset to front when moving to next card
        updateDisplay();
    }
}

// Previous button
void FlashCardStudy::on_btnPrevious_clicked()
{
    QVector<Flashcard> &vec = filteredFlashcards.isEmpty() ? flashcards : filteredFlashcards;
    if (currentIndex > 0) {
        currentIndex--;
        showingFront = true;  // reset to front when moving to previous card
        updateDisplay();
    }
}

// Flip button
void FlashCardStudy::on_btnFlip_clicked()
{
    showingFront = !showingFront;  // toggle front/back
    updateDisplay();
}

void FlashCardStudy::on_btnShuffle_clicked()
{
    QVector<Flashcard> &vec = filteredFlashcards.isEmpty() ? flashcards : filteredFlashcards;
    // Create a random seed with current time
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the flashcards vector
    std::shuffle(flashcards.begin(), flashcards.end(), g);

    // Reset to the first card and show front
    currentIndex = 0;
    showingFront = true;

    updateDisplay();
}

