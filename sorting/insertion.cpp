#include <iostream>
using namespace std;
void insert(int *array,int start,int end);
void insertion(int *array,int start,int end)
{
    for(int i=1;i<8;i++)
    {
        insert(array,start,i);
    }
}
void insert(int *array,int start,int end)
{
    int second=end-1;
    while(end!=start)
    {
        if(*(array+second)>*(array+end))
        {
            int a=*(array+second);
            *(array+second)=*(array+end);
            *(array+end)=a;
            end--;
            second--;
        }
        else{break;}
    }
}
int main()
{
    int array[]={12, 11, 13, 5, 6,54,4,7};
    insertion(array,0,7);

    for(int i=0;i<8;i++)
    {
        cout<<array[i]<<endl;
    }
    return 0;
}
