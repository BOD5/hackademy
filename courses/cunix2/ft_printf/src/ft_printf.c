#include "libftprintf.h"
#include <limits.h>

unsigned int  my_strlen (char * str) {
    unsigned int    len = 0;
    int             i = -1;

    while(str[++i] > 0)
    {
        len++;
    }
    return len;
}

int     my_atoi(const char *nptr) {
    int     number = 0;
    int     sign = 1;
    int     i = 0;

    if (nptr[i] == '-') {
        sign = -1;
        i+=1;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9') {
        number = 10 * number + (nptr[i] - '0');
        i++;
    }
    number *= sign;
    return number;
}

int     get_len(int n)
{
    int     len = 0;
    while ((n /= 10) > 0)
        len++;
    return len;
}

char    *my_itoa(int nmb) {
    unsigned int    a = nmb < 0 ? -nmb : nmb;
    int             i = 0;
    int             j = 0;
    char            ch;
    int             minus = 0;
    int             len = get_len(nmb);;
    char            *tmp = (char*)malloc((len + 1) * sizeof(char));

    if (nmb < 0)
        minus = 1;
    do 
    {
        tmp[i++] = a % 10 + '0';
    } while ((a /= 10) > 0);
    if(minus)
    {
        tmp[i++] = '-';
    }
    tmp[i] = '\0';
    i -= 1;
    while ((i / 2) >= j)
    {
        ch = tmp[i - j];
        tmp[i - j] = tmp[j];
        tmp[j] = ch;
        j++;
    }
    return tmp;
}

int     magic_print(char *tmp, int flags[], int width)
{
    // flags = [minus, plus, sp, zero];
    int     count = 0;
    char    space = ' ';
    char    first = ' ';
    char    *sp = NULL;
    int     len = my_strlen(tmp);

    if(flags[1] && !flags[2])
        first = '+';
    
    if ((flags[1] || flags[2]) && my_atoi(tmp) < 0)
    {
        first = '-';
        tmp = my_itoa(-my_atoi(tmp));
        len--;
    }
    if (width - len > 0)
    {
        sp = (char*)malloc(width - len);
        while (width-- > len)
            sp[width - len] = space;
    }
    if (flags[0])
    {
        if (flags[1] || flags[2])
        {
            write(1, &first, 1);
            write(1, tmp, len);
            if(sp)
            {
                write(1, &sp[1], my_strlen(&sp[1]));
                count += my_strlen(&sp[1]);
            }
        }
        else 
        {
            write(1, tmp, len);
            if(sp)
            {
                write(1, &sp[0], my_strlen(&sp[0]));
                count += my_strlen(&sp[0]);
            }
        }
    }
    else
    {
        if (flags[1] || flags[2])
        {
            write(1, &first, 1);
            if(sp)
            {
                write(1, &sp[1], my_strlen(&sp[1]));
                count += my_strlen(&sp[1]);
            }
        }
        else 
        {
            if(sp)
            {
                write(1, &sp[0], my_strlen(&sp[0]));
                count += my_strlen(&sp[0]);
            }
        }
        write(1, tmp, len);
    }
    count += len;
    if (sp)
        free(sp);
    return count;
}

int     ft_printf(const char *format, ...)
{
    int     i = 0;
    int     count = 0;
    int     width;
    char    *tmp;
    char    ch;
    int     len;
    int     minus_f;
    int     plus_f;
    int     sp_f;
    int     zero_f;
    int     d = 0;

    va_list args;

    va_start(args, format);

    while(format[i])
    {
        switch (format[i])
        {
        case '%':
            minus_f = 0;
            plus_f = 0;
            sp_f = 0;
            zero_f = 0;
            width = 0;
            i++;
            if (format[i] == ' ')
            {
                sp_f = 1;
                i++;
            }
            if (format[i] == '+')
            {
                plus_f = 1;
                i++;
            }
            if (format[i] == '-')
            {
                minus_f = 1;
                i++;
            }
            if (format[i] == '0' && !minus_f)
            {
                if(!minus_f)
                    zero_f = 1;
                i++;
            }
            int flags[] = { minus_f, plus_f, sp_f, zero_f };
            width = my_atoi(&format[i]);
            if (width)
                i += my_strlen(my_itoa(width));
            if (format[i] == '%')
            {
                write(1, &format[i], 1);
                count++;
                break;
            }
            
            switch (format[i])
            {
            case 'd':
                d = va_arg(args, int);
                tmp = my_itoa(d);
                len = magic_print(tmp, flags, width);
                count += len;
                free(tmp);
                break;
            case 's':
                tmp = va_arg(args, char*);
                if(!tmp)
                    break;
                for (int q = 1; q < 4; q++)
                    flags[q] = 0;
                len = magic_print(tmp, flags, width);
                count += len;
                break;
            case 'c':
                ch = va_arg(args, int);
                for (int q = 1; q < 4; q++)
                    flags[q] = 0;
                len = magic_print(&ch, flags, width);
                count += len;
                break;
            case 'i':
                tmp = my_itoa(va_arg(args, int));
                len = magic_print(tmp, flags, width);
                count += len;
                free(tmp);
                break;
            
            default:
                break;
            }
            break;
        
        default:
            write(1, &format[i], 1);
            count++;
            break;
        }
        i++;
    }
    return count;
}
