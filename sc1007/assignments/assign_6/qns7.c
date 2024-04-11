#include <assert.h>
#include <stdio.h>
#include <string.h>

int F(int n, int *memo) {
  assert(n >= 0);
  // initial conditions: F(0-2)
  if (n <= 2)
    return n;
  // check if cached in memo
  if (memo[n] != -1)
    return memo[n];
  // recursively compute value
  memo[n] = F(n - 1, memo) + 2 * F(n - 2, memo) - 3 * F(n - 3, memo);
  return memo[n];
}

int top_down_dp(int n) {
  // write your code here
  int memo[n + 1];
  memset(memo, -1, sizeof(int) * (n + 1));
  return F(n, memo);
}

int main() {
  int n;
  int function;
  int i;
  printf("Enter the value of n:\n");
  scanf("%d", &n);

  printf("The value of F(%d) is: %d \n", n, top_down_dp(n));
}
