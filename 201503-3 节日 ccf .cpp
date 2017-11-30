#include <bits/stdc++.h>
using namespace std;
int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleapyear(int y)
{
    return (y%4==0&&y%100)||(y%400==0);
}
int cptdays(int s,int e,int m)
{
    int sumday=0;
    while(s<e){
        sumday+=isleapyear(s++)?366:365;
    }
    if(isleapyear(e))month[2]=29;
    for(int i=1;i<m;++i){
        sumday+=month[i];
    }
    return sumday;
}
int thisdaybyweek(int w,int c,int b)
{
    int day=1;
    while(w!=c){
        ++day;
        ++w;
        if(w==8)w=1;
    }
    return day+(b-1)*7;
}
int main()
{
    int a,b,c,y1,y2;
    scanf("%d %d %d %d %d",&a,&b,&c,&y1,&y2);
    while(y1<=y2){
        int w=(cptdays(1850,y1,a)+2)%7;//a月1日星期几
        if(w==0)w=7;
        //printf("week : %d\n",w);
        int day=thisdaybyweek(w,c,b);
        if(day>month[a])printf("none\n");
        else printf("%d/%02d/%02d\n",y1,a,day);
        month[2]=28;
        ++y1;
    }
    return 0;
}
