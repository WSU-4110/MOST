#include "flashcardstudy.h"
#include "ui_flashcardstudy.h"
#include "../Homepage/homepage.h"
#include <QDebug>
#include <algorithm>
#include <random>


FlashCardStudy::FlashCardStudy(QString dbName, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlashCardStudy)
    , currentDbName(dbName)
{
    ui->setupUi(this);

    ui->lblSetName->setText(dbName);

    loadFlashcards();
    updateDisplay();

    // Connect navigation buttons
    connect(ui->btnNext, &QPushButton::clicked, this, &FlashCardStudy::on_btnNext_clicked);
    connect(ui->btnPrevious, &QPushButton::clicked, this, &FlashCardStudy::on_btnPrevious_clicked);
}

// For the purpose of the unit test, in order to create static cards in the unit test file, this new constructor was added (Khaliph Page - 11/5/2025)
FlashCardStudy::FlashCardStudy(const QVector<Flashcard> &cards, QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::FlashCardStudy)
{
    ui->setupUi(this);

    // Setup for using hardcoded cards for unit test instead of loading from database
    flashcards = cards;
    currentDbName.clear();  // clearing since no database is used
    currentIndex = 0;
    showingFront = true;

    updateDisplay();
}

FlashCardStudy::~FlashCardStudy()
{
    delete ui;
}

/*
// Home button
void FlashCardStudy::on_btnHome_clicked()
{
    homePage* home = new homePage();
    home->show();
    this->close();
}
*/

// Faux home button for the purpose of the unit test (Khaliph Page - 11/5/2025)
void FlashCardStudy::on_btnHome_clicked()
{
    emit homeButtonClicked();
    this->close();
}

// Load all flashcards from database
void FlashCardStudy::loadFlashcards()
{
    flashcards.clear();

    // Get all flashcards from the database
    flashcards = dbFlashcard.getAllFlashcards(currentDbName);

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
    if (flashcards.isEmpty()) return;

    const Flashcard &card = flashcards[currentIndex];

    // Update lblCard depending on showingFront
    ui->lblCard->setText(showingFront ? card.front : card.back);

    // Update flashcard counter
    ui->lblNumberOfFlashcards->setText(
        QString("%1 of %2").arg(currentIndex + 1).arg(flashcards.size())
        );
}

// Next button
void FlashCardStudy::on_btnNext_clicked()
{
    if (currentIndex < flashcards.size() - 1) {
        currentIndex++;
        showingFront = true;  // reset to front when moving to next card
        updateDisplay();
    }
}

// Previous button
void FlashCardStudy::on_btnPrevious_clicked()
{
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

