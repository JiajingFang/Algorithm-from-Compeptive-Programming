// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm> 
#include <map>
using namespace std;
/*
Print q lines. In the i-th line, print the name of the lowest common ancestor and the distance between two
The third line contains n ? 1 names s 2 ,s 3 ,...,s n , meaning that s i is the mother of l i 
Sample Input 1 									Sample Output 1
6 4
Gertrude Annegret Elisabeth Lea Jule Dieter
Gertrude Gertrude Elisabeth Annegret Annegret
Dieter Jule
Dieter Annegret
Dieter Lea
Jule Gertrude
													Annegret 2
													Annegret 1
													Gertrude 4
													Gertrude 2

*/ 

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
const ll maxn=200000;
vector<vector<ll>> adj (maxn);
map<ll, string> names;
map<string, ll> indices;
vector<vector<ll>> checklca (maxn);
vector<pair<ll,ll>> query;
ll V;
map<pair<ll,ll>,ll> reslca;

vector<bool> visited(maxn,false);
vector<ll> acum(maxn);
vector<ll> ancestor(maxn);

class UnionFind{
	private:
		vector<ll> parent;
	public:
		UnionFind(ll N){
			parent.resize(N);
			for(ll i=0;i<N;i++) parent[i]=i;
		}
	ll findSet(ll i){
		if(parent[i]==i) return i;
		else return findSet(parent[i]);
	}
	bool isSameSet(ll i,ll j){
		return findSet(i)==findSet(j);
	}
	void unionSet(ll i,ll j){
		i=findSet(i), j=findSet(j);
		if(!isSameSet(i,j)) parent[j]=i;
	}
	
};


auto UF=UnionFind(maxn);




void dfs(ll u){
	for(auto v:adj[u]){
		dfs(v);
		UF.unionSet(u,v);
		ancestor[UF.findSet(u)]=u;
	}
	visited[u]=true;
    for(auto v:checklca[u]){
    	if(visited[v]){
    		ll r=ancestor[UF.findSet(v)];
    		ll ma=max(v,u);
    		ll mi=min(v,u);
    		reslca.insert(std::pair<pair<ll,ll>,ll>(std::pair<ll,ll>(mi,ma),r));
    		/**for(std::size_t i=0;i<query.size();i++){
    			if(v==query[i].first){
    				if(u==query[i].second) reslca[i]=r;
				}
				if(u==query[i].first){
    				if(v==query[i].second) reslca[i]=r;
				}
			}**/

		}
	}
}

void distance(){
	queue<pair<ll,ll>> QD;
	QD.push({1,0});
	
	while(!QD.empty()){
		auto fr=QD.front();
		QD.pop();
		acum[fr.first]=fr.second;
		for(auto n:adj[fr.first]) QD.push({n,fr.second+1});
	}
}

int main() {
  ll  n;
  ll m;
  cin>>n>>m;
  ll  len=0;
  string sa,sb; 
  V=n+1;
  
  
  
  while(len!=n){
    cin>>sa;
    len++;
    names.insert(std::pair<ll,string>(len,sa));
  	indices.insert(std::pair<string,ll>(sa,len));
	
}
  len=0;
  checklca.resize(V);
  adj.resize(V);
  acum.resize(V);
  while(len!=n-1){
  	cin>>sa;
    len++;
  	adj[indices[sa]].push_back(len+1);	
  }
  
  len=0;
  while(len!=m){
  	cin>>sa>>sb;
  	
  	if(sa==sb)
  	checklca[indices[sb]].push_back(indices[sa]);
  	else{
	  checklca[indices[sb]].push_back(indices[sa]);
  	  checklca[indices[sa]].push_back(indices[sb]);
	  }
	if(indices[sa]<indices[sb]){
	  query.push_back(make_pair(indices[sa],indices[sb]));	
	}   
	else{
		query.push_back(make_pair(indices[sb],indices[sa]));
	} 
	  
  	len++;
  }

  for(ll i=1;i<V;i++) ancestor[i]=i;
  dfs(1);
  distance();
  ll dis;
  
  


  for(ll i=0;i<m;i++){
  	ll reslcanum;
//  	if(reslca[make_pair(query[i].first,query[i].second)]!=0){
  		reslcanum=reslca[make_pair(query[i].first,query[i].second)];
//	  }
//	else{
//		reslcanum=reslca[make_pair(query[i].second,query[i].first)];
//	}
  	dis=(acum[query[i].first]+acum[query[i].second])-2*acum[reslcanum];
	cout<<names[reslcanum]<<" "<<dis<<endl;	
  } 
  
//  for(ll i=1;i<7;i++) cout<<UF.parent[i]<<endl;
   return 0;
  	} 
