
// Program to build and print a grapgh data structure.  

     #include <stdio.h>
     #include <stdlib.h>
     #include <string.h>

     #define MaxWordSize 20
     #define MaxVertices 50
     
     typedef struct gEdge {
        int child;  //'child' is the location of the child vertex
        int weight; // weight on the edge 
        struct gEdge *nextEdge;
     } GEdge, *GEdgePtr;

     typedef struct {
        char id[MaxWordSize+1];
        GEdgePtr firstEdge;
     } GVertex;

     typedef struct graph {
        int numV;
        GVertex vertex[MaxVertices+1];
     } *GraphPtr;

     int main() 
     {
        int numVertices;
        GraphPtr newGraph(int);
        void buildGraph(FILE *, GraphPtr);
        void printGraph(GraphPtr);
        FILE * in = fopen("graph.in", "r");
        fscanf(in, "%d", &numVertices);
        GraphPtr G = newGraph(numVertices);
        buildGraph(in, G);
        printGraph(G);
        fclose(in);
 

     } // end main

     GraphPtr newGraph(int n) 
     {
        if (n > MaxVertices) 
        {
           printf("\nToo big. Only %d vertices allowed.\n", MaxVertices);
           exit(1);
        }
        GraphPtr p = (GraphPtr) malloc(sizeof(struct graph));
        p -> numV = n;
        return p;
     } //end newGraph

     void buildGraph(FILE * in, GraphPtr G) 
     {
        int numEdges, weight;
        GVertex newGVertex(char[]);
        void addEdge(char[], char[], int, GraphPtr);
        char nodeID[MaxWordSize+1], adjID[MaxWordSize+1];
        for (int h = 1; h <= G -> numV; h++) 
        {
           G -> vertex[h] = newGVertex("");      //create a vertex node
           fscanf(in, "%s", G -> vertex[h].id);   //read the name into id
        }
        for (int h = 1; h <= G -> numV; h++) 
        {
           fscanf(in, "%s %d", nodeID, &numEdges); //parent id and numEdges
           for (int k = 1; k <= numEdges; k++) 
           {
              fscanf(in, "%s %d", adjID, &weight); //get child id and weight
              addEdge(nodeID, adjID, weight, G);
           }
        }
     } //end buildGraph

     GVertex newGVertex(char name[]) 
     {
        GVertex temp;
        strcpy(temp.id, name);
        temp.firstEdge = NULL;
        return temp;
     }

     void addEdge(char X[], char Y[], int weight, GraphPtr G) 
     {
        GEdgePtr newGEdge(int, int);
        //add an edge X -> Y with a given weight
        int h, k;
        //find X in the list of nodes; its location is h
        for (h = 1; h <= G -> numV; h++) 
          if (strcmp(X, G -> vertex[h].id) == 0) 
            break;

        //find Y in the list of nodes; its location is k
        for (k = 1; k <= G-> numV; k++) 
          if (strcmp(Y, G -> vertex[k].id) == 0) 
            break;

        if (h > G -> numV || k > G -> numV) 
        {
           printf("No such edge: %s -> %s\n", X, Y);
           exit(1);
        }

        GEdgePtr ep = newGEdge(k, weight); //create edge vertex
        // add it to the list of edges, possible empty, from X;
        // it is added so that the list is in order by vertex id
        GEdgePtr prev, curr;
        prev = curr = G -> vertex[h].firstEdge;
        while (curr != NULL && strcmp(Y, G -> vertex[curr -> child].id) > 0) 
        {
           prev = curr;
           curr = curr -> nextEdge;
        }

        if (prev == curr) 
        {
           ep -> nextEdge = G -> vertex[h].firstEdge;
           G -> vertex[h].firstEdge = ep;
        }
        else {
           ep -> nextEdge = curr;
           prev -> nextEdge = ep;
        }
     } //end addEdge

     GEdgePtr newGEdge(int c, int w) 
     {
        //return a pointer to a new GEdge node
        GEdgePtr p = (GEdgePtr) malloc(sizeof (GEdge));;
        p -> child = c;
        p -> weight = w;
        p -> nextEdge = NULL;
        return p;
     }

     void printGraph(GraphPtr G) 
     {
        for (int h = 1; h <= G -> numV; h++) 
        {
           printf("%s: ", G -> vertex[h].id);
           GEdgePtr p = G -> vertex[h].firstEdge;
           while (p != NULL) 
           {
              printf("%s %d ", G -> vertex[p -> child].id, p -> weight);
              p = p -> nextEdge;
           }
           printf("\n");
        }
     } //end printGraph





