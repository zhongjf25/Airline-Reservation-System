#ifndef FRM_UESER_RESERVETION_H
#define FRM_UESER_RESERVETION_H

#include <QMainWindow>

namespace Ui {
class frm_ueser_reservetion;
}

class frm_ueser_reservetion : public QMainWindow
{
    Q_OBJECT

public:
    explicit frm_ueser_reservetion(QWidget *parent = nullptr);
    ~frm_ueser_reservetion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::frm_ueser_reservetion *ui;
};

#endif // FRM_UESER_RESERVETION_H
