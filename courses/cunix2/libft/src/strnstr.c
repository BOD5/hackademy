#include "../libft.h"

char	*ft_strnstr(const char *str1, const char *str2, int len)
{
    int     i = 0;
    int     j = 0;
    if (!*str2)
        return (char*)str1;
    while(str1[i] && (i < len || len == -1))
    {
        if (str1[i] == str2[j])
        {
            while(str1[i + j] == str2[j] && ((i + j) < len || len == -1) && str1[i + j])
                j++;
            if (!str2[j])
                return ((char*)str1 + i);
            j = 0;
        }
        i++;
    }
    return NULL;
}
