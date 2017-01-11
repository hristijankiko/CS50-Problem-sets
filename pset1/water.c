#include <stdio.h>

int main (void) {
  int i;

  printf("Minutes: ");
  scanf("%d", &i);
  printf("Bottles: %d", i * 12);
}