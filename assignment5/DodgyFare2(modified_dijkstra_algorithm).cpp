// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
/*
Input:A graph that is undirected, weighted and sparse with positive edge weights 
Output: the length of the shortest path from 1 to n

use Dijkstra algorithm(modified with metro ticket) 

Sample Input 2 Sample Output 2
5 6 1 1
1 2 1
1 3 3
2 3 1
2 4 2
3 5 4
4 5 5
2 5 1
                2
*/ 

typedef long long ll;
constexpr ll INF=numeric_limits<ll>::max()/3;
#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    
vector<vector<ll>> dijkstra(ll V,vector<vector<pair<int , ll>>>& adj_bus,vector<vector<pair<int , ll>>>& adj_metro,int t,int start){
	
	int n=adj_bus.size();
	vector<vector<ll>> dist(n,vector<ll>(t+1,INF));
	typedef tuple<ll,int,int> element;
	priority_queue<element, vector<element>, greater<element>> q;
//	priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater <tuple<ll,int,int>>> q;
	q.push({0, 0, start});
	//最小值（第一个值）先出的heap（mini heap）; 
	//if priority_queue<pair<int, int> > pq; then it's a max heap 
	
	while(q.size()){
		ll distance;
		int metro_tickets_used,node;
		tie(distance,metro_tickets_used,node)=q.top();
		
		q.pop();
		
		if(dist[node][metro_tickets_used]<=distance) continue;
		dist[node][metro_tickets_used]=distance;
		
		for(auto p:adj_bus[node]){
			q.push({distance+p.second,metro_tickets_used,p.first});
		}
		
		if(metro_tickets_used<t){
			for(auto p:adj_metro[node]){
				q.push({distance+p.second,metro_tickets_used+1,p.first});
			}
		}
		
	}
	return dist;
}
int main() {
  int n,b,m,t;
  char c; 
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>n>>b>>m>>t;
  }
  int V=n+1;
  vector<vector<pair<int , ll>>> adj1 (V),adj2 (V);
  for(auto p:{make_pair(b,&adj1),make_pair(m,&adj2)}){
  	int m1=p.first;
  	auto& adj=*p.second;
  	for(int i=0;i<m1;i++){
  		int u,v;
  		ll l;
  		cin>>u>>v>>l;
  		--u; --v;
  		adj[u].emplace_back(v,l);
  		adj[v].emplace_back(u,l);
	  }
  }
  auto dist=dijkstra(V,adj1,adj2,t,0);
  cout<<*min_element(dist.back().begin(),dist.back().end())<<endl;
  
   return 0;
  	} 
