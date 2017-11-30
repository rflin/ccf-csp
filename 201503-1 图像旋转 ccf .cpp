#include <bits/stdc++.h>
using namespace std;
int a[1024][1024];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
    }
    for(int j=m-1;j>=0;--j){
        for(int i=0;i<n;++i){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
