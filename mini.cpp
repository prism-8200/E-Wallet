#include "mini.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <sstream>
using namespace std;
/**
*The following two functions are used for hashing techniques
*/
void mini::kkk(char c[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(c[i] == ' ' || c[i] == 'z')
        {
            c[i] = 'a';
            for(int j = 1 ; j < 6; j++)
            {
                c[i]+=key1[j];
                c[i]+=key2[i];

            }
        }
        else
        {
            for(int j = 0 ; j < 6; j ++)
            {
                c[i] = c[i] + key2[j] + key1[i];
                if(c[i] == 'z')
                {

                    c[i] = 'a';
                    c[i]--;

                }
            }
        }


    }
}
string mini::jjj(char r[10])
{
    string x = "";
    kkk(r,10);
    char m[6],h[5];
    for(int i = 0 ; i < 6 ; i ++)
    {
        m[i] = r[4+i];
    }
    kkk(m,6);

    for(int i = 0 ; i < 5 ; i ++)
        h[i] = m[1+i];

    kkk(h,5);
    for (int i = 0 ; i < 5 ; i ++)
        x+=h[i];
    return x;
}

/**
*A function for registering a new Account
*/

void mini::registera()
{
    char pa[10];

    string t,line;
    double k;
    f.open("mat.txt",ios::in|ios::out|ios::app);
    int camp;
    do
    {
        camp = 1;
        cout<<"Enter the ID:";
        for(int i = 0 ; i < 10 ; i ++)
            cin>>code[i];
        t = jjj(code);

        while(f)
        {

            getline(f,line);
            if(t == line)
            {
                camp = 0;
                cout<<"\nID already exists! Try another ID!!\n";
            }
        }
        f.clear();
        f.seekp(0,ios::beg);
        f.seekg(0,ios::beg);
    }while(camp == 0);

    cout<<"Enter a 10-digit password\n";
    for(int i = 0 ; i < 10 ; i ++)
    {
        pa[i] = getch();
        cout<<"*";
    }

    string cat = jjj(pa);
    f<<t<<endl;
    int kkkk = 0;
    f<<kkkk<<endl;
    f<<cat<<endl;
    srand(time(0));
    int last = rand();
    f<<last<<endl;

    f<<"xxx"<<endl<<endl;
    f.close();
    ostringstream oss;
    oss<<last;
    string lll = "indi" + oss.str() + ".txt";
    f.open(lll.c_str(),ios::in|ios::out|ios::app);
    cout<<"\nEnter your Name: ";
    cin>>name;

    cout<<"\nEnter your date of birth in the following format DD/MM/YYYY: ";
    cin>>dob;

    cout<<"\nEnter your branch code(CSE or ECE or EEE or IT or MECH or CIVIL): ";
    cin>>branch;

    cout<<"\nEnter your roll no.: ";
    cin>>rollno;
    f<<name<<endl;
    f<<dob<<endl;
    f<<branch<<endl;
    f<<rollno<<endl;
    f<<"bal"<<endl;
    k = 0;
    f<<k;
    f<<endl<<"xxx"<<endl<<endl;
    f.close();


}

/**
*A function for checking the correctness of the password.
*/
 bool mini::compare()
{
    int flag = 0;



    cout<<"Enter the ID \n";
    for(int i = 0 ; i < 10 ; i ++)
        cin>>code[i];
    char dos[10];
    string l=jjj(code);

    string line;
    f.open("mat.txt",ios::in);
    int pcode = 0;
    while(getline(f,line))
    {

        if(l==line)
        {

            getline(f,line);
            int k = atoi(line.c_str());
            if(k != 0)
            {
              cout<<"Your account is blocked due to multiple entries of incorrect password!!!\n";
              f.close();
              system("pause");
              return 0;
            }
            do
            {

                cout<<"Enter the 10-digit password: ";

                for(int i = 0 ; i < 10 ; i ++)
                {
                    dos[i] = getch();
                    cout<<"*";
                }
                string just = jjj(dos);

                getline(f,line);
                if(just == line)
                {
                    getline(f,line);
                    fname = "indi" + line + ".txt";
                    f.close();
                    return 1;
                }
                else
                {
                    pcode++;
                    cout<<"\nIncorrect, password try again!! \nYou have only "<<3-pcode<<" more tries!!!\n";
                }

            }while(pcode < 3);


        }
        if(f.eof())
            break;


    }
    f.close();

    if(pcode >= 3)
    {
        fstream cat,tem;
        cat.open("mat.txt",ios::in);
        tem .open("temp.txt",ios::out);


        while(cat)
        {
            getline(cat,line);
            if(l == line)
            {
                tem<<line<<endl;
                getline(cat,line);
                tem<<1<<endl;
            }
            else
                tem<<line<<endl;
        }
        tem.close();
        cat.close();

        cat.open("mat.txt",ios::trunc);
        cat.close();
        remove("mat.txt");
        rename("temp.txt","mat.txt");
        cout<<"\nYour Account is blocked!!\nContact the administrator for renewal...\n";
        system("pause");

        return 0;
    }


}

