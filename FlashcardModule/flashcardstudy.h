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
private slots:

private:
    Ui::FlashCardStudy *ui;

};

#endif // FLASHCARDSTUDY_H
