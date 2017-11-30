#include <bits/stdc++.h>
using namespace std;
map<string,int> pri;
map<string,map<string,int> > rol;
map<string,map<string,int> > usr;
void find(string u,string x,int lev)
{
    if(usr.count(u)>0&&usr[u].count(x)>0)
    {
        if(lev==-1)
        {
            if(usr[u][x]>-1) cout<<usr[u][x]<<endl;
            else cout<<"true\n";
        }
        else
        {
            if(usr[u][x]>=lev) cout<<"true\n";
            else cout<<"false\n";
        }
    }
    else cout<<"false\n";
}
int main() 
{
    int n;
    cin>>n;//p
    while(n--)
    {
        string x;
        cin>>x;
        size_t pos=x.find(":");
        if(pos==string::npos) pri[x]=-1;
        else
        {
            int lev=x[pos+1]-'0';
            x=x.substr(0,pos);
            pri[x]=max(pri[x],lev);
        }
    }
    cin>>n;//r
    while(n--)
    {
        string role;
        int k;
        cin>>role>>k;
        while(k--)
        {
            string x;
            cin>>x;
            size_t pos=x.find(":");
            if(pos==string::npos) rol[role][x]=-1;
            else
            {
                int lev=x[pos+1]-'0';
                x=x.substr(0,pos);
                rol[role][x]=max(rol[role][x],lev);
            }
        }
    }
    cin>>n;//u
    while(n--)
    {
        string u;
        int k;
        cin>>u>>k;
        while(k--)
        {
            string x;
            cin>>x;
            map<string,int>::iterator it=rol[x].begin();
            while(it!=rol[x].end())
            {
                if(usr[u].count(it->first)>0)
                    usr[u][it->first]=max(usr[u][it->first],it->second);
                else
                    usr[u][it->first]=it->second;
                ++it;
            }
        }
    }
    cin>>n;//q
    while(n--)
    {
        string u,x;
        cin>>u>>x;
        size_t pos=x.find(":");
        if(pos==string::npos) find(u,x,-1);
        else find(u,x.substr(0,pos),x[pos+1]-'0');
    }
    return 0;
}
