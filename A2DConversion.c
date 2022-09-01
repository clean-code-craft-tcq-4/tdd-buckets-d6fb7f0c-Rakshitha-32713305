#include <math.h>
#include <stdio.h>

#define invalid -1;

int Amperearray[] = {};

int convertA2DToAmpere(int maxAmp,int A2Dvalue,int bitresolution)
{
   int Ampere = invalid;
   A2Dvalue = abs(A2Dvalue);
   int maxA2Dvalue = pow(2,bitresolution) - 2;
   if(A2Dvalue<=maxA2Dvalue)
   {
   float convertedvalue = (float)maxAmp * (float)A2Dvalue/(float)maxA2Dvalue; 
   Ampere = round(convertedvalue);
   }
   return Ampere;
}

void convertA2DToAmpereRange(int A2Dvaluearray[], int arraysize, int* Amperearray, int maxAmp, int bitresolution)
{
   int count=0;
   for(int index=0; index < arraysize; index++)
   {
     int Ampere = convertA2DToAmpere(maxAmp,A2Dvaluearray[index],bitresolution);
      if(Ampere != -1)
      {
         Amperearray[count] = Ampere;
         count++;
      }
   }
}
