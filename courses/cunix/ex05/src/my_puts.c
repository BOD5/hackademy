#include <unistd.h>

int my_puts (const char *s) {
  int size = 0;
  while (s[size++] != '\0') ;
  write(1, s, size - 1);
  write(1, "\r\n", 1);
  return size;
}