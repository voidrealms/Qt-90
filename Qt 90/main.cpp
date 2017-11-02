#include <QtCore/QCoreApplication>
#include <QtCore>
#include <QDebug>

void Write()
{
    QFile file("e:/test/myfile.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        stream << "Hello\r\n";
        stream << "World\r\n";

        stream.flush();
        file.close();
        qDebug() << "File Written";
    }
}

void Read()
{
    QFile file("e:/test/myfile.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        QString line;
        do
        {
            line = stream.readLine();
            qDebug() << line;
        }while(!line.isNull());

        file.close();
        qDebug() << "File Read";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Write();
    Read();

    return a.exec();
}
