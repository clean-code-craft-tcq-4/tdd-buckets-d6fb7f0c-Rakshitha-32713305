#include "CurrenttRange.h"
#include <assert.h>

int main()
{
int *chkrange;

int samplesarray[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
chkrange = detectAndPrintRangeDetails(samplesarray,arraysize);
//check start of range
assert(*(chkrange+4) == 3);
assert(*(chkrange+8) == 10);
// check end of range
assert(*(chkrange+5) == 5);
assert(*(chkrange+9) == 12);
// check number of readings 
assert(*(chkrange+6) == 4);
assert(*(chkrange+10) == 3);
// check number of range detected
assert(*(chkrange+11) == 2);  

return 0;
}
