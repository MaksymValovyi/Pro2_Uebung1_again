#include <iostream>
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

void createSubVectorOnHeap(const IVektor &source, IVektor **pSubVec, int begin, int end) {

    if (begin < 0 || end > source.getSize() || begin > end) {
        std::cerr << "Ungueltiger Bereich fuer den Teilvektor." << std::endl;
        *pSubVec = nullptr;
        return;
    }


    int subVectorSize = end - begin + 1;


    *pSubVec = new IVektor(subVectorSize);


    for (int i = 0; i < subVectorSize; ++i) {
        (*pSubVec)->setAt(i, source.getAt(begin + i));
    }
}

int main(int argc, char *argv[])
{
    //TEST 1
    /*
    for (int i=0; i<=1000; i++){
        test1(100000000);
    }
    */
    //---------------------------------

    //TEST 2

    //cout <<endl << "TEST 2" << endl;
    //test2();
    //--------------------------------
    
    //TEST 3

    cout <<endl << "TEST 3" << endl;
    test3();
    //--------------------------------

    //AUFGABE 1.5
    /*
    IVektor source(10);
    std::cout << "Quellvektor:" << std::endl;
    for (int i = 0; i <= source.getSize(); i++)
    {
        source.setAt(i, zufallNummer());
    }
    source.print();

    // Erstellen eines Zeigers auf den Teilvektor
    IVektor *pSubVec = nullptr;

    // Aufrufen von createSubVectorOnHeap(), um den Teilvektor zu erstellen
    createSubVectorOnHeap(source, &pSubVec, 3, 9);

    // Überprüfen, ob der Teilvektor erfolgreich erstellt wurde
    if (pSubVec != nullptr) {
        // Ausgabe des Teilvektors
        std::cout << "Teilvektor:" << std::endl;
        pSubVec->print();

        // Freigabe des dynamisch allokierten Speichers
        delete pSubVec;
    }
    */
    //--------------------------------------------------------------------
    return 0;
}