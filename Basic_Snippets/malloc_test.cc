#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode* next;
};
//Since we don't have a constructor for TreeNode, hence we have to use malloc.

int main()
{
    TreeNode* node1 = (TreeNode*)malloc(sizeof(TreeNode));
    node1->val = 1;
    TreeNode* node2 =(TreeNode*)malloc(sizeof(TreeNode));
    node1->next = node2;
    return 0;
}
