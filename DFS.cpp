void DFSUtil(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int u : adj[v]) {
        if (!visited[u])
            DFSUtil(u, adj, visited);
    }
}

void DFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFSUtil(i, adj, visited);
    }
}
