/* File:     list_int.c
 *
 * Purpose:  Implement a sorted linked list of ints with ops insert,
 *           print, member, delete, free_list.
 * 
 * IPP:   Section 4.9.1 (pp. 181 and ff.)
 */

#include <stdio.h>
#include <stdlib.h>
#include "list_int.h"

//#define DEBUG 1

//Extraído do livro ''An Introduction to Parallel Programming'', Peter Pacheco, Morgan Kaufmann, 2011 (cap4)


/*-----------------------------------------------------------------*/
/* Function:   Insert
 * Purpose:    Insert value in correct numerical location 
 *             into list.  If value is already in the list, 
 *             print a message and return 
 * In arg:     value, the value to be inserted            
 * In/out arg: head_pp, a pointer to the head of the list pointer
 * Return val: 1 if value was inserted, 0 otherwise
 */            
int Insert(int value, struct list_node_s** head_pp) {
   struct list_node_s* curr_p = *head_pp;
   struct list_node_s* pred_p = NULL;
   struct list_node_s* temp_p;
   
   while (curr_p != NULL && curr_p->data < value) {
      pred_p = curr_p;
      curr_p = curr_p->next;
   }

   if (curr_p == NULL || curr_p->data > value) {
      temp_p = malloc(sizeof(struct list_node_s));
      temp_p->data = value;
      temp_p->next = curr_p;
      if (pred_p == NULL)
         *head_pp = temp_p;
      else
         pred_p->next = temp_p;
#        ifdef DEBUG
      printf("%d was inserted in the list\n", value);
#        endif 
      return 1;
   } else { /* value in list */
#        ifdef DEBUG
      printf("%d is already in the list\n", value);
#        endif 
      return 0;
   }
}  /* Insert */

/*-----------------------------------------------------------------*/
/* Function:  Print
 * Purpose:   Print the contents of the list
 * In arg:    head_p, pointer to the head of the list
 */
void Print(struct list_node_s* head_p) {
   struct list_node_s* curr_p;

   printf("list = ");

   curr_p = head_p;
   while (curr_p != (struct list_node_s*) NULL) {
      printf("%d ", curr_p->data);
      curr_p = curr_p->next;
   }
   printf("\n");
}  /* Print */


/*-----------------------------------------------------------------*/
/* Function:    Member
 * Purpose:     Search list for value
 * In args:     value, the value to be searched for
 *              head_p, pointer to the head of the list  
 * Return val:  true, if value is in the list, false otherwise
 */
int  Member(int value, struct list_node_s* head_p) {
   struct list_node_s* curr_p;

   curr_p = head_p;
   while (curr_p != NULL && curr_p->data < value)
      curr_p = curr_p->next;

   if (curr_p == NULL || curr_p->data > value) {
#        ifdef DEBUG
      printf("%d is not in the list\n", value);
#        endif
      return 0;
   } else {
#        ifdef DEBUG
      printf("%d is in the list\n", value);
#        endif
      return 1;
   }
}  /* Member */

/*-----------------------------------------------------------------*/
/* Function:    Delete
 * Purpose:     If value is in the list, delete it.  Otherwise, just
 *              return.
 * In arg:      value, the value to be deleted
 * In/out arg:  head_pp, pointer to the head of the list pointer
 * Return val:  1 if value is deleted, 0 otherwise
 */
int Delete(int value, struct list_node_s** head_pp) {
   struct list_node_s* curr_p = *head_pp;
   struct list_node_s* pred_p = NULL;

   /* Find value */
   while (curr_p != NULL && curr_p->data < value) {
      pred_p = curr_p;
      curr_p = curr_p->next;
   }
   
   if (curr_p != NULL && curr_p->data == value) {
      if (pred_p == NULL) { /* first element in list */
         *head_pp = curr_p->next;
#        ifdef DEBUG
         printf("Freeing %d\n", value);
#        endif
         free(curr_p);
      } else { 
         pred_p->next = curr_p->next;
#        ifdef DEBUG
         printf("Freeing %d\n", value);
#        endif
         free(curr_p);
      }
      return 1;
   } else {
#     ifdef DEBUG
      printf("%d is not in the list\n", value);
#     endif
      return 0;
   }
}  /* Delete */

/*-----------------------------------------------------------------*/
/* Function:   Free_list
 * Purpose:    Free the storage used by the list
 * In/out arg: head_pp, pointer to the head of the list pointer
 *               on input, NULL on return
 */
void Free_list(struct list_node_s** head_pp) {
   struct list_node_s* curr_p;
   struct list_node_s* succ_p;

   if (Is_empty(*head_pp)) return;
   curr_p = *head_pp; 
   succ_p = curr_p->next;
   while (succ_p != NULL) {
#     ifdef DEBUG
      printf("Freeing %d\n", curr_p->data);
#     endif
      free(curr_p);
      curr_p = succ_p;
      succ_p = curr_p->next;
   }
#  ifdef DEBUG
   printf("Freeing %d\n", curr_p->data);
#  endif
   free(curr_p);
   *head_pp = NULL;
}  /* Free_list */

/*-----------------------------------------------------------------*/
/* Function:    Is_empty
 * Purpose:     Determine whether the list is empty
 * In arg:      head_p:  head of list pointer
 * Return val:  true, if head_p is NULL, false otherwise
 */
int  Is_empty(struct list_node_s* head_p) {
   if (head_p == NULL)
      return 1;
   else
      return 0;
}  /* Is_empty */

