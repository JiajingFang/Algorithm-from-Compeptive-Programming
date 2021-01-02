#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
#define INF numeric_limits<int>::max()

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
	int n,m,len=0,len1=0;
	cin>>n>>m; 
	char a;
   vector <long> edge;
   long num=0;
    while(len!=n){
 		while(len1!=m){
    		cin>>a;
    		if(a=='.'){
    			num++;
    			edge.push_back(len);
    			edge.push_back(len1);
			}
    		len1++;
		}
    	len1=0;
    	len++;
  	}
  
    adj.resize(2*num+3);
    capacity.assign(2*num+3, vector<int>(2*num+3, 0));
    for(unsigned long i=0;i<edge.size();i=i+2){
    	int b=edge[i];
    	int c=edge[i+1];
    	for(unsigned long j=i;j<edge.size();j=j+2){
    		if(b==edge[j]){
    			if(c+1==edge[j+1]||c-1==edge[j+1]){
    				int u=i/2;
    				int v=num+j/2;
    				adj[u].push_back(v);
    				adj[v].push_back(u);
    				capacity[u][v] += 1;
    				
    				u=j/2;
    				v=num+i/2;
					adj[u].push_back(v);
    				adj[v].push_back(u);
    				capacity[u][v] += 1;
    			
				}
    			
			}
			if(c==edge[j+1]){
    			if(b+1==edge[j]||b-1==edge[j]){
    				
    				int u=i/2;
    				int v=num+j/2;
    				adj[u].push_back(v);
    				adj[v].push_back(u);
    				capacity[u][v] += 1;
    				
    				u=j/2;
    				v=num+i/2;
					adj[u].push_back(v);
    				adj[v].push_back(u);
    				capacity[u][v] += 1;
    			
				}
    			
			}
		}
	}
	int start=2*num+1;
	int end=2*num+2;
    for (long i = 0; i < num; i++) {
        adj[start].push_back(i);
        adj[i].push_back(start);
        capacity[start][i] += 1;
    }
    for(long i=num;i<2*num;i++){
    	adj[end].push_back(i);
        adj[i].push_back(end);
        capacity[i][end] += 1;
	}
    int out = maxflow(start, end);
    if(out==num){
    	cout<<"YES"<<endl;
    	return 0;
	}
	cout<<"NO"<<endl;
    return 0;
}

