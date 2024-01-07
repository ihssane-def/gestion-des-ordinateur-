#ifndef AJOUTLOGICIEL_H
#define AJOUTLOGICIEL_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include<QFileInfo>
#include <QMessageBox>

namespace Ui {
class AJOUTLOGICIEL;
}

class AJOUTLOGICIEL : public QMainWindow
{
    Q_OBJECT

public:
    explicit AJOUTLOGICIEL(QWidget *parent = nullptr);
    ~AJOUTLOGICIEL();

private:
    Ui::AJOUTLOGICIEL *ui;
    QSqlDatabase DB_Connection;
};

#endif // AJOUTLOGICIEL_H
