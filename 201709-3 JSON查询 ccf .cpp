#include <bits/stdc++.h>
using namespace std;
bool isroot(string &jsonstr,size_t pos)
{
    int pcnt=0;
    for(size_t i=0;i<pos;++i)
    {
        if(jsonstr[i]=='{') ++pcnt;
        if(jsonstr[i]=='}') --pcnt;
    }
    return pcnt==0;
}
vector<string> split(string str)
{
    size_t pos=str.find(".");
    vector<string> ret;
    while(pos!=string::npos)
    {
        ret.push_back(str.substr(0,pos));
        str=str.substr(pos+1);
        pos=str.find(".");
    }
    ret.push_back(str);
    return ret;
}
string subjsonstr(string jsonstr,int lpos)
{
    int pcnt=1;
    size_t rpos=lpos;
    while(pcnt)
    {
        if(jsonstr[rpos]=='{')
            pcnt++;
        else if(jsonstr[rpos]=='}')
            pcnt--;
        ++rpos;
    }
    return jsonstr.substr(lpos,rpos-lpos-1)+",";
}
void search(vector<string> &ret,string jsonstr)
{
    size_t i=0;
    while(i<ret.size()-1)
    {
        size_t pos=jsonstr.find(ret[i]+":{");
        if(pos==string::npos||!isroot(jsonstr,pos))
        {
            cout<<"NOTEXIST\n";
            return;
        }
        jsonstr=subjsonstr(jsonstr,pos+ret[i].size()+2);
        ++i;
    }
    size_t pos=jsonstr.find(ret.back()+":");
    if(pos==string::npos||!isroot(jsonstr,pos))
    {
        cout<<"NOTEXIST\n";
    }
    else
    {
        i=pos+ret.back().size()+1;
        if(jsonstr[i]=='{')
            cout<<"OBJECT\n";
        else
        {
            size_t dp=jsonstr.find(",",i);
            if(dp==string::npos)
            {
                cout<<"NOTEXIST\n";
                return;
            }
            string x;
            while(i<dp)
                x+=jsonstr[i++];
            cout<<"STRING "<<x<<endl;
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    string jsonstr;
    int n,m;
    cin>>n>>m;
    cin.get();
    cin.get();
    for(int i=0;i<n;++i)
    {
        char ch;
        while((ch=cin.get())!='\n')
        {
            if(ch==' '||ch=='"') continue;
            if(ch=='\\')
            {
                jsonstr+=cin.get();
                continue;
            }
            jsonstr+=ch;
        }
    }
    jsonstr[jsonstr.length()-1]=',';
    while(m--)
    {
        string str;
        cin>>str;
        vector<string> ret=split(str);
        search(ret,jsonstr);
    }
    return 0;
}
