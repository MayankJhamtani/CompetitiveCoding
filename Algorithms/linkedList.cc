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

Node* insert(Node* head, int val, int index)
{
  //Insert a node into the LL. If index=1, then the new element has to be the
  //head, and if index exceeds the size of LL, then return without modification.
  if(index==1)
  {
    Node* new_head = new Node(val);
    new_head->next = head;
    return new_head;
  }
  else
  {
    Node* new_head = head;
    while(index!=2)
    {
      head=head->next;
      index--;
      if(head==NULL)
      {
        cout<<"Index Overshoots"<<endl;
        return new_head;
      }
    }
    Node* temp = new Node(val);
    temp->next = head->next;
    head->next = temp;
    return new_head;
  }
}
Node* deleteLastNode(Node* head)
{
  if(head->next==NULL)
  return NULL;
  else if(head->next->next==NULL)
  {

    head->next = NULL;
    return head;
  }
  else
  {
    Node* new_head = head;
    while(head->next->next!=NULL)
    {
      head=head->next;
    }
    head->next=NULL;
    return new_head;
  }
}

Node* deleteAtIndex(Node* head, int index)
{
  //If index is 1, then head is deleted, and so on.
  //If index is larger the LL size, then return unmodified LL.
  if(index==1)
  return head->next;
  else
  {
    Node* new_head = head;
    while(index!=2)
    {
      head=head->next;
      index--;
      if(head->next==NULL)  //Because we are using head->next->next after loop.
      {
        cout<<"Index Overshoots"<<endl;
        return new_head;
      }
    }
    head->next = head->next->next;
    return new_head;
  }
}
int main()
{
  Node* head;
  head = append(NULL,1);
  head = append(head,3);
  display(head);

  head = insert(head,0,1);
  display(head);
  head = insert(head,2,3);
  display(head);
  head = insert(head,4,6);
  display(head);
  head = insert(head,4,5);
  display(head);

  //deleteLastNode() works fine.
  head = deleteLastNode(head);
  display(head);

  //deleteAtIndex works fine.
  head = deleteAtIndex(head,5);
  display(head);
  head = deleteAtIndex(head,1);
  display(head);
  head = deleteAtIndex(head,3);
  display(head);

}
