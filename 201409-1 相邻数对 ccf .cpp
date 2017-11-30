#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    size_t i=0,cnt=0;
    while(i<v.size()-1)
    {
        while(i<v.size()-1&&v[i+1]-v[i]==1)
        {
            ++i;++cnt;
        }
        ++i;
    }
    cout<<cnt;
    return 0;
}
