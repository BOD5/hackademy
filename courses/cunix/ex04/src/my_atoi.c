int my_atoi(const char *nptr) {
  int number = 0;
  int sign = 1;
  int i = 0;
  if (nptr[i] == '-') {
    sign = -1;
    i+=1;
  }
  while (nptr[i] >= '0' && nptr[i] <= '9') {
    number = 10 * number + (nptr[i] - '0');
    i++;
  }
  number *= sign;
  return number;
}