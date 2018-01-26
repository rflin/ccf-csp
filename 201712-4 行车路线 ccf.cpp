#include <bits/stdc++.h>
using namespace std;
typedef long long llt;
const llt Inf=0x7fffffffffffffff;
llt sA[512][512],bA[512][512];
llt n,m;

llt sqe(llt x)//返回平方
{
	return x*x;
}
llt dijkstra()
{
	bool visit[512]={0};
	vector<llt> sr(sA[0],sA[0]+n),br(bA[0],bA[0]+n),presr(n,Inf);
	for(llt i=0;i<n;++i)
	{
		if(sr[i]<Inf)
		{
			presr[i]=sr[i];
			sr[i]*=sr[i];
		}
	}
	visit[0]=1;
	while(true)
	{
		llt minval=Inf,u=-1;
		for(llt i=0;i<n;++i)
		{
			if(!visit[i]&&minval>min(sr[i],br[i]))
			{
				minval=min(sr[i],br[i]);
				u=i;
			}
		}
		if(u==-1)break;
		visit[u]=1;
		for(llt w=0;w<n;++w)
		{
			if(visit[w]==0&&(sA[u][w]<Inf||bA[u][w]<Inf))
			{
				if(sA[u][w]<Inf)//新选择的边是小路
				{
					if(sr[u]<Inf)//选取的u节点前面存在小路
					{
						llt lena=sr[u]-sqe(presr[u])+sqe(presr[u]+sA[u][w]);//通过u节点得到新的路径，u节点前面是小路，新边是小路
						if(sr[w]>lena||(sr[w]==lena&&presr[w]>presr[u]+sA[u][w]))
						{
							sr[w]=lena;
							presr[w]=presr[u]+sA[u][w];//更新w节点前面连续小路
						}
					}
					if(br[u]<Inf)//选取的u节点前面存在大路
					{
						llt lenb=br[u]+sqe(sA[u][w]);//通过u节点得到新的路径，u节点前面是大路，新边是小路
						if(sr[w]>lenb||(sr[w]==lenb&&presr[w]>sA[u][w]))
						{
							sr[w]=lenb;
							presr[w]=sA[u][w];//更新w节点前面连续小路
						}
					}
				}
				if(bA[u][w]<Inf)//新选择的边是大路
				{
					if(sr[u]<Inf)//选取的u节点前面存在小路
					{
						llt lena=sr[u]+bA[u][w];//通过u节点得到新的路径，u节点前面是小路，新边是大路
						br[w]=min(lena,br[w]);
					}
					if(br[u]<Inf)//选取的u节点前面存在大路
					{
						llt lenb=br[u]+bA[u][w];//通过u节点得到新的路径，u节点前面是大路，新边是大路
						br[w]=min(lenb,br[w]);
					}
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
        	llt val=(i==j)?0:Inf;
        	sA[i][j]=sA[j][i]=val;
        	bA[i][j]=bA[j][i]=val;
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
