#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
  void *x;
  struct node *next;
  void (*print_x)(void *);
  void (*free_x)(void *);
} my_list ;

void free_int(void *x){
  free((int*)x);
}

void free_list(my_list *head){
  while(head != NULL){
    my_list *n = head->next;
    head->free_x(head->x);
    free(head);
    head = n;
  }
}

void print_int(void *x){
  int *c = x;
  printf("%d", *c);
}

void print_list(my_list *head){
  printf("[");
  if(head != NULL){
    head->print_x(head->x);
    head = head->next;
  }

  while(head != NULL){
    printf(", ");
    head->print_x(head->x);
    head = head->next;
  }
  printf("]\n");
}

void remove_first(my_list **head){
  if(*head == NULL)
    return;

  my_list *next = (*head)->next;
  (*head)->free_x((*head)->x);
  free(*head);
  *head = next;
}


int main(){
  my_list *head;
  int *x;
  head = malloc(sizeof(my_list));
  x = malloc(sizeof(int));
  *x = 5;
  head->x = x;
  head->print_x = &print_int;
  head->free_x = &free_int;
  head->next = NULL;

  head->next = malloc(sizeof(my_list));
  x = malloc(sizeof(int));
  *x = 6;
  head->next->x = x;
  head->next->free_x = &free_int;
  head->next->print_x = &print_int;
  head->next->next = NULL;

  print_list(head);

  remove_first(&head);

  print_list(head);

  free_list(head);

  return 0;
}
