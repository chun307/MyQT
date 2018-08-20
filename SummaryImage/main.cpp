#include <QApplication>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString SOURCEDIR = "D:/BMPSOURCE/";
    QString DESTDIR = "D:/BMPDEST/";
    QString  DestBMPName;
    QImage SourceBMP;

    QDir DirMother(SOURCEDIR);
    int BMPCount = 0;//图片名称自增

    QStringList strlist = DirMother.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    qDebug()<<strlist.count();//有多少子文件夹

    for(int i = 0; i < strlist.count(); i++){
        QDir DirChild(SOURCEDIR + strlist.at(i));
        QStringList strlist1 = DirChild.entryList(QDir::Files);
//        qDebug()<<strlist1.count();//每个子文件夹有多少个文件

        for(int j = 0; j < strlist1.count(); j++){
//            qDebug()<<strlist1.count();
//            qDebug()<<strlist1;
            QFileInfo file_info = strlist1.at(j);
            if(QString::compare(file_info.suffix(), QString("BMP"), Qt::CaseInsensitive) == 0){//是否是指定格式文件
                BMPCount++;
                SourceBMP.load(SOURCEDIR + strlist.at(i) + "/" + strlist1.at(j));
//                qDebug()<<SOURCEDIR + "/" + strlist.at(i) + "/" + strlist1.at(j);
                DestBMPName = DESTDIR + QString("%1.BMP").arg(BMPCount);
//                qDebug()<<DestBMPName;
                SourceBMP.save(DestBMPName);
            }
        }
    }
    return a.exec();
}
