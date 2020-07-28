// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
/*
Input:A graph that is undirected, weighted and sparse with positive edge weights 
Output: the length of the shortest path from 1 to n

use Dijkstra algorithm

Sample Input 1 Sample Output 1
5 6 1 0
1 2 1
1 3 3
2 3 1
2 4 2
3 5 4
4 5 5
2 5 1
				6
*/ 

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    
void dijkstra(ll V,vector<vector<pair<ll , ll>>> adj){
	vector<ll> dist(V,LONG_MAX);
	dist[1]=0;
	//最小值（第一个值）先出的heap（mini heap）; 
	//if priority_queue<pair<int, int> > pq; then it's a max heap 
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater <pair<ll,ll>>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		auto front=pq.top();
		pq.pop();
		ll d=front.first, v=front.second;
		if(d>dist[v]) continue;
		for(auto p:adj[v]){
			ll u=p.first;
			ll w=p.second;
			if(dist[v]+w<dist[u]){
				dist[u]=dist[v]+w;
				pq.push({dist[u],u});
			}
		}
	}
	cout<<dist[V-1];
}
int main() {
  ll n,b,m,t;
  char c; 
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>n>>b>>m>>t;
  }
  ll V=n+1;
  vector<vector<pair<ll , ll>>> adj (V);
  ll len=0;
  ll ta,tb,tc;
  while(len!=b+m){
    cin>>ta>>tb>>tc;
    if(len<b){
    adj[ta].push_back({tb,tc});
    adj[tb].push_back({ta,tc});	
	}
    len++;
  }
  dijkstra(V,adj);

  
   return 0;
  	} 
