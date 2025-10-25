#include<stdio.h>
#include<stdlib.h>
#define size 10
int que[size],front=1,rear=1;
void main()
{
void enque(int);
int deque(),opt,item,ans;
void display();
int search();
while(1)
{
printf("1.INSERT\n2.DELETE\n3.display\n4.SEARCH\n5.EXIT\n");
printf("your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("item to insert:");
       scanf("%d",&item);
       enque(item);
       break;
case 2:item=deque();
       printf("deleted item=%d\n",item);
       break;
case 3:display();
       break;
case 4:printf("item to search:");
       scanf("%d",&item);
       ans=search(item);
       if(ans==1)
         printf("found..\n");
       else
          printf("not found..\n");
        break;  
case 5:exit(0);       
       
}
}
}
//function to insert
void enque(int data)
{
int r1;
r1=(rear+1)%size;
if(r1==front)
 printf("queue is full\n");
 else{
 rear=r1;
 que[rear]=data;
 }
 return;
}
//function to delete
int deque(){
if(front==rear)
{
 printf("queue is empty\n");
exit(1);
}
else
{
front=(front+1)%size;
return que[front];
}
}
//function to display queue
void display(){
int f=front,r=rear;
while(f!=r)
{
 f=(f+1)%size;
 printf("%d,\n",que[f]);
}
return;
}
//function to search
int search(int item){
int f=front,r=rear;
while(f!=r)
{
 f=(f+1)%size;
 if(que[f]==item)
   return 1;
 }
   return 0;
 }  
