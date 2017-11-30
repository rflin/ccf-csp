#include <cstdio>
double rate[]={0,0.03,0.1,0.2,0.25,0.3,0.35,0.45};
int v[]={3500,1500,3000,4500,26000,20000,25000};
int u[]={3500,1500,3000,4500,26000,20000,25000};
void cpt()
{
    for(int i=1;i<7;++i)
    {
        u[i]+=u[i-1];
        v[i]=v[i-1]+v[i]*(1-rate[i]);
    }
}
int main() 
{
    int t,i=0;
    scanf("%d",&t);
    if(t<=3500)
    {
        printf("%d\n",t);
        return 0;
    }
    cpt();
    while(v[i]<=t&&i<7)++i;
    --i;
    int s=u[i]+(t-v[i])/(1-rate[i+1]);
    printf("%d\n",s);
    return 0;
}
