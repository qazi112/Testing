#include <iostream>
using namespace std;
void merge(int *arr1,int *arr2,int st1,int st2);
int main()
{
    int array1[]={2,4,6,8};
    int array2[]={1,3,5,7};
    merge(array1,array2,0,0);
    return 0;
}

void merge(int *arr1,int *arr2,int st1,int st2)
{
    int i=0;
    int sizeArray=4;
    int newArray[2*sizeArray]; // double size array 2*n
    for( i=0;i<8;i++)
    {
        if(st1==4 || st2==4)
        {
            break;
        }

        if(*(arr1+st1)<*(arr2+st2))
        {
            newArray[i]=*(arr1+st1);
            st1++;
        }
        else if(*(arr1+st1)>*(arr2+st2))
        {
            newArray[i]=*(arr2+st2);
            st2++;
        }
    }

    while(st1<4)
    {
        newArray[i]=*(arr1+st1);
        st1++;
        i++;
    }
    while(st2<4)
    {
        newArray[i]=*(arr1+st2);
        st2++;
        i++;
    }


    for(int j=0;j<8;j++)
    {
        cout<<newArray[j]<<endl;
    }

}

