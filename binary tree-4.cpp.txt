#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = 0;

node *create();
void traverse();
void inorder(node *temp);
void preorder(node *temp);
void postorder(node *temp);
void preorderiterative(node *temp);
void inorderiterative(node *temp);
void postorderiterative(node *temp);

int main()
{
    while(1)
    {
        int ch;
        cout<<"1. Create a tree"<<endl;
        cout<<"2.Traverse a tree"<<endl;
        cout<<"3.Choose from the above operations on the tree:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                root = create();
                break;

            case 2:
                traverse();
                break;
            
            default:
                cout<<"Enter valid number!"<<endl;
        }
    }
    return 0;
}

node *create()
{
    int x;
    node *newnode = new node();
    cout<<"Enter the data: (Enter -1 for no node): ";
    cin>>x;

    if (x == -1)
    {
        return 0;
    }
    else
    {
        newnode -> data = x;
        cout<<"Enter the left child of " << x <<endl;
        newnode -> left = create();
        cout<<"Enter the right child of " << x <<endl;
        newnode -> right = create();
        return newnode;
    }
}

void traverse()
{
    int ch;
    cout<<"1.Preorder Recursive"<<endl;
    cout<<"2.Inorder Recursive"<<endl;
    cout<<"3.Postorder Recursive"<<endl;
    cout<<"4.Preorder Iterative"<<endl;
    cout<<"5.Inorder Iterative"<<endl;
    cout<<"6.Postorder Iterative"<<endl;
    cout<<"Enter from the above traversal option:";
    cin>>ch;

    switch(ch)
    {
        case 1:
            preorder(root);
            cout<<"\n";
            break;

        case 2:
            inorder(root);
            cout<<"\n";
            break;

        case 3:
            postorder(root);
            cout<<"\n";
            break;

        case 4:
            preorderiterative(root);
            cout<<"\n";
            break;

        case 5:
            inorderiterative(root);
            cout<<"\n";
            break;

        case 6:
            postorderiterative(root);
            cout<<"\n";
            break;

        default:
            cout<<"Enter valid number!"<<endl;
    }
}

void preorder(node *temp)
{
    if (temp == 0)
    {
        return;
    }
    else
    {
        cout<<temp->data<<"";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(node *temp)
{
    if (temp == 0)
    {
        return;
    }
    else
    {
        cout<<temp->data<<"";
        inorder(temp->left);
               inorder(temp->right);
    }
}

void postorder(node *temp)
{
    if (temp == 0)
    {
        return;
    }
    else
    {
        cout<<temp->data<<"";
        postorder(temp->left);
        inorder(temp->right);
    }
}
void preorderiterative(node *root)
{
    if (root == NULL)
    return;
    stack<node*>stack;
    node *current = root;
    
    while(!stack.empty() || current != NULL)
    {
        while (current != NULL)
        {
            cout<<current->data<<"->";
            if (current->right)
            stack.push(current->right);
            current = current->left;
        }
        if (stack.empty() == false)
        {
            current = stack.top();
            stack.pop();
        }
    }

}

void inorderiterative(node *root)
{
    stack<node*>stack;
    node *current = root;

    while(current || !stack.empty())
    {
        while (current != NULL)
        {
            stack.push(current);
            current = current ->left;
        }
        current = stack.top();
        stack.pop();
        cout<< current->data<<"->";
        current = current->right;
    }
}

void postorderiterative(node *root)
{  
        stack<node*>stack;
        node *current = new node();
        current = root;
  
        while(current !=NULL || stack.empty())
        {
            if(current!=NULL)
            {
                stack.push(current);
                current = current->left;
            }
            else
            {
                node *temp = stack.top()->right;
                if(temp == NULL)
                {
                    temp = stack.top();
                    stack.pop();
                    cout<<temp->data;
                    cout<<"-";
                    while(!stack.empty() && temp == stack.top()->right)
                    {
                        temp = stack.top();
                        stack.pop();
                        cout<<temp->data;
                        cout<<"-";
                    }
                }
                else
                {
                     current = temp;
                 }
            }
        }
}

