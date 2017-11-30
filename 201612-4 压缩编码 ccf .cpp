#include <bits/stdc++.h>
using namespace std;
int a[1024],sum[1024],dp[1024][1024];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        for(int j=1;j<=n;++j){
            i==j?dp[i][j]=0:dp[i][j]=0x7fffffff;
        }
    }
    for(int w=2;w<=n;++w)
    {
        for(int i=1;i+w-1<=n;++i)
        {
            int j=i+w-1,s=sum[j]-sum[i-1];
            for(int k=i;k<j;++k)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