/**
*A function for printing the details of the account logged in
*/
void mini::printdetails()
{
string line2;
fstream bat;

bat.open(fname.c_str(),ios::in);

getline(bat,line2);
while(!(line2 == "bal"))
{
    cout<<line2<<endl;
    getline(bat,line2);
}
bat.close();
}
/**
*A function for checking the balance
*/

void mini::bala()
{
    fstream dog;
    double balance;
    string line3,l = "bal";
    dog.open(fname.c_str(),ios::in);


    while(!(line3 == "bal"))
    {
        getline(dog,line3);
    }
    getline(dog,line3);
    cout<<"\nYour balance is: Rs."<<line3<<endl<<endl;

    dog.close();
}
/**
*A function for depositing the given amount of money.
*/
void mini::deposit()
{
    string line,l = "bal",bal;
    int flag = 0;
    fstream bat;
    bat.open(fname.c_str(),ios::in|ios::out|ios::app);

    double balance,dep;


    cout<<"Enter the amount to be deposited: ";
    cin>>dep;
    if(dep < 0)
    {
        cout<<"\nSorry, but this is not a valid input\n";
    }
    fstream temp;
    temp.open("temp.txt",ios::out);


    while(bat)
    {
        getline(bat,line);
        if(line == l)
        {
            temp<<"bal"<<endl;


                bat>>balance;

                balance += dep;


                temp<<balance;


        }
        else
            temp<<line<<endl;
    }
    temp.close();
    bat.close();

    f.open(fname.c_str(),ios::trunc);
    f.close();
    remove(fname.c_str());
    rename("temp.txt",fname.c_str());


}
/**
*A function for withdrawing the given amount of money.
*/
void mini::withdraw()
{
    string line3,l = "bal";
    fstream bat;
    bat.open(fname.c_str(),ios::in|ios::out|ios::app);

    double balance,wit;

    cout<<"Enter the amount to be withdrawn: ";
    cin>>wit;
    if(wit < 0)
    {
        cout<<"Sorry,but a negative number is not a valid input!\n";
        return;
    }


    fstream temp;
    temp.open("temp.txt",ios::out);


    while(bat)
    {
        getline(bat,line3);
        if(line3 == l)
        {
            temp<<"bal"<<endl;

            bat>>balance;
            if(wit > balance)
                cout<<"The amount you entered is greater than the balance you have!!\n";
            else
                balance -= wit;
            temp<<balance;
        }
        else
            temp<<line3<<endl;
    }
    temp.close();
    bat.close();
    f.open(fname.c_str(),ios::trunc);
    f.close();
    remove(fname.c_str());
    rename("temp.txt",fname.c_str());


}
void mini::adminp()
{

    f.open("mat.txt",ios::in);
    char c[10], y = 'n';
    for(int i = 0 ; i < 10 ;i ++)
        c[i] = getch();
    string line2 = "´Á}‹ˆ";
    string ele = jjj(c),line,phan;
    try
    {
        getline(f,line);
        if(ele == line2)
        {
            cout<<"\nEnter the id of the account to be restored: ";
            for(int i = 0 ; i < 10 ;i ++)
                cin>>c[i];
            phan = jjj(c);

            while(f)
            {
                getline(f,line);
                if(phan == line)
                {
                    getline(f,line);
                    getline(f,line);
                    getline(f,line);
                    string hap = "indi" + line + ".txt";
                    fstream h;
                    h.open(hap.c_str(),ios::in);
                    string l;
                    getline(h,l);
                    while(l != "bal")
                    {
                        cout<<l<<endl;
                        getline(h,l);
                    }
                    h.close();
                    cout<<"\nIs the info correct\n";
                    cin>>y;
                    break;
                }

            }

            f.close();

            if(y == 'Y'||y == 'y')
            {
                f.open("mat.txt",ios::in);
                fstream temp;
                temp.open("temp.txt",ios::out);
                while(f)
                {
                    getline(f,line);
                    if(phan == line)
                    {
                        temp<<line<<endl;
                        getline(f,line);
                        temp<<0<<endl;
                    }
                    else
                    {

                        temp<<line<<endl;
                    }

                }
                f.close();
                temp.close();
                f.open("mat.txt",ios::trunc);
                f.close();
                remove("mat.txt");
                rename("temp.txt","mat.txt");
            }

        }
        else
            throw 1;

    }
    catch(int a)
    {
        cout<<"Incorrect Code!!\n";
    }

    f.close();
    system("pause");
    return;
}


