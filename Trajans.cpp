void tarjanDFS(int u, int& time, vector<vector<int>>& adj, vector<int>& disc,
               vector<int>& low, stack<int>& st, vector<bool>& inStack) {
    disc[u] = low[u] = ++time;
    st.push(u); inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v, time, adj, disc, low, st, inStack);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        cout << "SCC: ";
        while (true) {
            int v = st.top(); st.pop();
            inStack[v] = false;
            cout << v << " ";
            if (u == v) break;
        }
        cout << endl;
    }
}

void tarjansSCC(int V, vector<vector<int>>& adj) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> st;
    int time = 0;

    for (int i = 0; i < V; i++)
        if (disc[i] == -1)
            tarjanDFS(i, time, adj, disc, low, st, inStack);
}
