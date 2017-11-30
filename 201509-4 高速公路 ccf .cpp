#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[10001];
stack<int> stk;
int DFN[10001],LOW[10001];
int index,ans;
bool vis[10001];
void TarJan(int u)
{
    DFN[u]=LOW[u]=++index;
    stk.push(u);
    vis[u]=true;
    for(unsigned int i=0;i<v[u].size();++i)
    {
        int w=v[u][i];
        if(!DFN[w])
        {
            TarJan(w);
            LOW[u]=min(LOW[u],LOW[w]);
        }
        else if(vis[w]) LOW[u]=min(LOW[u],DFN[w]);
    }
    if(DFN[u]==LOW[u])
    {
        int s,cnt=0;
        do{
            s=stk.top();
            stk.pop();
            vis[s]=false;
            ++cnt;
        }while(u!=s);
        if(cnt>1) ans+=cnt*(cnt-1)/2;
    }
} 
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
    }
    for(int i=1;i<=n;++i)
    {
        if(!DFN[i]) TarJan(i);
    }
    cout<<ans;
    return 0;
}
