#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    string instr,outstr;
    map<string,string> mv;
    cin>>n>>m;
    cin.get();
    while(n--){
        string line;
        getline(cin,line);
        instr+=line+'\n';
    }
    while(m--){
        string var,x;
        cin>>var;
        cin.get();
        getline(cin,x);
        mv[var]=x.substr(1,x.size()-2);
    }
    size_t pos,nextpos;
    while((pos=instr.find("{{ "))!=string::npos){
        nextpos=instr.find(" }}")+3;
        string var(instr.begin()+pos+3,instr.begin()+nextpos-3);
        outstr+=instr.substr(0,pos);
        instr=instr.substr(nextpos);
        string val=mv.count(var)?mv[var]:"";
        outstr+=val;
    }
    outstr+=instr;
    cout<<outstr;
    return 0;
}

