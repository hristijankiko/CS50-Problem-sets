/*
Specification
In credit.c, write a program that prompts the user for a credit card number and then 
reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number,
per the definitions of each’s format herein.

So that we can automate some tests of your code, we ask that your program’s last line
of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less,
and that main always return 0.

For simplicity, you may assume that the user’s input will be entirely numeric (i.e.,
devoid of hyphens, as might be printed on an actual card).

Do not assume that the user’s input will fit in an int! Best to use get_long_long from CS50’s library
to get users' input. (Why?)
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {
  long long number;
  long long didgits[19];
  int i = 0;
  int length = 0;
  int sum = 0;

  //Get credit card number
  printf("Number: ");
  scanf("%lld", &number);

  //Parse didgits
  while(number > 0) {
    didgits[length] = number % 10;
    number /= 10;
    length++;
  }

  //Skip the last(first in the array because its reversed) didgit if odd length
  if(length % 2 == 1) {
    i = 1;
  } else {
    i = 0;
  }

  //Calculate every secound number and add it to sum
  for(int j = i, tmp; j < length; j += 2) {
    tmp = didgits[j] * 2;

    while (tmp > 0){
      sum += tmp % 10;
      tmp /= 10;
    }
  }
  
  //Calculate every first number and add it to sum
  for(int j = abs(i - 1); j < length; j += 2) {
    sum += didgits[j];
  }

  //Print out card provider
  if(sum % 10 != 0) {
    printf("INVALID\n");
  } else {
    switch (didgits[length - 1]) {
      case 3:
        if(didgits[length - 2] == 4 || didgits[length - 2] == 7)
        printf("AMEX\n");
        break;
      case 4:
        printf("VISA\n");
        break;
      case 5:
        switch(didgits[length - 2]) {
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
            printf("MasterCard");
        }
    }
  }
  return 0;
}