int tsp(int mask, int pos, vector<vector<int>>& dist, vector<vector<int>>& dp, int n) {
    if (mask == (1 << n) - 1)
        return dist[pos][0]; // Return to start

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city)))
            ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n));
    }

    return dp[mask][pos] = ans;
}

// Usage:
// vector<vector<int>> dist = {...};
// int n = dist.size();
// vector<vector<int>> dp(1 << n, vector<int>(n, -1));
// int result = tsp(1, 0, dist, dp, n);
