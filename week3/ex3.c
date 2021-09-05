#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
  int data;
  struct linked_list *next;  
};

struct linked_list *head = NULL;


void print_list(){
  struct linked_list *node = head;

  printf("Print linked list:\n");

  while(node!=NULL){
    printf("%d\n", node->data);
    node = node -> next;
  }
}

void insert_first(int data){
  struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
  link->data = data;
  head = link;
  head->next = NULL;
}


void insert_node(int data, int num){
  if(head==NULL){
    insert_first(data);
  }else{
    struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
    link->data = data;
    link->next = NULL;
    struct linked_list *previous = head;
    struct linked_list *search = previous->next;
    for(int index=0;index<num - 1;index++){
      previous = search;
      search = search->next;
    }
    link->next=search;
    previous->next=link;
  }
  printf("%d node was inserted\n", data);
}

void delete_node(int num){
  if(num==0){
    printf("Cannot delete head node!\n");
    return;
  }

  struct linked_list *previous = head;
  struct linked_list *search = previous->next;

  for(int index=0;index<num - 1;index++){
      previous = search;
      search = search->next;
    }
    previous->next=search->next;
    printf("Deleted %d\n",search->data);
    free(search);
}


int main(){
  insert_node(1,0);
  insert_node(3,1);
  insert_node(5,2);
  
  print_list();

  insert_node(4,2);
  print_list();

  delete_node(2);
  print_list();

  insert_node(7,2);
  print_list();

  return 0;
}
