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

signals:
    void homeButtonClicked();

private slots:
    void on_btnHome_clicked();

private:
    Ui::FlashCardStudy *ui;
};

#endif // FLASHCARDSTUDY_H
