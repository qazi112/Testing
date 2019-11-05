#include<fstream>
#include<string>
#include <iostream>
using namespace std;
class Contact{
private:
    string name;
    long long number;
    string eMail;
    string city;
public:
    Contact(){
        name="*";
        number=9;
        eMail="*";
        city="*";

    }
    Contact(long long number, string eMail,string city,string name);
    void setName(string name);
    void setNumber(long long number);
    void setCity(string city);
    void setEmail(string eMail);
    string getName();
    long long getNumber();
    string getCity();
    string getEmail();
    void displayContact();
};
//setter
void Contact::setName(string name){
    this->name=name;
}
void Contact::setNumber(long long number){
    this->number=number;
}
void Contact::setCity(string city){
    this->city=city;
}
void Contact::setEmail(string eMail){
   this->eMail=eMail;
}
//getter
string Contact::getName(){
    return name;
}
long long Contact::getNumber()
{
    return number;
}
string Contact::getCity()
{
    return city;
}
string Contact::getEmail()
{
    return eMail;
}
void Contact::displayContact()
{
    cout<<"Name : "<<name<<endl;
    cout<<"City : "<<city<<endl;
    cout<<"Phone Number : "<<number<<endl;
    cout<<"Email : "<<eMail<<endl;

}
// Second Class Contacts
class Contacts{
    Contact obj[50];
    const static int loop;
public:
    void addCon(Contact a);
    void removeContact( int index);
    void searchContact();
    void displayAll();
    void addConWithoutRep(Contact,int index);
    void contactCounter();
    void saveToFile();
    void readFromFile();


};
//implementation
void Contacts::readFromFile()
{

    fstream file;
    file.open("objects.txt", ios :: in);
    for(int i=0;i<50;i++)
    {file.read((char *)&obj[i], sizeof(obj[i]));

    }



}
void Contacts::saveToFile()
{
    fstream file;
    file.open("objects.txt", ios :: app | ios :: trunc);
        for(int i=0;i<50;i++)
    {
        if(obj[i].getName()!="*")
        {
            //file<<obj[i].getName();
            //file<<'\n';
            file.write((char *)&obj[i],sizeof(obj[i]));
        }
    }
    file.close();


}
void Contacts::contactCounter()
{
    int counter=0;
    for(int i=0;i<50;i++)
    {
        if(obj[i].getName()!="*")
        {
            counter++;
        }
    }
    cout<<"Total Contacts Are : "<<counter<<endl;
}
void Contacts::addConWithoutRep(Contact a, int index)
{
    if(obj[index].getName()=="*")
    {
        obj[index]=a;
    }
    else{
        for(int i=0;i<50;i++)
        {
            if(obj[i].getName()=="*")
            {
                obj[i]=obj[index];
                obj[index]=a;
                break;
            }
        }
    }
}
void Contacts::displayAll()
{
    for(int i=0;i<50;i++)
    {
        if(obj[i].getName()!="*")
        {
            obj[i].displayContact();
            cout<<endl;
        }
    }
}
void Contacts::addCon(Contact a)
{
    for(int i=0;i<50;i++)
    {
        if(obj[i].getName()=="*")
        {
            obj[i]=a;
            break;
        }
    }
}
void Contacts::searchContact()
{
    long long pno;
    cout<<"Enter Phone Number to Search :\n";
    cin>>pno;
    for(int i=0;i<50;i++)
    {
        if(obj[i].getNumber()==pno)
        {
            cout<<"Here Is Your Contact :\n";
            obj[i].displayContact();
        }
    }
}
void Contacts::removeContact(int index)
{
    if(obj[index].getName()!="*")
    {
        obj[index].setName("*");
        obj[index].setNumber(9);
        obj[index].setCity("*");
        obj[index].setEmail("*");

    }
    else{
        cout<<"No Contact At This Place \n";

    }
}

int main()
{
    Contacts obj;
    obj.readFromFile();
    char select;
    do{
    cout<<"Here Are Options Selects The Following : \n";
    cout<<"Press \'A\' to add contact :\n";
    cout<<"Press \'B\' to remove contact at specific index :\n";
    cout<<"Press \'C\' to Know The Contact Count :\n";
    cout<<"Press \'D\' to search a contact :\n";
    cout<<"Press \'E\' to Display All Contacts :\n";
    cout<<"Press \'F\' to add contact at specific index :\n";
    cout<<"Press \'G\' to save contacts to file :\n";
    cout<<"Press \'H\' to Load contacts from file :\n";
    cin>>select;
    switch(select)
    {
        case'A':
        {
            string name;
            string email;
            string city;
            long long no;
            Contact a;
            cout<<"Enter Name :\n";
            cin>>name;
            a.setName(name);
            cout<<"Enter Number :\n";
            cin>>no;
            a.setNumber(no);
            cout<<"Enter City :\n";
            cin>>city;
            a.setCity(city);
            cout<<"Enter Email :\n";
            cin>>email;
            a.setEmail(email);
            obj.addCon(a);
            break;
        }
        case 'B':
            {
                int index;
                cout<<"Enter The Index No :\n";
                cin>>index;
                obj.removeContact(index);
                break;
            }

        case 'C':
            {
                obj.contactCounter();
                break;
            }
        case 'D':
            {
                obj.searchContact();
                break;
            }
        case 'E':
            {
                obj.displayAll();
                break;
            }
        case 'F':
            {
            int index;
            string name;
            string email;
            string city;
            long long no;
            Contact a;
            cout<<"Enter Name :\n";
            cin>>name;
            a.setName(name);
            cout<<"Enter Number :\n";
            cin>>no;
            a.setNumber(no);
            cout<<"Enter City :\n";
            cin>>city;
            a.setCity(city);
            cout<<"Enter Email :\n";
            cin>>email;
            a.setEmail(email);
            cout<<"Enter index : \n";
            cin>>index;
            obj.addConWithoutRep(a,index);
            break;
            }
        case 'G':
            {

                obj.saveToFile();
                break;
            }
        case 'H':
            {
                obj.readFromFile();
                obj.displayAll();
            }
    }
    cout<<"Do You Want To Continue : press Y else N\n";
    cin>>select;
    }while(select=='Y'||select=='y');

}
