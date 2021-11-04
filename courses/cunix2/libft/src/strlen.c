#include "../libft.h"

int     ft_strlen(char const *s)
{
    int i = -1;
    while(s[++i]) ;
    return i;
}
