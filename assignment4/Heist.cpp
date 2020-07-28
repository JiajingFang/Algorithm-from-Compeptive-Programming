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
Sample Input 1 Sample Output 1
4 2
1 1 1 1
				2 2
				1 4
Sample Input 2 Sample Output 2
9 3
0 1 2 2 3 2 3 2 1
				6 3
				2 5 8
Sample Input 3 Sample Output 3
12 3
4 8 0 9 4 9 8 4 4 8 7 0
				29 4
				1 4 7 10
*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    

int main() {
	
	int n,m;
	cin>>n>>m;
	ll x[n];
	int len=0;
	int tmp;
	while(len!=n){
		cin>>tmp;
		x[len]=tmp;
		len++;
	}
	ll dp[n];
	ll last[n];
	
	for(int i=0;i<n;i++){
		dp[i]=i>0?dp[i-1]:0;
		last[i]=i>0?last[i-1]:-1;
		if(x[i]+(i>=m?dp[i-m]:0)>dp[i]){
			dp[i]=x[i]+(i>=m?dp[i-m]:0);
			last[i]=i;
		}
	}
	//deque can push the result from the front
	int l=n-1;
	deque<int> res;
	while(l>=0){
		l=last[l];
		if(l<0) break;
		res.push_front(l);
		l-=m;
	}

    cout<<dp[n-1]<<" "<<res.size()<<endl;
    //deque can be travered as the normal vector
	for (int i = 0; i < res.size(); i++)
        cout<<res[i]+1<<" ";
	
   return 0;
  	} 
