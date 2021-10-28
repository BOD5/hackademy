#include <stdlib.h>

char *my_itoa(int nmb) {
  int a = nmb;
  int i = 0;
  a = nmb;
  int j = 0;
  char ch;
  int minus = 0;
  char *tmp = (char*)malloc(12 * sizeof(char));
  if (a < 0) {
    a *= -1;
    minus = 1;
  }
  do {
    tmp[i++] = a % 10 + '0';
  } while ((a /= 10) > 0);
  if(minus) {
    tmp[i++] = '-';
  }
  tmp[i] = '\0';
  i -= 1;
  while ((i / 2) >= j) {
    ch = tmp[i - j];
    tmp[i - j] = tmp[j];
    tmp[j] = ch;
    j++;
  }
  return tmp;
}
