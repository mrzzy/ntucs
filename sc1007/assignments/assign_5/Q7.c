#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
    int V;
    int E;
    int *visited; //store the visited vertices
    int **matrix;
}Graph;

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} Stack;

// You should not change the prototypes of these functions
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
////GRAPH////////////////////////////////////////////
void printGraphMatrix(Graph );
////////////////////////////////////////////

int Connected (Graph);

int main()
{
    Graph g;
    int i,j;
    
    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
       for(j=0;j<g.V;j++)
           g.matrix[i][j] = 0;
	
	g.visited = (int *) malloc(sizeof(int)*g.V);
    for(i=0;i<g.V;i++) g.visited[i] = 0;
    
    
    int V1, V2;
    printf("Enter a directed edge: (press a to stop)\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.matrix[V1-1][V2-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter a directed edge: (press a to stop)\n");
    }
    scanf("%*c");
    
    
    int res = Connected(g);
    if(res == 1)
        printf("The graph is strongly connected.\n");
    else
        printf("The graph is not strongly connected.\n");

    return 0;
}

/* Walk the given graph from the first vertex (v = 0).
 * g - Graph to walk. g.matrix[u][v] implies that edge y.
 * reversed - If true, traverses directed edges in the opposite direction.
 * Returns the number vertices traversed in the walk.
*/
int dfsWalk(Graph g, bool reversed) {
    // no vertices: none traversed
    if(g.V <= 1)  return 0;

    // init stack to traverse starting from first vertex
    Stack toWalk;
    memset(&toWalk, 0, sizeof(Stack));
    push(&toWalk, 0);

    // mark none as visited
    int nVisited = 0;
    memset(g.visited, 0, sizeof(int) * g.V);
    
    // perform dfs walk of graph
    while(toWalk.size > 0) {
        // visit next vertex in stack
        int vertex = peek(toWalk);
        pop(&toWalk);
        if(!g.visited[vertex]) {
            nVisited ++;
            g.visited[vertex] = 1;
        
            // queue non-visted, connected vertices for walking
            for(int connected = 0; connected < g.V; connected ++) {
                bool isConnected =  (reversed) ? 
                    g.matrix[connected][vertex] :
                    g.matrix[vertex][connected];
                if(isConnected) {
                    push(&toWalk, connected);
                }
            }
        }
    }

    return nVisited;
}


int Connected (Graph g)
{
    // kosaraju's algorithm: for a graph to be strongly connected
    // both forward and reversed traversal of directed edges must
    // traverse entire graph.
    int nForward = dfsWalk(g, false);
    int nBackward = dfsWalk(g, true);
    return nForward == g.V && nBackward == g.V;
}


void printGraphMatrix(Graph g)
{
    int i,j;

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.matrix[i][j]);
        printf("\n");
    }

}

void push(Stack *sPtr, int vertex)
{
	StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if(sPtr==NULL || sPtr->head==NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

int isEmptyStack(Stack s)
{
     if(s.size==0) return 1;
     else return 0;
}

int peek(Stack s){
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
	while(pop(sPtr));
}
