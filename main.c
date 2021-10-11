#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  elem val; 
  
  list_t *test_list = list_alloc();


  /* Methods for adding to the list. */
  printf("Insertions");
  printf("Insert front, then back, then at index 2");
  list_add_to_front(test_list, 4);
  list_add_to_back(test_list, 16);
  list_add_at_index(test_list, 8, 2);
  list_print(test_list);

  /* Returns the length of the list. */
  printf("Length of the list");
  list_length(test_list);


  /* Prints the list in some format. */
  list_print(test_list);

  /* Checks to see if the given element exists in the list. */
  printf("Is 7 in the list?");
  list_is_in(test_list, 7);

  /* Returns the element at the given index. */
  list_get_elem_at(test_list, 4);
  
  printf("Remove from the back");
  val = list_remove_from_back(test_list);
  return 0;
}
