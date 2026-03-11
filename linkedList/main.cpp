#include<iostream>

struct Node
{
    int data;
    Node* next=NULL;
};

void addHead(Node*& head,int value);

void printList(Node* head);

void deleteTheLastNode(Node*& head);

void addToTheEndOfTheList(Node *&head, int value);

void deleteHead(Node*&head);


int main()
{
    Node* head = NULL;

    addHead(head,12);
    addHead(head,13);
    addHead(head,14);
    addHead(head,15);
    addToTheEndOfTheList(head,11);

    printList(head);
    deleteHead(head);
    //deleteTheLastNode(head);
    printList(head);
    return 0;
}

void addHead(Node*& head, int value)
{

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void printList(Node* head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        std::cout<<temp->data<<"->";
        temp = temp->next;
    }
    std::cout<<"Null"<<std::endl;

}

void deleteTheLastNode(Node*& head)
{
    Node* temp = head;
    while (temp->next->next!=nullptr)
    {
        temp = temp->next;
    }
    temp->next=nullptr;

}

void addToTheEndOfTheList(Node *&head, int value)
{
    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data=value;
    newNode->next=nullptr;
    temp->next=newNode;

}
void deleteHead(Node*&head)
{
    Node*temp = head->next;
    head = temp;
}