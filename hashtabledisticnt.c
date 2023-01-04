
#include <stdio.h>
#include <stdlib.h>

#define N 13
#define Empty 0

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr newNode(int n);
int search(int, NodePtr[], int);
void printList(NodePtr);
int main()
{
    int j, key, count = 0;
    FILE *in = fopen("numbers.in", "r");

    // also could test if able to open file if statement

    NodePtr hash[N];
    // initialize table of pointers to NULL
    for (j = 0; j < N; j++)
    {
        hash[j] = NULL;
    }

    while (fscanf(in, "%d", &key) == 1)
    {
        int value = search(key, hash, N);
        if (value == 0)
        {
            count++;
        }
    }
    printf("There are %d distinct numbers \n\n", count);

    // print out the values inserted into the hash table
    for (j = 0; j < N; j++)
    {
        // add code: print out the list of values for each index in table
        printf("Hash[%d]->", j);
        printList(hash[j]);
    }
    fclose(in);
}
NodePtr newNode(int n)
{
    NodePtr p = (NodePtr)malloc(sizeof(Node));
    p->num = n;
    p->next = NULL;
    return p;
}

int search(int inKey, NodePtr hash[], int n)
{
    int k = inKey % n + 1;
    NodePtr curr = hash[k];
    NodePtr prev = NULL;

    while (curr != NULL && inKey == curr->num)
    {
        return 1; // key is found
    }

    /*insert--*/
    // key is not found, inKey is new, add to likst +order
    NodePtr np = newNode(inKey);

    np->next = curr;
    if (prev == NULL)
    {
        hash[k] = np;
    }
    else
    {
        prev->next = np;
    }
    return 0;
}

void printList(NodePtr front)
{
    while (front != NULL)
    {
        printf("%2d->", front->num);
        front = front->next;
    }
    printf("\n");
}
