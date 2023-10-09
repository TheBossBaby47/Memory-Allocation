#include <iostream>

namespace NCL
{
	struct Node
	{
		int Value;
		Node* Left = NULL;
		Node* Right = NULL;
	};

	Node* CreateNode(const int InValue)
	{
		Node* OutNode = new Node;
		OutNode->Value = InValue;
		OutNode->Left = NULL;
		OutNode->Right = NULL;
		return OutNode;
	}

	Node* Root = NULL;

	void InsertInteger(Node** InTree, int InValue)
	{
		if (*InTree == NULL)
		{
			*InTree = CreateNode(InValue);
			return;
		}

		if ((*InTree)->Value < InValue)
		{
			InsertInteger(&(*InTree)->Left, InValue);
		}
		else
		{
			InsertInteger(&(*InTree)->Right, InValue);
		}
	}

	void PrintTree(Node* InTree)
	{
		std::cout << InTree->Value << ',';
		if (InTree->Left != NULL)
			PrintTree(InTree->Left);

		if (InTree->Right != NULL)
			PrintTree(InTree->Right);
	}

	void TerminateTree(Node* InTree)
	{
		if (InTree->Left != NULL)
			TerminateTree(InTree->Left);

		if (InTree->Right != NULL)
			TerminateTree(InTree->Right);

		delete InTree;
		InTree = NULL;
	}

	int LargestInteger(Node* InTree)
	{
		if (InTree->Left == NULL)
			return InTree->Value;
		LargestInteger(InTree->Left);
	}
}


int main()
{
	std::srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		NCL::InsertInteger(&NCL::Root, std::rand()%100);
	}

	NCL::PrintTree(NCL::Root);

	std::cout << "\nLargest integer in the tree is : " << NCL::LargestInteger(NCL::Root);

	return 0;
}