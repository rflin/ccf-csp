#include <bits/stdc++.h>
using namespace std;
struct point{
	int x,y,time;
	point(int xx,int yy,int tt):x(xx),y(yy),time(tt){}
};
int unsafe[128][128][2],visit[128][128][312];
int n,m,t;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool islegal(int x,int y)
{
	return x>=1&&y>=1&&x<=n&&y<=m;
}
bool issafe(int x,int y,int time)
{
	return unsafe[x][y][0]>time||unsafe[x][y][1]<time;
}
int main()
{
	// freopen("1.txt","r",stdin);
	scanf("%d %d %d",&n,&m,&t);
	for(int i=0;i<t;++i){
		int x,y,s,e;
		scanf("%d %d %d %d",&x,&y,&s,&e);
		unsafe[x][y][0]=s;
		unsafe[x][y][1]=e;
	}
	point s(1,1,0);
	queue<point> q;
	q.push(s);
	while(!q.empty()){
		point p=q.front();
		q.pop();
		if(p.x==n&&p.y==m){
			printf("%d\n",p.time);
			return 0;
		}
		int thistime=p.time+1;
		for(int i=0;i<4;++i){
			int xx=p.x+dx[i],yy=p.y+dy[i];
			if(islegal(xx,yy)&&issafe(xx,yy,thistime)&&!visit[xx][yy][thistime]){
				//printf("(%d %d %d)\n",xx,yy,thistime);
				point nextp(xx,yy,thistime);
				q.push(nextp);
				visit[xx][yy][thistime]=1;
			}
		}
	}
	return 0;
}
