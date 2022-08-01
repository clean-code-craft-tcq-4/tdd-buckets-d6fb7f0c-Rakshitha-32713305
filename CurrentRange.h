#include <stdio.h>
#include <stdlib.h>

typedef struct Range 
{
   int startvalue; int endvalue; int rangecount;
}Range;

int * detectAndPrintRangeDetails(int currentsamplesarray[],int arraysize);
int isConsecutive(int diff);
