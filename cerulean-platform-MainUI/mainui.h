#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>

namespace Ui {
    class mainUI;
}

class MainUI : public QWidget
{
    Q_OBJECT

public:
    explicit MainUI(QWidget *parent = 0);
    ~MainUI();

    //void paintEvent(QPaintEvent *);

private:
    Ui::mainUI *ui;
};

#endif // MAINUI_H
