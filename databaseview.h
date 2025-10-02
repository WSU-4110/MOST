#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QMainWindow>

namespace Ui {
class databaseview;
}

class databaseview : public QMainWindow
{
    Q_OBJECT

public:
    explicit databaseview(QWidget *parent = nullptr);
    ~databaseview();


private slots:

    void on_btnShowCards_clicked();

    void on_btnInsertCard_clicked();

    void on_btnBackMain_clicked();

private:
    Ui::databaseview *ui;
};

#endif // DATABASEVIEW_H
