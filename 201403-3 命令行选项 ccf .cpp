#include <bits/stdc++.h>
using namespace std;
map<string,int> mcmd;
map<string,string> m;
string nextsplit(string &str)
{
    size_t pos=str.find(" ");
    string ans;
    if(pos==string::npos){
        ans=str;
        str="";
        return ans;
    }
    ans=str.substr(0,pos);
    str=str.substr(pos+1);
    return ans;
}
void deal(string str)
{
    m.clear();
    nextsplit(str);
    while(str.size()>0){
        string x=nextsplit(str);
        if(mcmd.count(x+":")>0&&str.size()>0){
            string next=nextsplit(str);
            //if(next[0]=='-')return;此处多考虑了，是合法的
            m[x]=next;
            continue;
        }
        if(mcmd.count(x)>0){
            m[x]="";
            continue;
        }
        return;
    }
    return;
}
int main()
{
    int n;
    string cmd;
    cin>>cmd;
    for(size_t i=0;i<cmd.size();++i){
        if(i<cmd.size()-1&&cmd[i+1]==':'){
            mcmd['-'+string(1,cmd[i])+cmd[i+1]]=1;
            i++;
        }
        else{
            mcmd['-'+string(1,cmd[i])]=1;
        }
    }
    cin>>n;
    cin.get();
    for(int i=1;i<=n;++i)
    {
        string str;
        getline(cin,str);
        deal(str);
        cout<<"Case "<<i<<":";
        map<string,string>::iterator it=m.begin();
        while(it!=m.end())
        {
            cout<<" "<<it->first;
            if(it->second!="")
                cout<<" "<<it->second;
            ++it;
        }
        cout<<endl;
    }
    return 0;
}
