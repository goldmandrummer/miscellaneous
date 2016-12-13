#include <xinu.h>


/**
 * Destroys a linked list.
 * Arguments:
 * head    A pointer pointing to the first element of the linked list.
 *
 * Returns:
 * void
 *
 * Destroys (frees memory for) the whole linked list. 
 * You can either use recursion or a while loop.
 */
void List_destroy(Node * head)
{
  if(head == NULL)
    return;
  
  List_destroy(head -> next);
  free(head);
}

/**
 * Create and initialize a linked list. 
 *
 * Arguments:
 * value     The "value" of the new node
 * index     The "index" of the new node
 *
 * Returns:
 * Returns a newly constructed node. The node can be the head of a
 * linked list.
 * 
 * You should allocate memory in this function. 
 */
Node * List_create(int value, int index)
{
  Node * node = malloc(sizeof(Node));
  
  node -> index = index;
  node -> value = value;
  node -> next = NULL;
  
  return node;
}


/**
 * Inserting "value" and "index" into the correct location in the 
 * sparse array "head"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the linked list.
 * value     The "value" of the value
 * index     The "value" of the index
 *
 * Returns:
 * A sparse array
 *
 * This function inserts the node ["value", "index"] into the sparse
 * array "head", and ensures that the nodes remain in ascending order
 * by their "index".
 *
 * Before and after the call to this function, "head" must be in
 * ASCENDING order by the "index" of each node.
 */
Node * List_insert_ascend(Node * head, int value, int index)
{
  Node * insert_node = NULL;  // Create new Node using "index" and "value"
  insert_node = List_create(value, index);
  
  // If empty list
  if(head == NULL)
    {
      return insert_node;
    }
  
  // Don't add to list if 0 value
  if((value == 0))
    {
      printf("Zero value. Will not add to list. Returning original list.\n");
      return head;
    }
  
  // If last node
  if(head -> next == NULL)  //  || (head -> index == 0)
    {
      if(index > (head -> index))
        {
          head -> next = insert_node;  // Add new node at end
          return head;
        }
      if(index <= (head -> index))
        {
          insert_node -> next = head;  // Add original to end of new
          return insert_node;
        }
    }
  
  //Node * location = malloc(sizeof(Node));
  Node * location = List_search_index(head, index);  // End of first chunck -- "location" is to be followed by insert_node
  
  if(location -> index >= index)
    {
      insert_node -> next = location;
      return insert_node;
    }
  
  insert_node -> next = location -> next;  // Set insert_node to point to what location pointed to
  
  location -> next = insert_node;  // Set location to point to insert_node for COMPLETED insertion
  
  return head;
}


/**
 * This function deletes the node with the passed "index"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the sparse array.
 * index     The index to be deleted
 *
 * Returns: 
 * A sparse array with the node removed (the one with index)
 */
Node * List_delete(Node * head, int index)
{
  /*
    Method: make pointer to node before target node (end_first),
            make this end_first -> next = the node after the target node,
            the list now bypasses the target node.
  */
  
  if(head == NULL)  // Don't bother doing anything if empty list
    {
      //printf("Empty list\n");
      return NULL;
    }
  
  Node * end_first = NULL;
  
  end_first = List_search_index(head, index);  // Pointer to node before actual node to remove UNLESS (head -> index) == index
  
  if(end_first == NULL)  // If List_search_index FAILED
    return NULL;
  
  if((end_first -> index) == index)
    {
      end_first = end_first -> next;
      return end_first;
    }
    
  end_first -> next = end_first -> next -> next;  // end_first -> next  was node to remove, becomes the node AFTER the one to remove
  
  return head;  
}
