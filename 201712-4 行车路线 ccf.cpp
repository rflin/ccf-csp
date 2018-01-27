#include <bits/stdc++.h>
using namespace std;
typedef long long llt;
const llt inf=0x7fffffffffffffff;
llt sA[512][512],bA[512][512];
llt n,m;

llt sqe(llt x){return x*x;}//返回平方
llt dijkstra()
{
	bool visitsr[512]={0},visitbr[512]={0};
	vector<llt> sr(sA[0],sA[0]+n),br(bA[0],bA[0]+n),presr(n,inf);
	for(llt i=0;i<n;++i)
	{
		if(sr[i]<inf)
		{
			presr[i]=sr[i];
			sr[i]*=sr[i];
		}
	}
	visitsr[0]=visitbr[0]=1;
	while(true)
	{
		llt minval=inf,u=-1,flag=0;
		for(llt i=0;i<n;++i)//找到一条最短路径，并且用flag标记是大路还是小路
		{
			if(!visitbr[i]&&minval>br[i])
			{
				minval=br[u=i];
				flag=0;//大路
			}
			if(!visitsr[i]&&minval>sr[i])
			{
				minval=sr[u=i];
				flag=1;//小路
			}
		}
		if(u==-1)break;
		if(flag==1) visitsr[u]=1;
		else visitbr[u]=1;
		for(llt w=0;w<n;++w)
		{
			if(!visitsr[w]&&sA[u][w]<inf)//从u到w存在一条小路
			{
				if(flag==1)//u前驱是小路
				{
					llt len=sr[u]-sqe(presr[u])+sqe(presr[u]+sA[u][w]);
					if(sr[w]>len||(sr[w]==len&&presr[w]>presr[u]+sA[u][w]))
					{
						sr[w]=len;
						presr[w]=presr[u]+sA[u][w];
					}
				}
				else//u前驱是大路
				{
					llt len=br[u]+sqe(sA[u][w]);
					if(sr[w]>len||(sr[w]==len&&presr[w]>sA[u][w]))
					{
						sr[w]=len;
						presr[w]=sA[u][w];
					}
				}
			}
			if(!visitbr[w]&&bA[u][w]<inf)//从u到w存在一条大路
			{
				if(flag==1)//u前驱是小路
				{
					llt len=sr[u]+bA[u][w];
					br[w]=min(len,br[w]);
				}
				else//u前驱是大路
				{
					llt len=br[u]+bA[u][w];
					br[w]=min(len,br[w]);
				}
			}
		}
	}
	return min(sr[n-1],br[n-1]);
}
int main()
{
    scanf("%lld %lld",&n,&m);
    for(llt i=0;i<n;++i)
    {
        for(llt j=0;j<n;++j)
        {
        	sA[i][j]=sA[j][i]=inf;
        	bA[i][j]=bA[j][i]=inf;
        }
    }
    for(llt i=0;i<m;++i)
    {
        llt t,a,b,c;
        scanf("%lld %lld %lld %lld",&t,&a,&b,&c);
        --a,--b;
        if(t==1) sA[a][b]=sA[b][a]=min(c,sA[a][b]);
        else bA[a][b]=bA[b][a]=min(c,bA[a][b]);
    }
    llt ret=dijkstra();
    printf("%lld\n",ret);
    return 0;
}
