#include "MTreeNode.h"

MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_parent = parent;
	m_children = new MTreeNode* [4];
	m_i = 0;
	m_j = 0;
	m_distance = 0;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	auto start = new MTreeNode(nullptr);
	start->m_i = i;
	start->m_j = j;
	return start;
}

int MTreeNode::i() const
{
	return m_i;
}

int MTreeNode::j() const
{
	return m_j;
}

const MTreeNode* MTreeNode::parent() const
{
	return m_parent;
}

MTreeNode* MTreeNode::child(int i) const
{
	return m_children[i];
}

int MTreeNode::distance() const
{
	return m_distance;
}

int MTreeNode::childCount() const
{
	return m_childCount;
}

bool MTreeNode::addChild(int i, int j)
{
	m_children[m_childCount] = new MTreeNode(this);
	m_children[m_childCount]->m_i = i;
	m_children[m_childCount]->m_j = j;
	m_children[m_childCount]->m_distance = 1 + this->m_distance;
	m_children[m_childCount]->m_parent = this;
	m_childCount += 1;
	return this->m_children[m_childCount - 1];
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
	for (int k = 0; k < this->childCount(); k++)
		if (this->m_children[i]->m_i == i && this->m_children[i]->m_j == j)
			return this->m_children[i];
	return nullptr;
}