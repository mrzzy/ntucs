#include <stdio.h>
#include <stdlib.h>

int bottom_up_dp(int n, int *s, int *v, int C) {
  // write your code here
  //  init max value table memo table
  int maxValue[n + 1][C + 1];

  // build solution bottom up from base case
  for (int i = 0; i <= n; i++) {
    for (int c = 0; c <= C; c++) {
      // base case: no item or no capacity: value = 0
      if (i == 0 || c == 0) {
        maxValue[i][c] = 0;
        continue;
      }
      // case 1: skip item i
      int skip = maxValue[i - 1][c];
      // case 2: pick item i if we can fit it in
      int pick = 0;
      if (s[i] <= c) {
        pick = maxValue[i - 1][c - s[i]] + v[i];
      }
      maxValue[i][c] = (skip > pick) ? skip : pick;
    }
  }

  return maxValue[n][C];
}

int main() {
  int n, C;
  int function;
  int *s;
  int *v;
  int i, j;
  printf("Enter the number of items n:\n");
  scanf("%d", &n);
  printf("Enter the capacity C:\n");
  scanf("%d", &C);
  s = (int *)malloc(sizeof(int) * (n + 1));
  v = (int *)malloc(sizeof(int) * (n + 1));

  printf("Enter the sizes of items (as a list, separate by spacing:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &s[i]);

  printf("Enter the values of items (as a list, separate by spacing:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  printf("The maximum value is: %d \n", bottom_up_dp(n, s, v, C));
}
