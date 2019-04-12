#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (close(argv[1]))
            return 0;
    }
    else
        if (generate())
            return 0;
    return 1
}
