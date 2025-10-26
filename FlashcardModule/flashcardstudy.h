#ifndef FLASHCARDSTUDY_H
#define FLASHCARDSTUDY_H

#include <QWidget>

namespace Ui {
class FlashCardStudy;
}

class FlashCardStudy : public QWidget
{
    Q_OBJECT

public:
    explicit FlashCardStudy(QWidget *parent = nullptr);
    ~FlashCardStudy();
    void setFlashCard(const QString &question, const QString &answer);
private slots:
    void on_flipButton_clicked();
    void on_homeButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::FlashCardStudy *ui;

    QString displayQuestion;
    QString displayAnswer;
    bool showingQuestion = true;
signals:
    void goHome();
};

#endif // FLASHCARDSTUDY_H
