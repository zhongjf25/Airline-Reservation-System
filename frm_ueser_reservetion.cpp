#include "frm_ueser_reservetion.h"
#include "ui_frm_ueser_reservetion.h"


frm_ueser_reservetion::frm_ueser_reservetion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::frm_ueser_reservetion)
{
    ui->setupUi(this);
    ui->threerank->setPixmap(QPixmap(":/img/fly.png"));
    ui->threerank->setScaledContents(true);  // 图片自适应 QLabel 大小


}

frm_ueser_reservetion::~frm_ueser_reservetion()
{
    delete ui;
}

void frm_ueser_reservetion::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

