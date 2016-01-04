#include<iostream>
#include<string>
using namespace std;
int main()
{
		string str,str1,str2,sum="";
		cin>>str;
		int i=str.length()-1;
		while(true)
		{
			str2=sum;
		//	cout<<str2<<endl;
			sum=""; 
			str1="";
			for(;i>=0&&str[i]!='+';i--)
			{
				str1+=str[i];
			}
			//cout<<str1<<endl;
			i--;
			if(str2.length()>str1.length())
			{
				for(int i=str1.length();i<str2.length();i++)
				str1+='0';
			}
			if(str2.length()<str1.length())
			{
				for(int i=str2.length();i<str1.length();i++)
					str2+='0';
			}
			int inf=0;
			for(int j=0;j<str1.length();j++)
			{
				int tmp=str1[j]-'0'+str2[j]-'0'+inf;
					inf=0;
				if(tmp>9)
				{
					sum+=(char)(tmp-10+'0');
					inf=1; 
				}
				else
					sum+=(char)(tmp+'0');							
			}
			if(inf==1)
				sum+='1';
			if(i==-2)
				break;
		}
			for(int i=sum.length()-1;i>=0;i--)
				cout<<sum[i];
				cout<<endl;
			return 0;
 } 
