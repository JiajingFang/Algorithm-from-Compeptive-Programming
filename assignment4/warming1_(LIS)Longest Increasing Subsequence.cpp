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
我们发现一个上升子序列最后一个元素越小，那么它成长为最长的上升子序列的可能就越大 比如说A=(1,3,9）和B =(1,4,6）两个子序列，
现在有一个元素为8，显然对于B序列能组成更长的上升子序列（1,4,6,8）而A序列就不行（1,3,9,8）,


那么我们就有了这样的想法，维护一个栈，当扫描到的新元素比栈顶的元素还大，那么直接加入栈中，
如果新元素比栈顶元素小，那么我们就从栈中找到第一个比他大的元素，替换掉，来增加最长上升子序列的可能。

栈中的length 是正确的但是元素不是正确的 

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
