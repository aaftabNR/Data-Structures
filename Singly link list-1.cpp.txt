#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert();
void delete();
void reverse();
void concatenate();

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *temp, *head2;

int main()
{
	int choice;
	while(1)
	{
		printf("\n            MAIN MENU              ");
		printf("\n 1.CREATE ");
		printf("\n 2.DISPLAY ");
    	printf("\n 3.INSERT ");	
 		printf("\n 4.DELETE ");
 		printf("\n 5.REVERSE ");
 		printf("\n 6.CONCATENATE ");
 		printf("\n 7.EXIT " );
		printf("\n-------------------------------\n");
		printf("ENTER YOUR CHOICE:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
		        display();
		        break;
		    case 3:
		    	insert();
		    	break;

		   	case 4:
		    	delete();
		    	break;
		    	
		    case 5:
		    	reverse();
		    	break;
		    case 6:
		    	concatenate();
		    	break;
		    case 7:
		    	exit(0);
		    	break; 
		    default:
		    	printf("\n WRONG CHOICE:");
	     	}
	}
		return 0;
}

void create()
{
	int ch;
    while(ch)
	{
		struct node *newNode; 
		
		newNode=malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head = temp = newNode;
		}
		else
		{
		    temp->next = newNode;
		    temp = newNode;
		}
		printf("Do you wish to continue making nodes (0/1)");
		scanf("%d",&ch);
		if(ch==0)
		{
		    printf("Congratulations list is created");
		}
	}
}

void display()
{
   temp = head;
   while(temp != NULL)
   {
   		printf("%d\n",temp->data);
   		temp = temp->next;
   }	
}

void insert()
{
	void insert_begin();
	void insert_end();
	void insert_position();
	int ch;
	printf("\n 1.INSERT AT BEGINING ");
	printf("\n 2.INSERT AT END ");
	printf("\n 3.INSERT AT POSITION ");
	printf("\n-------------------------------\n");
	printf("ENTER YOUR CHOICE:");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			insert_begin();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			insert_position();
			break;
	}
}

void insert_begin()
{
	struct node *newNode;
	newNode=malloc(sizeof(struct node));
	printf("\n Enter the data to be inserted at begining: ");
	scanf("%d", &newNode -> data);
	newNode -> next = head;
	head = newNode;
	printf("The new list or updated list is \n ");
	display();
}

void insert_end()
{
	temp = head;
	struct node *newNode;
	newNode=malloc(sizeof(struct node));
	printf("\n Enter the data to be inserted at end: ");
	scanf("%d",&newNode -> data);
	newNode -> next = NULL;
	
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = newNode;
	printf("The new list or updated list is \n ");
	display();
}

void insert_position()
{
	int i=1;
	int pos;
	struct node *newNode;
	newNode=malloc(sizeof(struct node));
	printf("Enter the position after which you wish to insert data: ");
	scanf("%d", &pos);
	temp = head;
	
	while(i<pos)
	{
		temp = temp -> next;
		i++;
	}
	printf("Enter the data: ");
	scanf("%d",&newNode -> data);
	newNode -> next = temp -> next;
    temp -> next = newNode;
    printf("The new list or updated list is \n ");
    display();
}

void delete()
{
	void delete_begin();
	void delete_end();
	void delete_position();
	int ch;
	printf("\n 1.DELETE FROM BEGINING ");
	printf("\n 2.DELETE FROM END ");
	printf("\n 3.DELETE FROM POSITION ");
	printf("\n-------------------------------\n");
	printf("ENTER YOUR CHOICE:");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			delete_begin();
			break;
		case 2:
			delete_end();
			break;
		case 3:
			delete_position();
			break;
	}
}

void delete_begin()
{
	temp = head;
	if(head == NULL)
	{
		printf("The list is empty.. \n");
	}
	else
	{
		head = temp -> next;
		free (temp);
	}
	printf("The new list or updated list is \n ");
	display();
}

void delete_end()
{
	struct node *prevNode;
	prevNode=malloc(sizeof(struct node));
	temp = head;
	while (temp -> next != NULL)
    {
        prevNode = temp;
        temp = temp -> next;
    }
    free (temp);
    prevNode -> next = NULL;
    printf("The new list or updated list is \n ");
    display();
}

void delete_position()
{
	int i=1;
	int pos;
	printf("Enter the position at which you want to delete data: ");
	scanf("%d", &pos);
	struct node *temp2;
	temp2=malloc(sizeof(struct node));
	temp = head;
	
	while(i < pos)
	{
		temp2 = temp;
        temp = temp -> next;
        i++;
	}
	temp2 -> next = temp -> next;
    free (temp);
    printf("The new list or updated list is \n ");
    display();
}

void reverse()
{
	struct node *prevNode, *currentNode, *nextNode;
	prevNode = 0;
    currentNode = nextNode = head;
    
    while(nextNode != NULL)
    {
        nextNode = nextNode -> next;
        currentNode -> next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    printf("Reversed list: \n");
    display();
}

void concatenate()
{
	int choice;
    struct node *head2 = NULL;
    head2=malloc(sizeof(struct node));
    do
    {
        struct node *temp2;
        temp2=malloc(sizeof(struct node));
        struct node *newnode;
        newnode=malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode -> data );
        
        newnode -> next = NULL;
        if (head2 == NULL)
        {
            head2 = temp2 = newnode;
        }
        else
        {
            temp2 -> next = newnode;
            temp2 = newnode;
        }
        printf("Do you wish to continue making nodes (0/1)");
        scanf("%d",&choice);
        
        if (choice == 0)
        {
            printf("Congratulations, The list is created ");
        }
    } while(choice);
    temp = head;
    
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = head2;
    head2 = NULL;
    display();
}
