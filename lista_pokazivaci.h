#include <iostream>
using namespace std;

struct pacijent{
       int matbr;
       int dob;
};

struct tpacijenti{
       pacijent podaci;
       tpacijenti *sljedeci;
};

void InitL(tpacijenti *lista){
     lista->sljedeci=NULL;              
}

tpacijenti *FirstL(tpacijenti *lista){
     return lista->sljedeci;     
} 

tpacijenti *EndL(tpacijenti *lista){
    return NULL;
}

tpacijenti *NextL(int p, tpacijenti *lista){
     tpacijenti *zadnji;
     zadnji=lista;
     int brojac=0;
     while(zadnji->sljedeci){
          brojac++;
          zadnji=zadnji->sljedeci;
          if (brojac==p){
               if (zadnji->sljedeci==NULL) return EndL(lista);
               else{
                    return zadnji->sljedeci;
                    }
                                
               }                        
     }
}

tpacijenti *PreviousL(int p, tpacijenti *lista){
     tpacijenti *zadnji, *prethodni;
     prethodni=lista;
     zadnji=prethodni->sljedeci;
     int brojac=2;
     if(p==0 || p==1)cout<<"Prethodni ne postoji"<<endl;
     else{
          while(zadnji->sljedeci){
                prethodni=zadnji;
                zadnji=zadnji->sljedeci;
                prethodni->sljedeci=zadnji;
                brojac++;
                if(brojac==p){
                      return prethodni->sljedeci;            
                      }
          }                       
     }                 
}

tpacijenti *LocateL(int x, tpacijenti *lista){
     tpacijenti *zadnji;
     zadnji=lista;
     int brojac=1;
     while(zadnji->sljedeci){
         if(x==brojac) return zadnji->sljedeci;
         zadnji=zadnji->sljedeci;
         brojac++;
     }
     return EndL(lista);
}
void InsertL(pacijent x, int p, tpacijenti *lista){
     int brojac=0;
     tpacijenti *zadnji,*prethodni;
     prethodni=lista;
     zadnji=prethodni->sljedeci;
     while(prethodni->sljedeci){
                             if(p==brojac){
                                           tpacijenti *novi=new tpacijenti;
                                           novi->podaci.matbr=x.matbr;
                                           novi->podaci.dob=x.dob;
                                           novi->sljedeci=zadnji;
                                           prethodni->sljedeci=novi;
                             } 
     prethodni=prethodni->sljedeci;
     brojac++;
     }   
}

void unos(pacijent x, tpacijenti *lista){
     tpacijenti *zadnji, *novi;
     zadnji=lista;
     while(zadnji->sljedeci)
                            zadnji=zadnji->sljedeci;
     novi=new tpacijenti;
     novi->podaci=x;
     zadnji->sljedeci=novi;
     novi->sljedeci=NULL;
}     

void Delete(tpacijenti *lista, int matbr){
     tpacijenti *brisi=lista->sljedeci;
     tpacijenti *prethodni=lista;
     while(brisi){
                  if(brisi->podaci.matbr==matbr){
                                                prethodni->sljedeci=brisi->sljedeci;
                                                delete brisi;
                                                break;                              
                  }             
                  prethodni=brisi;
                  brisi=brisi->sljedeci;
     }     
}

void DeleteL(int p, tpacijenti *lista){
     int brojac=1;
     tpacijenti *zadnji,*prethodni, *brisi;
     prethodni=lista;
     zadnji=prethodni->sljedeci;
     while(prethodni->sljedeci){
                             if(p==brojac){
                                  brisi=prethodni->sljedeci;
                                  prethodni->sljedeci=brisi->sljedeci;
                                  delete brisi;
                             }                      
     }         
}

tpacijenti *RetrieveL(int p, tpacijenti *lista){
         int brojac=0;
         tpacijenti *trenutni;
         trenutni=lista;
         while(trenutni->sljedeci){
                                   if (p==brojac) return trenutni;
                                   else{
                                        brojac++;
                                        trenutni=trenutni->sljedeci;
                                   }
         }
}

void DeleteAllL(tpacijenti *lista){
     tpacijenti *zadnji, *brisi;
     while(lista->sljedeci){
                            brisi=lista->sljedeci;
                            zadnji=brisi->sljedeci;
                            lista->sljedeci=zadnji;
                            delete brisi;                       
     }    
}

void sort(tpacijenti *lista){
  tpacijenti *prethodni,*tekuci,*sljedeci;
  int indikator,brojac=0;
  do{
    indikator = 0;
    tekuci=lista->sljedeci;
    prethodni=lista;
    while (tekuci->sljedeci){
      sljedeci=tekuci->sljedeci;
      if (tekuci->podaci.matbr > sljedeci->podaci.matbr){
         prethodni->sljedeci=sljedeci;
         tekuci->sljedeci=sljedeci->sljedeci;
         sljedeci->sljedeci=tekuci;
         indikator=1;
      }
      prethodni=prethodni->sljedeci;
      tekuci=prethodni->sljedeci;
    }
  } while (indikator==1);
}

void ispis(tpacijenti *lista){
     tpacijenti *zadnji;
     zadnji=lista->sljedeci;
     while(zadnji){
                             cout<<"Maticni broj: "<<zadnji->podaci.matbr<<endl;
                             cout<<"Dob: "<<zadnji->podaci.dob<<endl;
                             cout<<"------------------"<<endl;
                             zadnji=zadnji->sljedeci;                                               
     }    
     
}

void ispisgodine(tpacijenti *lista){
     int brojac=0;
     tpacijenti *zadnji;
     zadnji=lista;
     while(zadnji){
         if (zadnji->podaci.dob<18){
            cout << "Maticni broj: "<<zadnji->podaci.matbr<<endl;
            cout << "Dob: "<<zadnji->podaci.dob<<endl;
            cout << "----------------"<<endl;
            brojac++;
         }
     zadnji=zadnji->sljedeci;
     }     
cout << "Mladih od 18 ima: "<<brojac<<endl;
}
