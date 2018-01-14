#include <bits/stdc++.h>
using namespace std;
//vector<string> vMon={"","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};//c++11 surport
//vector<string> vWek={"sun","mon","tue","wed","thu","fri","sat"};//c++11 surport
char vMon[][4]={"","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
char vWek[][4]={"sun","mon","tue","wed","thu","fri","sat"};
int mtharray[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
map<string,int> mMon,mWek;
map<string,string> mrt;
void buildMonAndWekMap()
{
	for(int i=1;i<=12;++i) mMon[vMon[i]]=i;
	for(int i=0;i<=6;++i) mWek[vWek[i]]=i;
}

string to_string(int n)//c++11 surport
{
	if(n==0) return "0";
	string ans;
	while(n!=0)
	{
		ans+='0'+n%10;
		n/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int stoi(const string &str)//c++11 surport
{
	int len=str.size();
	int ans=0;
	for(int i=0;i<len;++i)
	{
		ans=ans*10+str[i]-'0';
	}
	return ans;
}
void tostandard(string &str)//转化为标准小写 
{
	int len=str.size();
	for(int i=0;i<len;++i)str[i]=tolower(str[i]);
}
vector<string> splitStringAndbuildVector(string &str,int TAG)//TAG=0(other),1(month),2(dayofweek);
{
	str+=",";
	vector<string> vret;
	size_t found=str.find(",");
	while(found!=string::npos)
	{
		string x=str.substr(0,found);
		str=str.substr(found+1,str.size()-found-1);
		size_t fdx=x.find("-");
		if(fdx==string::npos)//非连续值 
		{
			if(TAG==1&&isalpha(x[0])) x=to_string(mMon[x]);//month
			if(TAG==2&&isalpha(x[0])) x=to_string(mWek[x]);//day of week;
			if(x.size()==1) x="0"+x;
			vret.push_back(x);
		}
		else//连续值 
		{
			string L=x.substr(0,fdx),R=x.substr(fdx+1,x.size()-fdx-1);
			int left,right;
			if(TAG==0) left=stoi(L),right=stoi(R);
			else if(TAG==1)//month
			{
				left=(isalpha(L[0]))?mMon[L]:stoi(L);
				right=(isalpha(R[0]))?mMon[R]:stoi(R);
			}
			else if(TAG==2)//day of week
			{
				left=(isalpha(L[0]))?mWek[L]:stoi(L);
				right=(isalpha(R[0]))?mWek[R]:stoi(R);
			}
			while(left<=right)
			{
				string num=to_string(left);
				if(num.size()==1)num="0"+num;
				vret.push_back(num);
				++left;
			} 
		}
		found=str.find(",");
	}
	return vret;
}
void d(vector<string> &v)
{
	int n=v.size();
	for(int i=0;i<n;++i)
	cout<<v[i]<<" ";
	cout<<endl;
}
bool isleapyear(int y)
{
	return (y%4==0&&y%100)||y%400==0;
}
string getWeekday(string year,string month,string day)
{
	int y=stoi(year),m=stoi(month),d=stoi(day);
	if(isleapyear(y)) mtharray[2]=29;
	else mtharray[2]=28;
	int by=1970,countday=0;
	while(by<y)
	{
		countday+=(isleapyear(by))?366:365;
		++by; 
	}
	for(int i=1;i<m;++i) countday+=mtharray[i];
	countday+=d-1;
	return "0"+to_string((4+countday%7)%7);
}
int main()
{
	int n;
	string st,et;
	buildMonAndWekMap();
	freopen("2.txt","r",stdin);
	cin>>n>>st>>et;
	string syy=st.substr(0,4),smm=st.substr(4,2),sdd=st.substr(6,2),sHH=st.substr(8,2),sMM=st.substr(10,2);
	string eyy=et.substr(0,4),emm=et.substr(4,2),edd=et.substr(6,2),eHH=et.substr(8,2),eMM=et.substr(10,2);
	int syInt=stoi(syy),eyInt=stoi(eyy);
	while(n--)
	{
		vector<string> vmts,vhur,vdfm,vmth,vdfw;
		string minutes,hours,dofmon,month,dofwek,command;
		cin>>minutes>>hours>>dofmon>>month>>dofwek>>command;
		tostandard(month);//不区别大小写，转化为标准小写 
		tostandard(dofwek);//不区别大小写，转化为标准小写 
		if(minutes=="*") minutes="0-59";
		vmts=splitStringAndbuildVector(minutes,0);//应该执行的分钟 
		if(hours=="*") hours="0-23";
		vhur=splitStringAndbuildVector(hours,0); //应该执行的小时
		if(dofmon=="*") dofmon="1-31";
		vdfm=splitStringAndbuildVector(dofmon,0);//应该执行的天 
		if(month=="*") month="1-12";
		vmth=splitStringAndbuildVector(month,1);//应该执行的月份 
		if(dofwek=="*") dofwek="0-6";
		vdfw=splitStringAndbuildVector(dofwek,2);//应该周几执行 
		set<string> wekexist;
		for(size_t i=0;i<vdfw.size();++i) wekexist.insert(vdfw[i]);//更快的检索当前日期（dayofweek）是不是应该执行 
		int curyear=syInt;//从开始年份执行 
		while(curyear<=eyInt)
		{
			if(isleapyear(curyear)) mtharray[2]=29;//leapyear的2月份应该是29天 
			else mtharray[2]=28;
			string year=to_string(curyear);//年份 
			for(size_t mi=0;mi<vmth.size();mi++)//month
			{
				string curm=vmth[mi];//当前月份 
				for(size_t di=0;di<vdfm.size();di++)//day of month
				{
					string curd=vdfm[di];//当前日期 
					string wd=getWeekday(year,curm,curd);//该年，该月，该日是星期几 
					if(wekexist.count(wd)==0||stoi(curd)>mtharray[stoi(curm)])continue;//命令行中不包含该星期或者当前天数超过当前月份的应有天数时 
					for(size_t Hi=0;Hi<vhur.size();++Hi)//hour
					{
						for(size_t Mi=0;Mi<vmts.size();++Mi)//minutes
						{
							string datetime=year+curm+curd+vhur[Hi]+vmts[Mi];
							if(datetime>=st&&datetime<et) mrt[datetime]=command;//在当前日期时间内 
						}
					}
				}
			}
			++curyear;//进入下一年 
		}
	}
	for(map<string,string>::iterator it=mrt.begin();it!=mrt.end();++it)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
