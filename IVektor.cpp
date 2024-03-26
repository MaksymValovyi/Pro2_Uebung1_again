
#include <iostream>
#include "IVektor.h"

using namespace std;

IVektor::IVektor(int n){
   //daten = new int[groesse];
   //this->groesse = groesse;
    this->daten = new int[n];
    this->groesse = n;


/* Це не круто
    for (int i=0; i<this->groesse;i++){
        this->daten[i]=0;
    }
    */
   if(this->daten != nullptr){
        for (int i=0; i<this->groesse;i++){
        this->daten[i]=0;
    }
   }else{
        cout << "Memory alloc failure - Proper exception handling will \n";
   }
}

IVektor::~IVektor() {
    delete[] daten;
}

int IVektor::getSize(){
    return this->groesse;
}

int IVektor::getAt(int n){
    if(n<0){
        return 0;
    }else if(n>this->groesse){
        return this->daten[this->groesse];
    }else{
        return this->daten[n-1];
    }
}

void IVektor::setAt(int n, int value){
    this->daten[n-1]=value;
}

IVektor IVektor::getSubVector(int begin, int end){
    IVektor vektor(end-begin);
    if(begin < 0){
        begin = 0;
    }


    for(int i = 0; i <= vektor.groesse; i++){
        vektor.daten[i]=begin;
        cout << "vektor [ " << i << " ] = " << begin << endl;
        begin++;     
    }

    return vektor;
}

void IVektor::setSubVector(IVektor v){
    int howLong;
    if(this->groesse < v.groesse){
        howLong = this->groesse;
    }else{
        howLong = v.groesse;
    }
    for(int i = 0; i<howLong; i++){
        this->daten[i-1]=v.getAt(i);
    }
}

void IVektor::print(){
    cout << "Your Vektor" << endl;
    for (int i = 0; i < this->groesse; i++){
        cout << this->daten[i] << endl;
    }
}