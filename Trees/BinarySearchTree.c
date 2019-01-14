#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

  int Value;
  nodeType * Right, Left;

} nodeType;


nodeType * insert(nodeType * base, int newKey) {

  nodeType * new, * finder;
  int trigger = 1;

  new = (nodeType *)malloc(sizeof(nodeType));

  new->Value = newKey;
  new->Right = NULL;
  new->Left = NULL;

  if(base == NULL) {

    base = new;
    base->Right = NULL;
    base->Left = NULL;


  }

  finder = base;

  while(trigger == 1) {

    if(newKey < finder->Value) {

      if(finder->Left == NULL) {

        finder->Left = new;

      } else {

        finder = finder->Left;
      }

    } else {

      if(finder->Right == NULL) {

        finder->Right = new;

      } else {

        finder = finder->Right;

      }
    }

  }

  return base;
}


int main() {

  nodeType * start;



  return 0;
}
