#include "treeitem.h"

TreeItem::TreeItem(QString newId)
    : m_id(newId)
{
}

TreeItem::~TreeItem()
{
    while (m_children.count()) {
        /* This will cause children to delete their children and so on. */
        delete m_children.takeFirst();
    }
}

QString TreeItem::id() const
{
    return m_id;
}

TreeItem* TreeItem::parent() const
{
    return m_parent;
}

void TreeItem::setParent(TreeItem *newParent)
{
    m_parent = newParent;
}

int TreeItem::rowInParent() const
{
    return m_row;
}

void TreeItem::setRow(int row)
{
    m_row = row;
}

void TreeItem::addChild(TreeItem *newChild)
{
    /* Update the child with the knowledge of its position in the hierarchy. */
    newChild->setParent(this);
    newChild->setRow(m_children.count());
    m_children.append(newChild);
}

int TreeItem::numOfChildren() const
{
    return m_children.count();
}

TreeItem* TreeItem::childAt(int index) const
{
    return m_children.at(index);
}
