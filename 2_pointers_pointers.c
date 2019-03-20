#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct node {
  int x;
  struct node *next;
};

typedef struct node my_list;

void free_list(my_list *head){
  while(head != NULL){
    my_list *n = head->next;
    free(head);
    head = n;
  }
}

void print_list(my_list *head){
  printf("[");
  if(head != NULL){
    printf("%d", head->x);
    head = head->next;
  }

  while(head != NULL){
    printf(", %d", head->x);
    head = head->next;
  }
  printf("]\n");
}

void remove_first(my_list **head){
  if(*head == NULL)
    return;

  my_list *next = (*head)->next;
  free(*head);
  *head = next;
}


int main(){
  my_list *head;
  head = malloc(sizeof(my_list));
  head->x = 5;
  head->next = NULL;
  head->next = malloc(sizeof(my_list));
  head->next->x = 6;
  head->next->next = NULL;

  print_list(head);

  remove_first(&head);
  print_list(head);

  free_list(head);

  return 0;
}
