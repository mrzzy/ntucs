#include <stdio.h>
#include <stdlib.h>

int count = 0; // count the number of solutions
int V;         // number of regions

/* A utility function to print solution */
void printSolution(int *color) {
  printf("Solution Exists:"
         " Following are the assigned colors \n");
  for (int i = 0; i < V; i++)
    printf(" %d ", color[i]);
  printf("\n");
}

/* A utility function to check if
   the current color assignment
   is safe for vertex v i.e. checks
   whether the edge exists or not
   (i.e, graph[v][i]==1). If exist
   then checks whether the color to
   be filled in the new vertex(c is
   sent in the parameter) is already
   used by its adjacent
   vertices(i-->adj vertices) or
   not (i.e, color[i]==c) */
int isSafe(int v, int **graph, int *color, int c) {
  for (int i = 0; i < V; i++)
    if (graph[v][i] && c == color[i])
      return 0;
  return 1;
}

/* A backtracking function
to solve m coloring problem */
void graphColoring(int **graph, int m, int *color, int v) {
  // write your code here
  //  base case: no more vertices to color
  if (v >= V) {
    // found solution
    count++;
    return;
  }

  // attempt to color vertex v with available colors
  for (int c = 1; c <= m; c++) {
    // skip color if it breaks graph coloring invariant
    if (!isSafe(v, graph, color, c))
      continue;
    // color vertex v with color c
    color[v] = c;
    // recursively color remaining vertices.
    graphColoring(graph, m, color, v + 1);
  }

  // backtrack for more solutions
  color[v] = 0;
}

int main() {
  int m;
  int **graph;
  int *color;

  printf("Enter number of colors:\n");
  scanf("%d", &m);

  printf("Enter number of regions:\n");
  scanf("%d", &V);

  int i, j;
  color = (int *)malloc(V * sizeof(int));
  graph = (int **)malloc(V * sizeof(int *));

  for (i = 0; i < V; i++)
    graph[i] = (int *)malloc(V * sizeof(int));

  printf("Input the adjacency matrix:\n");
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      scanf("%d", &graph[i][j]);

  // Initialize all color values as 0.
  for (i = 0; i < V; i++)
    color[i] = 0;

  graphColoring(graph, m, color, 0);

  printf("There is/are total %d solution(s)", count);
  return 0;
}
