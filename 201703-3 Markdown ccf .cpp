#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("3.txt","r",stdin);
    string line,text;
    bool x=false;
    getline(cin,line);
    while(true)
    {
        if(line.size()>0)
        {
            text+=line+"\n";
        }
        else if(line.size()==0&&text.size()>0)
        {
            size_t pos=text.find("_");
            while(pos!=string::npos)
            {
                text.replace(pos,1,"<em>");
                size_t nxp=text.find("_",pos);
                text.replace(nxp,1,"</em>");
                pos=text.find("_",nxp);
            }
            pos=text.find("[");
            while(pos!=string::npos)
            {
                size_t nxp=text.find("]",pos);
                size_t lp=text.find("(",nxp);
                size_t rp=text.find(")",lp);
                string tt=text.substr(pos+1,nxp-pos-1);
                string lk=text.substr(lp+1,rp-lp-1);
                text.replace(text.begin()+pos,text.begin()+rp+1,"<a href=\""+lk+"\">"+tt+"</a>");
                pos=text.find("[",rp);
            }
            if(text[0]=='#')
            {
                int i=0;
                while(text[i]=='#') ++i;
                text=text.substr(i+1);
                text="<h"+string(1,'0'+i)+">"+text;
                text.insert(text.size()-1,"</h"+string(1,'0'+i)+">");
            }
            else if(text[0]=='*')
            {
                text.insert(0,"<ul>\n");
                text.insert(text.size(),"</ul>\n");
                size_t pos=text.find("*");
                while(pos!=string::npos)
                {
                    size_t nxp=text.find("\n",pos);
                    text.insert(nxp,"</li>");
                    text.replace(pos,2,"<li>");
                    pos=text.find("*",nxp);
                }
            }
            else
            {
                text="<p>"+text;
                text.insert(text.size()-1,"</p>");
            }
            cout<<text;
            text="";
        }
        line="";
        if(x) break;
        if(!getline(cin,line))
        {
            x=true;
            line="";
        }
    }
    return 0;
}
