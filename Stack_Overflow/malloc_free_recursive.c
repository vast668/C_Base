#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *dummy = "1234567890";
const char* inlet = "_";

void do_something(int c, char* s){
  printf("%p %s\n", s, s);
  if (c < 10) {
    //char *ns = malloc(sizeof(char)*11);
    char *ns = calloc(11, sizeof(char));
    strncpy(ns, s, c);
    strncat(ns, inlet, 1);
    strncat(ns, &s[c+1],10-c);
    do_something(c+1, ns);
    free(ns);
    printf("free %d\n", c);
    // printf("%p %s\n", ns, ns);
  }
}

void main() {
  for(int i = 0; i < 1; i++) {
    //char *s = malloc(sizeof(char)*11);
    char *s = calloc(11, sizeof(char));
    strcpy(s, dummy);
    do_something(0, s);
    free(s);
    printf("free %d\n", i);
  }
}