/*
  Given a binary tree of left and right nodes,
  print the value for every node at level n where
  the root is defined to be level 1.

*/
#include <stdio.h>
#include <stdlib.h>

#include "LevelnNodes.h"

/*
  Given current level, and expected level print or traverse a tree
  and return the number of nodes at the expected level.

  Note. the going parameter is used for debugging, but is left in
  the code with no significant effect, but is there to help in any future
  maintenance.

*/
int traverse(int lvl, int elvl, struct _tree *curr_lvl, char going) {

  //printf("\nat level %d, %c node",lvl, going);

  //
  // short-circuit deep searches past expected level
  //
  if (lvl > elvl)  {return 0;}

  if (lvl == elvl) {
     printf("\nHave a %c node at depth %d, valu=%d",going, lvl, curr_lvl->valu);
	 return 1;
  }

  //
  // too shallow
  //
  //printf("\n::drilling, at lvl=%d, valu=%d    \n",lvl,curr_lvl->valu);

  int nr_nodes = 0;
  if (curr_lvl->lnode != NULL) {
	  nr_nodes = nr_nodes + traverse(lvl+1, elvl, curr_lvl->lnode, 'L');
  }

  if (curr_lvl->rnode != NULL) {
	  nr_nodes = nr_nodes + traverse(lvl+1, elvl, curr_lvl->rnode, 'R');
  }


  return nr_nodes;

} // end traverse

int LevelnNodes(int n, struct _tree *root) {

  printf("\n\nValues of nodes at level %d::\n",n);

  if (n <= 0) {
    printf("Value of n=%d is too small\n",n);
	return 0;

  } else {
     // define root as level 1
	 int tot_nr_nodes;
     tot_nr_nodes = traverse(1,n,root,'T');
	 printf("\nHave %d nodes at level %d",tot_nr_nodes,n);
	 return tot_nr_nodes;

  }  // endif

} // endfunction
