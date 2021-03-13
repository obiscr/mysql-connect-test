#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
void connect_mysql()
{
       QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("127.0.0.1");     // 主机名(如果填写127.0.0.1不能连接，则改成 localhost)
       db.setPort(3306);                // 端口
       db.setDatabaseName("mysql");    // 数据库
       db.setUserName("root");          // 账号
       db.setPassword("root");    // 密码
       db.open();
       if(!db.open())
       {
           qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
           return ;
       }
       else
       {
            qDebug()<<"连接成功"<<"connect to mysql OK";
       }
       QSqlQuery query(db);
       query.exec("select * from user");
       qDebug() << "----- Data of mysql.user -----";
       while(query.next()){
           qDebug()<< "Host:" << query.value("Host").toString() << "User:" << query.value("user").toString();
       }
       exit(0);
}
int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);
    connect_mysql();
    return a.exec();
}
