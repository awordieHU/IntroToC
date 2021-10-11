// list/list.c
// 
// Implementation for linked list.
//
// Akosua Wordie

//Colllab: Dr. Burge and Izzac Ballard

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() {
  list_t *l = malloc(sizeof(list_t));
  l->head = NULL;
  return l; 
}

node_t *node_alloc(elem val){
  node_t *n = malloc(sizeof(node_t));
  n->value = val; 
  n->next = NULL; 
  return n;
}

void list_free(list_t *l) {
  node_t *tempp, *currp;
  if(l->head != NULL){
    if(l->head->next != NULL){
      currp = l->head;
    while(currp != NULL){
      tempp = currp->next;
      free(currp);
      //l->head = tmp; ????
      currp = tempp;
    }
  }
  else{
    free(l->head);
  }
  l->head = NULL;
  }
}

void node_free(node_t *n){
  free(n);
}

void list_print(list_t *l) {
  node_t *cur = l->head;
  while (cur != NULL){
    printf("%d\n", cur->value);
    cur = cur-> next; 
  }
}



int list_length(list_t *l) {
    node_t *current = l->head; 
    int len = 0; 
    while (current != NULL){
      len++;
      current = current-> next; 
    }
    return len;     
}


void list_add_to_front(list_t *l, elem value) {
  node_t *newNode; 
  newNode = node_alloc(value);
  newNode ->next = l->head; 
  l->head = newNode;   
}



void list_add_at_index(list_t *l, elem val, int index) {
  int i = 0;
  node_t *newNode = node_alloc(val);
  node_t *current = l->head;
  
  if (index==0){
    list_add_to_front(l, val);
  }
  else if (index > 0){
    while (i < (index - 1) && current -> next != NULL){
      current = current->next;
      i++;
    }
  newNode -> next = current -> next; 
  current->next= newNode; 
  }
}


void list_add_to_back(list_t *l, elem value) {
  node_t *newNode = node_alloc(value);
  newNode -> next = NULL;
  if (l->head == NULL){
    l->head = newNode;  
  }
  else{
    node_t *current = l->head;
    while (current->next != NULL){
      current = current->next; 
    }
    current->next = newNode;
  }

}

elem list_remove_from_front(list_t *l) {
  node_t *current;
  elem value = (elem) -1;
  if (l->head == NULL){
    return value; 
  }
  else{
    current = l->head; 
    value = current ->value; 
    l->head = l->head->next; 
    node_free(current);
  }
  
  return value; 
}

elem list_remove_at_index(list_t *l, int index) { 
  int i = 0;
  elem value = (elem) -1;
  
  bool found = false; 
  
  if (l->head == NULL){
    return value; 
  }
  else if (index == 0){
    return list_remove_from_front(l);
  }
  else if (index > 0){
    node_t *current = l->head;
    node_t *prev = current;
   
    i=0;
    while(current != NULL && !found){
      if (i == index){
        found = true; 
      }
      else{
        prev = current;
        current = current -> next; 
        i++;
      }
    }
    if (found){
      value = current->value; 
      prev->next = current->next; 
      node_free(current);
    }
  }
  return value; 
}

elem list_remove_from_back(list_t *l) { 
  elem value = (elem) -1;
  node_t *current = l->head; 
  if (l->head != NULL){
    if (current -> next == NULL){
      l->head = NULL;
      value = current->value; 
      node_free(current);
    }
    else{
      while (current->next->next != NULL){
        current = current -> next;
      }
      value = current -> next -> value; 
      node_free(current->next->next);
      current -> next = NULL; 
    }
  }
  return value; 
}

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l->head; 
  while (current != NULL){
    if(value == current->value){
      return true;
    }
    current = current->next;
  }
return false; 
}


elem list_get_from_front(list_t *l){
  node_t *current;
  elem value = (elem) -1;
  if (l->head == NULL){
    return value; 
  }
  else{
    current = l->head; 
    value = current ->value; 
  }
  return value; 
}
  

elem list_get_elem_at(list_t *l, int index) {
  int i; 
  elem value = (elem) -1;
  if(l->head == NULL){
    return value; 
  }
  else if (index ==0){
    return list_get_from_front(l);
  }
  else if (index > 0){
    node_t *current = l->head; 
    i=0;
    while (current != NULL){
      if (i == index){
        return (current->value);
      }
      else{
        current = current->next;
        i++;
      }
    }
  }
  return value; 
}


int list_get_index_of(list_t *l, elem value) {
  int i = 0; 
  node_t *current = l->head; 
  if (l->head == NULL){
    return -1; 
  }
  while(current != NULL){
    if (value == current->value){
      return i; 
    }
    current = current->next;
    i++;
  }
  return -1;
}

