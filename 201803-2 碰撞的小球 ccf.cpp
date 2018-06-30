#include <bits/stdc++.h>
using namespace std;
int main()
{
    typedef pair<int,int> P;
    vector<P> balls;
    int n,L,t;
    scanf("%d %d %d",&n,&L,&t);
    for(int i=0;i<n;++i){
        int pos;
        scanf("%d",&pos);
        balls.push_back(make_pair(pos,1));
    }
    while(t--){
        for(int i=0;i<n;++i){
            if(balls[i].first==0||balls[i].first==L){
                balls[i].second*=-1;
            }
            balls[i].first+=balls[i].second;
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(balls[i].first==balls[j].first){
                    balls[i].second*=-1;
                    balls[j].second*=-1;
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        printf("%d ",balls[i].first);
    }
    return 0;
}
