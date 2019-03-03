#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <string>
using namespace std;

// ʮ����תN���� 
string conversion(long long data, int conv);
// ʮ������ת�˽���
string hex2oct(string data); 
// ʮ������ת������
string hex2binary(string data);
// ʮ��������ת4λ������ 
string hexnum2binary(char num);
// ������ת�˽��� (�������λ�������Ż�)
string binary2oct(string data); 

int main(){
	long long data = 100000;
	int conv = 16;
//	cout<<conversion(data, conv)<<endl;
	
	string hex = "AD345";
	cout<<hex2oct(hex)<<endl;
	return 0;
} 


/* 
����ת��
Args:
	data:ԭʼ���ݣ�ʮ�������� 
	conv:��ת�������� (2-16)
*/  
string conversion(long long data, int conv){
	string result = "";
	stack<int, vector<int> > s;
	// ��������� 
	if(data < 0){
		result += "-";
	}
	while(data){
		s.push(data % conv);
		data /= conv;
	}
	while(s.empty() == false){
		int temp = s.top();
		s.pop();
		// ˵��convС�ڵ���ʮ���� 
		if(temp < 10){
			result += temp + '0';
		} else {
			result += temp - 10 + 'A';
		}
	}
	return result;
}


/**
16����ת8����
Args:
	data: 8���Ʊ�ʾ�����ַ���
Return��
	16���Ʊ�ʾ�������ַ��� 
*/
string hex2oct(string data){
	string tmp = hex2binary(data);
	return binary2oct(tmp);
}



/**
 16����ת2����
Args:
	data: ʮ�����Ʊ�ʾ�������ַ���
Return��
	�����ƴ� 
*/
string hex2binary(string data){
	int len = data.length();
	if(len <= 0){
		return "";
	}
	string res = "";
	for(int i=0; i<len; i++){
		res += hexnum2binary(data.at(i)); 
	}
	return res;
} 

/*
ʮ��������ת��Ϊ�������ַ���
Args:
	num: ʮ��������
Return:
	���������Ʊ�ʾ 
*/
string hexnum2binary(char num){   
    string res;
    switch(num){
        case '0':res="0000";break;
        case '1':res="0001";break;
        case '2':res="0010";break;
        case '3':res="0011";break;
        case '4':res="0100";break;
        case '5':res="0101";break;
        case '6':res="0110";break;
        case '7':res="0111";break;
        case '8':res="1000";break;
        case '9':res="1001";break;
        case 'A':res="1010";break;
        case 'B':res="1011";break;
        case 'C':res="1100";break;
        case 'D':res="1101";break;
        case 'E':res="1110";break;
        case 'F':res="1111";break;
    }
    return res;
}


/**
������ת�˽���
Args:
	data: �����Ʊ�ʾ�ַ������������λ�������Ż���
Return��
	�˽����ַ��� 
*/
string binary2oct(string data){
	int len = data.length();
	if(len <= 0){
		return "";
	}
	int binary[3] = {0,0,0}, k=0;
	string res = "";
	for(int i=len-1; i>=0; i--){
		binary[k++] = data.at(i) - '0';
		if(k % 3 == 0){
			int m = binary[2]*4+binary[1]*2+binary[0]*1;
			res += m + '0';
			k = 0;
		}
	}
	if(k==1){
		int m = binary[0] * 1;
		res += m + '0';
	} else if(k == 2){
		int m = binary[1] * 2 + binary[0] * 1;
		res += m + '0'; 
	}
	int start = 0;
	// ����ǰ��0 
	for(int i=res.length()-1; i>=0; i--){
		if(res.at(i) != '0'){
			start = i;
			break;
		} 
	}
	string result = "";
	for(int i=start; i>=0; i--){
		result += res.at(i);
	}
	return result;
}
