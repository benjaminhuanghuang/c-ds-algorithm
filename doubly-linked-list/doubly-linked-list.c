#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
  struct Node *prev;
};

typedef Node *NodePtr;


/*

*/
void deleteNodePtr(NodePtr *ptrHead, NodePtr *ptrTail, NodePtr ptrDel)
{
  printf("\ndeleteNode\n");
  NodePtr currNode = *ptrHead;
  NodePtr nextNode;

  if (ptrDel == NULL || currNode == NULL)
    return;

  if (currNode == ptrDel) //first node
  {
    deleteMe = currNode;
    currNode = currNode->next;
    free(deleteMe);
    *ptrHead = currNode;
    if (currNode)
      currNode->prev = NULL;
    else
      *ptrTail = NULL;
    return;
  }
  while (currNode != NULL)
  {
    nextNode = currNode->next;
    if (nextNode == ptrDel) //node to be deleated
    {
      currNode->next = nextNode->next;
      nextNode->next->prev = currNode;
      if (nextNode == *ptrTail)
        *ptrTail = nextNode->prev; //last node
      free(nextNode);
    }
    else
    {
      currNode = nextNode;
    }
  }
}