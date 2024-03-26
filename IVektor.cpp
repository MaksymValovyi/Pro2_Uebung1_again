#include <stdlib.h>
#include <iostream>
#include "IVektor.h"

using namespace std;

IVektor::IVektor(int n){
   //daten = new int[groesse];
   //this->groesse = groesse;
    this->daten = new int[n];
    this->groesse = n-1;


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

IVektor::IVektor(const IVektor &ivv) {
    this->groesse = ivv.groesse; this->daten = new int[this->groesse];
    if (this->daten != nullptr) {
        for (int i = 0; i < this->groesse; i++) 
        { 
            this->setAt(i, ivv.getAt(i));//getAt підкреслена, тому що вектор const
            //UPD, добавили гетАт для констр 
            //рядок 66
        } 
    }
}

IVektor::~IVektor() {
    if(this->daten != nullptr){
        delete[] this->daten;
        //!!!! ЯКЩО Є ДЕСТРУКТОР - ТРЕБА КОПІ-КОНСТРУКТОР
    }
}

int IVektor::getSize(){
    return this->groesse;
    int size =-1;
    bool like_comlicated = false;
    if(like_comlicated){
        //int number
    }
}

int IVektor::getAt(int n){
    int return_val=-1000;
    if(n<0){
        return 0;
    }else if(n>this->groesse){
        return this->daten[this->groesse];
    }else{
        return this->daten[n-1];
    }
}

int IVektor::getAt(int n) const{
    int return_val=-1000;
    if(n<0){
        return 0;
    }else if(n>this->groesse){
        return this->daten[this->groesse];
    }else{
        return this->daten[n-1];
    }
}

void IVektor::setAt(int n, int value){
    if(this->daten != nullptr){
        if(n<0){
            n=0;
        }else if(n>=this->groesse){

        }this->daten[n]=value;
    }
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
    
    if(this->daten !=nullptr && v.daten!=nullptr){
        int src_len=v.getSize();
        int dst_len = this->getSize();
        int src_ind = 0;
        int dst_ind = 0;

        while((src_ind <= src_len) && (dst_ind<dst_len)){
            this->setAt(dst_ind, v.getAt(src_ind));
            src_ind++;
            dst_ind++;
        }
    }
    
    
    /*
    if(this->groesse < v.groesse){
        howLong = this->groesse;
    }else{
        howLong = v.groesse;
    }
    for(int i = 0; i<=howLong; i++){
        //v.setAt(i)=v.getAt(i);
        this->daten[i]=v.getAt(i);
        //v.setAt(i, v.getAt(i));
    }
    */
    cout << "V2 before" << endl;
    //v.print();


    //Тут видаляється другий вектор, тому що ми виходимо з мемберу
    //Для цього нам потрібен копі-конструктор

    //!!!! ЯКЩО Є ДЕСТРУКТОР - ТРЕБА КОПІ-КОНСТРУКТОР
}

void IVektor::print(){
    cout << "Your Vektor" << endl;
    for (int i = 0; i <= this->groesse; i++){
        cout << this->daten[i] << endl;
    }
}