#include "frm_login.h"
#include "ui_frm_login.h"
#include "frm_admin.h"
#include "frm_register.h"
#include "frm_user.h"



Frm_Login::Frm_Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Frm_Login)
{
    ui->setupUi(this);
    setWindowTitle("登录");

    // 加载背景图片
    QPixmap originalBkgnd(":/img/back.jpg"); // 图片资源的路径，根据实际情况调整

    // 将 QPixmap 转换为 QImage，以便进行亮度调整
    QImage image = originalBkgnd.toImage();

    // 调整亮度：增加亮度可以通过增加每个像素的 RGB 值来实现
    int brightnessFactor = 1000; // 增加的亮度（范围可以根据需求调整）

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QColor color = image.pixelColor(x, y);
            int r = qMin(color.red() + brightnessFactor, 255);
            int g = qMin(color.green() + brightnessFactor, 255);
            int b = qMin(color.blue() + brightnessFactor, 255);
            image.setPixelColor(x, y, QColor(r, g, b));
        }
    }

    // 将调整过亮度的 QImage 转换回 QPixmap
    QPixmap bkgnd = QPixmap::fromImage(image);

    // QPixmap bkgnd(originalBkgnd.size());
    bkgnd.fill(Qt::transparent); // 使用透明填充初始化新的 QPixmap
    QPainter p(&bkgnd);
    p.setOpacity(0.9); // 设置透明度为80%
    p.drawPixmap(0, 0, originalBkgnd);
    p.end();

    // 设置背景图片
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    //连接数据库
    db = QSqlDatabase::addDatabase("QODBC");   //加载ODBC数据库驱动


    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("airline_database");

    if(db.open()) {
        qDebug() << "连接数据库成功";
        QString SET_SATYMODE = "SET SQL_SAFE_UPDATES = 0;";

        QSqlQuery q;
        if(q.exec(SET_SATYMODE)) {
            qDebug() << "安全模式设置成功";
        }

    }
    else {
        QMessageBox::warning(this, "连接提示", "数据库连接失败，部分功能可能无法使用");
    }

    QSqlQuery q;
    if(!q.exec("select Username from PrevInfo where ID='1'")) {
        qDebug() << "历史用户名获取失败";
    }
    q.next();
    ui->txt_user->setText(q.value(0).toString());   //设置为上次启动的用户名

    if(!q.exec("select UserPwd from PrevInfo where ID='1'")) {
        qDebug() << "历史密码获取失败";
    }
    q.next();
    ui->txt_pwd->setText(q.value(0).toString());    //设置为上次密码 若未记住密码会设置为空

    if(!q.exec("select is_rem from PrevInfo where ID='1'")) {
        qDebug() << "记住密码状态获取失败";
    }
    q.next();
    if(q.value(0).toBool()) {
        ui->chk_remb_pwd->setCheckState(Qt::CheckState::Checked);   //设置记住密码状态
    }

    QPushButton *to_manager = ui->btn_register; // 获取 UI 中的按钮
    to_manager->setStyleSheet("QPushButton {"
                              "border: none;"          // 去除边框
                              "background: transparent;" // 背景透明
                              "color: blue;"  // 设置文字颜色
                              "text-decoration: underline;" // 添加下划线
                              "}"
                              "QPushButton:hover {"
                              "color: red;"  // 鼠标悬停时文字颜色
                              "}");


}

Frm_Login::~Frm_Login()
{
    QSqlQuery q;
    q.prepare("update PrevInfo set Username=:username where ID='1'");
    q.bindValue(":username", ui->txt_user->text());
    if(!q.exec()) {
        qDebug() << "退出程序时用户名写入失败";
    }


    QString pwd;
    if(ui->chk_remb_pwd->isChecked()) {
        pwd = ui->txt_pwd->text();
        if(!q.exec("update PrevInfo set is_rem=1 where ID='1'")) {
            qDebug() << "退出程序时记住密码状态更新失败";
        }
    } else {
        pwd = "";
        if(!q.exec("update PrevInfo set is_rem=0 where ID='1'")) {
            qDebug() << "退出程序时记住密码状态更新失败";
        }
    }

    q.prepare("update PrevInfo set UserPwd=:password where ID='1'");
    q.bindValue(":password", pwd);
    if(!q.exec()) {
        qDebug() << "退出程序时更新密码失败";
    }

    delete ui;
}

void Frm_Login::on_btn_Login_clicked()  //登录
{
    QString username = ui->txt_user->text();
    QString pwd = ui->txt_pwd->text();

    if(username == "") {
        QMessageBox::warning(this, "登录错误", "请输入用户名");
        return;
    } else if(pwd == "") {
        QMessageBox::warning(this, "登录错误", "请输入密码");
        return;
    }

    if(username == "admin" && pwd == "admin") {     //管理员登录

        if(!ui->chk_remb_pwd->isChecked()) {    //检查是否记住密码
            ui->txt_pwd->clear();
        }
        this->hide();
        Frm_Admin *frm_admin = new Frm_Admin(nullptr, this);
        frm_admin->show();
        return;
    }

    QSqlQuery q;
    q.prepare("select count(*) from UserInfo where Username=:username and UserPwd=:password");

    q.bindValue(":username", username);
    q.bindValue(":password", pwd);
    if(q.exec()) {
        q.next();
        int cnt = q.value(0).toInt();
        if(cnt == 0) {
            QMessageBox::warning(this, "登陆失败", "用户名或密码错误");
            return;
        }

        //登陆成功
        if(!ui->chk_remb_pwd->isChecked()) {    //检查是否记住密码
            ui->txt_pwd->clear();
        }

        this->hide();
        Frm_User *frm_user = new Frm_User(this, this, username);
        frm_user->show();
        return;
    }
    else {
        QMessageBox::warning(this, "登陆失败", "未知错误");
    }
}


void Frm_Login::on_btn_Exit_clicked()
{
    QApplication::quit();
}


void Frm_Login::on_btn_register_clicked()
{
    this->hide();
    Frm_Register *frm_register = new Frm_Register(nullptr, this);
    frm_register->show();

    // qDebug() << "registered";
}
