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
    int m_row;
};

#endif // TREEITEM_H
