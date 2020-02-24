#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

int priority(char operator1){
	if(operator1=='(') return 1;
	if(operator1=='+'||operator1=='-') return 2;
	if(operator1=='*'||operator1=='/') return 3;
}



void calculate_stack(stack<double>& st_operand,char operator1){
	double num2 = st_operand.top();
	st_operand.pop();
	double num1 = st_operand.top();
	st_operand.pop();
	if(operator1=='+') st_operand.push(num1+num2);
//	cout<<num1+num2; 
	if(operator1=='-') st_operand.push(num1-num2);
	if(operator1=='*') st_operand.push(num1*num2);
	if(operator1=='/') st_operand.push(num1/num2);
}


int main(){
	string str1="(1+2)*(5/(4-1))";
//	getline(cin,str1);
	stack<char> operator1;
	stack<double> operand1;
	//58
	string tmp_str;
	int j;
	
	for(int i=0;i<str1.size();++i){
		if(isdigit(str1[i])){
			j=i;
			while(isdigit(str1[j++])){
			;}
//		operand1.push(stoi(str1.substr(i,j-i),0,10));
	istringstream iss(str1.substr(i,j-i));
	double temp;
	iss>>temp;
//	cout<<temp<<endl; 
	operand1.push(temp);
		i=j-2;
		}
		//operator
		else if(str1[i]=='(')  operator1.push(str1[i]);
		else if(str1[i]==')') {
				while(!operator1.empty() ){
					if(operator1.top()=='(') {
						operator1.pop();
						break;
					}
					else{
						calculate_stack(operand1,operator1.top());
						operator1.pop();
					}
				}
			}
			
			
			else{  // + - * /
//				cout<<"operator"<<endl; 
			if(operator1.empty()) operator1.push(str1[i]);
			else{
			
				while(!operator1.empty() && (priority(operator1.top())>=priority(str1[i])))
						{
						calculate_stack(operand1,operator1.top());
						operator1.pop();
						}
						operator1.push(str1[i]);
				}
			}
//			cout<<"str1"<<str1[i]<<endl;
	}
	
	//after traversion, if the stack(operator) is not empty, pop and calculate the result;
	while(!operator1.empty()){
		calculate_stack(operand1,operator1.top());
		operator1.pop();
	}
	cout<<operand1.top();
//	cout<<operand1.size();
}


