#include <bits/stdc++.h>
using namespace std;
struct teacher
{
    int num,s,e;
    teacher(int x=0,int y=0,int z=0):num(x),s(y),e(z){}
};
vector<teacher> p,q;
int keyn,tean;
int key[1024];
bool cmpp(const teacher &a,const teacher &b)
{
    return a.s<b.s;
}
bool cmpq(const teacher &a,const teacher &b)
{
    return a.e==b.e?a.num<b.num:a.e<b.e;
}
int searchkeypos(int keyid)
{
    for(int i=1;i<=keyn;++i)
        if(keyid==key[i]) return i;
    cout<<"can't find "<<keyid<<endl;
    return -1;
}
int main()
{
    cin>>keyn>>tean;
    for(int i=1;i<=keyn;++i)
        key[i]=i;
    for(int i=0;i<tean;++i)
    {
        teacher x;
        cin>>x.num>>x.s>>x.e;
        x.e+=x.s;
        p.push_back(x);
        q.push_back(x);
    }
    sort(p.begin(),p.end(),cmpp);
    sort(q.begin(),q.end(),cmpq);
    int i=0,j=0;
    while(i<tean&&j<tean)
    {
        if(p[i].s<q[j].e)
        {
            int pos=searchkeypos(p[i++].num);
            key[pos]=-1;
        }
        else if(p[i].s>=q[j].e)
        {
            int pos=searchkeypos(-1);
            key[pos]=q[j++].num;
        }
    }
    while(j<tean)
    {
        int pos=searchkeypos(-1);
        key[pos]=q[j++].num;
    }
    for(int i=1;i<=keyn;++i)
        cout<<key[i]<<" ";
    return 0;
}
