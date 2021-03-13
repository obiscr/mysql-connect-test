# mysql-connect-test

在QT中测试Mysql驱动的工具

macOS 下 QT 的安装可以[参考这里](https://obiscr.com/posts/macos-qt-mysql/)



# 在QT中进行测试


### 在线（推荐）

可以直接克隆github的测试工程

```bash
git clone https://github.com/obiscr/mysql-connect-test.git
```

然后使用QT打开工程，打开后如图所示

![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-10.png)

替换代码中默认的数据库密码之后，点击运行，查看运行结果。出现链接成功则配置完成。

### 离线

如果网络不方便，也可以手动创建测试工程。

1. 打开QT，点击 <b>New Project</b>

![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-1.png)

2. 选择 <b>QT Widgets Application</b>  然后选择 <b>Choose</b>

![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-2.png)

3. 名称和创建路径可以随便写，点击 <b>继续</b>

   ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-3.png)

4. 默认配置，不用动，点击 <b>继续</b>

   ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-4.png)

5. 默认配置，不用动，点击 <b>继续</b>

   ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-5.png)

6. 默认配置，不用动，点击 <b>继续</b>

   ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-6.png)

7. 版本控制选不选都可以，点击 <b>继续</b>

   ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-7.png)

8. 创建完成之后的默认的工程目录如下

   ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-8.png)

9. 首先修改一下 pro 文件的引入的库，第一行添加 `  sql `（注意：gui 和 sql 之间需要添加空格）

   ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-9.png)

10. 然后把 <b>main.cpp</b> 中默认生成的内容删掉，用下面的代码替换（注意数据库密码需要替换成自己的）

    ```c++
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
    ```

    替换完成之后如下图。然后点击运行，查看运行结果。出现连接成功则配置完成。

    ![image-20210306155815932](https://obiscr.oss-cn-hongkong.aliyuncs.com/res/macOS-QT-Mysql/new-project-10.png)