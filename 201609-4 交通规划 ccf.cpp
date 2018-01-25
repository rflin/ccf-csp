/*数据量过大，需采用堆优化的dijkstra算法*/
#include <bits/stdc++.h>
using namespace std;
const int Inf=0x7fffffff;
int n,m;
struct edge
{
	int v;
	int cost;
	edge(int x,int c):v(x),cost(c){}
};
struct cmp
{
	bool operator()(edge &a,edge &b)
	{
		return a.cost>b.cost;
	}
};
vector<edge> vg[10000];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		--x,--y;
		vg[x].push_back(edge(y,w));
		vg[y].push_back(edge(x,w));
	}
	//dijkstra
	priority_queue<edge,vector<edge>,cmp> pq;
	vector<int> dist(n,Inf);
	vector<int> cost(n,Inf);
	vector<bool> visit(n,0);
	pq.push(edge(0,0));
	dist[0]=cost[0]=0;
	while(!pq.empty())
	{
		edge t=pq.top();//最短路径（花费）边
		pq.pop();
		visit[t.v]=1;//访问该节点
		for(size_t i=0;i<vg[t.v].size();++i)
		{
			edge e=vg[t.v][i];//该节点的所有邻接边
			if(visit[e.v])continue;//另外一端节点访问过了，跳过
			if(dist[e.v]>dist[t.v]+e.cost)//更新最短路径
			{
				dist[e.v]=dist[t.v]+e.cost;
				cost[e.v]=e.cost;
				pq.push(edge(e.v,dist[e.v]));//新的更新边
			}
			else if(dist[e.v]==dist[t.v]+e.cost)
			{
				cost[e.v]=min(cost[e.v],e.cost);
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;++i)
		sum+=cost[i];
	printf("%d\n",sum);
	return 0;
}
