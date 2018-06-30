#include <bits/stdc++.h>
using namespace std;
struct regulation{
    string name;
    vector<string> regv;
    regulation(string a,vector<string> v):name(a),regv(v){}
};
vector<regulation> regulations;
vector<string> str2regv(string str){
    vector<string> res;
    str=str.substr(1,str.size()-1);
    res.push_back("/");
    size_t pos=str.find("/");
    while(pos!=string::npos){
        res.push_back(str.substr(0,pos));
        res.push_back("/");
        str=str.substr(pos+1);
        pos=str.find("/");
    }
    if(str.size()) res.push_back(str);
    return res;
}
void urlmap(string str){
    vector<string> v=str2regv(str);
    for(size_t i=0;i<regulations.size();++i){
        vector<string> &r=regulations[i].regv;
        string res=regulations[i].name;
        size_t lr=r.size(),lv=v.size(),j=0,k=0;
        while(j<lr&&k<lv){
            if(r[j]==v[k]){
                ++j,++k;continue;
            }
            if(r[j]=="<path>"){
                if(v[lv-1]=="/") break;
                res+=" ";
                while(k<lv){
                    res+=v[k++];
                }
                cout<<res<<endl;
                return;
            }else if(r[j]=="<int>"){
                string num;
                bool tag=1;
                for(size_t l=0;l<v[k].size();++l){
                    if(isdigit(v[k][l])) num+=v[k][l];
                    else {
                        tag=0;break;
                    }
                }
                if(tag==0) break;
                size_t uz=0;
                while(num[uz]=='0'&&uz<num.size()-1) ++uz;
                res+=" "+num.substr(uz,num.size()-uz);
            }else if(r[j]=="<str>"){
                res+=" "+v[k];
            }else break;
            ++j;++k;
        }
        if(j==lr&&k==lv){
            cout<<res<<endl;
            return;
        }
    }
    cout<<"404"<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        string regstr,name;
        cin>>regstr>>name;
        regulations.push_back(regulation(name,str2regv(regstr)));
    }
    while(m--){
        string str;
        cin>>str;
        urlmap(str);
    }
    return 0;
}
