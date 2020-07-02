/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* temp = new TreeNode(a_nValue);
	TreeNode* comp = m_pRoot;
	if (m_pRoot == nullptr)
	{
		m_pRoot = temp;
	}
	while (comp != nullptr)
	{
		if (temp->GetData() > comp->GetData())
		{
			if (comp->GetRight() != nullptr)
			{
				comp = comp->GetRight();
			}
			else
			{
				comp->SetRight(temp);
				return;
			}
				
		}
		else if (temp->GetData() < comp->GetData())
		{
			if (comp->GetLeft() != nullptr)
			{
				comp = comp->GetLeft();
			}
			else
			{
				comp->SetLeft(temp);
				return;
			}
		}
		else
		{
			return;
		}
	}
}
void BinaryTree::Insert(TreeNode* Node)
{
	TreeNode* temp = Node;
	TreeNode* comp = m_pRoot;
	if (m_pRoot == nullptr)
	{
		m_pRoot = temp;
	}
	while (comp != nullptr)
	{
		if (temp->GetData() > comp->GetData())
		{
			if (comp->GetRight() != nullptr)
			{
				comp = comp->GetRight();
			}
			else
			{
				comp->SetRight(temp);
				return;
			}

		}
		else if (temp->GetData() < comp->GetData())
		{
			if (comp->GetLeft() != nullptr)
			{
				comp = comp->GetLeft();
			}
			else
			{
				comp->SetLeft(temp);
				return;
			}
		}
		else
		{
			return;
		}
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{


	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	TreeNode* temp = new TreeNode(a_nValue);
	TreeNode* comp = m_pRoot;
	TreeNode* p_comp = comp;
	TreeNode* temp1;
	TreeNode* temp2;
	bool dir = true; // true = right, false = left
	if (m_pRoot == nullptr)
	{
		m_pRoot = temp;
	}
	while (comp != nullptr)
	{
		if (temp->GetData() > comp->GetData())
		{
			if (comp->GetRight() != nullptr)
			{
				p_comp = comp;
				comp = comp->GetRight();
				dir = true;
			}
			else
			{
				return;
			}

		}
		else if (temp->GetData() < comp->GetData())
		{
			if (comp->GetLeft() != nullptr)
			{
				p_comp = comp;
				comp = comp->GetLeft();
				dir = false;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (p_comp != nullptr)
			{
				if (dir == true)
					p_comp->SetRight(nullptr);
				else
					p_comp->SetLeft(nullptr);
			}
			temp1 = comp->GetRight();
			temp2 = comp->GetLeft();
			delete comp;
			if (temp1 != nullptr)
			{
				Insert(temp1);
			}
			if (temp2 != nullptr)
			{
				Insert(temp2);
			}
			return;
		}
	}
}
//TreeNode* left = NULL;
//TreeNode* right = NULL;
//if (m_left == nullptr && m_right == nullptr)
//{
//	delete this;
//}
//if (m_left != nullptr)
//{
//	left = m_left;
//	while (left->GetRight() != nullptr)
//	{
//		left = left->GetRight();
//	}
//}
//if (m_right != nullptr)
//{
//	right = m_right;
//	while (right->GetLeft() != nullptr)
//	{
//		right = right->GetLeft();
//	}
//}
//if (left != NULL && right != NULL)
//{
//	int leftDif = this->GetData() - left->GetData();
//	int rightDif = right->GetData() - this->GetData();
//	if (leftDif > rightDif)
//	{
//		this->SetData(left->GetData());
//		delete left;
//	}
//	else
//	{
//		this->SetData(right->GetData());
//		delete right;
//	}
//}

//if (comp->GetLeft == nullptr && comp->GetRight == nullptr)
//{
//	// delete from parents
//	if (p_comp != nullptr)
//	{
//		if (dir = true)
//			p_comp->SetRight(nullptr);
//		else
//			p_comp->SetLeft(nullptr);
//	}
//	// delete comp
//	comp->~TreeNode();
//}
//else if (comp->GetLeft != nullptr || comp->GetRight != nullptr)
//{
//	// delete from parents
//	if (p_comp != nullptr)
//	{
//		if (p_comp->GetLeft == comp)
//		{
//			p_comp->SetLeft(nullptr);
//		}
//		else
//		{
//			p_comp->SetRight(nullptr);
//		}
//	}
//	// get replacement
//
//	// delete comp
//
//}
void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{
	std::cout << pNode->GetData() << std::endl;
	PrintOrderedRecurse(pNode->GetLeft());
	PrintOrderedRecurse(pNode->GetLeft());
}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}