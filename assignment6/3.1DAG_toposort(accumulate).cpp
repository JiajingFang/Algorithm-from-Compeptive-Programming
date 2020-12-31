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
Sample Input 1 Sample Output 1
5 5
10 20 30 40 50
1 2
2 5
1 3
3 4
4 5
                  130
In this case the graph is a DAG graph: 一个有向图从任意顶点出发无法经过若干条边回到该点，则这个图是一个有向无环图DAG
*/ 

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
const ll maxn=1000000;
vector <ll> indegree(maxn);
vector<vector<ll>> adj (maxn);
ll V;
map<ll,ll>nums;
vector<ll> counting;

vector<ll> toposort(){
	ll num=0;
	queue<ll> q;
	vector<ll> res;
	for(ll i=1;i<=V;i++){
		if(indegree[i]==0) q.push(i);
	}
	
	while(!q.empty()){
		ll u=q.front();
		res.push_back(u);
		q.pop();
		for(std::size_t i=0;i<adj[u].size();i++){
			ll v=adj[u][i];
			indegree[v]--;
			if(indegree[v]==0) q.push(v);
		}
		adj[u].clear();
		num++;
	}
	return res;
}



int main() {
  ll n,m;
  scanf("%lld%lld",&n,&m);
  
  ll len=0,a,b,c; 
  V=n;
  counting.push_back(0);
  while(len!=n){
  	scanf("%lld",&c);
  	nums.insert(std::pair<ll,ll>(len+1,c));
  	counting.push_back(c);
  	len++;
  }
  
  len=0;
  while(len!=m){
    scanf("%lld%lld",&a,&b);
    adj[a].push_back(b);
    indegree[b]++;
	len++;
  }
  
  vector<vector<ll>> adj1=adj;
  vector<ll> topo;
  ll sum=0;
  topo=toposort();
  for(auto u:topo){
  	cout<<u<<endl;
  	for(auto p:adj1[u]){
  		counting[p]=max(counting[u]+nums[p],counting[p]);
    }
   }

  for(auto i:counting){
	if(sum<i) sum=i;
  }
  cout<<sum<<endl;
  return 0;
}
	
  
  
  


  
   
  	
