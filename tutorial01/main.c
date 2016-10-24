#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{

    int tuna = 18;
    int * ptuna = &tuna;
    printf("%p", ptuna);
    return 0;
}
