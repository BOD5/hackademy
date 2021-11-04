#include "../libft.h"

void    *ft_memset (void *s, int c, size_t n)
{
    char    *str = (char *)s;
    size_t  i = 0;
    
    printf("res = %s\n", str);
	while (i < n)
    {
        printf("ch = %c\n", str[i]);
        str[i] = (char)c;
        printf("ch = %c\n", str[i]);
        i++;
    }
    s = str;
    return s;
}
