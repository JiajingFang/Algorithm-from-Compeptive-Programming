// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
/*
Longest Increasing Subsequence
���Ƿ���һ���������������һ��Ԫ��ԽС����ô���ɳ�Ϊ������������еĿ��ܾ�Խ�� ����˵A=(1,3,9����B =(1,4,6�����������У�
������һ��Ԫ��Ϊ8����Ȼ����B��������ɸ��������������У�1,4,6,8����A���оͲ��У�1,3,9,8��,


��ô���Ǿ������������뷨��ά��һ��ջ����ɨ�赽����Ԫ�ر�ջ����Ԫ�ػ�����ôֱ�Ӽ���ջ�У�
�����Ԫ�ر�ջ��Ԫ��С����ô���Ǿʹ�ջ���ҵ���һ���������Ԫ�أ��滻��������������������еĿ��ܡ�

ջ�е�length ����ȷ�ĵ���Ԫ�ز�����ȷ�� 

Sample Input 2 Sample Output 2
6 0
1 5 1 2 2 4
                 3
*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    

int main() {
	ll n,x;
	cin>>n>>x;
	vector<ll> in;
	ll len=0;
	ll tmp;
	while(len!=n){
		cin>>tmp;
		in.push_back(tmp);
		len++;
	}
	vector<ll> st;
	for(auto &x:in){
		auto it=lower_bound(st.begin(),st.end(),x);
		if(it==st.end()){
	//	    cout<<x<<endl;
			st.push_back(x);
		} 
		else{
			*it=x;
			
		} 
	}
	for(auto x:st) cout<<x<<" " ;
	cout<<endl; 
	cout<<st.size();
   return 0;
  	} 
