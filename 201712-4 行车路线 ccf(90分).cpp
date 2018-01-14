/*未完全AC，只有90分，dijkstra
容易说明，采用此种策略的迪杰斯特拉算法存在漏洞，当前选择的局部最优可能导致最后结果不是最优
考虑如下测试用例：
4 4
1 1 2 1
1 2 3 1
1 3 4 1
0 1 3 5
最终结果是9，但是正确答案应该是6（1->3->4）
此测试用例也说明，前面的路段的选择会受到后续段的影响，主要体现在小路上
如果后续段是大路，应该可以确定最优解（猜测）
*/
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
