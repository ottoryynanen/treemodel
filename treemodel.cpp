#include "treemodel.h"
#include "treeitem.h"
#include <QDebug>

TreeModel::TreeModel(QObject* parent)
    : QAbstractItemModel(parent)
{
    m_root = new TreeItem("Invisible");
    TreeItem* level1item1 = new TreeItem("First item at first level");
    TreeItem* level1item2 = new TreeItem("Second item at first level");
    TreeItem* level1item3 = new TreeItem("Third item at first level");
    m_root->addChild(level1item1);
    m_root->addChild(level1item2);
    m_root->addChild(level1item3);
    level1item1->addChild(new TreeItem("First child of first item"));
    level1item1->addChild(new TreeItem("Second child of first item"));
    level1item1->addChild(new TreeItem("Third child of first item"));
    level1item2->addChild(new TreeItem("First child of second item"));
    level1item2->addChild(new TreeItem("Second child of second item"));
    TreeItem* level2item3 = new TreeItem("Third child of second item");
    level1item2->addChild(level2item3);
    level1item3->addChild(new TreeItem("First child of third item"));
    level1item3->addChild(new TreeItem("Second child of third item"));
    level1item3->addChild(new TreeItem("Third child of third item"));
    level2item3->addChild(new TreeItem("First child of third child of second item"));
    level2item3->addChild(new TreeItem("Second child of third child of second item"));
    level2item3->addChild(new TreeItem("Third child of third child of second item"));
}

TreeModel::~TreeModel()
{
    delete m_root;
}

QModelIndex TreeModel::index(int row, int column,
                          const QModelIndex &parent) const
{
    if (row >= 0 && column >= 0 && column < 1) {
        TreeItem* parentItem = getTreeItem(parent);
        if (parentItem->numOfChildren() > row) {
            return createIndex(row, column, parentItem->childAt(row));
        }
    }
    qWarning() << "No matching item found for row" << row << "column" << column;
    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &child) const
{
    TreeItem* item = getTreeItem(child);
    if (item->parent()) {
        return indexOf(item->parent());
    } else {
        qWarning() << "Asking for a parent of root item!";
        return QModelIndex();
    }
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem* parentItem = getTreeItem(parent);
    return parentItem->numOfChildren();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

bool TreeModel::hasChildren(const QModelIndex &parent) const
{
    TreeItem* parentItem = getTreeItem(parent);
    return parentItem->numOfChildren() > 0;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return getTreeItem(index)->id();
    } else {
        return QVariant();
    }
}

TreeItem* TreeModel::getTreeItem(const QModelIndex &indexToUse) const
{
    TreeItem* itemOfIndex;
    if (indexToUse == QModelIndex()) {
        itemOfIndex = m_root;
    } else {
        itemOfIndex = static_cast<TreeItem*>(indexToUse.internalPointer());
    }
    return itemOfIndex;
}

QModelIndex TreeModel::indexOf(TreeItem *item) const
{
    Q_ASSERT(item);
    if (item->parent()) {
        return createIndex(item->rowInParent(), 0, item);
    } else {
        /* Root item is invisible and has no index */
        return QModelIndex();
    }
}
