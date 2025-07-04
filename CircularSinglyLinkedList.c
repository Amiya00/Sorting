#include<stdio.h>
#include<stdlib.h>
struct Node{
int info;
struct Node *link;
 };


 struct Node*insert_at_begin(struct Node*start){
int element;
struct Node*fresh;
fresh=(struct Node*)malloc(sizeof(struct Node));
if(fresh==NULL){
printf("overflow!");
}
else{
 printf("Enter the element to be inserted:");
scanf("%d",&element);
}
fresh->info=element;
fresh->link=NULL;
 if(start==NULL){
start=fresh;
}
else{
fresh->link=start;
start=fresh;
}
return start;
}



struct Node*insert_at_end(struct Node*start){
int element;
struct Node*fresh,*ptr;
fresh=(struct Node*)malloc(sizeof(struct Node));
if(fresh==NULL){
printf("overflow!");
}
else{
printf("Enter the element to be inserted:");
scanf("%d",&element);
 }
fresh->info=element;
fresh->link=NULL;
if(start==NULL){
start=fresh;
}
 else{
 for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
 ptr->link=fresh;
 }
return start;
 }



struct Node*delete_at_begin(struct Node*start){
struct Node *ptr;
if(start==NULL){
        printf("underflow");
        
}
else{
        ptr=start;
        start=start->link;
        printf("the delete element is %d",ptr->info);
        free(ptr);
}
}




struct Node*delete_at_end(struct Node*start){
struct Node *ptr;
if(start==NULL){
        printf("underflow");
       
}
else if(start->link==NULL){
        free(start);
        start=NULL;
}
else{
        while(start->link!=NULL){
                ptr=start;
                start=start->link;
        }
        free(start);
        ptr->link=NULL;
}
}


void display(struct Node *start){
    struct Node *ptr;
	if(start==NULL){
		printf("Linked List does not exist");
	}
	else{
	printf("The Elements are: \n");
	for(ptr=start;ptr!=NULL;ptr=ptr->link){
		printf("%d ", ptr->info);
	}
	}
    printf("\n");
}



int main(){ 
int choice;
struct Node *start,*ptr;
do{
printf("Enter your choice 1.inserction at begining\n2.inserction at end\n3.delete at begining\n4.delete at end\n5.display\n6.Exit");
scanf("%d",&choice);
switch(choice){
case 1: start=insert_at_begin(start);
break;
case 2: start=insert_at_end(start);
break;
case 3: start=delete_at_begin(start);
break;
case 4: start=delete_at_end(start);
break;
case 5: display(start);
break;
case 6: break;

                }
        }
        while(choice!=6);1
}