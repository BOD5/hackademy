#include "../libft.h"

int     ft_memcmp(const void *st1, const void *st2, int size)
{
    const unsigned char    *s1 = (const unsigned char*)st1;
    const unsigned char    *s2 = (const unsigned char*)st2;

    if (s1 == s2 || size <= 0)
		return (0);
    while (*s1 == *s2 && size-- > 1)
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
