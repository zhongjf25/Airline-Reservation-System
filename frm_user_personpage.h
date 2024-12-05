#ifndef FRM_USER_PERSONPAGE_H
#define FRM_USER_PERSONPAGE_H

#include <QMainWindow>

namespace Ui {
class frm_user_personpage;
}

class frm_user_personpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit frm_user_personpage(QWidget *parent = nullptr);
    ~frm_user_personpage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::frm_user_personpage *ui;
};

#endif // FRM_USER_PERSONPAGE_H
