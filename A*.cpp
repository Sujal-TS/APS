struct Node {
    int id, f, g;
    bool operator<(const Node& other) const {
        return f > other.f;
    }
};

vector<int> AStar(vector<vector<pair<int, int>>>& graph, int start, int goal, vector<int>& heuristic) {
    priority_queue<Node> pq;
    pq.push({start, heuristic[start], 0});
    unordered_map<int, int> came_from;
    unordered_map<int, int> g_score;
    g_score[start] = 0;

    while (!pq.empty()) {
        auto [curr, f, g] = pq.top(); pq.pop();
        if (curr == goal) break;

        for (auto [next, cost] : graph[curr]) {
            int new_g = g + cost;
            if (!g_score.count(next) || new_g < g_score[next]) {
                g_score[next] = new_g;
                pq.push({next, new_g + heuristic[next], new_g});
                came_from[next] = curr;
            }
        }
    }
    return {}; // Reconstruct path from came_from if needed
}
