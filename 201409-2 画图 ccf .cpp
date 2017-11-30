#include <bits/stdc++.h>
using namespace std;
int matrix[128][128];
int main()
{
    int n,cnt=0;
    cin>>n;

    while(n--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<x2;++i)
        {
            for(int j=y1;j<y2;++j)
                matrix[i][j]=1;
        }
    }
    for(int i=0;i<=100;++i){
        for(int j=0;j<=100;++j){
            if(matrix[i][j]==1)++cnt;
        }
    }
    cout<<cnt;
    return 0;
}
