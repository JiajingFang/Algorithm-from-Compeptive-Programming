#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>

using namespace std;

typedef long long ll;
/* use ctr+z to end
Sample Input 1              Sample Output 1
+(3, * (4,113,7))
* (50,500)
+(7,5)
+(7,5)
0
+(7,5)
* (50,500)
+(3, * (4,113,7))
+(7,5)
                            Equal
*/

int main(){
	/*cin��cout�ٶ���������Ϊ�Ȱ�Ҫ����Ķ������뻺�����������������Ч�ʽ��ͣ������ios_base::sync_with_stdio(false)
	����������iostream������������棬���Խ�ʡ���ʱ�䣬ʹЧ����scanf��printf����޼�
	*/
	ios_base::sync_with_stdio(false);
	multiset<string> m1,m2;
	
	string exp;
	
	
	while(getline(cin,exp)&&exp!="0"){
		m1.insert(exp);
	}
	cout<<"middle"<<endl;
	while(getline(cin,exp)){
		m2.insert(exp);
		cout<<"1"<<endl;
	}
	if(m1==m2) cout<<"Equal"<<endl;
	else cout<<"UnEqual"<<endl;
	return 0;
}
