#include <iostream>

using namespace std;
void seletionSort(int *arr,int start,int end);
/*
    //movMin() will find minimum from the array and replace
    // it with the starting index
*/
void movMin(int *arr,int start,int end);


int main()
{
    int arr[]={74, 23, 17, 13, 7, 1, 9, 4};
    seletionSort(arr,0,7);

    for(int i=0;i<=7;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}

void movMin(int *arr,int start,int end)
{
    int min=10000;
    for(int i=start;i<=end;i++)
    {
        if(*(arr+i)<min)
        {
            min=*(arr+i);           // Min
            *(arr+i)=*(arr+start);  // Swapping
            *(arr+start)=min;       // swapping

        }
    }

}
void seletionSort(int *arr,int start,int end)
{
    for(int i=0;i<=end;i++)
    {
        movMin(arr,i,end);
    }
}
