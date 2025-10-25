#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next;
};
void main()
{
struct node *start=(struct node*)0;
struct node * insert(struct node*,int);
struct node * delete(struct node*);
void display(struct node*);
int search(struct node*,int),opt,item,ans;
while(1)
{
printf("\n 1.insert \n 2.delete \n 3.display \n 4.search \n 5.end \n");
printf("your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert:");
       scanf("%d",&item);
       start=insert(start,item);
       break;
case 2:start=delete(start);
       break;
case 3:display(start);
       break;
case 4:printf("item to search:");
       scanf("%d",&item);
       ans=search(start,item);
       if(ans == 1){
       printf("item found");
       }else
       printf("item not found");
       break;
case 5:exit(0);       
}
}
}
//function to push
struct node * insert(struct node* list,int data)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
t->next=list;
list=t;
return list;
}
//function to pop
struct node * delete(struct node* list)
{
struct node *t=list;
if(list !=(struct node*)0)
{
printf("deleted data is: %d \n",list->data);
list=list->next;
free(t);
}else
printf("list is null \n");
return list;
}
//function to display
void display(struct node* list)
{
while(list != (struct node*)0)
{
printf("%d, \n",list->data);
list=list->next;
}
return;
}
//function to search
int search(struct node * list,int item)
{
while(list !=(struct node *)0 && item!=list->data)
list = list->next;
if(list==(struct node*)0)
{
  return 0;
  }
else
{
return 1;
}
}
