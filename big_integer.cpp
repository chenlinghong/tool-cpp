#include <iostream>
#include <stack>
#include <list>
#include <cstring>
#define N 10005
using namespace std;

// ���ڴ���м�ֵ���� 
int tmp_a[N];

// �ӷ� 
string addition(string a, string b);
// �׳�
string factorial(long n);
int main(){
	string a = "11111111";
	string b = "2222222222";

	// �ӷ� 
//	string res = addition(a,b);
//	cout<<a<<"+"<<b<<"="<<res<<endl;

	// �׳� 
	long c = 11111;
	cout<<factorial(c)<<endl;	
	return 0;
}

/* 
�������ӷ� 
Args:
	a: �����������
	b: ����������� 
*/ 
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

/**
����һ�����Ľ׳�
Args:
	n: �������� 
Return:
	�׳� 
*/
string factorial(long n){
	// ����ֱ�ӷ��ؿմ� 
	if(n < 0){
		return "";
	}
	// ������a��ʼ��Ϊ0 
	memset(tmp_a, 0, sizeof(tmp_a));
	tmp_a[0] = 1;
	// carry:��λ 
	int tmp, carry = 0;
	for(int i=2; i<=n; i++){
		// TODO �˴������Ż��ڲ�ѭ�����������ж� 
		for(int j=0; j<N-1; j++){
			tmp = tmp_a[j] * i + carry;
			tmp_a[j] = tmp % 10;
			carry = tmp / 10;
		} 
	}
	string result = "";
	for(int i=N-1; i>=0; i--){
		if(tmp_a[i] != 0){
			for(int j=i; j>=0; j--){
				result += tmp_a[j] + '0';
			}
			break;
		}
	}
	return result;
}
