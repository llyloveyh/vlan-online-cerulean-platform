#include "mainui.h"
#include "ui_mainui.h"
#include <QPainter>
#include <QListWidget>

MainUI::MainUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainUI)
{
    ui->setupUi(this);

    for(int i=0;i<25;i++)
    {
        QListWidgetItem *item=new QListWidgetItem("asdf",ui->roomListWidget);

    }
}

MainUI::~MainUI()
{
    delete ui;
}

/*void mainUI::paintEvent (QPaintEvent *event)
{
    QPainter painter(this);
    QRectF r = rect();
    QLinearGradient grad(0,0,width(),height());

    grad.setColorAt (1,QColor(0x4A,0x4D,0x47).darker ());
    grad.setColorAt (0.5,QColor(0x6A,0x6D,0x67));
    grad.setColorAt (0,QColor(0x6A,0x6F,0x70));
    QBrush brush(grad);


    painter.setRenderHint (QPainter::Antialiasing,true);
    painter.setPen(Qt::NoPen);
    painter.setBrush (brush);

    painter.drawRect (r);

}*/
