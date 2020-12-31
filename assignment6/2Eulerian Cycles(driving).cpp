// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <deque> 
#include <set>
using namespace std;
/*
Eulerian Cycles
如果图G中的一个路径包括每个边恰好一次，则该路径称为欧拉路径(Euler path)。
如果一个回路是欧拉路径，则称为欧拉回路(Euler circuit)。
Can you determine whether it is possible to find a route starting from 1 and ending in n that drives through every street
exactly once?
Sample Input 1 Sample Output 1
3 3
1 2
2 1
1 3
                POSSIBLE
*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
const ll maxn=1000000;
vector <unsigned long> indegree(maxn);
vector<vector<unsigned long>> adj (maxn);
deque<unsigned long> cycle;

void find_cycle(ll u){
	while (adj[u].size()){
		ll v=adj[u].back();
		adj[u].pop_back();
		find_cycle(v);
	}
	cycle.push_front(u);
//deque -push_front:从前面插入，即和堆一样，先入的往后 
}


int main() {
  unsigned long  n;
  unsigned long m;
  cin>>n>>m;
  unsigned long len=0,a,b; 
  unsigned long V=n;
  
  
  while(len!=m){
    cin>>a>>b;
    adj[a].push_back(b);
    indegree[b]++;
	len++;
}

  if(indegree[V]==adj[V].size()+1) indegree[V]--;
  if(indegree[1]+1==adj[1].size())  indegree[1]++;
 
  for(unsigned long i=1; i<=V;i++){
  	if(indegree[i]!=adj[i].size()){
		  cout<<"IMPOSSIBLE"<<endl;
  		return 0;
	  }
  }
  find_cycle(1);
  

  
  if(cycle.size()==m+1&&cycle[cycle.size()-1]==n){
  	cout<<"POSSIBLE"<<endl;
  	return 0;
  } 


  	cout<<"IMPOSSIBLE"<<endl;
  

  
   return 0;
  	} 
