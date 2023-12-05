#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);


int main() {
  int x = 121;
  bool result = isPalindrome(x);
  printf("%d\n", result);

  int y = -121;
  result = isPalindrome(y);
  printf("%d\n", result);
  return 0;
}

bool isPalindrome(int x) {
  if (x < 0)
    return false;
  return true;
}
