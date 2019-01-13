#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

  char code[4];
  struct Node *Next;

} NodeType;

void insertNewLastNode(char * NewCode, NodeType ** L) {

  NodeType *New, *Find;

  New = (NodeType *)malloc(sizeof(NodeType));

  strcpy(New->code, NewCode);

  New->Next = NULL;

  if(*L == NULL) {

    *L = New;



  } else {

    Find = *L;

    while(Find->Next != NULL)
      Find = Find->Next;

    Find->Next = New;



  }


}


void printlist(NodeType * L) {

  int Counter = 0;

  if(L != NULL) {

    while(L->Next != NULL) {

      printf("%d: %s\n",Counter++,L->code);
      L = L->Next;

    }

    printf("%d: %s\n",Counter, L->code);

  }
}

void DeleteLastNode(NodeType ** L) {


  NodeType *Last, *NextToLast;

  if((*L)->Next == NULL) {

    free(*L);
    *L = NULL;

  } else {

    NextToLast = *L;
    Last = (*L)->Next;

    while(Last->Next != NULL) {
      NextToLast = Last;
      Last = Last->Next;

    }

    free(Last);
    NextToLast->Next = NULL;


  }

}

NodeType * nextNode(NodeType * L) {

  if(L->Next != NULL) {

    L = L->Next;

  } else {

    printf("End of List, Cant Move\n");
  }

  return L;

}

void printCurrNode(NodeType * L) {

  printf("%s\n", L->code);

}


int main(int argc, char * argv[]) {

  NodeType *start, *currNode;
  char command[100];
  int numberItems, i;
  FILE * CurrentFile;
  char currstring[4];

  start = NULL;

  if(argc == 3) {

    numberItems = atoi(argv[1]);

    CurrentFile = fopen(argv[2], "r");




  } else {

    printf("Error: Usage - Number of items in list, Filename");
    exit(0);
  }


  for (i = 0; i < numberItems; i++) {

    fgets(currstring, 4, CurrentFile);

    currstring[3] = '\0';

    insertNewLastNode(currstring, &start);

  }

  currNode = start;

  do {

    printf("Enter a new command:\n");
    fgets(command, 100, stdin);

    if(strncmp(command,"Next", 4) == 0) {

      currNode = nextNode(currNode);

    }

    if(strncmp(command,"printNode", 9) == 0) {

      printCurrNode(currNode);

    }

    if(strncmp(command, "printAll", 8) == 0) {

      printlist(start);
    }



  }  while(strncmp(command,"quit", 4) != 0);


  for(i = 0; i < numberItems; i++) {

    DeleteLastNode(&start);

  }




  return 0;
}
