#include <bits/stdc++.h>
using namespace std;
struct record
{
    string opt;
    double price;
    int amount;
    bool isvalid;
}rec[5004];
int main()
{
    //freopen("1.txt","r",stdin);
    int i=0;
    while(cin>>rec[i].opt){
        if(rec[i].opt=="cancel"){
            rec[i].isvalid=false;
            int x;
            cin>>x;
            rec[x-1].isvalid=false;
            ++i;
            continue;
        }
        cin>>rec[i].price>>rec[i].amount;
        rec[i].isvalid=true;
        ++i;
    }
    int n=i;
    set<double> pst;
    for(i=0;i<n;++i){
        if(rec[i].isvalid){
            pst.insert(rec[i].price);
        }
    }
    double ansp=0.0;
    long long maxsum=0;
    for(set<double>::iterator it=pst.begin();it!=pst.end();++it){
        double p=*it;
        long long sumbuy=0,sumsell=0;
        for(i=0;i<n;++i){
            if(rec[i].isvalid==false)continue;
            if(rec[i].opt=="buy"&&rec[i].price>=p){
                sumbuy+=rec[i].amount;
            }
            else if(rec[i].opt=="sell"&&rec[i].price<=p){
                sumsell+=rec[i].amount;
            }
        }
        long long sum=min(sumsell,sumbuy);//成交量
        if(sum>=maxsum){
            maxsum=sum;
            ansp=p;
        }
    }
    printf("%.2lf %lld\n",ansp,maxsum);
    return 0;
}
