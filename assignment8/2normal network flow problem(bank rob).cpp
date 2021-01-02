#include<bits/stdc++.h>

using namespace std;
#define INF numeric_limits<int>::max()
/*
Input
The first line of the input contains an integer t. t test cases follow.
Each test case begins with a line containing three integers l, the amount of available policemen, n, the amount of
intersections and m, the amount of roads. m lines follow, each consisting of three integers i,j,k, specifying a road
from intersection i to j with k being the amount of policemen it takes to construct a roadblock on it. All roads are
useable in both directions. Dieter always starts at intersection 1 and wants to get to the border (intersection n). Every
test case ends with a blank line.
Output
For each test case, print a line containing ¡°Case #i: t¡± with i being the number of the test case, starting at 1, and t being
¡°yes¡± if the minimal amount of policemen it takes to construct at least one road block on every path from intersection
1 to n is smaller or equal to l, ¡°no¡± otherwise

Sample Input 1 Sample Output 1
3
10 2 3
2 2 3
1 2 4
1 1 3

2 3 3
1 3 5
1 2 5
3 3 5

9 2 1
2 1 10
				Case #1: yes
				Case #2: no
				Case #3: no
*/ 
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
    int police;
    int V;
    int E;
    string mystring;
    for(int i=0;i<n;i++){
        cin>>police>>V>>E;
        capacity.clear();
        adj.clear();
        V=V+1;
        adj.resize(V);
        capacity.assign(V, vector<int>(V, 0));
        int u, v, c;
        for (int j = 0; j < E; j++) {
            cin >> u >> v >> c;
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v] += c;
            capacity[v][u] += c;
        }
        int out = maxflow(1, V-1);
        if(out>police){
            cout<<"Case #"<<i+1<<": no"<<endl;
        }
        else{
            cout<<"Case #"<<i+1<<": yes"<<endl;
        }
        getline(cin,mystring);
    }

}
