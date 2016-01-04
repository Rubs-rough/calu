#include<iostream>
#include<string>
#include<stack>
using namespace std;

int getPriority(char operators)  
{  
    if(operators == '(' )  
    {  
        return 0;  
    }  
    else if(operators == '+' || operators == '-')  
    {  
        return 1;  
    }  
    else if(operators == '*' || operators == '/')  
    {  
        return 2;  
    }  
    else if(operators == ")")
    {
	return 3;
    }
}  

string add(string str1,string str2)
{

}
string sub(string str1,string str2)
{
}
string mul(string str1,string str2)
{

}
string div(string str1,string str2)
{
}
string solve(string str)
{
	stack<string> S1;
	stack<string> S2;
	for(int i = 0;i < str.length();)
	{
		if(str[i] >= '0' && str[i] <= '9' || str[i] == '.')
		{
			string temp = "";
			while(str[i] >= '0' && str[i] <= '9' || str[i] == '.')
			{
				temp += str[i];
				i++;
			}
			S1.push(temp);
		}
		else if(str[i] == '(')
		{
			S2.push("(");
			i++;
		}
		else if(str[i] == ')')
		{
			do
			{
				S1.push(S2.top());
				S2.pop();
			}while(S2.top() != "(");
			S2.pop();		
			i++;	
		}
		else
		{
			if(S2.empty())
			{
				string temp = "";
				temp += str[i];
				S2.push(temp);
				i++;
			}
			else
			{
				if(getPriority(str[i] >= getPriority(S2.top()))
				{
					string temp = "";
					temp += str[i];
					S2.push(temp);
					i++;
				}
				else 
				{
					do
					{
						S1.push(S2.top());
						S2.pop();
					}while(!S2.empty() &&  getPriority(str[i] < getPriority(S2.top()));
					string temp = "";
					temp += str[i];
					S2.push(temp);
					i++;
				}
			}
		}
	}
	while(!S2.empty())
	{
		S1.push(S2.top);
		S2.pop();
	}
	while(!S1.empty())
	{
		S2.push(S1.top());
		S1.pop();
	}
	while(!S2.empty())
	{
		string temp = "";
		temp = S2.top();	
		S2.pop();
		if(temp[0] >= '0' && temp[0] <= '9')
		{
			S1.push(temp);
		}	
		else 
		{
			string str1 = S1.top();
			S1.pop();
			string str2 = S1.top();
			S1.pop();
			if(temp == "+")
			{
				S1.push(add(str1,str2));
			}
			else if(temp == "-")
			{
				S1.push(sub(str1,str2));
			}
			else if(temp == "*")
			{
				S1.push(mul(str1,str2));
			}
			else if(temp == "/")
			{
				S1.push(div(str1,str2));
		        {	
		}
		
	}
	return S1.top();
}
int main()
{
	string str;
	while(cout<<"...>" && cin>>str)
	{
		cout<<".."<<solve(str)<<endl;
	}
	return 0;
}
