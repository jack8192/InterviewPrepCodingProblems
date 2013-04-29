/*
  Given a binary tree of left and right nodes,
  print the value for every node at level n where
  the root is defined to be level 1.

  The value stored in each node is the simplest of node numbering schemes:

                                 root=1                                 Level 1
                left=2                            right=3               Level 2
       left=4           right=5           left=6          right=7       Level 3
   left=8 right=9  left=10 right=11  left=12 right=13 left=14 right=15  Level 4

  etc.

*/
#include <stdio.h>
#include <stdlib.h>

//
// Module Under Test
//
#include "LevelnNodes.c"


void main () {

  struct _tree  root;         // Storage for root of tree is allocated

  struct _tree *curr_node;    // just a ptr to a tree is allocated
  struct _tree *next_node;
  struct _tree *nextl_node;
  struct _tree *nextr_node;

  //
  // build a tree for testing
  //

  // root, with two children, no grandkids
  root.lnode = calloc(sizeof(struct _tree),1);
  root.rnode = calloc(sizeof(struct _tree),1);
  root.valu  = 1;

  curr_node        = root.lnode;
  curr_node->lnode = NULL;
  curr_node->rnode = NULL;
  curr_node->valu  = 2;

  curr_node        = root.rnode;
  curr_node->lnode = NULL;
  curr_node->rnode = NULL;
  curr_node->valu  = 3;

  // have built a tree with nodes: 1,2,3
  LevelnNodes(1, &root);
  LevelnNodes(2, &root);
  LevelnNodes(3, &root);  // test for no nodes at that level

  printf("\nadding level 3 nodes....\n");

  //
  // Add two more nodes to left-interior of tree, and re-examine
  //
  curr_node        = root.lnode;

  curr_node->lnode = calloc(sizeof(struct _tree), 1);     // allocate a new node
  next_node        = curr_node->lnode;    // shallow copy ptr to node
  next_node->lnode = NULL;
  next_node->rnode = NULL;
  next_node->valu  = 4;
  nextl_node       = next_node;

  curr_node->rnode = calloc(sizeof(struct _tree), 1);     // allocate a new node
  next_node        = curr_node->rnode;    // shallow copy
  next_node->lnode = NULL;
  next_node->rnode = NULL;
  next_node->valu  = 5;
  nextr_node       = next_node;

  // have built a: 1,2,3,4,5 tree (note, nodes 6 and 7 are missing)
  LevelnNodes(3, &root);

  /*
     add more nodes, continue to create an unbalanced tree
  */
  printf("\nadding level 4 nodes....\n");

  // it is easiest to simply drill down from root
  curr_node        = root.lnode->lnode;
  if (curr_node->valu != 4) {
     printf("Error 4a\n");
  }
  curr_node->lnode = calloc(sizeof(struct _tree), 1);
  curr_node->rnode = NULL;

  next_node        = curr_node->lnode;
  next_node->lnode = NULL;
  next_node->rnode = NULL;
  next_node->valu  = 8;

  // drill down to node 5
  curr_node        = root.lnode->rnode;
  if (curr_node->valu != 5) {
     printf("Error 5a\n");
  }
  curr_node->lnode = calloc(sizeof(struct _tree), 1);     // allocate a new L node
  curr_node->rnode = calloc(sizeof(struct _tree), 1);     // allocate a new R node

  next_node        = curr_node->lnode;    // shallow copy ptr to node
  next_node->lnode = NULL;
  next_node->rnode = NULL;
  next_node->valu  = 10;

  next_node        = curr_node->rnode;    // shallow copy
  next_node->lnode = NULL;
  next_node->rnode = NULL;
  next_node->valu  = 11;

  //
  // Now have a: 1,2,3,4,5,8,10,11 tree
  //

  /*

  having setup the test tree, traverse to various depths

  */
  LevelnNodes(1, &root);
  LevelnNodes(2, &root);
  LevelnNodes(3, &root);
  LevelnNodes(4, &root);
  LevelnNodes(5, &root);
  LevelnNodes(0, &root);

  fflush(stdout);

} // end main
