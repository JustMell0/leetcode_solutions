#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x);
void itoa(int num, char* str);

int main(){
  int x = 123;
  printf("%d\n", reverse(x));
  return 0;
}

void itoa(int num, char* str) {
    sprintf(str, "%d", num);
}

int reverse(int x){
  char *str;
  itoa(x, str);
  char *r_str = malloc(strlen(str));
  for (int i = 0; i < strlen(str); i++){
    r_str[i] = str[strlen(str) - i];
  }
  return atoi(r_str);
}
