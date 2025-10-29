#include<stdio.h>
#include<stdlib.h>
struct node
{
   int value; //value of the node
   struct rep *repptr; //pointer to its representative structure
   struct node *next; //pointer to the next node in the same set
};

struct rep
{
 struct node *head; //pointer to the first element in the set
 struct node *tail;//pointer to the last element in the set
};
//structure to store key & object node pointer
struct nodaddr
{
  int key;
  struct node *obj_node_ptr;
  struct nodaddr *next;
};

struct nodaddr *ndr=0;//list to store keys&object node pointer
//function to create a set for an object
void makeset(int a)
{//create a objectnode pointer
struct nodaddr *t=(struct nodaddr *)malloc(sizeof(struct nodaddr));
//create newset
struct rep *newset=(struct rep *)malloc(sizeof(struct rep));
struct node *n=(struct node *)malloc(sizeof(struct node));
//fill values
n->value=a;
n->repptr=newset;
n->next=0;
//initialize head and tail
newset->head=newset->tail=n;
//to store object node pointer &key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}
//function to return pointer of the representation (header node)of the set containing x
struct rep *find(int x)
{
struct nodaddr *t=ndr;
while(t!=0 && t ->key!=x)
  t = t->next;
return t->obj_node_ptr->repptr;
}
//to find union of two sets correspondind to objects given
void unionset(int key1,int key2)
{
 struct rep *set1,*set2;
 struct node *t1;
 set1=find(key1);
 set2=find(key2);
 if(set1==set2)
    printf("\n%d and %d belongs to same set\n",key1,key2);
 else{//changing header pointers of objects of set2 to that of set1
     t1=set2->head;
     while(t1!=0)
     {
      t1->repptr=set1;
      t1=t1->next;
     }
 set1->tail->next=set2->head;
 set1->tail=set2->tail;//set the tail of the set1 to tail of set2 
 free(set2);
 }
 }
 //function to display a set
 void display(int a)
 {
  struct rep*r;
  struct node *t;
  r=find(a);
  t=r->head;
  printf("\n set numbers containing %d:",a);
  while(t!=0)
  {
    printf("%d,",t->value);
    t=t->next;
 }
 }
  void main(){
 makeset(10);
 makeset(20);
 makeset(30);
 makeset(40);
 makeset(50);
 printf("Find(10)=%X",find(10));
 printf("\nFind(20)=%X",find(20));
 printf("\nFind(30)=%X",find(30));
 printf("\nFind(40)=%X",find(40));
 unionset(10,20);
 printf("\n after union of 10&20 Find(20)=%X",find(20));
 unionset(30,40);
 printf("\n after union of 30&40 Find(40)=%X",find(40));
 unionset(20,40);
 printf("\n after union of 20&40 Find(40)=%X",find(40));
 display(40);
} 
 
