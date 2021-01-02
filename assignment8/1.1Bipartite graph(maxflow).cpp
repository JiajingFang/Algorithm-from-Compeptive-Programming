// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


typedef long long ll;
#define INF numeric_limits<int>::max()
#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
vector<vector<int>> capacity;
vector<vector<int>> adj;
vector<int> parent;

void bfs(int s) {
    parent.assign(adj.size(), -1);
    parent[s] = -2; // s is visited

    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : adj[u]) // go u -> v
            if (parent[v] == -1 and capacity[u][v] > 0) {
                Q.push(v);
                parent[v] = u;
            }
    }
}

int maxflow(int s, int t) {
    int totalflow = 0;
    int u;
    while (true) {
        // build bfs tree
        bfs(s);
        if (parent[t] == -1) // t unreachable
            break;
        // find bottleneck capacity
        int bottleneck = INF;
        u = t;
        while (u != s) {
            int v = parent[u];
            bottleneck = min(bottleneck, capacity[v][u]);
            u = v;
        }
        // update capacities along path
        u = t;
        while (u != s) {
            int v = parent[u];
            capacity[v][u] -= bottleneck;
            capacity[u][v] += bottleneck;
            u = v;
        }
        totalflow += bottleneck;
    }
    return totalflow;
}

int main() {
    int n;
	cin>>n;
	int V=2*n;
	adj.resize(V+3);
    capacity.assign(V+3, vector<int>(V+3, 0));
    int tmp;
    for(int i=1;i<=n;i++){
    	for(int j=n+1;j<=V;j++){
    		cin>>tmp;
    		if(tmp==1){
    			adj[i].push_back(j);
    			adj[j].push_back(i);
            	capacity[i][j] = 1;
            	//capacity[j][i] = 1;
			}
		}
	}
	
    for(int i=1;i<=n;i++){
    	adj[0].push_back(i);
    	adj[i].push_back(V);
        capacity[0][i] = 1;
        //capacity[i][V] = 1;
	}
	for(int i=n+1;i<=V;i++){
    	adj[i].push_back(V+1);
    	adj[V+1].push_back(i);
        capacity[i][V+1] = 1;
        //capacity[V+1][i] = 1;
	}
	
	int out = maxflow(0, V+1);
	cout<<out;
	return out;

}
