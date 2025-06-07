void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adj) {
    visited[v] = true;

    for (int u : adj[v])
        if (!visited[u])
            topologicalSortUtil(u, visited, st, adj);

    st.push(v);
}

void topologicalSort(int V, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, st, adj);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
