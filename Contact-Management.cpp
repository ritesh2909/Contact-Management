#include<bits/stdc++.h>
#include<fstream>
using namespace std;

string fname,lname,phn_num;

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{   short int choice;
    system("cls");
    system("color 0A");
    cout<<"\n\n\n\t\tContact Management";
    cout<<"\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t";
    cin>>choice;
    switch(choice)
    {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4: 
            self_exit();
            break;
        default:
            cout<<"\n\n\tInvalid Input !";
            cout<<" \n\tPress Any Key to Continue...";
            main();
    }
    return 0;
}

void self_exit()
{
        system("cls");
        cout<<"\n\n\n\t\tThank You for using !";
        exit(1);
}

void help()
{
    cout<<"This displays Help....";
}
void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout<<"\n\n\tEnter your First Name: ";
    cin>>fname;
    cout<<"\n\n\tEnter your Last Name: ";
    cin>>lname;
    cout<<"Enter Your 10 Digit Phone Number: ";
    cin>>phn_num;

    if(check_digits(phn_num) == true)
    {
        if(check_numbers(phn_num)==true)
        {
                if(phone.is_open())
                {
                    phone << fname <<" "<<lname<<" "<<phn_num<<endl;
                    cout<<"Contact Saved Successfully !";
                }
                else
                {
                    cout<<"\n\t Error Openeing File !";
                }
        }

        else
        {
            cout<<"\n\tA Phone Number Only Contain Digits !";

        }
        phone.close();
    }
    else
    {
        cout<<"\n\tA Phone Number Must Contain 10 Digits.";
    }

}

void searchContact()
{
    ifstream myfile("number.txt");
    string keyword;
    cout<<"\n\t Enter Name to Search: ";
    cin>>keyword;
    while(myfile >> fname >>lname >> phn_num)
    {
        if(keyword==fname || keyword == lname)
        {
            cout<<"\n\n\n\t\tContact Details..";
            cout<<"\n\n\tFirst Name: "<<fname;
            cout<<"\n\n\tLast Name: "<<lname;
            cout<<"\n\tPhone Number: "<<phn_num;
            break;

        }

        else
        {
            cout<<"\n\n\t\tContact Not Found !";
        }
    }
}

bool check_digits(string x)
{
    if(x.length()==10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_numbers(string x)
{
    bool check = true;
    for(int i = 0;i<x.length();i++)
    {
        if(!(int(x[i])>=48 && int(x[i])<=57))
        {
            check = false;
        }
    }
    if(check==true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}