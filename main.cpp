#include <iostream>
//#include "IVektor.h"
#include "IVektor.cpp"

using namespace std;

void test1(int chunkSize){
    IVektor v(chunkSize);
    cout << v.getSize() << endl;
}

void test2(){
    IVektor v1(10);
    IVektor v2(10);
    v1.setAt(1,12);
    v1.setAt(2,53);
    v1.setAt(3,3);
    v1.setAt(4,1);
    v1.setAt(5,1);
    v1.setAt(6,1);

    v2.setAt(4,122);
    v2.setAt(3,121);
    v2.setAt(1,124);
    v2.setAt(6,125);
    v2.setAt(8,126);
    v2.setAt(9,127);
    v1.print();
    v2.print();
    v2.setSubVector(v1);
    v1.print();
    v2.print();
}

int main(int argc, char *argv[])
{
    int i=10;
    IVektor v1(10);
    cout << i << " HELLO WORLD !\n";
    //for (int i=0; i<=1000; i++){
    //    test1(100000000);
    //    cout << "how to clean memory";
    //}
    cout << v1.getSize() << endl;
    cout << v1.getAt(10) << endl;
    v1.setAt(1,123);
    cout << v1.getAt(5) << endl;
    v1.getSubVector(5,6);
    IVektor v2(5);
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
    
    cout <<endl << "TEST 2" << endl;
    test2();
    return 0;
}
