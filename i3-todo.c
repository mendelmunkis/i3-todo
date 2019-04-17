#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//clean old lines
int clean(FILE *clean)
{
}

//spwan messages
int generate(FILE *input)
{
    //arbitrarily set a max of 50 items of 20 words of 10 chars each
    char *items[50];
    int  i = 0;
    char buffer[100];
    char *buf = buffer;
    size_t characters;
    while(fgets(buffer,100,input))
    {
        i = 0;
        memset(items, 1, 50 * sizeof(items[0]));
        items[i] = strtok(buf, " ");
        i++;
        while(items[i] = strtok(NULL, " "))
            i++;
    }
    fclose(input);
    return 0;
}

// remove completed task
int close(char *x)
{
x=0;
}







int main(int argc, char *argv[])
{
    FILE *todo;
    char file[200];
    file[0] = '\0';
    strcat(file, getenv("HOME"));
    strcat(file, "/todo");
    if((todo = fopen(file, "r+")) == NULL)
    {
        printf("error opening %s\n", file);
        return 0;
    }
    if(argc == 2)
    {
        printf("test");
        if (close(argv[1]))
            return 1;
        return 0;
    }
    if(generate(todo))
        return 1;
    return 0;
}
