/*  ArvN.h
 Declara��o de classe "�rvore c/ N filhos".
 Implementa��o atrav�s de uma lista de filhos e ponteiro para pr�ximo.
 Equivalente a �rvore bin�ria.
 N�o h� limite no n�mero de filhos.
 Obs: Como a �rvore � identificada pelo seu n� raiz, nessa
 implementa��o os conceitos de "n�" e "�rvore" se misturam.
 */

class arv_n{
    int val;     /* valor armazenado na raiz */
    arv_n *prim, /* ponteiro para primeiro filho */
    *prox; /* ponteiro para irm�o */
    
public:
    arv_n(int valor); /* Construtor de �rvore sem sub-�rvores. */
    ~arv_n(void);     /* Destrutor: apaga todas as sub-�rvores. */
    
    int ret_val(void);       /* Retorna o valor armazenado na raiz. */
    arv_n *ret_filho(int i); /* Retorna a sub-�rvore correspondente ao
                              i-�simo filho ou NULL, caso este n�o exista.
                              */
    
    arv_n *ret_irmao(); /* Retorna, se houver, o irm�o imediato do n�.
                         Caso n�o haja, retorna NULL */
    
    void def_val(int valor); /* Modifica o valor armazenado na raiz. */
    
    /* Insere mais um filho. */
    void insere_filho(arv_n *sub);
    
    
    /* Remove, se houver, o i-�simo filho.
     Se houver remo��o, retorna true, sen�o false. */
    bool remove_filho(int i);
    
    arv_n *busca(int valor);   /* Verifica se um valor est� na �rvore.
                                Se estiver retorna um ponteiro para o
                                o n� que tem esse valor. Caso contr�rio,
                                retorna NULL. */
    
    void mostra(void);  /* Imprime o conte�do da �rvore em pr�-ordem */
};