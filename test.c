#include "CurrentRange.h"
#include "A2DConversion.h"
#include <assert.h>

int main()
{
int *chkrange; 
int samplesarray[];
 int arraysize;
int *ptr; 
 
 //Test case for current value range check
printf("\n\nCurrentRange:Test case 1");
samplesarray[] = {3, 3, 5, 4, 10, 11, 12};
arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
chkrange = PrintRange(samplesarray,arraysize);
//Test case to check start of range
assert(*(chkrange+4) == 3);
assert(*(chkrange+8) == 10);
//Test case to check end of range
assert(*(chkrange+5) == 5);
assert(*(chkrange+9) == 12);
//Test case to check number of readings in the range
assert(*(chkrange+6) == 4);
assert(*(chkrange+10) == 3);
//Test case to check number of range detected
assert(*(chkrange+11) == 2);  
  
printf("\n\nCurrentRange:Test case 2");
 samplesarray[] = {3, 30, 5, 7, 10, 15, 12, 20};
 arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
chkrange = PrintRange(samplesarray,arraysize);
//Test case to check number of range detected
assert(*(chkrange+3) == 0); 
  
printf("\n\nCurrentRange:Test case 3");
 samplesarray[] = {-3, -30, -5, -7, -10, -11, -12, 20, -6};
 arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
chkrange = PrintRange(samplesarray,arraysize); 
//Test case to check start of range
assert(*(chkrange+4) == -12);
assert(*(chkrange+8) == -7);
//Test case to check end of range
assert(*(chkrange+5) == -10);
assert(*(chkrange+9) == -5);
//Test case to check number of readings in the range
assert(*(chkrange+6) == 3);
assert(*(chkrange+10) == 3);
//Test case to check number of range detected
assert(*(chkrange+11) == 2); 

  
printf("\n\nCurrentRange:Test case 4");
 samplesarray[] = {-2,-1,0,1,2,3,4,5};
 arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
chkrange = PrintRange(samplesarray,arraysize);
//Test case to check start of range
assert(*(chkrange+4) == -2);
//Test case to check end of range
assert(*(chkrange+5) == 5);
//Test case to check number of readings in the range
assert(*(chkrange+6) == 8);
//Test case to check number of range detected
assert(*(chkrange+7) == 1);  
  
printf("\n\nCurrentRange:Test case 5");
 samplesarray[] = {};
 arraysize5 = sizeof(samplesarray) / sizeof(samplesarray[0]);
chkrange = PrintRange(samplesarray,arraysize);
//Test case to check number of range detected
assert(*(chkrange+3) == 0); 
 
 /*********************************************************************************************/ 
  
//Test case for conversion check
assert(convertA2DToAmpere(10,1146,12) == 3);
assert(convertA2DToAmpere(10,4095,12) == -1);
assert(convertA2DToAmpere(10,4094,12) == 10);

//Test case for ampere value range check
printf("\n\nA2D:Test case 1");
int A2Dvaluearray[] = {4095};
int A2Darraysize = sizeof(A2Dvaluearray) / sizeof(A2Dvaluearray[0]);  
int Amperearray[] = {};
convertA2DToAmpereRange(A2Dvaluearray,A2Darraysize,Amperearray,10,12);
ptr = detectAndPrintRangeDetails(Amperearray,A2Darraysize);
//Test case to check number of range detected
assert(*(ptr+3) == 0);   
  

printf("\n\nA2D:Test case 2");
 A2Dvaluearray[] = {1146,4094};
 A2Darraysize = sizeof(A2Dvaluearray) / sizeof(A2Dvaluearray[0]);  
 Amperearray[] = {};
convertA2DToAmpereRange(A2Dvaluearray,A2Darraysize,Amperearray,10,12);
ptr = detectAndPrintRangeDetails(Amperearray,A2Darraysize);
//Test case to check number of range detected
assert(*(ptr+3) == 0);   
  

printf("\n\nA2D:Test case 3");
 A2Dvaluearray[] = {1146,1600,4094};
 A2Darraysize = sizeof(A2Dvaluearray) / sizeof(A2Dvaluearray[0]);  
 Amperearray[] = {};
convertA2DToAmpereRange(A2Dvaluearray,A2Darraysize,Amperearray,10,12);
ptr = detectAndPrintRangeDetails(Amperearray,A2Darraysize);
//Test case to check start of range
assert(*(ptr+4) == 3);
//Test case to check end of range
assert(*(ptr+5) == 4);
//Test case to check number of readings in the range
assert(*(ptr+6) == 2);
//Test case to check number of range detected
assert(*(ptr+7) == 1);    
  

printf("\n\nA2D:Test case 4");
 A2Dvaluearray[] = {-1000,-1146,-4094};
 A2Darraysize = sizeof(A2Dvaluearray) / sizeof(A2Dvaluearray[0]);  
 Amperearray[] = {};
convertA2DToAmpereRange(A2Dvaluearray,A2Darraysize,Amperearray,10,12);
ptr = detectAndPrintRangeDetails(Amperearray,A2Darraysize);
//Test case to check start of range
assert(*(ptr+4) == 2);
//Test case to check end of range
assert(*(ptr+5) == 3);
//Test case to check number of readings in the range
assert(*(ptr+6) == 2);
//Test case to check number of range detected
assert(*(ptr+7) == 1);
  

return 0;
}
