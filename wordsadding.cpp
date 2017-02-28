#include "wordsadding.h"
#include "ui_wordsadding.h"

WordsAdding::WordsAdding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WordsAdding)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Words");
}


void WordsAdding::getVal(QStringList &w, QStringList &t)
{
    w=ui->word_2->toPlainText().split("\n");
    t=ui->translate_2->toPlainText().split("\n");
}

WordsAdding::~WordsAdding()
{
    delete ui;
}
