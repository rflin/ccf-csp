#include <iostream>
#include <vector>
#include <algorithm>
#define Inf 0x7fffffff
using namespace std;
struct node
{
    int u,v;
    int w;
    node(int a,int b,int x):u(a),v(b),w(x){}
    bool operator <(const node &p)const
    {
        return w<p.w;
    }
};
vector<node> edge;
int vn,an;
int pa[100001];
int find(int x)
{
    return x==pa[x]?x:pa[x]=find(pa[x]);
}
int kruskal()
{
    for(int i=1;i<=vn;++i) pa[i]=i;
    for(int i=0;i<an;++i)
    {
        int x=find(edge[i].u),y=find(edge[i].v);
        if(x!=y) pa[x]=y;
        if(find(1)==find(vn))  return edge[i].w;
    }
    return -1;
}
int main()
{
    cin>>vn>>an;
    for(int i=0;i<an;++i)
    {
        int a,b,x;
        cin>>a>>b>>x;
        edge.push_back(node(a,b,x));
    }
    sort(edge.begin(),edge.end());
    cout<<kruskal();
    return 0;
}
