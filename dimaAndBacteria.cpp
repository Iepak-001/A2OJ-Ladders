#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

// DSU arrays (for up to n nodes)
vector<int> parent, sz;

int findDSU(int v) {
    return (parent[v] == v) ? v : parent[v] = findDSU(parent[v]);
}

void unionDSU(int a, int b) {
    a = findDSU(a);
    b = findDSU(b);
    if(a != b) {
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // Read the sizes of each bacteria type.
    vector<int> cnt(k);
    for (int i = 0; i < k; i++){
        cin >> cnt[i];
    }

    // For each node (bacteria), determine its type.
    // Types are assigned in the order given.
    vector<int> nodeType(n);  // nodeType[i] = type (0-indexed) of node i.
    // Also store the nodes for each type.
    vector<vector<int>> groups(k);
    int cur = 0;
    for (int t = 0; t < k; t++){
        for (int j = 0; j < cnt[t]; j++){
            nodeType[cur] = t;
            groups[t].push_back(cur);
            cur++;
        }
    }

    // Initialize DSU (for n nodes)
    parent.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }

    // Read all edges.
    // Also store edges for later processing.
    vector<tuple<int,int,int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;  // convert to 0-indexed
        edges.push_back({u, v, w});
        // For zero–cost edges, union the endpoints.
        if(w == 0)
            unionDSU(u, v);
    }

    // Verify that each bacteria type is connected by zero–cost edges.
    for (int t = 0; t < k; t++){
        int comp = findDSU(groups[t][0]);
        for (int node : groups[t]){
            if(findDSU(node) != comp){
                cout << "No\n";
                return 0;
            }
        }
    }
    
    cout << "Yes\n";
    
    // Build the contracted graph on bacteria types.
    // Let groupDist[i][j] be the minimal cost to go from type i to type j.
    vector<vector<int>> groupDist(k, vector<int>(k, INF));
    for (int i = 0; i < k; i++){
        groupDist[i][i] = 0;
    }
    
    // For every edge that connects two nodes of different types, update the cost.
    for (auto &e : edges) {
        int u, v, w;
        tie(u, v, w) = e;
        int gu = nodeType[u], gv = nodeType[v];
        if (gu == gv) continue; // within the same type, cost is 0 by connectivity
        groupDist[gu][gv] = min(groupDist[gu][gv], w);
        groupDist[gv][gu] = min(groupDist[gv][gu], w);
    }
    
    // Run Floyd–Warshall on the contracted graph.
    for (int mid = 0; mid < k; mid++){
        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++){
                if(groupDist[i][mid] < INF && groupDist[mid][j] < INF)
                    groupDist[i][j] = min(groupDist[i][j], groupDist[i][mid] + groupDist[mid][j]);
            }
        }
    }
    
    // Output the k x k distance matrix.
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            cout << (groupDist[i][j] == INF ? -1 : groupDist[i][j]) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
