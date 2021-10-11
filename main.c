#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  elem val; 
  
  list_t *test_list = list_alloc();


  /* Methods for adding to the list. */
  printf("Inserting 4 in the front. \n");
  list_add_to_front(test_list, 4);
  printf("Inserting 16 in back. \n");
  list_add_to_back(test_list, 16);
  printf("Inserting 8 in place 2. \n");
  list_add_at_index(test_list, 8, 5);
  printf("Inserting 12 in the front. \n");
  list_add_to_front(test_list, 12);
  printf("Inserting 20 in back. \n");
  list_add_to_back(test_list, 20);
  printf("Inserting 24 in place 5. \n");
  list_add_at_index(test_list, 24, 5);
  list_print(test_list);

  /* Returns the length of the list. */
  printf("Length of the list = %d\n", list_length(test_list));


  /* Checks to see if the given element exists in the list. */
  printf("Is 7 in the list? = %d\n", list_is_in(test_list, 7));

  /* Returns the element at the given index. */
  printf("What's at place 4? It should be 20. = %d\n", list_get_elem_at(test_list, 4)); 

  
  printf("Remove from the back. 24 should be gone. = %d\n", list_remove_from_back(test_list));
  list_print(test_list);
  
  return 0;
}
