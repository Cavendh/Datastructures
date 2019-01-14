#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

  int Value;
  struct node * Right, * Left;

} nodeType;


void printList(nodeType * base) {

    if(base != NULL) {

      printList(base->Left);
      printf("%d\n", base->Value);
      printList(base->Right);

    }

}


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


  } else {

  finder = base;

  while(trigger == 1) {

    if(newKey < finder->Value) {

      if(finder->Left == NULL) {

        finder->Left = new;
        trigger = 0;

      } else {

        finder = finder->Left;
      }

    } else {

      if(finder->Right == NULL) {

        finder->Right = new;
        trigger = 0;

      } else {

        finder = finder->Right;

      }
    }

  }

}

  return base;
}


int main(int argc, char * argv[]) {

  nodeType * start;
  int currVal, i;

  start = NULL;

  if(argc == 2) {



    for(i = 0; i < atoi(argv[1]); i++) {

      fscanf(stdin, "%d", &currVal);

      start = insert(start, currVal);

    }

  } else {

    printf("Error: Usage - Items in Tree, File for list\n");
    exit(0);
  }


  printList(start);


  return 0;
}
