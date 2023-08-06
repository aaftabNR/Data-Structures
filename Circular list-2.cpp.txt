#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

node *head = NULL;
node *temp, *head2; 
node *tail;
node *prev;
int size;

void create();
void display();
void insertion();
void deletion();
void reverse();
void concatenate();

int main()
{
	 while(1)
    {
        int ch;
        cout<<"-----welcome to linked list----" <<endl;
        cout<<"1. Create" <<endl;
        cout<<"2. Display" <<endl;
        cout<<"3. Insertion" <<endl;
        cout<<"4. Deletion" <<endl;
        cout<<"5. Reverse" <<endl;
        cout<<"6. Concatenate" <<endl;
        cout<<"Choose from the above operations: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
               insertion();
                break;
            case 4:
                deletion();
                break;
            case 5:
                reverse();
                break;
            case 6:
                concatenate();
                break;
            default:
                cout<<"Enter valid number between 1 and 6!" <<endl;
        }
    }
    		return 0;
}

void create()
{
	int choice;
	while(choice)
	{
		node *newnode = new node(); //newnode banya
		cout<<"Enter the data:";  //data liya user se
		cin>>newnode -> data;     //data newNode main store kiya
		if( head==NULL)
		{
			head = temp = newnode;
			newnode -> next = head;
		}
		else
		{
			temp -> next = newnode;
			newnode -> next = head;
			temp = newnode;
		}
		cout<<"Do you wish to continue (0/1)";
		cin>>choice;
	}
}

void display()
{
	temp = head;
	while(temp -> next != head)
	{
		cout<<temp->data <<endl;
		temp = temp -> next;
	}
	cout<<temp -> data <<endl;
}

void insertion()
{
    void insert_beg();
    void insert_end();
    void insert_after();
    int ch;
    cout<<"1. Insertion at the beginning" <<endl;
    cout<<"2. Insertion at the end" <<endl;
    cout<<"3. Insertion after a given node" <<endl;
    cout<<"Choose from the above insertion operations: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_after();
            break;
    }
}

void insert_beg()
{
	node *newnode = new node();
	cout<<"Enter the data to be inserted at begining :" ;
	cin>>newnode -> data;
	newnode -> next = head;
	while(temp -> next != head)
	{
		temp = temp -> next;
	}
	temp -> next = newnode;
	head = newnode;
	temp = head;
	
	cout<<"The updated list is :" <<endl;
	display();
}

void insert_end()
{
	temp = head;
	node *newnode =new node();
	cout<<"Enter the data to be inserted at end :" ;
	cin>>newnode -> data;
	if(head == NULL)
	{
		head = newnode;
		newnode -> next = head;
	}
	else
	{
		while(temp->next != head)
		{
			temp = temp->next;
		}
			temp -> next = newnode;
			newnode -> next = head;
	}
	
	cout<<"The updated list is :" <<endl;
	display();
}

void insert_after()
{
	int i=1 ;
    int pos;
    node *newnode = new node();
    cout<<"Enter the position after which you wish to insert: ";
    cin>>pos;
    temp = head;
    while (i<pos)
    {
        temp = temp -> next;
        i++;
    }
    cout<<"Enter the data: ";
    cin>>newnode -> data;
    newnode -> next = temp -> next;
    temp -> next = newnode;
    display();
}

void deletion()
{
	void delete_beg();
    void delete_end();
    void delete_at();
    int ch;
    cout<<"1. Delete at the beginning" <<endl;
    cout<<"2. Delete at the end" <<endl;
    cout<<"3. Delete after a given node" <<endl;
    cout<<"Choose from the above insertion operations: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            delete_beg();
            break;
         case 2:
            delete_end();
            break;
          case 3:
            delete_at();
            break;
    }
}

void delete_beg()
{
	if (head == 0)
    {
        cout<<"The list is empty!" <<endl;
    }
    else
    {
        tail=head;
        while(tail-> next != head)
        {
            tail= tail->next;
        }
        temp=head;
        head = temp ->next;
        tail ->next = head;
        free(temp);

        cout<<"The updated list is :" <<endl;
	    display(); 
    }
}

void delete_end()
{
    if (head == 0)
    {
        cout<<"The list is empty :"<<endl;
    }
    tail=head;
    while(tail->next != head)
    {
        tail=tail->next;
    }
    temp=head;
    while(temp->next != tail)
    {
        temp=temp->next;
    }
    temp->next=head;
    free(tail);

        cout<<"The updated list is :" <<endl;
        display(); 
}

void delete_at()
{
    node *prev;
    int i=1;
    int pos;
    cout<<"Enter the position at which node is to be deleted :"<<endl;
    cin>>pos;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    prev=head;
    while(i<pos-1)
    {
        prev=prev->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);

    cout<<"The updated list is :" <<endl;
    display(); 
}

void reverse()
{
    node *prevnode, *currentnode, *nextnode;
    tail = head;
    while (tail -> next != head)
    {
        tail = tail -> next;
    }
    prevnode = NULL;
    currentnode = nextnode = head;
    while (nextnode -> next != head)
    {
        nextnode = nextnode -> next;
    if (currentnode == head)
    {
        currentnode -> next = tail;
    }
    else
    {
        currentnode -> next = prevnode;
    }
        prevnode = currentnode;
        currentnode = nextnode;
    }
    currentnode->next=prevnode;
    head=currentnode;
 
    cout<<"The updated list is :" <<endl;
    display(); 
}

void concatenate()
{
    int choice;
    while(choice)
    {
        node *newnode = new node();
        cout<<"Enter the data: ";
        cin>>newnode -> data;
        if (head2 == NULL)
        {
            head2 = temp = newnode;
            temp -> next = head2;
        }
        else
        {
            temp -> next = newnode;
            newnode -> next = head2;
            temp = newnode;
        }
            cout<<"Do you wish to continue? (0/1): ";
            cin>>choice;
    }
        temp = head;
        while (temp -> next != head)
        {
            temp = temp -> next;
        }
            temp -> next = head2;
            temp = head2;
        while (temp -> next != head2)
        {
            temp = temp -> next;
        }
            temp -> next = head;

           cout<<"The updated list is :" <<endl;
           display();  
}

