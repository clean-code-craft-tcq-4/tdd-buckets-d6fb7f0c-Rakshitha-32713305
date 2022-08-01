#include "CurrentRange.h"
#include <assert.h>

int main()
{
int *chkrange;

int array[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize = sizeof(array) / sizeof(array[0]);
  
chkrange = detect_PrintRange(array,arraysize);

assert(*(chkrange+4) == 3);
assert(*(chkrange+5) == 5);
assert(*(chkrange+6) == 4);
assert(*(chkrange+11) == 2);  

return 0;
}
