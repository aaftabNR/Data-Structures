#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *head=NULL;
node *prev=NULL;
node *tail, *head2, *temp, *tail2;
int size, free;

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
    while (choice)
    {
        node *newnode = new node();
        cout<<"Enter the data :" <<endl;
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }

        cout<<"Do you wish to continue (0/1)";
		cin>>choice;
        
    }
}

void display()
{
    temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
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
    cout<<"Enter the data to be inserted at beginning : ";
    cin>>newnode -> data;
    newnode -> prev = NULL;
    newnode -> next = head;
    head = newnode;

    cout<<"The updated list is :" <<endl;
    display();
}

void insert_end()
{
    node *newnode = new node();
    cout<<"Enter the data to be inserted in the end: ";
    cin>>newnode -> data;
    newnode -> next = NULL;
    newnode -> prev = tail;
    tail -> next = newnode;
    tail = newnode;

    cout<<"The updated list is :" <<endl;
    display();
}

void insert_after()
{
    int pos;
    int i = 1;
    node *newnode = new node();
    cout<<"Enter the position after which you wish to insert: ";
    cin>>pos;
    cout<<"Enter the data: ";
    cin>> newnode -> data;
    temp = head;
    while (i < pos)
    { 
        temp = temp -> next;
        i++;
    }
    newnode -> prev = temp;
    newnode -> next = temp -> next;
    temp -> next = newnode;
    temp -> next -> prev = newnode;

    cout<<"The updated list is :" <<endl;
    display();
}
void deletion()
{
    int ch;
    void delete_beg();
    void delete_end();
    void delete_at();
    cout<<"1. Delete from the beginning" <<endl;
    cout<<"2. Delete from the end" <<endl;
    cout<<"3. Delete from the specified position" <<endl;
    cout<<"Choose from the above deletion oerations: " <<endl;
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
        default:
        cout<<"Enter only from the above operations!" <<endl;
    }
}

void delete_beg()
{
    temp = head;
    head = temp -> next;
    temp -> next -> prev = NULL;
    free(temp);

    cout<<"The updated list is :" <<endl;
    display();
}

void delete_end()
{
    temp = tail;
    tail -> prev -> next = NULL;
    tail -> prev = NULL;
    tail = temp -> prev;
    free (temp);

    cout<<"The updated list is :" <<endl;
    display();
}

void delete_at()
{
    int i = 1;
    int pos;
    cout<<"Enter the position at which you want to delete the node: ";
    cin>>pos;
    temp = head;
    while (i < pos)
    {
        temp = temp -> next;
        i++;
    }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);

        cout<<"The updated list is :" <<endl;
        display(); 
}

void reverse()
{
    if (head == NULL)
    {
        cout<<"The list is empty, nothing to reverse!!" <<endl;
    }
    else
    {
        temp = tail;
        tail = head;
        head = temp;
        cout<<"----Reversed linked list----" <<endl;

        while (temp != NULL)
        {
            cout<< temp -> data <<endl;
            temp = temp -> prev;
        }
    }
}

void concatenate()
{
    cout<<"Enter the details of second node!" <<endl;
    int choice;
    while(choice)
    {
    node *newnode = new node();
    cout<<"Enter the data: ";
    cin>>newnode -> data;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    if (head2 == NULL)
    {
        head2 = tail2 = newnode;
    }
    else
    {
        tail2 -> next = newnode;
        newnode -> prev = tail2;
        tail2 = newnode;
    }
        cout<<"Do you wish to continue? (0/1): "<<endl;
        cin>>choice;
    }
        tail -> next = head2;
        head2 -> prev = tail;

        cout<<"The updated list is :" <<endl;
        display();
}
