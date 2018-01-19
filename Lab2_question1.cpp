#include<iostream>
using namespace std;

/*
 * */
class node
{ 
  public:
  int val;
  node* next;
  node();
  {
    val=0;
    next=NULL;
  }
};
/*
 * */
class SLL
{
  private:
		node* head;
		node* tail;
  int size;
  public:
  SLL()
  {
    head=NULL;
    tail=NULL;
    size=0;
  }
  void insertEnd(int data);
  void insertAt(int pos, int data);
  int deleteEnd();
  int deleteAt(int pos);
  int countItems();
  void display();
};
/*
 * */
void SLL::insertEnd(int data)
{
  node* temp1=new node;
  temp1->val=data;
  temp1->next=NULL;
  if(head==NULL)
  {
    head=temp1;
    tail=temp1;
  }
  else
  {
    tail->next=temp1;
    tail=temp1;
  }
  size++;
}
/*
 * */
void SLL::insertAt(int pos, int data)
{
  node *temp2=new node();
  temp2->val=data;
  temp2->next=NULL;
  node *traverse;
  traverse=head;
  if(pos==size+1)//If to be inserted at the end
  {
   insertEnd(data);
  }
  else if(pos==1)//If to be inserted at the beginning
  {
   temp->next=head;
   head=temp;
  }
  else if(pos>1 && pos<=size)//If to be inserted from second to the second last position
  {
   for(int i=1;i<pos;i++)
   {
     if(i==pos-1)
     {
       temp2->next=traverse->next;
       traverse=temp2;
     }
     else
       traverse=traverse->next;
   }
  }
  else//If pos exceeds size
  {
   cout<<"\n \nSORRY ! ! ! Linked List does not have that many elements";
  }
}
/*
 * */
int SLL::deleteEnd()
{
  if(head==NULL)
  { 
   cout<<"\n \n \nThe Linked List is empty";
   return 0;
  }
  node *tmp;
  tmp=head;
  while(tmp->next!=tail)
  {
    tmp=tmp->next;
  }
  tail=tmp;
  node *a;
  a=tmp->next; 
  return a->val;
  delete a;
}
/*
 * */
int SLL::deleteAt(int pos)
{
  node *traverse;
  traverse=head;
  if(pos==1)//If first element to be deleted
  {
   head=traverse->next;
   traverse->next==NULL;
   return traverse->val;
   delete traverse;
  }
  else if(pos>1 && pos<=size)//If  second to the last element to be deleted
  {
   for(int i=1;i<pos;i++)
   {
     if(i==pos-1)
     {
       node *a;
       a=traverse->next;
       traverse->next=a->next;
       a->next=NULL;
       return a->val;
       delete a;
     }
     else
       traverse=traverse->next;
   }
  }
  else//If pos exceeds size
  {
   cout<<"\n \nSORRY ! ! ! Linked List does not have that many elements";
   return 0;
  }
/*
 * */
}
int SLL::countItems()
{
  return size;
}
/*
 * */
void display()
{
  node *traverse;
  traverse=head;
  if(head!=NULL)
  {
   cout<<"\n \n \nThe elements in the linked list are: ";
   while(traverse!=NULL)
   {  
    cout<<traverse->val<<" -> ";
    traverse=traverse->next;  
   }
   cout<<"NULL";
  }
 
 else
  cout<<"\n \n \nThe Linked List is empty ! ! !";
}
/*
 * */
int main()
{
    SLL l1;
    for(int i=1;i<=8;i++)
    {
      l1.insertEnd(i+10);
    }
    l1.insertAt(5,25);
    int n=l1.deleteEnd();
    cout<<"\n \n"<<n<<" has been deleted from the end";
    n=l1.deleteAt(3);
    cout<<"\n \n"<<n<<" has been deleted from 3rd position";
    cout<<"\n \nThe number of items are :"<<countItems();
    l1.display();
    return 0;
 }
