#include "treewindow.h"
#include "ui_treewindow.h"

TreeWindow::TreeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TreeWindow)
{
    ui->setupUi(this);
    model = new TreeModel(this);
    ui->treeView->setModel(model);
}

TreeWindow::~TreeWindow()
{
    delete ui;
}

