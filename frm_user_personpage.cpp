#include "frm_user_personpage.h"
#include "ui_frm_user_personpage.h"

frm_user_personpage::frm_user_personpage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::frm_user_personpage)
{
    ui->setupUi(this);
    QPixmap pix(":/img/arrow.png");
    ui->touxiang->setPixmap(pix);
    ui->touxiang->setScaledContents(true);  // 图片自适应 QLabel 大小
}

frm_user_personpage::~frm_user_personpage()
{
    delete ui;
}

void frm_user_personpage::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

