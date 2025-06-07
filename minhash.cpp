int simpleHash(const string& s, int mod) {
    int hash = 0;
    for (char c : s) {
        hash = (hash * 31 + c) % mod;
    }
    return hash;
}

int jaccardIndex(unordered_set<string>& a, unordered_set<string>& b) {
    int inter = 0;
    for (const auto& el : a)
        if (b.count(el)) inter++;

    int uni = a.size() + b.size() - inter;
    return (100 * inter) / uni; // Percentage similarity
}
