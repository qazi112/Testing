#include <iostream>
const int TableSize=11;
using namespace std;
class Node
{
private:
    int data;
    Node *next;
public:
    Node()
    {   data=0;
        next=NULL;
    }
    Node(int d)
    {   data=d;
        next=NULL;
    }
    void setData(int d);
    void setPointer(Node *n);
    int getData();
    Node* getPointer();
};
void Node:: setData(int d)
{   data=d;
}
void Node:: setPointer( Node *n)
{   next=n;
}
int Node::getData()
{   return data;
}
Node* Node:: getPointer()
{   return next;
}

/*
    ****************
    Node Class Ended
    ****************
*/
class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
    {   first=NULL;
    }
    void setFirst(Node *first);
    Node* getFirst();
    void add(int d);
    void addAtStart(int d);
    void removeFromStart();
    void removeFromEnd();
    void display();
    int getSize();
    void addAt(int value,int index);
    void removeValue(int d);
};
void LinkedList:: setFirst(Node *first)
{   this->first=first;
}
Node* LinkedList:: getFirst()
{   return first;
}
void LinkedList::add(int d)
{   Node *temp=new Node(d);
    if(first == NULL)
    {
           first=temp;
    }
    else
    {

        Node *second=first;
        while(second->getPointer()!=NULL)
        {
              second=second->getPointer();
        }
        second->setPointer(temp);
    }
}
void LinkedList::addAtStart(int d)
{   Node *temp=new Node(d);
    Node *second=first;
    first=temp;
    temp->setPointer(second);
}
void LinkedList::removeFromStart()
{
    first=first->getPointer();
}
void LinkedList::removeFromEnd()
{   Node *temp=first;
    if(first==NULL)
    {
        return;
    }
    else if(temp->getPointer()==NULL)
    {
        first=NULL;
    }
    else
    {

    while(temp->getPointer()->getPointer()!=NULL)
    {
           temp=temp->getPointer();
    }
    temp->setPointer(NULL);
    }
}
void  LinkedList::display()
{   Node *temp=first;
    if(first==NULL)
    {
        cout<<"Empty List\n";
    }
    else
    {   while(temp!=NULL)
        {   cout<<temp->getData()<<" \t";
            temp=temp->getPointer();
        }
    }
}
int LinkedList::getSize()
{
    if(first==NULL)
    {
        cout<<"List Is Empty!\n";
        return 0;
    }
else{
     int i=0;            // counter
    Node *temp=first;
    for( i=0; temp!=NULL; i++)
    {
         temp=temp->getPointer();
    }
    return i;
    }       // Length of List
}
void LinkedList::removeValue(int d)
{   Node *temp2=first;
    Node *temp=first;
    if(temp==NULL)
    {   cout<<"Empty List\n";
    }
    else if(temp->getData()==d)
    {   removeFromStart();
    }
    else
    {   temp2=temp;
        temp=temp->getPointer();
        while(temp->getPointer()!=NULL)
        {

            if(temp->getData()==d)
            {   temp2->setPointer(temp->getPointer());
                break;
            }
            else
            {   temp2=temp;
                temp=temp->getPointer();
            }
        }

    }
}



/*
    ****************
    LinkedList Class Ended
    ****************
*/

class Hashing{
private:
    LinkedList hashTable[11];
public:
    Hashing()
    {
        for(int i=0;i<11;i++)
        {
            hashTable[i].setFirst(NULL);
        }
    }
    int hash(int key);
    void insert(int key);
    void delete_Key(int key);
    void search(int key);
    void display();
};
int Hashing::hash(int key)
{
    return key%TableSize;
}
void Hashing::insert(int key)
{
    int index=hash(key);
    hashTable[index].addAtStart(key);
}
void Hashing::search(int key)
{
    int index=hash(key);
    Node* temp=hashTable[index].getFirst();
    while(temp!=NULL)
    {
        if(temp->getData()==key)
        {
            cout<<"Found\n";
            return;
        }
    }
    cout<<"Not Found\n";
}
void Hashing::delete_Key(int key)
{
    int index=hash(key);
    hashTable[index].removeValue(key);

}
void Hashing::display()
{
    for(int i=0;i<TableSize;i++)
    {
        if(hashTable[i].getFirst()!=NULL)
        {
            cout<<i <<" "<<"->>>";
            hashTable[i].display();
            cout<<endl;
        }
        else{
            cout<<i <<" "<<endl;
        }

    }
}
int main()
{
    Hashing a;
    a.insert(20);
    a.insert(34);
    a.insert(23);
    a.insert(55);
    a.insert(66);
    a.delete_Key(66);

    a.display();
}
