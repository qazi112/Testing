//  Complexity O(1) of both enqueue and dequeue -> task one lab 6
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;
    Node *prev;
public:
    Node()
    {   data=0;
        next=NULL;
        prev=NULL;
    }
    Node(int d)
    {   data=d;
        next=NULL;
        prev=NULL;
    }
    void setData(int d);
    void setNext(Node *n);
    void setPrev(Node *p);
    Node* getPrev();
    int getData();
    Node* getNext();
};
void Node::setData(int d)
{   data=d;
}
void Node::setNext(Node *n)
{   next=n;
}
void Node::setPrev(Node *p)
{   prev=p;
}
int Node::getData()
{   return data;
}
Node* Node::getNext()
{   return next;
}
Node* Node::getPrev()
{   return prev;
}

// 2nd class
class LinkedList
{
public:
    Node *first;
    Node *back;
public:
    LinkedList()
    {
        first=NULL;
    }

    void display();
    void add(int d);
    void removeFromStart();
    int getSize();
    int findFunction(int value);

};
void LinkedList::display()
{   Node *temp=first;
    if(temp==NULL)
    {
        cout<<"Empty List\n";
        return;
    }
    else
    {   while(temp!=NULL)
        {
            cout<<temp->getData()<<" :"<<endl;
            temp=temp->getNext();
        }
    }
}
void LinkedList::add(int d)
{
    Node *toBeAdded=new Node(d);
    Node *temp=first;
    if(first==NULL)
    {   first=toBeAdded;
        back=toBeAdded;
        return;
    }
    else
    {
        back->setNext(toBeAdded);   // back pinter will always remain at end
        toBeAdded->setPrev(back);
        back=back->getNext();
    }
}
void LinkedList::removeFromStart()
{
    if(first==NULL)
    {
        return;
    }
    else
    {
        if(first->getNext()==NULL)
        {
            first=NULL;
        }
        else
        {
            first=first->getNext();
            first->setPrev(NULL);
        }
    }
}
int LinkedList::getSize()
{
    if(first==NULL)
    {
        cout<<"Empty List\n";
        return 0;
    }
    else
    {
        int i;
        Node *temp=first;
        for(i=0;temp!=NULL;i++)
        {
            temp=temp->getNext();
        }
        return i;
    }
}
int LinkedList::findFunction(int value)
{

    int counter=0; // exceed check
    int i=0;
    Node *temp=first;
    for(i=0; temp!=NULL; i++)
    {   counter++;
        if(temp->getData()==value)
        {   return i;
            break;
        }
        else
        {   temp=temp->getNext();
        }
    }
    if(counter==getSize()) // check exceeding
    {   return -1;
    }
}

// ============ QUEUE =============== //
class Queue
{
private:
    LinkedList doubly;

public:
    void enqueue(int value);
    void dequeue();
    int back();
    int peekFront();
    void displayQueue();
    int queueSize();
    int find(int value);
    void reverse();
};
void Queue::enqueue(int value)
{
    doubly.add(value);

}
void Queue::dequeue()
{
    doubly.removeFromStart();

}
void Queue::displayQueue()
{
    doubly.display();
}
int Queue::peekFront()
{
    if(doubly.first==NULL)
    {
        return -1;
    }
    else
    {
        return doubly.first->getData();
    }
}
int Queue::back()
{
    if(doubly.first==NULL)
    {
        return -1;
    }
    else
    {
        return doubly.back->getData();
    }

}
int Queue::queueSize()
{
    return doubly.getSize();
}
int Queue::find(int value)
{
    return doubly.findFunction(value);
}
void Queue::reverse()
{
    Node *second;
    if(doubly.first==NULL)
    {
        return;
    }
    else
    {
        Node *temp=doubly.first;
        while(temp->getNext()!=NULL)
        {
            temp=temp->getNext();
        }

        doubly.first=temp;
        while(temp->getPrev()!=NULL)
        {
            second=temp->getPrev();
            temp->setPrev(temp->getNext());
            temp->setNext(second);
            temp=temp->getNext();
        }
        second=temp->getPrev();
        temp->setPrev(temp->getNext());
        temp->setNext(second);
    }
}

// ================ MAIN FUNCTION STARTS HERE ================ //
int main()
{
    Queue q;
    char choice;
    int value=0;
    cout<<"************************\n";
    cout<<"Press A To Enqueue\n";
    cout<<"Press B To Dequeue\n";
    cout<<"Press C To Peek/Front\n";
    cout<<"Press D To Display \n";
    cout<<"Press E To Get Back \n";
    cout<<"Press F To To Reverse The Queue\n";
    cout<<"Press G To Get Size\n";
    cout<<"Press H To Find Index OF Value\n";
    cout<<"Press Q To Quit \n";
    cout<<"************************\n";
    cin>>choice;
    while(choice!='Q')
    {
        switch(choice)
        {
        case 'A':
            {
                cout<<"Enter Value \n";
                cin>>value;
                q.enqueue(value);
                break;
            }
        case 'B':
            {
                q.dequeue();
                break;
            }
        case 'C':
            {
                cout<<q.peekFront()<<endl;
                break;
            }
        case 'D':
            {
                q.displayQueue();
                cout<<endl;
                break;
            }
        case 'E':
            {
                cout<<q.back()<<endl;
                break;
            }
        case 'F':
            {
                q.reverse();
                break;
            }
        case 'G':
            {
                cout<<q.queueSize()<<endl;
                break;
            }
        case 'H':
            {
                cout<<"Enter Value\n";
                cin>>value;
                cout<<q.find(value)<<endl;
                break;
            }
        }
    cout<<"************************\n";
    cout<<"Press A To Enqueue\n";
    cout<<"Press B To Dequeue\n";
    cout<<"Press C To Peek/Front\n";
    cout<<"Press D To Display \n";
    cout<<"Press E To Get Back \n";
    cout<<"Press F To To Reverse The Queue\n";
    cout<<"Press G To Get Size\n";
    cout<<"Press H To Find Index OF Value\n";
    cout<<"Press Q To Quit \n";
    cout<<"************************\n";
    cin>>choice;

    }


}
