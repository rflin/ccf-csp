/*
这里k值貌似没有太大用处，所以其实不记录counts也是可以的，
通过bfs策略得到的一定最优的，所以一定是满足小于等于k的，除非存在不合法例
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long llt;
struct node
{
	int x,y;
	int vertexnum;
	int counts;
	node(int a,int b,int vn,int c):x(a),y(b),vertexnum(vn),counts(c){}
};
vector<node> v;
bool matrix[256][256];
bool visit[256];
bool isConnect(node &a,node &b,int r)//在r范围内
{
	return (llt)(a.x-b.x)*(a.x-b.x)+(llt)(a.y-b.y)*(a.y-b.y)<=(llt)r*r;
}
int main()
{
	int n,m,k,r;
	scanf("%d %d %d %d",&n,&m,&k,&r);
	for(int i=0;i<n+m;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v.push_back(node(x,y,i,0));
	}
	for(int i=0;i<n+m;++i)//创建邻接矩阵matrix
	{
		for(int j=0;j<n+m;++j)
		{
			matrix[i][j]=isConnect(v[i],v[j],r);
		}
	}
	queue<node> q;
	q.push(v[0]);
	int elecnt=1,level=1;
	while(elecnt>0)//bfs
	{
		int nextelecnt=0;//记录下一层次元素个数
		for(int i=0;i<elecnt;++i)
		{
			node cur=q.front();
			q.pop();
			if(cur.vertexnum==1)//是第二个路由器，得到结果
			{
				printf("%d\n",level-2);
				return 0;
			}
			int w=cur.vertexnum,u=0;
			while(u<m+n)//依次遍历n+m个节点
			{
				if(matrix[w][u]&&!visit[u]&&cur.counts<=k)
				{
					visit[u]=true;
					v[u].counts=(u>=n)?cur.counts+1:cur.counts;
					q.push(v[u]);
					++nextelecnt;
				}
				++u;
			}
		}
		elecnt=nextelecnt;
		++level;
	}
	return 0;
}
