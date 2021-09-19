#ifndef MINI_H_INCLUDED
#define MINI_H_INCLUDED
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
class mini
{
private:
    string fname;
    int s=0;
    fstream f;
    streampos start;
    char code[10];
    string rollno;
    string name;
    string branch;
    string dob;
    char key1[11]="9873459385" ;
    char key2[11]="7324232847" ;

public:
    string jjj(char r[10]);
    void kkk(char c[],int n);
    void registera();
    bool compare();
    void printdetails();
    void bala();
    void deposit();
    void withdraw();
    void adminp();

};

#endif // MINI_H_INCLUDED

