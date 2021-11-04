#include "../libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    int     i = 0;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
    if(!(str = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
        return 0;

    while (*s1)
        str[i++] = *s1++;
    while (*s2)
        str[i++] = *s2++;
    str[i++] = '\0';
    return str;
}
