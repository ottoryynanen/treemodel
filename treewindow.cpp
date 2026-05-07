// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

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

