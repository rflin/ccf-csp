#include <bits/stdc++.h>
using namespace std;

int A[3][3];//棋盘
bool rck(int i,int val){//横向
    return A[i][0]==val&&A[i][1]==val&&A[i][2]==val;
}
bool cck(int j,int val){//竖向
    return A[0][j]==val&&A[1][j]==val&&A[2][j]==val;
}
bool dck(int val){//斜向
    return (A[0][0]==val&&A[1][1]==val&&A[2][2]==val)||(A[0][2]==val&&A[1][1]==val&&A[2][0]==val);
}
int zeroCpt(){//计算空白格子个数（分数）
    int res=0;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(A[i][j]==0) res++;
        }
    }
    return res;
}
int win(int player){//player=1代表Alice, player=2代表Bob
    bool r=rck(0,player)||rck(1,player)||rck(2,player);
    bool c=cck(0,player)||cck(1,player)||cck(2,player);
    bool d=dck(player);
    int w=r||c||d;//当前状态玩家player是否胜出
    if(w==0) return 0;//未胜出，棋局还未结束
    w=zeroCpt()+1;//player胜出，返回分数，棋局结束
    return player==1?w:-w;
}
int dfs(int player){
    if(zeroCpt()==0) return 0;//平局
    int Min=10,Max=-10;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(A[i][j]==0){
                A[i][j]=player;
                int w=win(player);
                if(w){//棋局结束
                    A[i][j]=0;
                    return w>0?max(Max,w):min(Min,w);
                }
                if(player==1) Max=max(Max,dfs(2));
                else Min=min(Min,dfs(1));
                A[i][j]=0;
            }
        }
    }
    return player==1?Max:Min;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                scanf("%d",&A[i][j]);
            }
        }
        int x=win(1),y=win(2);
        if(x) printf("%d\n",x);
        else if(y) printf("%d\n",y);
        else printf("%d\n",dfs(1));
    }
    return 0;
}
