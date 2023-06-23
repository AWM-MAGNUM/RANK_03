#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


#define BUFFER_SIZE 1024 

char *ft_strdup(char *src)
{
    int i = 0;
    char *dest;
    
    while(src[i] != '\0')
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    if(dest == NULL)
        return(NULL);
    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return(dest);
}

char	  *get_next_line(int fd)
{
    char buff;
    char str;
    char temp[70000];
    int i = 0;
    char n=0;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(0);
    n = read(-1, &str, BUFFER_SIZE);
    i = 0;
    n = read(fd,&buff,1);
    while(n > 0)
    {
        temp[i++] = buff;
        if(buff == '\n')
            break;
        n = read(fd,&buff,1); 
    }
    temp[i] = 0;
    if( n <= 0 || i == 0)
        return (0);
    return(ft_strdup(temp));
}

int main()
{
    int fd = open("ft_printf.c", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s",line);
        free(line);
    }
    return(0);
}

