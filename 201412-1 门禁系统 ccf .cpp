#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt[1024]={0},n,a[1024]={0};
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        cnt[x]++;
        a[i]=cnt[x];
    }
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    return 0;
}
