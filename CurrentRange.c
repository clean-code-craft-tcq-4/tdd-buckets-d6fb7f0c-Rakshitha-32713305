#include "CurrentRange.h"

static int RangeValue[20][4];

int cmpfunc (const void * value1, const void * value2) 
{
   return ( *(int*)value1 - *(int*)value2 );
}

int calcRangeCnt(int consecutivecnt,int rangecnt,int start,int end)
{
   if(consecutivecnt!=0)
     {
        rangecnt++;
        printf("Range,Readings\n");
        printf("%d - %d, %d",start,end,consecutivecnt+1);
        RangeValue[rangecnt][0] = start;
        RangeValue[rangecnt][1] = end;
        RangeValue[rangecnt][2] = consecutivecnt+1;
      }
   return rangecnt;
}

int isConsecutive(int difference)
{
   int consecutive = 0;
   if((difference==0) || (difference)==1)
     consecutive=1;
   return consecutive;
}
               
   
int * PrintRange(int array[],int arraysize)
{ 
   int rangecount=0;
   int consecutivecount=0;
   int start=array[0];
   int end=array[0];
   int index = 0;
   int diff = 10;  
  
  qsort(array, arraysize, sizeof(int), cmpfunc);
 
  for( index = 0 ; index < arraysize; index++ ) 
     {  
        if((index+1) < arraysize)
        {
          diff = array[index+1] - array[index];        

            if(isConsecutive(diff)==1)
           {
              consecutivecount++;
              end = array[index+1];
           }
           else 
           {
              rangecount = calcRangeCnt(consecutivecount,rangecount,start,end);
              start = array[index+1];
              end = array[index];
              consecutivecount=0;
           }
        }
     }
  RangeValue[rangecount][3] = rangecount;  

  return &RangeValue[0][0];
}
