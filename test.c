#include "CurrentRange.h"
#include <assert.h>

int main()
{
int *chkrange;

int samplesarray[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
  
chkrange = detect_PrintRangeDetails(samplesarray,arraysize);

assert(*(chkrange+4) == 3);
assert(*(chkrange+5) == 5);
assert(*(chkrange+6) == 4);
assert(*(chkrange+11) == 2);  

return 0;
}
