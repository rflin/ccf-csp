#include <bits/stdc++.h>
using namespace std;
int mat[16][11];
int v[5][5],L,d;
bool judge(int r,int p)
{
    for(int i=d;i>=1&&r>=p;--i)
    {
        for(int j=1;j<=4;++j)
            if(v[i][j]&&mat[r][L+j-1])
                return false;
        --r;
    }
    return true;
}
void putv()
{
    int r=1;
    while(r<=15)
    {
        if(judge(r,max(r-3,1)))++r;
        else break;
    }
    --r;
    for(int i=d;i>=1&&r>=max(r-3,1);--i)
    {
        for(int j=1;j<=4;++j)
            if(v[i][j])mat[r][L+j-1]=1;
        --r;
    }
}
void disp()
{
    for(int i=1;i<=15;++i)
    {
        for(int j=1;j<=10;++j)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}
int main()
{
    for(int i=1;i<=15;++i)
    {
        for(int j=1;j<=10;++j)
            cin>>mat[i][j];
    }
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=4;++j)
        {
            cin>>v[i][j];
            if(v[i][j]==1) d=i;
        }
    }
    cin>>L;
    putv();
    disp();
    return 0;
}
