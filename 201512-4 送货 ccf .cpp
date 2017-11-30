#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
bool arcvis[10001][10001];
int de[10001];
void dis(vector<int> v)
{
    int i=v.size()-1;
    while(i>=0) cout<<v[i--]<<" ";
}
int main()
{
    int n,m,odd=0;
    vector<int> ans,v[10001];
    stack<int> stk;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int u,w;
        cin>>u>>w;
        v[u].push_back(w);
        v[w].push_back(u);
        de[u]++;de[w]++;
    }
    for(int i=1;i<=n;++i)
    {
        sort(v[i].begin(),v[i].end());
        if(de[i]&1) odd++;
    }
    stk.push(1);
    while(!stk.empty())
    {
        int u=stk.top();
        bool flag=false;
        for(unsigned int i=0;i<v[u].size();++i)
        {
            int w=v[u][i];
            if(!arcvis[w][u])
            {
                flag=true;
                stk.push(w);
                arcvis[u][w]=true;
                arcvis[w][u]=true;
                break;
            }
        }
        if(!flag)
        {
            ans.push_back(u);
            stk.pop();
        }
    }
    if(ans.size()==m+1&&(odd==0||(odd==2&&de[1]&1))) dis(ans);
    else cout<<-1;
    return 0;
}
