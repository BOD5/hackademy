unsigned int  my_strlen (char * str) {
    unsigned int  len = 0;
  
    while(*str++)
    {
        len++;
    }
    return len;
}
