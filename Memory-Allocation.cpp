#include <iostream>

namespace NCL
{
	struct Node
	{
		int Value;
		Node* Left = NULL;
		Node* Right = NULL;
	};

	Node* Root = NULL;

	Node* CreateNode(const int InValue)
	{
		Node* OutNode = new Node;
		OutNode->Value = InValue;
		OutNode->Left = NULL;
		OutNode->Right = NULL;
		return OutNode;
	}

	void InsertInteger(Node** InTree, int InValue)
	{
		if (*InTree == NULL)
		{
			*InTree = CreateNode(InValue);
			return;
		}
		
		if (InValue < (*InTree)->Value)
		{
			InsertInteger(&(*InTree)->Left, InValue);
			return;
		}

		InsertInteger(&(*InTree)->Right, InValue);
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

	int MostCommonInteger(Node* InTree)
	{
		return 0;
	}

	int LargestInteger(Node* InTree)
	{
		if (InTree->Right == NULL)
			return InTree->Value;
		LargestInteger(InTree->Right);
	}

	int SumOfAllIntegers(Node* InTree)
	{
		int OutSum = 0;
		return	OutSum;
	}
}


int main()
{
	std::srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		NCL::InsertInteger(&NCL::Root, std::rand()%100);
	}

	NCL::PrintTree(NCL::Root);

	std::cout << "\nLargest integer in the tree is : " << NCL::LargestInteger(NCL::Root);
	std::cout << "\nSum of all integer is : " << NCL::SumOfAllIntegers(NCL::Root);

	return 0;
}