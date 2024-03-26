
#include <iostream>
using namespace std;

class IVektor
{
private:
    int groesse = 0;
    int *daten = nullptr;
public:
    IVektor(){
        int n=1;
        this->daten = new int[n];
        this->groesse = n;

        if(this->daten != nullptr){
                for (int i=0; i<this->groesse;i++){
                this->daten[i]=0;
            }
        }else{
                cout << "Memory alloc failure - Proper exception handling will \n";
        }
    }
    ~IVektor();
    IVektor(int);
    int getSize();
    int getAt(int n);
    int getAt(int n) const;
    void setAt(int , int );
    IVektor getSubVector(int, int );
    void setSubVector(IVektor);
    void print();
    IVektor(const IVektor &ivv);
};

