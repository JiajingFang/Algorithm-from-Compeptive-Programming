// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Sample Input 1 Sample Output 1
5 5
1 2
2 3
2 4
3 4
4 5             2

*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    
ll dfs_counter=0;
const ll UNVISITED=-1;
ll bridge=0,V=0;
const ll maxn=1000000;
  vector<ll> dfs_num(maxn, UNVISITED);
  //dfs num[v] the timestamp at which v was explored
 //数组中的值表示该顶点在DFS中的遍历顺序(或者说时间戳)，每访问到一个未访问过的顶点，访问顺序的值（时间戳）就增加1
  vector<ll> dfs_min(maxn, UNVISITED);
  //dfs min[v] the minimum dfs num reachable from v using the directed Tree Edges and at most one Back Edge
  //数组中的值表示DFS中该顶点不通过父顶点能访问到的祖先顶点中最小的顺序值（或者说时间戳）。
  vector<ll> dfs_parent(maxn,-1);
  vector<vector<ll>> adj (maxn);


void dfs(ll u){
	dfs_min[u]=dfs_num[u]=dfs_counter++;
	for(auto v:adj[u]){
		if(dfs_num[v]==UNVISITED){
			dfs_parent[v]=u;
			dfs(v);
			
			if(dfs_num[u]<dfs_min[v]) {
				bridge++;
		    }
			dfs_min[u]=min(dfs_min[u],dfs_min[v]);
		}
		else if(v!=dfs_parent[u])
		    dfs_min[u]=min(dfs_min[u],dfs_num[v]);
	}
}
int main() {
  ll n,m;
  scanf("%lld%lld",&n,&m);
  ll len=0,a,b; 
  V=n;
  
  while(len!=m){
    scanf("%lld%lld",&a,&b);
    adj[a].push_back(b);
  	adj[b].push_back(a);
	len++;
  }
  

  
  


  for(ll i=1;i<=V;i++){
  	  if(dfs_num[i]==UNVISITED){
  	  	dfs(i);
		}
	  
  }

  
   printf("%lld\n",bridge);
  
   return 0;
  	} 
