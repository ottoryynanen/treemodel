#ifndef TREEWINDOW_H
#define TREEWINDOW_H

#include <QMainWindow>
#include "treemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TreeWindow; }
QT_END_NAMESPACE

class TreeWindow : public QMainWindow
{
    Q_OBJECT

public:
    TreeWindow(QWidget *parent = nullptr);
    ~TreeWindow();

private:
    TreeModel *model;
    Ui::TreeWindow *ui;
};
#endif // TREEWINDOW_H
