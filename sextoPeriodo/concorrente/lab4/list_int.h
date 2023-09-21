/* File:     list_int.h
 *
 * Purpose:  Implement a sorted linked list of ints with ops insert,
 *           print, member, delete, free_list.
 * 
 * 
 * IPP:   Section 4.9.1 (pp. 181 and ff.)
 */

//Extraído do livro ''An Introduction to Parallel Programming'', Peter Pacheco, Morgan Kaufmann, 2011 (cap4)

#include <stdio.h>
#include <stdlib.h>

//elemnto da lista
struct list_node_s {
   int    data;
   struct list_node_s* next;
};

//insere elemento na lista (nao permite a inserção de valores repetidos) 
int  Insert(int value, struct list_node_s** head_p);

//verifica se ha um elemento com o valor dado na lista
int  Member(int value, struct list_node_s* head_p);

//exclui o elemento com o valor dado da lista, caso exista
int  Delete(int value, struct list_node_s** head_p);

//libera o espaco de memoria ocupado pela lista
void Free_list(struct list_node_s** head_p);

//verifica se a lista eh vazia
int  Is_empty(struct list_node_s* head_p);

//imprime a lista
void Print(struct list_node_s* head_p);

