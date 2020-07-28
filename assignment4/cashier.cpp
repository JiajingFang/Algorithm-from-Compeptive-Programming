// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include<map>
#include <algorithm>
using namespace std;


typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    
int C,N;
int V[500];
int dp[500][100001];

int32_t main(){
	cin>>C>>N;
	for(int i=0;i<N;i++) cin>>V[i];
	
	for(int i=0;i<N;i++){
		for(int c=1;c<=C;c++){
			dp[i][c]=i>0 ? dp[i-1][c] : 1e9;
			if(c>=V[i]) dp[i][c]=min(dp[i][c],dp[i][c-V[i]]+1);
		}
	}
	
	if(dp[N-1][C]>=1e9) cout<<"impossible"<<endl;
	else cout<<dp[N-1][C]<<endl;
}
