#include<stdio.h>
struct node
{
    int info;
    struct node*link;
};
int main()
{
    int choice;
    struct node*start;

    do
    {
        printf("Enter your cboice;\n1.Insert at beg\n2.Insert at end\nDelet at beg\n3.Delet at end\n4.Display\n5.exist");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:start = insert_at_begin(start);
            break;
            case 2:start = insert_at_end(start);
            break;
            case 3:start = delet_at_begin(start);
            break;
            case 4:start = delet_at_end(start);
            break;
            case 5:display(start);
            break;
            default:printf("Enter the correct choice");
            break;
        }
    } while(choice!=6);   
}

struct node*insert_at_begin(struct node*start)
{   int size;
    int element;
    struct node*fresh,*prev,*ptr;
    fresh=(struct node*)malloc(size of (struct node));
}