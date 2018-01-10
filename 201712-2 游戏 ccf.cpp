#include <bits/stdc++.h>
using namespace std;
vector<int> getNext(vector<int> &v,int k,int &num)
{
    vector<int> nextv;
    int n=v.size(),i=0;
    while(i<n)
    {
        if((num+i+1)%10==k||(num+i+1)%k==0) ++i;
        else nextv.push_back(v[i++]);
    }
    num+=v.size();
    if(nextv.empty())
        nextv.push_back(v.back());
    return nextv;
}
int main()
{
    int n,k;
    vector<int> v;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i)
        v.push_back(i);
    int num=0;
    while(v.size()>1) v=getNext(v,k,num);
    cout<<v[0]<<endl;
    return 0;
}
