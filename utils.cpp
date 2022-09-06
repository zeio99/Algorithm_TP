#include "utils.h"

//Defined reservations
BST* setNode(int begin_t, int end_t, string name, BST* lchild, BST* rchild)
{
BST* n= new BST ;
n ->data.b_time = begin_t;
n ->data.e_time = end_t;
n ->data.name = name;
n ->lchild = lchild;
n ->rchild = rchild;
return n;
}

//Q4  the print function
void printT(BST* node)
{
  if (node != nullptr) 
  {
    printT(node->lchild);
    cout <<"the " << node->data.name <<" is begin at " <<node->data.b_time<< " and end at "<< node->data.e_time <<endl;
    printT(node->rchild);
  }
}

//Q5  the add function
BST* add(BST* nres, BST* node)
{
  if (node == nullptr )
  {
    node = new BST ;
    node->data = nres->data ;
    node ->lchild = nullptr;
    node ->rchild = nullptr;
  }
  else
    {
    if(node ->data.b_time > nres ->data.e_time)
    //If data is less than the value of the root node, insert it into the left subtree 
    {
      node ->lchild = add(nres,node ->lchild);
    }
    else if(node ->data.e_time < nres ->data.b_time)
    //If data is greater than the value of the root node, insert it into the right subtree
    {
      node ->rchild = add(nres,node ->rchild);
    }
    else
    cout << "You have entered an incorrect reservation, please check the information" << endl;
    }
  return node;
}

//Q6  the remove function
BST* remove(const Res& rnode, BST* node)
{
  if(node == nullptr)
  //When the tree is empty, NULL is returned directly
  {
    cout << "You have entered an incorrect reservation, please check the information" << endl;
    return node;
  }
  //If data is larger than the root node, go to the right subtree and delete data
  else if(rnode.b_time > node->data.e_time)
  {
    node -> rchild = remove(rnode, node -> rchild);
    return node;
  }
  //If data is smaller than the root node, go to the left subtree and delete data
  else if(rnode.e_time < node -> data.b_time)
  {
    node -> lchild = remove(rnode, node -> lchild);
    return node;
  }
  else if(rnode.b_time == node -> data.b_time && rnode.e_time == node -> data.e_time)
  {
    //When neither the left nor the right subtree is empty, the smallest of the right subtree is used to replace the root node
    if (node -> lchild != nullptr && node ->rchild != nullptr)
    {
      BST* temp = findmin(node -> rchild);
      node -> data = temp ->data;
      node -> rchild = remove(temp -> data, node -> rchild);
    }
    //When both the left and right subtrees are empty or when there is an empty
    else
    {
      BST* temp = node;
      if (node -> lchild == nullptr)
      {
        node = node -> rchild;
      }
      else if(node -> rchild == nullptr)
      {
        node = node -> lchild;
      }
      delete temp;
    }
    return node;
  }
  else
  {
    cout << "You have entered an incorrect reservation, please check the information" << endl;
    return node;
  }
  return 0;
}

//find min
BST* findmin(BST* node)
{
  BST* temp = node;
	while(temp)
  {
	//If the left subtree is empty, return the node 
		if(temp->lchild == nullptr)
    {
			return temp;
		}
    else
    {
  //Otherwise find the minimum value in the left subtree 
			temp = temp->lchild;
		} 
	}
  return temp;
}