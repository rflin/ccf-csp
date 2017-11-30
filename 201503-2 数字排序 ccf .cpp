#include <bits/stdc++.h>
using namespace std;
int n,cnt[1024];
struct node
{
    int idx,w;
    node(int a,int b):idx(a),w(b){}
};
vector<node> v;
bool cmp(const node &a,const node &b)
{
    return a.w==b.w?a.idx<b.idx:a.w>b.w;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=0;i<=1000;++i)
    {
        if(cnt[i])
            v.push_back(node(i,cnt[i]));
    }
    sort(v.begin(),v.end(),cmp);
    for(size_t i=0;i<v.size();++i)
    {
        cout<<v[i].idx<<" "<<v[i].w<<endl;
    }
    return 0;
}
