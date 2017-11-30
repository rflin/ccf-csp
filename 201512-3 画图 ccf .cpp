#include <iostream>
using namespace std;
char a[128][128];
int n,m,q;
void init()
{
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            a[i][j]='.';
        }
    }
}
bool isrange(int x,int y)
{
    return x>=0&&y>=0&&x<n&&y<m;
}
bool isline(char c)
{
    return c=='-'||c=='|'||c=='+';
}
void paintline(int x1,int y1,int x2,int y2)
{
    if(x1==x2){
        if(y1>y2)swap(y1,y2);
        int y=y1;
        while(y<=y2){
            if(isline(a[y][x1])&&a[y][x1]!='|')a[y][x1]='+';
            else a[y][x1]='|';
            ++y;
        }
    }
    else{//y1==y2
        if(x1>x2)swap(x1,x2);
        int x=x1;
        while(x<=x2){
            if(isline(a[y1][x])&&a[y1][x]!='-')a[y1][x]='+';
            else a[y1][x]='-';
            ++x;
        }
    }
}
void fillblank(int x,int y,char c,int visit[][128])
{
    if(visit[y][x]||!isrange(x,y)||isline(a[y][x]))return;
    a[y][x]=c;
    visit[y][x]=1;
    fillblank(x-1,y,c,visit);
    fillblank(x+1,y,c,visit);
    fillblank(x,y-1,c,visit);
    fillblank(x,y+1,c,visit);
}
int main()
{
    cin>>n>>m>>q;
    init();
    while(q--){
        int opt;
        cin>>opt;
        if(opt==0){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            paintline(x1,y1,x2,y2);
        }
        else{
            int x,y;
            char c;
            cin>>x>>y>>c;
            int visit[128][128]={0};
            fillblank(x,y,c,visit);
        }
    }
    for(int i=m-1;i>=0;--i){
        for(int j=0;j<n;++j){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
