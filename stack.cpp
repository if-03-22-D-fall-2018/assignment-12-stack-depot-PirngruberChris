#include "stack.h"

struct Node {
    struct Node* next;
    void* data;
};

struct StackImplementation {
    struct Node* head;
    int count;
};
/**
 * Used to create a stack structure.
 * @return The newly created stack.
 */
Stack create_stack(){
  Stack stack = (Stack) smalloc(sizeof(struct StackImplementation));
  stack->head = 0;
  stack->count = 0;
}

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack){
  Node* node = stack->head;
  while (node != 0) {
    Node* temp = node;
    node = node->next;
    sfree(temp);
  }
  sfree(stack);
}
/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void *data){
  Node* new_node = (Node*) smalloc(sizeof(struct Node));
  new_node->next = stack->head;
  new_node->data = data;
  stack->head = new_node;
  stack->count++;
}

/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack){
  return stack->count;
}

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void* pop_stack(Stack stack){
  if (stack->head == 0) {
    return 0;
  }
  else{
    Node* removed_node = stack->head;
    void* data = removed_node->data;
    stack->head = stack->head->next;
    sfree(removed_node);
    stack->count--;
    return data;
  }
}

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
*/
void* peek_stack(Stack stack){
  if (stack->count == 0) {
    return 0;
  }
  return stack->head->data;
}
