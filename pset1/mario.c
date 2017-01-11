/*
Specification

Write, in a file called mario.c in your ~/workspace/pset1 directory, a program that recreates these half-pyramids using 
hashes (#) for blocks.

To make things more interesting, first prompt the user for the half-pyramids' heights, a non-negative 
integer no greater than 23.(The height of the half-pyramids pictured above happens to be 4, the width of each 
half-pyramid 4, with an a gap of size 2 separating them.)

If the user fails to provide a non-negative integer no greater than 23, you should re-prompt 
for the same again.

Then, generate (with the help of printf and one or more loops) the desired half-pyramids.

Take care to left-align the bottom-left corner of the left-hand half-pyramid with the 
left-hand edge of your terminal window.

*/

#include <stdio.h>

void printChar(char c, int times);

int main(void) {
  int height;

  // Get the height from user
  do {
    printf("Height: ");
    scanf("%d", &height);
  } while(height > 23 || height < 0);

  // Print the pyramid
  for(int i = 0; i < height; i++) {
    printChar(' ', height - i + 1);
    printChar('#', i + 1);
    printChar(' ', 2);
    printChar('#', i + 1);
    printChar(' ', height - i + 1);
    printf("\n");
  }
}

// Print a character n times
void printChar(char c, int n) {
  for(int i = 0; i < n; i++) {
    printf("%c", c);
  }
}