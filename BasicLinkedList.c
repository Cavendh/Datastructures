#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

  char code[4];
  struct Node *Next;
  struct Node *Previous;

} NodeType;


NodeType * insertNewNodeSort(char * NewCode, NodeType ** L) {


  NodeType *New, *Find, *BeforeNew;
  int trigger = 1;
  int trigger2 = 1;
  int i = 0;

  New = (NodeType *)malloc(sizeof(NodeType));

  strcpy(New->code, NewCode);

  if(*L == NULL) {

    *L = New;
    (*L)->Previous = NULL;

  } else {

    Find = *L;

    while(trigger == 1) {

      if(New->code[i] < Find->code[i]) {

        if(Find->Previous == NULL) {

          New->Previous = NULL;
          New->Next = Find;
          Find->Previous = New;
          trigger = 0;
          trigger2 = 0;

        } else {

          BeforeNew = Find->Previous;
          Find->Previous = New;
          New->Next = Find;
          New->Previous = BeforeNew;
          BeforeNew->Next = New;
          trigger = 0;

        }


      }

      if(New->code[i] == Find->code[i]) {

        i++;
      }

      if(New->code[i] > Find->code[i]) {

        if(Find->Next == NULL) {

           Find->Next = New;
           New->Previous = Find;
           New->Next = NULL;
           trigger = 0;

        } else {

          Find = Find->Next;
          i = 0;

        }

      }

      if(i == 2 && New->code[i] == Find->code[i]) {

        BeforeNew = Find->Previous;
        Find->Previous = New;
        New->Next = Find;
        New->Previous = BeforeNew;
        BeforeNew->Next = New;
        trigger = 0;

      }


    }


  }

  if(trigger2 == 0) {

    return New;
  } else {

    return (*L);
  }

}

void insertNewLastNode(char * NewCode, NodeType ** L) {

  NodeType *New, *Find;

  New = (NodeType *)malloc(sizeof(NodeType));

  strcpy(New->code, NewCode);

  New->Next = NULL;

  if(*L == NULL) {

    *L = New;
    (*L)->Previous = NULL;



  } else {

    Find = *L;

    while(Find->Next != NULL)
      Find = Find->Next;

    Find->Next = New;
    New->Previous = Find;



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

    Last->Previous = NULL;

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

NodeType * previousNode(NodeType * L) {

  if(L->Previous != NULL) {

    L = L->Previous;
  } else {

    printf("Start of List, Cant Move\n");
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

    //insertNewLastNode(currstring, &start);
    start = insertNewNodeSort(currstring, &start);

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

    if(strncmp(command, "Previous", 8) == 0) {

      currNode = previousNode(currNode);
    }



  }  while(strncmp(command,"quit", 4) != 0);


  for(i = 0; i < numberItems; i++) {

    DeleteLastNode(&start);

  }




  return 0;
}
