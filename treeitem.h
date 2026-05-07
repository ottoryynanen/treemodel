// Copyright (C) 2026 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef TREEITEM_H
#define TREEITEM_H
#include <QVector>

class TreeItem
{
public:
    TreeItem(QString newId);
    ~TreeItem();
    QString id() const;
    TreeItem* parent() const;
    void setParent(TreeItem* newParent);
    int rowInParent() const;
    void setRow(int row);
    void addChild(TreeItem* newChild);
    int numOfChildren() const;
    TreeItem* childAt(int index) const;
private:
    QVector<TreeItem*> m_children;
    TreeItem* m_parent = nullptr;
    QString m_id;
    /* m_row is the "row of this item under the parent index"
     * i.e. "index of this item in the m_children of the parent".
     * It's stored purely for performance, it could equally be fetched via
     * m_parent->m_children.indexOf(this);
     */
    int m_row;
};

#endif // TREEITEM_H
