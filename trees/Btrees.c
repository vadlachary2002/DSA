#include <stdio.h>
#include <stdlib.h>
#define chary main()
#define order 3
#define MAX 2
#define MIN 1
#define scan(a) scanf("%d",&a)
struct branch {
  int val[MAX + 1], count;//we dont use index 0 only indices 1 2 3 are used
  struct branch *link[MAX + 1];
};

struct branch *root=NULL;

// Create a node
struct branch *createNode(int val, struct branch *child) {
  struct branch *newNode;
  newNode = (struct branch *)malloc(sizeof(struct branch));
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}

// Insert node
void insertNode(int val, int pos, struct branch *node,
        struct branch *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}

// Split node
void splitNode(int val, int *pval, int pos, struct branch *node,
         struct branch *child, struct branch **newNode) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (struct branch *)malloc(sizeof(struct branch));
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) {
    insertNode(val, pos, node, child);
  } else {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

// Set the value
int setValue(int val, int *pval,
           struct branch *node, struct branch **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1;
  }

  if (val < node->val[1]) {
    pos = 0;
  } else {
    for (pos = node->count;
       (val < node->val[pos] && pos > 1); pos--)
      ;
    if (val == node->val[pos]) {
      printf("Duplicates are not permitted\n");
      return 0;
    }
  }
  if (setValue(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      insertNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

// Insert the value
void insert(int val) {
  int flag, i;
  struct branch *child;

  flag = setValue(val, &i, root, &child);
  if (flag){
  	root = createNode(i, child);
  }
    
}

// Search node
void search(int val, int *pos, struct branch *myNode) {
  if (!myNode) {
  	printf("returned\n");
    return;
  }

  if (val < myNode->val[1]) {
    *pos = 0;
  } else {
//  	printf("ok ");
    for (*pos = myNode->count;(val < myNode->val[*pos] && *pos > 1); (*pos)--)
      ;
    if (val == myNode->val[*pos]) {
      printf("%d is found", val);
      return;
    }
  }
  search(val, pos, myNode->link[*pos]);

  return;
}

void traverse(struct branch *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traverse(myNode->link[i]);
      printf("%d ", myNode->val[i + 1]);
    }
    traverse(myNode->link[i]);
  }
}

int chary{
  int val, ch;
  while(printf("\nChoices\n")){
  	printf("1.insert\n");
  	printf("2.traverse\n");
  	printf("3.search\n");
  	printf("3.delete\n");
  	int choice;
  	scan(choice);
  	switch(choice){
  		case 1:
  			system("cls");
  			int data;
  			printf("enter data:");
  			scan(data);
  			insert(data);
  		case 2:
  			traverse(root);
  			int i=0;
  			printf("\n");
  			while(i<4){
  				printf("%d ",root->val[i++]);
			  }
  			break;
  		case 3:
  			system("cls");
  			int d1;
  			printf("enter data to seacrh:");
  			scan(d1);
  			search(d1,&ch,root);
  			break;
  		default:
  			system("cls");
  			printf("enter valid choice .....\n");
	  }
  }
  
}
