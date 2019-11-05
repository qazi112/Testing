//stream finder
#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    int counter=0;
    int a=0;
    char arr[]="stream"; // wanted to scan
    char word;
    char compare[6];
    ifstream file("main.cpp");
    if(!file)
    {
        cout<<"File Not Open \n";
    }
    while(file.eof()==0)
    {
        file.get()
    }
    while(file.eof()==0)
    {

            file.get(word);
            if(word==arr[0])
            {
                for(int i=1;i<6;i++)
                {
                    a=i;
                    file.get(word);
                    if(word!=arr[i])
                    {
                        a=0;
                        break;
                    }

                }
                if(a==5)
                {
                    counter++;
                }
            }

    }
cout<<"String Stream Is : "<<counter<<" Times .\n";

    return 0;
}
