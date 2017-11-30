#include <bits/stdc++.h>
using namespace std;
vector<int> v[1024];
int isconnect[1024][1024];
void dfsSolve(int u,int visit[],int cur)
{
    visit[u]=1;
    isconnect[u][cur]=isconnect[cur][u]=1;
    for(size_t i=0;i<v[u].size();++i)
    {
        if(visit[v[u][i]]==0)
            dfsSolve(v[u][i],visit,cur);
    }
}
int main()
{
    int n,m,total=0;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
    }
    for(int i=1;i<=n;++i)
    {
        int visit[1024]={0};
        dfsSolve(i,visit,i);
    }
    for(int i=1;i<=n;++i)
    {
        int j;
        for(j=1;j<=n;++j) 
            if(isconnect[i][j]==0)break;
        if(j==n+1)++total;
    }
    cout<<total;
    return 0;
}
