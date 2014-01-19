#include <iostream>
using namespace std;

struct pacijent{
       int matbr;
       int dob;
};

struct tpacijenti{
       pacijent podaci[500];
       int kursor;
};

void InitL(tpacijenti *lista){
     lista->kursor=0;    
}

int FirstL(tpacijenti *lista){
     return 0;     
} 

int EndL(tpacijenti *lista){
     return lista->kursor;
}

int NextL(int p, tpacijenti *lista){
     if(p==lista->kursor-1) return EndL(lista);
                            if (p>=lista->kursor) cout << "Greska lista nije definirana"<<endl;
                            else{
                                 cout << "Maticni broj pacijenta "<<lista->podaci[p+1].matbr;
                                 cout << "Dob pacijenta "<<lista->podaci[p+1].dob;        
                            } 
}

void PreviousL(int p, tpacijenti *lista){
     if(p==lista->kursor) {
                   cout << "Maticni broj pacijenta "<<lista->podaci[lista->kursor-1].matbr;
                   cout << "Dob pacijenta "<<lista->podaci[lista->kursor-1].dob;
     }
     else{
     if (p<=0 || p>lista->kursor) cout << "Greska lista nije definirana"<<endl;
     else{
                             cout << "Maticni broj pacijenta "<<lista->podaci[p-1].matbr;
                             cout << "Dob pacijenta "<<lista->podaci[p-1].dob;        
                        }    
     }                   
}

int LocateL(int x, tpacijenti *lista){
     for (int i=0;i<lista->kursor;i++){
         if (lista->podaci[i].matbr==x) return i;
     }
     return EndL(lista);
}
void InsertL(pacijent x, int p, tpacijenti *lista){
     if(p>=0 && p<=lista->kursor){
             lista->kursor++;
             for (int i=lista->kursor-1;i>=p;i--){
                 lista->podaci[i]=lista->podaci[i-1];
                 }    
             lista->podaci[p]=x;
     }
     else cout << "Niste unijeli dobru poziciju"<<endl;     
} 

void unos(pacijent x, tpacijenti *lista){
    
     lista->podaci[lista->kursor]=x;
     lista->kursor++;         
}
void DeleteL(int p, tpacijenti *lista){
     if(p>=0 && p<=lista->kursor){
             for (int i=p;i<lista->kursor-1;i++){
                 lista->podaci[i]=lista->podaci[i+1];
                 }    
             lista->kursor--;
     }
     else cout << "Niste unijeli dobru poziciju"<<endl;     
}

pacijent RetrieveL(int p, tpacijenti *lista){
         if (p<0 || p>=lista->kursor) cout << "Krivo unesena pozicija"<<endl;
         else return lista->podaci[p];         
}

void DeleteAllL(tpacijenti *lista){
     lista->kursor=0;    
}

void sort(tpacijenti *lista){
     for (int i=1; i<lista->kursor; i++){
         int j=i-1;
         pacijent pom=lista->podaci[i];
         while(j>=0 && lista->podaci[j].matbr>pom.matbr)
                    lista->podaci[j+1]=lista->podaci[j--];
         lista->podaci[j+1]=pom;    
     }
}
void ispis(tpacijenti *lista){
     for(int i=0;i<lista->kursor;i++){
             cout << "Maticni broj: "<<lista->podaci[i].matbr<<endl;
             cout << "Dob: "<<lista->podaci[i].dob<<endl;
             cout <<"-------------------"<<endl;        
     }     
     
}

void ispisgodine(tpacijenti *lista){
     int brojac=0;
     for (int i=0;i<lista->kursor;i++){
         if (lista->podaci[i].dob<18){
            cout << "Maticni broj: "<<lista->podaci[i].matbr<<endl;
            cout << "Dob: "<<lista->podaci[i].dob<<endl;
            cout << "----------------"<<endl;
            brojac++;
         }}  
cout << "Mladih od 18 ima: "<<brojac<<endl;     
}

void Delete(tpacijenti *lista, int matbr){
     for (int i=0;i<lista->kursor;i++){
         if(lista->podaci[i].matbr==matbr){
                                              for (int j=i;j<lista->kursor-1;j++){
                                              lista->podaci[j]=lista->podaci[j+1];
                                              }
                                              lista->kursor--;                                     
         }    
     }
}







