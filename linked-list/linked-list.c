#include <stdlib.h>
#include <stdio.h>

struct Node
{
  // Any data type can be stored in this node
  void *data;
  struct Node *next;
};

typedef struct Node *NodePtr;

/*

*/
void push(struct Node** head_ref, void *new_data, size_t data_size) 
{ 
    // Allocate memory for node 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    new_node->data  = malloc(data_size); 
    new_node->next = (*head_ref); 
  
    // Copy contents of new_data to newly allocated memory. 
    // Assumption: char takes 1 byte. 
    int i; 
    for (i=0; i<data_size; i++) 
        *(char *)(new_node->data + i) = *(char *)(new_data + i); 
  
    // Change head pointer as new node is added at the beginning 
    (*head_ref)    = new_node; 
} 
  
void iterateList(struct Node *node, void (*fptr)(void *)) 
{ 
    while (node != NULL) 
    { 
        (*fptr)(node->data); 
        node = node->next; 
    } 
} 


// Function to print an integer 
void printInt(void *n) 
{ 
   printf(" %d", *(int *)n); 
} 
  
// Function to print a float 
void printFloat(void *f) 
{ 
   printf(" %f", *(float *)f); 
} 

int main() 
{ 
    NodePtr start = NULL; 
  
    // Create and print an int linked list 
    unsigned int_size = sizeof(int); 
    int arr[] = {10, 20, 30, 40, 50}, i; 
    for (i=4; i>=0; i--) 
       push(&start, &arr[i], int_size); 
    printf("Created integer linked list is \n"); 
    iterateList(start, printInt); 
  
    // Create and print a float linked list 
    unsigned float_size = sizeof(float); 
    start = NULL; 
    float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5}; 
    for (i=4; i>=0; i--) 
       push(&start, &arr2[i], float_size); 
    printf("\n\nCreated float linked list is \n"); 
    iterateList(start, printFloat); 
  
    return 0; 
} 