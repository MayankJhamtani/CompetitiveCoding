#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int node_val, TreeNode* node_left, TreeNode* node_right)
  {
    val=node_val;
    left = node_left;
    right = node_right;
  }
};

void PreOrderR(TreeNode* root)
{
  if(root==NULL)
  return;
  cout<<root->val<<" ";
  PreOrderR(root->left);
  PreOrderR(root->right);
  return;
}

void InOrderR(TreeNode* root)
{
  if(root==NULL)
  return;
  InOrderR(root->left);
  cout<<root->val<<" ";
  InOrderR(root->right);
  return;
}

void PostOrderR(TreeNode* root)
{
  if(root==NULL)
  return;
  PostOrderR(root->left);
  PostOrderR(root->right);
  cout<<root->val<<" ";
}

void PreOrder(TreeNode* root)
{
  if(root==NULL)
  return;
  stack<TreeNode*> S;
  S.push(root);
  while(S.empty()!=true)
  {
    //Process top.
    TreeNode* top = S.top();
    S.pop();
    cout<<top->val<<" ";
    if(top->right)
    S.push(top->right);
    if(top->left)
    S.push(top->left);
  }
  return;
}

void Inorder(TreeNode* root)
{
  // IDEA (PsuedoCode)
  //Push the root to stack.
  //if goRight is false, then go left. If left is empty, then make goRight true,.
  //If goRight is true, then process node, pop it, insert a right node, make goRight false again.
  if(root==NULL)
  return;
  bool goRight=false;
  stack<TreeNode*> S;
  S.push(root);
  while(S.empty()==false)
  {
    TreeNode* temp = S.top();
    if(goRight==true)
    {
      //Process node in temp, and pop()
      cout<<temp->val;
      S.pop();
      if(temp->right)
      {
        S.push(temp->right);
        goRight=false;
      }
    }
    else
    {
      if(temp->left)
      {
        S.push(temp->left);
      }
      else
      goRight=true;
    }
  }
  return;
}

void PostOrder(TreeNode* root)
{
  if(root==NULL)
  return;
  stack<TreeNode*> S;
  S.push(root);
  S.push(root);
  while(S.empty()==false)
  {
    TreeNode* top = S.top();
    S.pop();
    if(S.empty()==false && S.top()==top)  //We have encountered this node for the first time.
    {
      //Push children to stack twice if not NULL, first RIGHT.
      if(top->right)
      {
        S.push(top->right);
        S.push(top->right);
      }
      if(top->left)
      {
        S.push(top->left);
        S.push(top->left);
      }
    }
    else
    {
      //Process node.
      cout<<top->val<<" ";
    }
  }
}

void LevelOrder(TreeNode* root)
{
  if(root==NULL)
  return;
  queue<TreeNode*> Q;
  Q.push(root);
  while(Q.empty()==false)
  {
    int n = Q.size();
    for(int i=0;i<n;i++)
    {
      TreeNode* node = Q.front();
      cout<<node->val<<" ";
      Q.pop();
      if(node->left)
      Q.push(node->left);
      if(node->right)
      Q.push(node->right);
    }
  }
}
int main()
{
  //TreeConstruction.
  TreeNode* n1 = new TreeNode(1,NULL,NULL);
  TreeNode* n2 = new TreeNode(2,NULL,NULL);
  TreeNode* n3 = new TreeNode(3,NULL,NULL);
  n1->left = n2;
  n1->right = n3;

  TreeNode* n4 = new TreeNode(4,NULL,NULL);
  TreeNode* n5 = new TreeNode(5,NULL,NULL);
  TreeNode* n6 = new TreeNode(6,NULL,NULL);
  TreeNode* n7 = new TreeNode(7,NULL,NULL);
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;
  n3->right = n7;

  //NOTE All traversals work.
  // PreOrderR(n1);
  // cout<<endl;
  // InOrderR(n1);
  // cout<<endl;
  // PostOrderR(n1);
  // cout<<endl;
  //
  // PreOrder(n1);
  // cout<<endl;
  // InOrderR(n1);
  // cout<<endl;
  // PostOrder(n1);
  // cout<<endl;

  LevelOrder(n1);
  cout<<endl;
  //If we need zigzag level order traversal, then we can use vector and reversing vectors.
  //But better approach would be deque based.

  return 0;
}
