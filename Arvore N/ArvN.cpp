/* ArvN.cpp: Implementa��o da classe �rvore c/ N filhos.
 Implementa��o com lista de filhos.
 */

#include <iostream>
#include "ArvN.h"
using namespace std;

/* Construtor de �rvore sem sub-�rvores.  */
arv_n::arv_n(int valor){
    val = valor;
    prim = NULL;
    prox = NULL;
}

/* Destrutor: apaga todas as sub-�rvores. */
arv_n::~arv_n(void){
    arv_n *p,*q;
    
    for(p = prim; (p != NULL); p = q)
    {
        q = p->prox;
        delete p;
    }
}

/* Retorna o valor armazenado na raiz. */
int arv_n::ret_val(void){
    return val;
}

/* Retorna a sub-�rvore correspondente ao i-�simo filho ou NULL,
 caso este n�o exista.  */
arv_n * arv_n::ret_filho(int i){
    
    arv_n *p;
    int j = 0;
    
    if (i < 0) return NULL;
    for (p = prim; ( (p != NULL) && (j < i)); p = p->prox)
        j++;
    
    return p;
    
}

/* Retorna, se houver, o irm�o imediato do n�.
 Caso n�o haja, retorna NULL */
arv_n * arv_n::ret_irmao(){
    return prox;
}

/* Modifica o valor armazenado na raiz. */
void arv_n::def_val(int valor){
    val = valor;
}

/* Insere mais um filho. Insere no in�cio da lista de filhos. */
void arv_n::insere_filho(arv_n *sub){
    sub->prox = prim;
    prim = sub;
}

/* Remove, se houver, o i-�simo filho.Se houver remo��o,
 retorna true, sen�o false. */
bool arv_n::remove_filho(int i){
    
    int j = 0;
    arv_n *p, *ant = NULL;
    
    if (i < 0) return false;
    for (p = prim; ((j < i) && (p != NULL)); p = p->prox)
    {
        ant = p;
        j++;
    }
    if (p == NULL)
        return false;
    if (i == 0)
        prim = p->prox;
    else
        ant->prox = p->prox;
    delete p;
    return true;
}

/* Verifica se um valor est� na �rvore. Se estiver, retorna um ponteiro para o
 o n� que tem esse valor. Caso contr�rio, retorna NULL. */
arv_n * arv_n::busca(int valor){
    arv_n *p, *ret;
    
    /* Se � igual ao valor armazenado, n�o precisa procurar mais. O n� � a raiz. */
    if (valor == val)
        return this;
    
    /* Sen�o, procura nos filhos */
    ret = NULL;
    for (p = prim; p != NULL; p = p->prox)
        if ((ret = p->busca(valor)) != NULL)
            return ret;
    return NULL;
}


/* Imprime o conteúdo da árvore em pré-ordem */
void arv_n::mostra(void){
    cout << "(" << val;
    for (arv_n *p = prim;(p != NULL); p = p->prox)
        p->mostra();
    cout<<")";
}

int arv_n::altura() const{
    arv_n *p;
    int altura_arvore = -1;
    int altura_filho = -1;
    
    for (p = prim; p != NULL; p = p->prox) {
        altura_filho = p->altura();         // calcula a altura de cada filho recursivamente
        if (altura_filho > altura_arvore)
            altura_arvore = altura_filho;   // guarda a maior altura dos filhos
    }
    
    return altura_arvore + 1;
}

int arv_n::grau() const{
    arv_n *p;
    int grau = 0;
    int grauMax = 0;
    
    for (p = prim; p!=NULL; p = p->prox)
        grauMax++;                          // obtém o grau dos filhos da raiz
    for (p = prim; p!=NULL; p = p->prox) {
        grau = p->grau();                   // obtém o grau dos filhos dos filhos
        if (grau > grauMax)
            grauMax = grau;
    }
    return grauMax;
}

int arv_n::maior_valor() const{
    int maior = INT_MIN;
    
    for (arv_n * filho = prim; filho !=NULL; filho=filho->prim){
        for (arv_n * irmao = prox; irmao != NULL; irmao=irmao->prox){
            if (this->val > maior)
                maior = this->val;
        }
    }
    return maior;
}

int arv_n::filhos() const{
    int i = 0;
    for (arv_n *filho = prim; filho != NULL && filho->prox != NULL; filho = filho->prox, i++){}
    return i;
}


