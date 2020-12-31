// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>
using namespace std;
/*
Output a single integer: The maximum total quality.
Sample Input 1 Sample Output 1
4 6
1 2 15
1 3 3
2 3 1
2 4 -1
3 4 -2
1 1 5
                23
*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
ll init=100000;
vector<bool> visited(init,false);
vector<vector<pair<ll , ll>>> adj (init);
priority_queue<tuple<ll,ll,ll>> PQ;
vector<ll> mst;
vector<ll> all;

void visit(ll v){
	visited[v]=true;
	for(auto p:adj[v]){
		ll u=p.first;
		ll w=p.second;
		if(!visited[u]){
			PQ.push(make_tuple(w,v,u));
			
		} 
	}
}

int main() {
  ll n,m;
  char c; 
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>n>>m;
  }
  ll V=n+1;
  visited.resize(V);
  adj.resize(V);
  ll len=0;
  ll ta,tb,tc;
  while(len!=m){
    cin>>ta>>tb>>tc;
    adj[ta].push_back({tb,tc});
    adj[tb].push_back({ta,tc});	
    all.push_back(tc);
    
    len++;
  }
  visit(1);
  ll weight,to,from;
  ll sum=0;
  while(!PQ.empty()){
  	auto front=PQ.top();
  	PQ.pop();
  	weight=std::get<0>(front);
  	to=std::get<2>(front);
  	from=std::get<1>(front);
  	if(!visited[to]){
 // 		cout<<weight<<" "<<from<<to<<endl;
  		mst.push_back(weight);
  		sum=sum+weight;
  		visit(to);
	  }
  }
  sort(all.begin(),all.end());
  sort(mst.begin(),mst.end());
  vector<ll> diffset;
  set_difference(all.begin(),all.end(),mst.begin(),mst.end(),inserter(diffset, diffset.begin()));
  for(auto i:diffset){
  	if(sum+i>sum) sum=sum+i;
//  	cout<<i<<endl;
  }
  
  
  
  
  cout<<sum<<endl;
   return 0;
  	} 
