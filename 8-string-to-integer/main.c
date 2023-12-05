#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int myAtoi(char *s);

int main() {
  char *a = "42";
  char *b = "-  42";
  char *c = "-91283472332";

  printf("%d\n", myAtoi(a));
  printf("%d\n", myAtoi(b));
  printf("%d\n", myAtoi(c));
}

int myAtoi(char *s) {
  int n_digits = 0;
  int status = 0;

  if (*s == ' ') {
    return myAtoi(s + 1);
  }

  if (*s == '-') {
    status = 1;
    s++;
  } else if (*s == '+') {
    s++;
  }

  while (*s == '0') {
    s++;
  }

  for (char *p = s; *p; ++p) {
    if (*p < '0' || *p > '9') {
      break;
    }
    n_digits++;
  }

  if (n_digits == 0) { 
    return 0;
  } else if (n_digits > 10) {
    return (status) ? INT_MIN : INT_MAX;
  } else {
    long long int sum = 0LL;

    for (int i = 0; i < n_digits; ++i) {
      sum = sum * 10 + (s[i] - '0');

      if (n_digits == 10) {
        // Positive number out of bounds
        if (status == 0 && (sum > INT_MAX)) {
          return INT_MAX;
        }
        // Negative number out of bounds
        if (status && (-sum < INT_MIN)) {
          return INT_MIN;
        }
      }
    }
    return (status) ? (-sum) : (sum);
  }
}
