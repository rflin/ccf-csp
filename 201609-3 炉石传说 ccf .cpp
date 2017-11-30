#include <bits/stdc++.h>
using namespace std;
struct role
{
    int attack,health;
    role(int ak,int ht):attack(ak),health(ht){}
};
vector<role> va,vb;
int n,turn=0;
void dis(vector<role> &v)
{
    cout<<v[0].health<<endl;
    cout<<v.size()-1;
    for(size_t i=1;i<v.size();++i)
    {
        cout<<" "<<v[i].health;
    }
    cout<<endl;
}
int main()
{
    va.push_back(role(0,30));
    vb.push_back(role(0,30));
    cin>>n;
    for(int i=0;i<n;++i)
    {
        string action;
        cin>>action;
        if(action=="summon")
        {
            int pos,ak,ht;
            cin>>pos>>ak>>ht;
            if(turn==0)
                va.insert(va.begin()+pos,role(ak,ht));
            else
                vb.insert(vb.begin()+pos,role(ak,ht));
        }
        else if(action=="end")
            turn=(turn+1)%2;
        else if(action=="attack")
        {
            int i,j;
            cin>>i>>j;
            if(turn==0)
            {
                va[i].health-=vb[j].attack;
                vb[j].health-=va[i].attack;
                if(va[i].health<=0&&i)
                {
                    va.erase(va.begin()+i);
                }
                if(vb[j].health<=0&&j)
                {
                    vb.erase(vb.begin()+j);
                }
            }
            else
            {
                vb[i].health-=va[j].attack;
                va[j].health-=vb[i].attack;
                if(va[j].health<=0&&j)
                {
                    va.erase(va.begin()+j);
                }
                if(vb[i].health<=0&&i)
                {
                    vb.erase(vb.begin()+i);
                }
            }
        }
        if(va[0].health<=0||vb[0].health<=0)
        {
            break;
        }
    }
    if(va[0].health<=0&&vb[0].health>0)
        cout<<-1<<endl;
    else if(va[0].health>0&&vb[0].health<=0)
        cout<<1<<endl;
    else cout<<0<<endl;
    dis(va);
    dis(vb);
    return 0;
}
