//double hashing
#include <iostream>
using namespace std;
const int tableSize=11;
const int PRIME=7;
class Hashing{
public:
    int counter;
    int hashTable[11];
    Hashing()
    {
        counter=0;
        for(int i=0;i<tableSize;i++)
        {
            hashTable[i]=-1;
        }
    }
    void display();
   int hash1(int key);
   int hash2(int key);
    void insert(int key);
    void delete_Key(int key);
    bool isFull();
    bool isEmpty();
    int search(int key);

};

bool Hashing::isFull()
{
    if(counter==10)
        return true;
    else {
        return false;
    }
}
bool Hashing::isEmpty()
{
    if(counter==0)
        return true;
    else {
        return false;
    }
}
void Hashing::insert(int key)
{
    if(isFull())
    {
        cout<<"Table Full \n";
    }
    else{

        int i=1;
        int index=hash1(key);
        while(hashTable[index]!=-1)
        {
            index=(hash1(key)+i*(hash2(key)))%tableSize;
            i++;
        }
        hashTable[index]=key;
        counter++;
        }

}
int Hashing::search(int key)
{
    int a=0;
    int i=1;
    int index=hash1(key);
    int prev=index;
    if(hashTable[index]==key)
    {
        cout<<"Found : At : "<<endl;
        return index;
    }
    else{
        while(a!=35)
        {
            index=(hash1(key)+i*(hash2(key)))%tableSize;
            if(hashTable[index]==key)
            {
                cout<<"Found : At :\n";
                return index;
            }

            i++;
            a++;

        }

}
}
void Hashing::delete_Key(int key)
{
    if(isEmpty()==true)
    {
        cout<<"Hash Table Is Empty\n";
        return;
    }
    else{
        int index=search(key);
        if(index!=-1)
        {
            cout<<"in\n";
            hashTable[index]=-1;
            counter--;
            return;
        }
    }
}
int Hashing::hash1(int key)
{
    return key%tableSize;
}
int Hashing::hash2(int key)
{
    return (PRIME - (key%PRIME));
}
void Hashing::display()
{
    for(int i=0;i<11;i++)
    {
        if(hashTable[i]!=-1)
        {
            cout<<i<<"-->"<<hashTable[i]<<endl;
        }
        else{
            cout<<i<<endl;
        }
    }
}
int main()
{
    Hashing h;
    h.insert(2);
    h.insert(13);
    h.insert(11);
    h.insert(34);
    h.insert(54);
    h.insert(14);
    h.insert(46);
    h.display();
    return 0;

}
