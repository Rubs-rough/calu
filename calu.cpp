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
    else if(operators == ')')
    {
	return 3;
    }
}  

inline int compare(string str1, string str2) {
    if(str1.size() > str2.size())
	return 1;
    else if(str1.size() < str2.size())
        return -1;
    else
        return str1.compare(str2);
}
string ADD_INT(string str1, string str2) {
    string SUB_INT(string str1, string str2);
    int sign = 1;
    string str;
    if(str1[0] == '-') {
        if(str2[0] == '-') {
            sign = -1;
            str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));
        } else {
            str = SUB_INT(str2, str1.erase(0, 1));
        }
    } else {
        if(str2[0] == '-')
            str = SUB_INT(str1, str2.erase(0, 1));
        else {
            string::size_type l1, l2;
            int i;
            l1 = str1.size(); l2 = str2.size();
            if(l1 < l2) {
                for(i = 1; i <= l2 - l1; i++)
                    str1 = "0" + str1;
            } else {
                for(i = 1; i <= l1 - l2; i++)
                    str2 = "0" + str2;
            }
            int int1 = 0, int2 = 0; 
            for(i = str1.size() - 1; i >= 0; i--) {
                int1 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) % 10;
                int2 = (int(str1[i]) - '0' + int(str2[i]) - '0' +int2) / 10;
                str = char(int1 + '0') + str;
            }
            if(int2 != 0) str = char(int2 + '0') + str;
        }
    }
    if((sign == -1) && (str[0] != '0'))
        str = "-" + str;
    return str;
}
string SUB_INT(string str1, string str2) {
    string MUL_INT(string str1, string str2);
    int sign = 1;
    string str;
    int i;
    if(str2[0] == '-')
        str = ADD_INT(str1, str2.erase(0, 1));
    else {
        int res = compare(str1, str2);
        if(res == 0) return "0";
        if(res < 0) {
            sign = -1;
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        string::size_type tempint;
        tempint = str1.size() - str2.size();
        for(i = str2.size() - 1; i >= 0; i--) {
            if(str1[i + tempint] < str2[i]) {
                str1[i + tempint - 1] = char(int(str1[i + tempint - 1]) - 1);
                str = char(str1[i + tempint] - str2[i] + ':') + str;
            } else
                str = char(str1[i + tempint] - str2[i] + '0') + str;
        }
        for(i = tempint - 1; i >= 0; i--)
            str = str1[i] + str;
    }
    str.erase(0, str.find_first_not_of('0'));
    if(str.empty()) str = "0";
    if((sign == -1) && (str[0] != '0'))
        str = "-" + str;
    return str;
}
string MUL_INT(string str1, string str2) {
    int sign = 1;
    string str;
    if(str1[0] == '-') {
        sign *= -1;
        str1 = str1.erase(0, 1);
    }
    if(str2[0] == '-') {
        sign *= -1;
        str2 = str2.erase(0, 1);
    }
    int i, j;
    string::size_type l1, l2;
    l1 = str1.size(); l2 = str2.size();
    for(i = l2 - 1; i >= 0; i --) {
        string tempstr;
        int int1 = 0, int2 = 0, int3 = int(str2[i]) - '0';
        if(int3 != 0) {
            for(j = 1; j <= (int)(l2 - 1 - i); j++)
                tempstr = "0" + tempstr;
            for(j = l1 - 1; j >= 0; j--) {
                int1 = (int3 * (int(str1[j]) - '0') + int2) % 10;
                int2 = (int3 * (int(str1[j]) - '0') + int2) / 10;
                tempstr = char(int1 + '0') + tempstr;
            }
            if(int2 != 0) tempstr = char(int2 + '0') + tempstr;
        }
        str = ADD_INT(str, tempstr);
    }
    str.erase(0, str.find_first_not_of('0'));
    if(str.empty()) str = "0";
    if((sign == -1) && (str[0] != '0'))
        str = "-" + str;
    return str;
}
string DIVIDE_INT(string str1, string str2, int flag) {
    string quotient, residue; 
    int sign1 = 1, sign2 = 1;
    if(str2 == "0") {
        quotient = "ERROR!";
        residue = "ERROR!";
        if(flag == 1) return quotient;
        else return residue;
    }
    if(str1 == "0") {
        quotient = "0";
        residue = "0";
    }
    if(str1[0] == '-') {
        str1 = str1.erase(0, 1);
        sign1 *= -1;
        sign2 = -1;
    }
    if(str2[0] == '-') {
        str2 = str2.erase(0, 1);
        sign1 *= -1;
    }
    int res = compare(str1, str2);
    if(res < 0) {
        quotient = "0";
        residue = str1;
    } else if(res == 0) {
        quotient = "1";
        residue = "0";
    } else {
        string::size_type l1, l2;
        l1 = str1.size(); l2 = str2.size();
        string tempstr;
        tempstr.append(str1, 0, l2 - 1);
        for(int i = l2 - 1; i < l1; i++) {
            tempstr = tempstr + str1[i];
            for(char ch = '9'; ch >= '0'; ch --) {
                string str;
                str = str + ch;
                if(compare(MUL_INT(str2, str), tempstr) <= 0) {
                    quotient = quotient + ch;
                    tempstr = SUB_INT(tempstr, MUL_INT(str2, str));
                    break;
                }
            }
        }
        residue = tempstr;
    }
    quotient.erase(0, quotient.find_first_not_of('0'));
    if(quotient.empty()) quotient = "0";
    if((sign1 == -1) && (quotient[0] != '0'))
        quotient = "-" + quotient;
    if((sign2 == -1) && (residue[0] != '0'))
        residue = "-" + residue;
    if(flag == 1) return quotient;
    else return residue;
}
string DIV_INT(string str1, string str2) {
    return DIVIDE_INT(str1, str2, 1);
}
string MOD_INT(string str1, string str2) {
    return DIVIDE_INT(str1, str2, 0);
}
string solve(string str){
	stack<string> S1;
	stack<string> S2;
	for(int i = 0;i < str.size();)
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
				string temp = "";
				temp += str[i];
				if(getPriority(str[i]) >= getPriority(temp[0]))
				{
				        temp = "";
					temp += str[i];
					S2.push(temp);
					i++;
				}
				else 
				{
					temp = "";
					temp += str[i];
					do
					{
						S1.push(S2.top());
						S2.pop();
					}while(!S2.empty() &&  getPriority(str[i]) < getPriority(temp[0]));
					temp = "";
					temp += str[i];
					S2.push(temp);
					i++;
				}
			}
		}
	}
	while(!S2.empty())
	{
		S1.push(S2.top());
		S2.pop();
	}
	while(!S1.empty())
	{
		S2.push(S1.top());
		cout<<S2.top()<<endl;
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
				S1.push(ADD_INT(str1,str2));
			}
			if(temp == "-")
			{
				S1.push(SUB_INT(str1,str2));
			}
			if(temp == "*")
			{
				S1.push(MUL_INT(str1,str2));
			}
			if(temp == "/")
			{
				S1.push(DIVIDE_INT(str1,str2,0));
                        }	
		}
		
	}
	return S1.top();
}
string pretreatment(string str){
	if(str[0] == '-')
		str.insert(0,"0");
	for(int i = 1;i < str.size();i++){
		if(str[i] == '-' && (str[i - 1] < '0' || str[i - 1] > '9') && str[i - 1] != ')')
		{
			str.insert(i,"0");
		}}return str;
}	
int main(int argc,char **argv)
{
	string str;
	while(cout<<"...>")
	{
		cin>>str;
		str = pretreatment(str);
		cout<<str<<endl;
		cout<<".."<<solve(str)<<endl;
	}
	return 0;
}
