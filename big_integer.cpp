#include <iostream>
#include <stack>
#include <list>
using namespace std;
string addition(string a, string b);
int main(){
	string a = "11111111";
	string b = "2222222222";
	// �ӷ� 
	string res = addition(a,b);
	cout<<a<<"+"<<b<<"="<<res<<endl;
	
	return 0;
}

// �������ӷ� 
string addition(string a, string b){
	// ��˫����������ջ�ĵײ�ṹ
	stack<int, list<int> > s1,s2,res;
	int len_a = a.length(), len_b = b.length();
	for(int i=0;i<len_a;i++){
		s1.push(a.at(i) - '0');
	}
	for(int i=0; i<len_b; i++){
		s2.push(b.at(i) - '0');
	}
	int len = min(len_a, len_b), f = 0;
	// ���㹫�����ȵĲ��� 
	for(int i=0; i<len; i++){
		f += s1.top() + s2.top();
		s1.pop(), s2.pop();
		res.push(f%10);
		f /= 10;
	}
	// �˲��ִ���ֻ��ִ��һ��while 
	while(s1.empty() == false){
		f += s1.top();
		s1.pop();
		res.push(f%10);
		f /= 10;
	}
	while(s2.empty() == false){
		f += s2.top();
		s2.pop();
		res.push(f%10);
		f /= 10;
	}
	// �������ʣ��Ľ�λf 
	while(f){
		res.push(f%10);
		f /= 10;
	}
	// res ���򼴽���ַ��� 
	string result = "";
	while(res.empty() == false){
		result += res.top() + '0';
		res.pop();
	}
	return result;
}
