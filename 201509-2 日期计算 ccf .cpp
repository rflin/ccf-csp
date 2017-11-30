#include <bits/stdc++.h>
using namespace std;
int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
bool isleapyear(int y)
{
    return (y%4==0&&y%100)||(y%400==0);
}
int main()
{
    int y,d;
    cin>>y>>d;
    if(isleapyear(y)) month[2]+=1;
    int m=1,sumday=0;
    while(m<=12&&sumday<d)
    {
        sumday+=month[m++];
    }
    m--;
    cout<<m<<endl<<d-sumday+month[m];
    return 0;
}
