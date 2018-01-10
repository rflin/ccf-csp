#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[1024],n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int i=1,minval=999999;
    while(i<n)
    {
        minval=min(minval,a[i]-a[i-1]);
        ++i;
    }
    printf("%d\n",minval);
    return 0;
}
