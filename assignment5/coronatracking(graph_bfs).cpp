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
Breath first search of undirect unweight graph
Sample Input 1 Sample Output 1
6 5 2 3
2 4
4 3
3 1
1 5
4 6
                 5 
*/ 

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    
void bfs(ll start,ll V,vector<vector<ll>> adj,ll d){
	vector<ll> distance (V+1,LONG_MAX);
	queue<ll> Q;
	distance[start]=0;
	Q.push(start);
	while(!Q.empty()){
		ll v=Q.front();
		Q.pop();
		for ( int u : adj [ v ]){
			if(distance[u]==LONG_MAX){
			distance[u]=distance[v]+1;
			Q.push(u);
		  }
		}
		
		
	}
	//return the number of people that have distance more than d
	ll sum=0;
	for(ll i:distance){
		if(i<=d)
		sum++;
	}
	cout<<sum<<endl;
}
int main() {
  ll n,m,s,d;
  char c; 
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>n>>m>>s>>d;
  }
  vector <ll> a(2*m);
  long len=0;

  while(len!=2*m){
    cin>>a[len];
    len++;
  }
  ll V=n;
  vector<vector<ll>> adj (V+1);
  for(ll i=0;i<2*m-1;i=i+2){
  	adj[a[i]].push_back(a[i+1]);
  	adj[a[i+1]].push_back(a[i]);
  }
  bfs(s,V,adj,d);

  
   return 0;
  	} 
