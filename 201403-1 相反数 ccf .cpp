#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[1024]={0},n,cnt=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a[abs(x)]++;
    }
    for(int i=0;i<=1000;++i)
        if(a[i]==2)++cnt;
    cout<<cnt;
    return 0;
}
