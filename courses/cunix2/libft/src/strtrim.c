#include "../libft.h"

char    *ft_strtrim(char const *s)
{
    int     start = -1;
    int     len = ft_strlen(s);
    char    *str;

    while ((s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n') && len)
        len--;
    while ((s[++start] == ' ' || s[start] == '\t' || s[start] == '\n') && len)
        len--;

    if(!(str = (char*)malloc(sizeof(char) * (len + 1))))
        return NULL;
    s = s + start;
    start = -1;
    while (++start < len)
        str[start] = *s++;
    str[start] = '\0';
    return str;
}
