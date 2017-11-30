#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,s=0,i=0,w,cnt=0;
    cin>>n>>k;
    while(i<n)
    {
        cin>>w;
        ++i;
        s=w;
        while(i<n&&s<k)
        {
            cin>>w;
            s+=w;
            ++i;
        }
        ++cnt;
    }
    cout<<cnt;
    return 0;
}
