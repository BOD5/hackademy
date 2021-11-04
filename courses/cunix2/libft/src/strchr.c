#include "../libft.h"

char    *ft_strchr(const char *s, int c)
{
    if (c > 256)
        c %= 256;
    while (*s && *s != c) s++;
    if(!*s && c != '\0') 
        return 0;
    return (char*)s;    
}
