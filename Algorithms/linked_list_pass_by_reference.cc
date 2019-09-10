#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  Node* next;
  Node(int v)
  {
    val = v;
  }
};

void display(Node* head)
{
  cout<<"Display LL: ";
  while(head!=NULL)
  {
    cout<<head->val<<" ";
    head=head->next;
  }
  cout<<endl;
  return;
}

Node* append(Node* head, int val)
{
  //This function takes the head to a linked list, appends the val as a new
  //node, and returns the head to the linked list.
  if(head==NULL)
  {
    Node* temp = new Node(val);
    head = temp;
    return head;
  }
  else
  {
    Node* new_head = head;
    while(head->next!=NULL)
    {
      head=head->next;
    }
    Node* temp = new Node(val);
    head->next = temp;
    return new_head;
  }
}

void shiftNode(Node* head)
{
  head=head->next;
}

void shiftNodeByRef(Node* &head)
{
  head=head->next;
}

void shiftNodeByRef2(Node** head)
{
  *head=(*head)->next;
}
int main()
{
  Node* head;
  head = append(NULL,1);
  head = append(head,2);
  head = append(head,3);
  head = append(head,4);
  display(head);

  //Call shiftNode and then display(); This doesn't affect head here.
  shiftNode(head);
  display(head);

  //shiftNodeByRef. This effects the head.
  shiftNodeByRef(head);
  display(head);

  //shiftNodeByRef2
  shiftNodeByRef2(&head);
  display(head);
}
