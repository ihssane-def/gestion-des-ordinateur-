#include "ajoutlogiciel.h"
#include "ui_ajoutlogiciel.h"

AJOUTLOGICIEL::AJOUTLOGICIEL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AJOUTLOGICIEL)
{
    ui->setupUi(this);
}

AJOUTLOGICIEL::~AJOUTLOGICIEL()
{
    delete ui;
}
