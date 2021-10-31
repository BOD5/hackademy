char    *my_strcpy(char *dest, const char *src) {
    int i = 0;
    
    for ( ; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i + 1] = '\0';
    return dest;
}