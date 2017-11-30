#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0;
    vector<int> v;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;++i)
        cin>>v[i];
    for(int i=1;i+1<n;++i)
    {
        if((v[i]>v[i-1]&&v[i]>v[i+1])||(v[i]<v[i-1]&&v[i]<v[i+1]))
            ++cnt;
    }
    cout<<cnt<<endl;
    return 0;
}
