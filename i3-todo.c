#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FONT "pango:Hack 6"

//clean old lines
int clean(FILE *clean)
{
}

//spwan messages
int generate(FILE *input)
{
    //arbitrarily set a max of 50 items of 20 words of 10 chars each
    char *items[50];
    int  i;
    char strline[12];
    char buffer[100];
    char *buf = buffer;
    size_t characters;
    int line =1;
    while(fgets(buffer,100,input))
    {
        i = 10;
        memset(items, 1, 50 * sizeof(items[0]));
        items[i] = strtok(buf, " ");
        i++;
        while(items[i] = strtok(NULL, " "))
            i++;
#ifdef FONT
        items[1] = "-f";
        items[2] = FONT;
#endif
        if(!strcmp(items[10], "low"))
        {
            items[10] = " ";
            items[3] = "-t";
            items[4] = "warning";
        }
        if(!strcmp(items[10], "high"))
        {
            items[10] = " ";
            items[3] = "-t";
            items[4] = "error";
        }
        items[5] = "-b";
        snprintf(strline, 6, "%d", line);
        items[6] = "i3-todo";
        items[7] = strline;
        line++;
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
