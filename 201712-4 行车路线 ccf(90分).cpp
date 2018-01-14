#include <bits/stdc++.h>
using namespace std;
const long long Inf=999999999999999;
long long arc[512][512];
long long n,m;
bool isSmall[512][512];

long long dijkstra()
{
	bool visit[512]={0};
	long long dist[512]={0};
	long long acsmlen[512]={0};//accumulated smallroad length
	for(long long i=1;i<=n;++i)
	{
		if(arc[1][i]<Inf)//connected
		{
			if(isSmall[1][i])//smallroad
			{
				dist[i]=arc[1][i]*arc[1][i];
				acsmlen[i]=arc[1][i];
			}
			else dist[i]=arc[1][i];
		}
		else dist[i]=Inf;
	}
	visit[1]=1;
	while(true)
	{
		long long minval=Inf,x=-1;
		for(long long j=1;j<=n;++j)//getminval
		{
			if(visit[j]==0&&dist[j]<minval)
			minval=dist[x=j];
		}
		if(x==-1)break;//notfound
		visit[x]=1;
		for(long long w=1;w<=n;++w)
		{
			if(visit[w]==0&&arc[x][w]<Inf)//notvisited_and_isconnected
			{
				long long preac=dist[x]-acsmlen[x]*acsmlen[x];//goback
				long long lenbyx=(isSmall[x][w])?preac+(acsmlen[x]+arc[x][w])*(acsmlen[x]+arc[x][w]):preac+acsmlen[x]*acsmlen[x]+arc[x][w];
				if(lenbyx<dist[w])
				{
					dist[w]=lenbyx;//update
					acsmlen[w]=(isSmall[x][w])?acsmlen[x]+arc[x][w]:0;
				}
				else if(lenbyx==dist[w])
				{
					long long acbyx=(isSmall[x][w])?acsmlen[x]+arc[x][w]:0;
					if(acbyx<acsmlen[w])acsmlen[w]=acbyx;
				}
			}
		}
	}
	return dist[n];
}
int main()
{
	//freopen("1.txt","r",stdin);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;++i)
	{
		for(long long j=1;j<=n;++j) arc[i][j]=arc[j][i]=Inf;
	}
	for(long long i=0;i<m;++i)
	{
		long long t,a,b,c;
		scanf("%lld %lld %lld %lld",&t,&a,&b,&c);
		arc[a][b]=arc[b][a]=c;
		isSmall[a][b]=isSmall[b][a]=t;
	} 
	cout<<dijkstra();
	return 0;
}
