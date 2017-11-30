#include <bits/stdc++.h>
using namespace std;
int val[1024];
int main()
{
    int n,ans=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&val[i]);
    for(int i=1;i<=n;++i)
    {
        int v=val[i];
        for(int j=i+1;j<=n;++j)
        {
            v=min(v,val[j]);
            ans=max(v*(j-i+1),ans);
        }
    }
    cout<<ans;
    return 0;
}
