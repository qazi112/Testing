#include <iostream>
using namespace std;
const int tableSize=9;
class Hashing{
public:
    int counter;
    int hashTable[9];
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
    void delete(int key);
    bool isFull();
    bool isEmpty();
    int search(int key);
};

bool Hashing::isFull()
{
    if(counter==9) return true;
}
bool Hashing::isEmpty()
{
    if(counter==0) return true;
}
void Hashing::insert(int key)
{
    int i=1;
    int index=hash(key);
    while(hashTable[index]!=)
}
int Hashing::hash(int key)
{
    return key%tableSize;
}
