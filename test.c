#include "CurrentRange.h"
#include <assert.h>

int main()
{
int *chkrange; 

printf("\n\nTest case 2");
int samplesarray1[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize1 = sizeof(samplesarray1) / sizeof(samplesarray1[0]);
chkrange = PrintRange(samplesarray1,arraysize1);
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
  
printf("\n\nTest case 3");
int samplesarray2[] = {3, 30, 5, 7, 10, 15, 12, 20};
int arraysize2 = sizeof(samplesarray2) / sizeof(samplesarray2[0]);
chkrange = PrintRange(samplesarray2,arraysize2);
//Test case to check number of range detected
assert(*(chkrange+3) == 0); 
  
printf("\n\nTest case 4");
int samplesarray3[] = {-3, -30, -5, -7, -10, -11, -12, 20, -6};
int arraysize3 = sizeof(samplesarray3) / sizeof(samplesarray3[0]);
chkrange = PrintRange(samplesarray3,arraysize3); 
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

  
printf("\n\nTest case 5");
int samplesarray4[] = {-2,-1,0,1,2,3,4,5};
int arraysize4 = sizeof(samplesarray4) / sizeof(samplesarray4[0]);
chkrange = PrintRange(samplesarray4,arraysize4);
//Test case to check start of range
assert(*(chkrange+4) == -2);
//Test case to check end of range
assert(*(chkrange+5) == 5);
//Test case to check number of readings in the range
assert(*(chkrange+6) == 8);
//Test case to check number of range detected
assert(*(chkrange+7) == 1);  
  
printf("\n\nTest case 6");
int samplesarray5[] = {};
int arraysize5 = sizeof(samplesarray5) / sizeof(samplesarray5[0]);
chkrange = PrintRange(samplesarray5,arraysize5);
//Test case to check number of range detected
assert(*(chkrange+3) == 0); 
  
return 0;
}
