#ifndef LevelnNodes_h
#define LevelnNodes_h

//
// value of a node and linkage between nodes
//
struct _tree {

  struct _tree *lnode;
  struct _tree *rnode;
  int valu;

};


int  LevelnNodes(int, struct _tree *t);
int  traverse(int, int, struct _tree *t, char);

#endif
