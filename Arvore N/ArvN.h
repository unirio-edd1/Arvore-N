/*  ArvN.h
 Declaração de classe "árvore c/ N filhos".
 Implementação através de uma lista de filhos e ponteiro para pr�ximo.
 Equivalente a árvore binária.
 Não há limite no número de filhos.
 Obs: Como a árvore é identificada pelo seu nó raiz, nessa
 implementação os conceitos de "nó" e "árvore" se misturam.
 */

class arv_n{
    int val;     /* valor armazenado na raiz */
    arv_n *prim, /* ponteiro para primeiro filho */
    *prox; /* ponteiro para irmão */
    
public:
    arv_n(int valor); /* Construtor de árvore sem sub-árvores. */
    ~arv_n(void);     /* Destrutor: apaga todas as sub-árvores. */
    
    int ret_val(void);       /* Retorna o valor armazenado na raiz. */
    arv_n *ret_filho(int i); /* Retorna a sub-árvore correspondente ao
                              i-ésimo filho ou NULL, caso este não exista.
                              */
    
    arv_n *ret_irmao(); /* Retorna, se houver, o irmão imediato do nó.
                         Caso não haja, retorna NULL */
    
    void def_val(int valor); /* Modifica o valor armazenado na raiz. */
    
    /* Insere mais um filho. */
    void insere_filho(arv_n *sub);
    
    
    /* Remove, se houver, o i-ésimo filho.
     Se houver remoção, retorna true, senão false. */
    bool remove_filho(int i);
    
    arv_n *busca(int valor);   /* Verifica se um valor está na árvore.
                                Se estiver retorna um ponteiro para o
                                o nó que tem esse valor. Caso contrário,
                                retorna NULL. */
    
    void mostra(void);  /* Imprime o conteúdo da árvore em pré-ordem */
    int grau() const;
    int altura() const;
    int filhos() const;
    int maior_valor() const;
};