#include <bits/stdc++.h>
using namespace std;
int n,m,a[32][32],b[32][32];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cin>>a[i][j];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int k=j+1;
            while(k<m&&a[i][k]==a[i][k-1])++k;
            if(k-j<3){
                j=k-1;
            }
            else{
                while(j<k)b[i][j++]=1;
                --j;
            }
        }
    }
    for(int j=0;j<m;++j){
        for(int i=0;i<n;++i){
            int k=i+1;
            while(k<n&&a[k][j]==a[k-1][j])++k;
            if(k-i<3){
                i=k-1;
            }
            else{
                while(i<k)b[i++][j]=1;
                --i;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(b[i][j]==0)
                cout<<a[i][j]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
