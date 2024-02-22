#include <cs50.h>
#include <stdio.h>

int main(void)

//start size = i
//end size = j
//current size = k
//years passed = l

{
    int i;
    do
    {
        i = get_int("Start size: ");
    }
    while (i < 9);

    int j;
    do
    {
        j = get_int("End size: ");
    }
    while (i > j);

    int k = i;
    int l = 0;
    while (k < j)
    {
        k = (k + k / 3 - k / 4);
        l++;
    }
    printf("Years: %i\n", l);




}


