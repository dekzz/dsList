#include <iostream>
//#include "lista_pokazivaci.h"
#include "lista_polje.h"
using namespace std;

int main(){
    tpacijenti *lista=new tpacijenti;
    pacijent polje;
    InitL(lista);
    int izbor,matbr;
    do{
           cout << "------------IZBORNIK------------"<<endl;
           cout << "1. Dodavanje pacijenta"<<endl;
           cout << "2. Ispisivanje zapisa prema maticnom broju"<<endl;
           cout << "3. Ispis mladih od 18"<<endl;
           cout << "4. Brisanje pacijenta"<<endl;
           cout << "9. Izlaz iz programa"<<endl;
           cin >> izbor;
           switch(izbor){
                         case 1:
                              cout << "Unesite maticni broj: "<<endl;
                              cin >> polje.matbr;
                              cout << "Unesite dob: "<<endl;
                              cin >> polje.dob;
                              unos(polje,lista);
                              break;
                         case 2:
                              sort(lista);
                              ispis(lista);
                              break;
                         case 3:
                              cout << "Pacijenti mladi od 18 godina"<<endl;
                              cout << "-------------------------------"<<endl;
                              ispisgodine(lista);
                              break;
                         case 4:
                              cout << "Upisite maticni broj elementa koji zelite obrisati: ";
                              cin >> matbr;
                              Delete(lista, matbr);
                              break;
                         case 9:
                              break;              
                         default: cout << "Odabrali ste nepostojecu opciju!"<<endl;
                                  break;
           }
           
           
           
           
       
    } while(izbor!=9);   
return 0;    
}
