// Emmanuel Isidahomen
/*
*************************************************************************************************
Your task is to report on the visit order of the nodes for the three possible btree traversals.***
Visit order is an integer that indicates the ordering of the nodes in the traversal,*************
e.g. the first node traversed has traversal order 1, the second 2, etc.**************************
*************************************************************************************************
*/
# include <iostream> // Input and Output
# include <queue>    // FIFO
# include <string>   // Ordered sequence of characters
# include <cstdlib>  // Searching, sorting and converting
using namespace std; // Namespace
class node
{
public:
	int info;
	// pointers to link the nodes to other nodes in the 
	node *left;  // left node
	node *right; // right node
	bool operator < (node const &obj) 
	{
		if (info < obj.info)
			return 1;
		else
			return 0;
	}
// we going to use this to find the Bbtree elements later on after we have gotten the node numbers
}*leaf;
int e = 0;
int m = 0;
int a = 0;
class BST
{
public:
	void insert(node *, node *);
	void preorder(node *, int pr[]);
	void inorder(node *, int in[]);
	void postorder(node *, int po[]);
	BST()
	{
		leaf = NULL;
	}
};
int find(int arr[], int codekey)
{
	int o = 0;
	for (int q = 0; q<11; q++)
	{
		if (arr[q] == codekey)
			o = q;
	}
	return o + 1;
}
int main()
{
	int meanselection;
	int id_num; // will contain the id_num and the value of the
	BST bst;
	node *temp;
	int btree_array[] = { 50,30,20,15,25,22,29,35,60,55,65 }; // 11 on the array.
	// This are the 1 represting the 11 arrays 
	int in[] = { 1,1,1,1,1,1,1,1,1,1,1 }; // 11 in total
	int pr[] = { 1,1,1,1,1,1,1,1,1,1,1 }; // 11 in total 
	int po[] = { 1,1,1,1,1,1,1,1,1,1,1 }; // 11 in total
	for (int q = 0; q<11; q++)
	{
		temp = new node;
		temp->info = btree_array[q];
		bst.insert(leaf, temp);
	}
	bst.inorder(leaf, in);
	bst.preorder(leaf, pr);
	bst.postorder(leaf, po);
	for (int i = 0; i<11; i++)
	{
		cout << " We are going to find the node number for these :-" << endl;
		cout << "*************************************************************" << endl;
		cout << " Node_Idnumber=" << " " << i << endl;
		cout << "*************************************************************" << endl;
		cout << " Preorder___visit order = " << find(pr, btree_array[i]) << endl;
		cout << "*************************************************************" << endl;
		cout << " Postorder__visit order = " << find(po, btree_array[i]) << endl;
		cout << "*************************************************************" << endl;
		cout << " Inorder____visit order = " << find(in, btree_array[i]) << endl;
		cout << "*************************************************************" << endl;
		cout << " Node_______value is  = " << btree_array[i] << endl << endl;
	}
	cout << "**********************" << endl;
	cout << "End_Node_findings";
	system("PAUSE"); // pausing the program to display our output.
}
//Finding the Elements in the btree
void BST::insert(node *btree, node *newnode)
{
	if (leaf == NULL)
	{
		leaf = new node;
		leaf->info = newnode->info;
		leaf->left = NULL;
		leaf->right = NULL;
		return;
	}
	if ((*btree) < (*newnode))
	{
		if (btree->right != NULL)
		{
			insert(btree->right, newnode);
		}
		else
		{
			btree->right = newnode;
			(btree->right)->left = NULL;
			(btree->right)->right = NULL;
			return;
		}
	}
	else
	{
		if (btree->left != NULL)
		{
			insert(btree->left, newnode);
		}
		else
		{
			btree->left = newnode;
			(btree->left)->left = NULL;
			(btree->left)->right = NULL;
			return;
		}
	}
}
//preorder Traversal 

void BST::preorder(node *ptr, int pr[])
{
	if (leaf == NULL)
	{
		cout << "btree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		pr[e] = ptr->info;
		e++;
		preorder(ptr->left, pr);
		preorder(ptr->right, pr);
	}
}
//InOrder Traversal
void BST::inorder(node *ptr, int in[])
{
	if (leaf == NULL)
	{
		cout << " This btree is Empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inorder(ptr->left, in);
		in[m] = ptr->info;
		m++;
		inorder(ptr->right, in);
	}
}
//Postorder Traversal
void BST::postorder(node *ptr, int po[])
{
	if (leaf == NULL)
	{
		cout << " This btree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		postorder(ptr->left, po);
		postorder(ptr->right, po);
		po[a] = ptr->info;
		a++;
	}
}
