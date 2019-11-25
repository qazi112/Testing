#include <iostream>
using namespace std;
const int tableSize=10;
class Hashing{
public:
    int counter;
    int hashTable[10];
    Hashing()
    {
        counter=0;
        for(int i=0;i<tableSize;i++)
        {
            hashTable[i]=-1;
        }
    }
   int hash(int key);
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
    if(isFull()==true)
    {
        cout<<"Table Full \n";
    }
    else{

        int i=1;
        int index=hash(key);
        while(hashTable[index]!=-1)
        {
            index=(hash(key)+i)%tableSize;
            i++;
        }
        hashTable[index]=key;
        counter++;
        }

}
int Hashing::search(int key)
{
    int i=1;
    int index=hash(key);
    if(hashTable[index]==key)
    {
        cout<<"Found : At : "<<endl;
        return index;
    }
    else{
        while(hashTable[index]!=key || hashTable[index]!=-1)
        {
            index=(hash(key)+i)%tableSize;
            i++;

        }
    if(hashTable[index]==key)
    {
        cout<<"Found : At :\n";
        return index;
    }
    else {
        cout<<"Not Found\n";
        return -1;
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
            hashTable[index]=-1;
            counter--;
            return;
        }
    }
}
int Hashing::hash(int key)
{
    return key%tableSize;
}
int main()
{
    return 0;

}
