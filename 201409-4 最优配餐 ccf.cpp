#include <bits/stdc++.h>
using namespace std;
typedef long long llt;
struct node
{
	int x,y;
	llt distance;
	node(int a,int b,llt dis):x(a),y(b),distance(dis){}
};
queue<node> q;
int posNum[1024][1024];
bool visit[1024][1024];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,k,m,d;
bool islegal(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=n;
}
int main()
{
	scanf("%d %d %d %d",&n,&k,&m,&d);
	for(int i=0;i<k;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		q.push(node(x,y,0));
		visit[x][y]=1;
	}
	for(int i=0;i<m;++i)
	{
		int x,y,nums;
		scanf("%d %d %d",&x,&y,&nums);
		posNum[x][y]=nums;
	}
	for(int i=0;i<d;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		visit[x][y]=1;
	}
	llt ret=0;
	while(!q.empty())
	{
		node cur=q.front();
		q.pop();
		for(int i=0;i<4;++i)
		{
			int x=cur.x+dx[i],y=cur.y+dy[i],dis=cur.distance;
			if(islegal(x,y)&&!visit[x][y])
			{
				ret+=posNum[x][y]*(dis+1);
				visit[x][y]=1;
				q.push(node(x,y,dis+1));
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}
