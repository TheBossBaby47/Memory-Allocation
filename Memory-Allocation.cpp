#include <iostream>
#include <vector>

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

	void InOrderSort(Node* InTree, std::vector<int> *OutSortedArray)
	{
		if (InTree->Left != NULL)
			InOrderSort(InTree->Left, OutSortedArray);

		OutSortedArray->push_back(InTree->Value);

		if (InTree->Right != NULL)
			InOrderSort(InTree->Right, OutSortedArray);
	}

	int MostCommonInteger(Node* InTree)
	{
		std::vector<int> TempSortedBST;
	
		InOrderSort(InTree, &TempSortedBST);
		
		int TempMostCommonInteger = 0;
		int TempCount = 0;
		int TempMaxCount = 0;

		for (int i = 1; i < TempSortedBST.size(); i++)
		{
			if (TempSortedBST[i - 1] != TempSortedBST[i])
			{
				TempCount = 0;
			}

			if (TempMaxCount < ++TempCount)
			{
				TempMaxCount = TempCount;
				TempMostCommonInteger = TempSortedBST[i];
			}
		}

		return TempMostCommonInteger;
	}

	int LargestInteger(Node* InTree)
	{
		if (InTree->Right == NULL)
			return InTree->Value;
		LargestInteger(InTree->Right);
	}

	int SumOfAllIntegers(Node* InTree)
	{
		if (InTree == NULL) return 0;

		return InTree->Value + SumOfAllIntegers(InTree->Left) + SumOfAllIntegers(InTree->Right) ;
	}
}


int main()
{
	std::srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		NCL::InsertInteger(&NCL::Root, std::rand()%10);
	}

	NCL::PrintTree(NCL::Root);

	std::cout << "\nLargest integer in the tree is : " << NCL::LargestInteger(NCL::Root);
	std::cout << "\nSum of all integer is : " << NCL::SumOfAllIntegers(NCL::Root);
	std::cout << "\nMost common integer is : " << NCL::MostCommonInteger(NCL::Root);
	return 0;
}