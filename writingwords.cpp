#include "writingwords.h"
#include "ui_writingwords.h"


WritingWords::WritingWords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WritingWords)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Words");
}

WritingWords::~WritingWords()
{
    delete ui;
}
void WritingWords::getVal(QStringList &w, QStringList &t)
{
    w=ui->word->toPlainText().split("\n");
    t=ui->translate->toPlainText().split("\n");
}
