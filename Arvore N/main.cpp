/* main.cpp: Teste da classe arvore c/ N filhos.
 Implementa��o c/ lista de filhos.
 */

#include <cstdlib>
#include <iostream>
#include "ArvN.h"
using namespace std;

int main(void){
    
    arv_n *a[30], *p;
    int i;
    
    for (i = 0; i < 30; i++)
        a[i] = new arv_n(i);
    
    for (i = 1; i < 12; i++)
        a[0]->insere_filho(a[i]);
    
    for (i = 13; i < 16; i++)
        a[8]->insere_filho(a[i]);
    
    for (i = 16; i < 20; i++)
        a[14]->insere_filho(a[i]);
    
    for (i = 20; i < 23; i++)
        a[4]->insere_filho(a[i]);
	   
    cout << endl << "Arvore depois das insercoes " << endl;
    
    a[0]->mostra();
    cout<<endl;
    
    for (i=0;(i<10);i++)
        if (a[0]->remove_filho(4))
            cout << "Removido o filho de indice "<<4<<" do no " << 0 << endl;
        else
            cout << "Não foi possivel remover o filho de indice " << 4 << " do no " << 0 << endl;
    
    cout << endl << "Arvore depois das remocoes " << endl;
    
    a[0]->mostra();
    
    for (i=24;i<30;i++)
        a[0]->insere_filho(a[i]);
    
    cout <<endl<< "Arvore depois de novas insercoes "<<endl;
    a[0]->mostra();
    cout<<endl;
    
    p=a[0]->ret_filho(2);
    if (p!=NULL)
        cout<< "O filho de indice 2 do no 0 e o no "<<p->ret_val()<<endl;
    else
        cout << "O no 0 nao possui filho de indice 2"<<endl;
    
    p=a[8]->ret_filho(3);
    if (p!=NULL)
        cout << "O filho de indice 3 do no 8 e o no "<<p->ret_val()<<endl;
    else
        cout << "O no 8 nao possui filho de indice 3"<<endl;
    
    p=a[15]->ret_irmao();
    if (p!=NULL)
        cout<<"O irmao imediato do no 15 e o no "<<p->ret_val()<<endl;
    else
        cout << "O no 15 nao possui irmao imediato"<<endl;
    
    p=a[13]->ret_irmao();
    if (p!=NULL)
        cout << "O irmao imediato do no 13 e o no "<<p->ret_val()<<endl;
    else
        cout << "O no 13 nao possui irmao imediato"<<endl;
    
    for (i=1; i<30; i++)
        if (a[0]->busca(i))
            cout<<"Valor "<< i <<" presente na arvore."<<endl;
//    
//    delete a[0]; /* Obs: todos os elementos que est�o na arvore  
//                  s�o removidos  */
    
    int b = a[0]->maior_valor();
    
    system("PAUSE");                     
    return 0;
}