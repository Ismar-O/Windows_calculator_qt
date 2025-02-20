#include "mainwindow.h"
#include "../src/csvReader.h"
#include <QLabel>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLabel *lbl = new QLabel("test", &w);

    csvReader *myCsv = new csvReader;
    try{
        csvReader::csvResult res =  myCsv->loadCSV("csvFiles/skriven.csv");
        double db = myCsv->findValue(res,399,99);
        QString str = QString::number(db);
        lbl->setText(str);
    }
    catch (std::exception &e){
        lbl->setText(e.what());
        lbl->adjustSize();
    }
    lbl->show();


    w.show();
    return a.exec();
}
