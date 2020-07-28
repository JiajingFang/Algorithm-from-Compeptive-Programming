// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
/*
Toposort(topological ordering) for a directed,unweighted graph to determine if it is a DAG(Directed Acyclic Graph有向无环图)
TopoSort algorithm 

how to renew the map of id and names:
map<string,int> id;
map<int,string> names;
int next_id=0;
int get_id(const string& name){
	if(!id.count(name)){
		id[name]=next_id;
		names[next_id]=name;
		next_id++;
	}
	return id[name];
}

'<'and'>' can be saved as char  op;
*/ 

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

void TopSort(vector<vector<ll>> &adj, ll V,vector<ll> &inDegree, map<ll, string> names){
	ll num=0;
    queue<ll> q;
    vector<ll> res;
    for(ll i=0;i<V;i++){
    	if(inDegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		ll u=q.front();
		res.push_back(u);
		q.pop();
		for(std::size_t i=0;i<adj[u].size();i++){
			ll v=adj[u][i];
			inDegree[v]--;
			if(inDegree[v]==0) q.push(v);
		}
		adj[u].clear();
		num++;
	}
	if(num==V){
		cout<<"possible"<<endl;
		for(auto i:res){
			cout<<names[i]<<" ";
		}
	}
	else{
		cout<<"impossible"<<endl;
	}
}
 

int main() {
  ll n;
  char c; 
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>n;
  }
  vector <string> s1;
  string s;
  ll len=0;

  while(len!=n){
  	getline(cin,s);
    s1.push_back(s);
    len++;
  }
  map<ll, string> names;
  map<string, ll> indices;
  
  vector<ll> tmp;
  string sa,sb;
  ll pos=0,ind=0;
  for(string ss:s1){
  	std::size_t  ss_size=ss.size();
  	if(ss.find("<")<ss_size){
  		pos=ss.find("<");
  		sa=ss.substr(0,pos-1);
  		sb=ss.substr(pos+2);
  		if(indices.count(sa)<=0||indices.size()==0){
  			
  			names.insert(std::pair<ll,string>(ind,sa));
  			indices.insert(std::pair<string,ll>(sa,ind));
			ind++;
		  }
		if(indices.count(sb)<=0){
			
  			names.insert(std::pair<ll,string>(ind,sb));
  			indices.insert(std::pair<string,ll>(sb,ind));
  			ind++;
		  }
		  tmp.push_back(indices[sb]);
		  tmp.push_back(indices[sa]);
	  }
	else{
		pos=ss.find(">");
  		sa=ss.substr(0,pos-1);
  		sb=ss.substr(pos+2);
  		if(indices.count(sa)<=0||indices.size()==0){
  			
  			names.insert(std::pair<ll,string>(ind,sa));
  			indices.insert(std::pair<string,ll>(sa,ind));
  			ind++;
		  }
		if(indices.count(sb)<=0){
			
  			names.insert(std::pair<ll,string>(ind,sb));
  			indices.insert(std::pair<string,ll>(sb,ind));
  			ind++;
		  }
		  tmp.push_back(indices[sa]);
		  tmp.push_back(indices[sb]);
		  
	}
  }
  ll V=indices.size();
  vector<vector<ll>> adj(V);
  for(std::size_t  i=0;i<tmp.size();i=i+2){
  	adj[tmp[i]].push_back(tmp[i+1]);
  }
  // set the indegree of each V in graph
  vector<ll> inDegree(V);
  for(auto x:adj){
  	for(auto y:x){
  		inDegree[y]++;
	  }
  }
  TopSort(adj,V,inDegree,names);

  
   return 0;
  	} 
