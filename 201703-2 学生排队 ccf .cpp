#include <bits/stdc++.h>
using namespace std;
int n,m;
int mpos[1024],v[1024];
void move(int pos,int len,int stp)
{
    int temp=v[pos];
    while(len)
    {
        v[pos]=v[pos+stp];
        mpos[v[pos]]=pos;
        pos+=stp;
        --len;
    }
    mpos[temp]=pos;
    v[pos]=temp;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        mpos[i]=i;
        v[i]=i;
    }
    for(int i=0;i<m;++i)
    {
        int id,val;
        cin>>id>>val;
        int pos=mpos[id];
        val<0?move(pos,-val,-1):move(pos,val,1);
    }
    for(int i=1;i<=n;++i)
        cout<<v[i]<<" ";
    return 0;
}
