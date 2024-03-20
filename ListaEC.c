#include <stdio.h>
#include <stdlib.h>

//aqui eu declarei a  lista e seus atríbutos, ela será do tipo num, e apontará para o próximo. 
struct no{
    int num;
    struct no* next;
};

//Agora criarei uma função responsável por criar e inicializar o nó.
struct no* newno(int data){
    //nó, cria um objeto, que recebe
    struct no* newno=(struct no*)malloc(sizeof(struct no));
    if(newno == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }
    newno->num = data;
    newno->next = NULL;
    return newno;
}

//esta função adiciona um novo nó ao final da lista 
void add(struct no** headRef, int data){
    struct no* current = *headRef;
    struct no* newnode = newno(data);
    if(*headRef ==  NULL){
        *headRef = newnode;
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newnode;
}

//vou declarar a função que imprime os elementos da lista 
void imprime(struct no* head){
    struct no* current = head;
    while(current != NULL){
        printf("%d ->", current->num);
        current = current->next;
    }
    printf("NULL\n");
}

// aqui onde eu criarei os objetos da lista!
int main()
{
    struct no* head = NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);

    printf("Lista Encadeada: ");
    imprime(head);
   
    return 0;
}
