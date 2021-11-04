#include "../libft.h"

void    *ft_memcpy(void *dest, const void *source, int count)
{
    int     i = 0;
    char    *s = (char*) source;

    if(!dest && !source)
        return NULL;
    while (i < count && s)
	{
		*((char *)dest + i) = *((char *)s + i);
		i++;
	}
    return dest;
}
