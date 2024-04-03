#include <iostream>
//#include "IVektor.h"
#include "IVektor.cpp"
#include <time.h>
using namespace std;

int zufallNummer() {
    return rand() % 100 + 1; // zwischen 1 und 100
}

void test1(int chunkSize){
    IVektor v(chunkSize);
    cout << v.getSize() << endl;
}

void test2(){
    IVektor v1(10);
    IVektor v2(10);
    srand(time(NULL));
    for (int i = 0; i <= v1.getSize(); i++)
    {
        v1.setAt(i, zufallNummer());
    }
    for (int i = 0; i <= v2.getSize(); i++)
    {
        v2.setAt(i, zufallNummer());
    }
    v1.print();
    v2.print();
    
    v1.setSubVector(v2);
    
    v1.print();
    v2.print();
}

void test3() {
    IVektor v1(10);
    IVektor v2 = v1;
    for (int i = 0; i <= v1.getSize(); i++)
    {
        v1.setAt(i, zufallNummer());
    }
    v1.print();
    v2.print();
    for (int i = 0; i <= v2.getSize(); i++)
    {
        v2.setAt(i, zufallNummer());
    }
    v1.print();
    v2.print();
}

int main(int argc, char *argv[])
{
    int i=10;
    IVektor v1(10);
    IVektor v2(5);
    cout << i << " HELLO WORLD !\n";
    /*
    for (int i=0; i<=1000; i++){
        test1(100000000);
        cout << "how to clean memory";
    }
    */
    /*
        cout << v1.getSize() << endl;
        cout << v1.getAt(10) << endl;
        v1.setAt(1,123);
        cout << v1.getAt(5) << endl;
        v1.getSubVector(5,6);
        
        v1.setAt(0,12);
        v1.setAt(1,53);
        v1.setAt(6,3);
        v1.setAt(7,1);
        v1.setAt(10,1);
        v1.setAt(3,1);


        v2.setAt(4,122);
        v2.setAt(3,121);
        v1.setSubVector(v2);
    
    cout <<endl << "PRINT" << endl;
    v1.print();
    cout <<endl << "PRINT" << endl;
    v2.print();
    */

    //TEST 2
    //cout <<endl << "TEST 2" << endl;
    //test2();
    cout <<endl << "TEST 3" << endl;
    test3();
    return 0;
}