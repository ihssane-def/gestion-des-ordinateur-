#include "modif_supp.h"
#include "ui_modif_supp.h"

modif_supp::modif_supp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modif_supp)
{
    ui->setupUi(this);
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("ajoueordinateur.db");

    if(DB_Connection.open())
    {
        qDebug() << "Database connected";
    }
    else
    {
        qDebug() << "Database is not connected";
        qDebug() << "Error" << DB_Connection.lastError();
    }

}

modif_supp::~modif_supp()
{
    delete ui;
}

void modif_supp::on_pushButton_modif_clicked()
{
    if (!DB_Connection.isOpen())
    {
        qDebug() << " Database not open!";
        return;
    }
    QSqlDatabase::database().transaction();

    QString ID=ui->lineEdit->text();

    QString Couleur =ui->lineEdit_3->text();
    QString Processeur =ui->lineEdit_4->text();
    QString status =ui->comboBox->currentText();
    QString departementAttribue =ui->comboBox_2->currentText();

    QSqlQuery QueryUpdateData(DB_Connection);
    QueryUpdateData.prepare("UPDATE ordinateur SET  Couleur=:Couleur, Processeur=:Processeur, status=:status, departementAttribue=:departementAttribue WHERE ID=:ID");
    QueryUpdateData.bindValue(":ID",ID);

    QueryUpdateData.bindValue(":Couleur",Couleur);
    QueryUpdateData.bindValue(":Processeur",Processeur);
    QueryUpdateData.bindValue(":status",status);
    QueryUpdateData.bindValue(":departementAttribue",departementAttribue);

    if(QueryUpdateData.exec()) {
        qDebug() << "ordinateur Modifier--";

    }else{

        qDebug() << "erreur modification--";
        qDebug() << "Error" << QueryUpdateData.lastError().text();
    }

    QSqlDatabase::database().commit();

}

void modif_supp::on_pushButton_supp_clicked()
{
    if (!DB_Connection.isOpen())
    {
        qDebug() << " Database not open!";
        return;
    }
    QString ID=ui->lineEdit->text();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryDeleteData(DB_Connection);
    QueryDeleteData.prepare("DELETE FROM ordinateur WHERE ID=:ID");
    QueryDeleteData.bindValue(":ID",ID);

    if(QueryDeleteData.exec()) {
        qDebug() << "ordinateur supprimer--";

    }else{
        qDebug() << "erreur suppretion--";
        qDebug() << "Error" << QueryDeleteData.lastError().text();
    }

    QSqlDatabase::database().commit();
}
