#include <iostream>
#include <string>
using namespace std;

struct Res
{
  int b_time,e_time;
  string name;
};

struct BST 
{
  Res data;
  BST *lchild;
  BST *rchild;
};

BST* setNode(int begin_t, int end_t, string name, BST* lchild, BST* rchild);
BST* setNode1(int begin_t, int end_t, string name);
void printT(BST* node);
BST* add(BST* nres, BST* node);
BST* remove(const Res& rnode, BST* node);
BST* findmin(BST* node);