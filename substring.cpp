#include <iostream>
using namespace std;
long long max_substring(int a[], int n);
int main(){
	int a[7] = {-4,11,-2,13,-7,-3,12};
	int b = 7;
	cout<<max_substring(a,b)<<endl;
	return 0;
}
/**
����һ���������У��������Ӵ��ͣ��Ӵ���������Ҫ���ڣ�
Args:
	data: ��������
	len: ���鳤��
*/
long long max_substring(int data[], int len){
	long long result = data[0], tmp = data[0];
	for(int i=0; i<len; i++){
		if(tmp > 0){
			tmp += data[i];
		} else {
			tmp = data[i];
		}
		if(tmp > result){
			result = tmp;
		}
	} 
	return result;
}
