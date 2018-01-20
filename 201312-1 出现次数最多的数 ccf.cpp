#include <bits/stdc++.h>
using namespace std;
int v[11024];
int main()
{
    int n,maxcnt=-1;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        v[x]++;
    }
    for(int i=1;i<=10000;++i)
        maxcnt=max(maxcnt,v[i]);
    for(int i=1;i<=10000;++i)
    {
        if(maxcnt==v[i])
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
