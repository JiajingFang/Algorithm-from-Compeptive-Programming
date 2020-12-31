// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue> 
#include <map>
using namespace std;


typedef long long ll;
/*
Print the total value of gold ingots you can collect when you can choose the start and end cave freely.
Sample Input 3 Sample Output 3
4 4
4 5 2 7
1 2
2 1
1 3
2 4
                16
In this case the graph may contain circle 
*/ 

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
stack<int> S; // stack
const ll maxn=1000000;
map<ll,ll>nums;
vector<ll> counting;
int dp[maxn];
vector<vector<ll>> adj (maxn);
vector<vector<ll>> adj1 (maxn);
int dfs_counter = 0;
const int UNVISITED = -1;

vector<int> dfs_num (maxn, UNVISITED);
vector<int> dfs_min (maxn, UNVISITED);
vector<bool> on_stack (maxn, false);
vector<vector<int>> dfs_res;

void dfs(int u){
	dfs_min[u]=dfs_num[u]=dfs_counter++;
	S.push(u);
	on_stack[u]=true;
	for(auto v:adj[u]){
		if(dfs_num[v]==UNVISITED) dfs(v);
		if(on_stack[v]) dfs_min[u]=min(dfs_min[u],dfs_min[v]);
		
	}
	if(dfs_min[u]==dfs_num[u]){
		vector<int> tmp;
		int v=-1;
		while(v!=u){
			v=S.top();
			S.pop();
			on_stack[v]=false;
			tmp.push_back(v);
		}
		dfs_res.push_back(tmp);
	}
}



int main() {
  ll n,m;
  scanf("%lld%lld",&n,&m);
  ll V=n;
  
  
  ll len=0,a,b,c; 
  V=n;
  counting.push_back(0);
  while(len!=n){
  	scanf("%lld",&c);
  	counting.push_back(c);
  	nums.insert(std::pair<ll,ll>(len+1,c));
  	len++;
  }
  
  len=0;
  while(len!=m){
    scanf("%lld%lld",&a,&b);
    adj[a].push_back(b);
	len++;
  }
  
  for(int i=1;i<=V;i++){
  	if(dfs_num[i]==UNVISITED) dfs(i);
  }
  
  int res=0;
  for(auto u:dfs_res){
  	  if(u.size()>1){
  	  	
		  
	  }
	  if(u.size()==1){
  		int tmpa=u[0];
  		for(auto p:adj[tmpa]){
  		counting[tmpa]=max(counting[tmpa]+nums[p],counting[p]);
	  	}
	  }
  	
  }
  
  for(auto i:counting){
  	cout<<i<<endl;
	if(res<i) res=i;
  }
  cout<<res;
  return 0;
}
