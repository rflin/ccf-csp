#include <bits/stdc++.h>
using namespace std;
struct window
{
    int x1,y1;
    int x2,y2;
    int num;
    window(int a=0,int b=0,int c=0,int d=0,int x=0):x1(a),y1(b),x2(c),y2(d),num(x){}
};
vector<window> v;
bool check(int x,int y,window &w)
{
    if(x>=w.x1&&y>=w.y1&&x<=w.x2&&y<=w.y2)
        return true;
    return false;
}
void search(int x,int y)
{
    size_t i=0;
    while(i<v.size())
    {
        if(check(x,y,v[i]))
        {
            window temp=v[i];
            v.erase(v.begin()+i);
            v.insert(v.begin(),temp);
            cout<<temp.num<<endl;
            return;
        }
        ++i;
    }
    cout<<"IGNORED\n";
}
int main()
{
    int n,m;
    cin>>n>>m;
    v.resize(n);
    for(int i=n-1;i>=0;--i)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        v[i]=window(x1,y1,x2,y2,n-i);
    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        search(x,y);
    }
    return 0;
}
