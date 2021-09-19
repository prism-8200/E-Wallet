#include "mini.h"
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

int main()
{   int p;
    mini raju;
    cout<<" 1.New User \n 2.Existing User \n";
    cin>>p;
    switch(p)
    {
    case 1:
        raju.registera();
        break;

    case 2:

        if(raju.compare())
        {
            int q;
            cout<<"\nRecord Found! \n";
            do
            {

                cout<<"MENU:\n 1.Print Details \n 2.View Balance \n 3.Deposit money \n 4.Withdraw money \n 5.Exit \n";
                cin>>q;
                switch(q)
                {
                case 1:
                    raju.printdetails();
                    break;
                case 2:
                   raju.bala();
                    break;
                case 3:
                    raju.deposit();
                    break;
                case 4:
                    raju.withdraw();
                    break;
                case 5:
                    break;
                default:
                    cout<<"Incorrect option entered\n";
                    break;
                }
            }while(q!=5);
        }
        else
            {
                cout<<"Incorrect Credentials\n";
            }
        break;

    case 5897:
            raju.adminp();
            break;
    default:
            cout<<"Invalid option\n";
    }

    return 0;
}
