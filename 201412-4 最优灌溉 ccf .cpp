#include <iostream>
#include <vector>
#define INF 0x7fffffff
using namespace std;
int prim(vector<vector<int> > &v,int u)
{
    int n=v.size()-1,minv,sum=0;
    vector<int> cost=v[u];
    vector<bool> vis(n+1,false);
    vis[u]=true;
    for(int i=1;i<n;++i)
    {
        int val=INF;
        for(int k=1;k<=n;++k) if(!vis[k]&&cost[k]<val) val=cost[minv=k];
        sum+=val;
        vis[minv]=true;
        for(int i=1;i<=n;++i) if(!vis[i]&&cost[i]>v[minv][i]) cost[i]=v[minv][i];
    }
    return sum;

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n+1,vector<int>(n+1,INF));
    for(int i=0;i<m;++i)
    {
        int s,e,w;
        cin>>s>>e>>w;
        adj[s][e]=w;
        adj[e][s]=w;
    }
    cout<<prim(adj,1);
    return 0;
}
