#include "probelib.h"
#include <cstdio>
using namespace std;
int n;

main()
{
    int n = probe_init();
    int mid=n/2;
    int last=n;
    int first=0;
    for(int i=0; i<22; i++) {
        if(first==last) {
            probe_answer(first);
        }
        if(probe_check(first,mid)) {
            last=mid;
            mid=(first+last)/2;
        } else {
            first=mid+1;
            mid=(first+last)/2;
        }
    }
}
