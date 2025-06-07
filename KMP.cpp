vector<int> buildLPS(string& pat) {
    int m = pat.size(), len = 0;
    vector<int> lps(m, 0);
    for (int i = 1; i < m; ) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}

bool KMPsearch(string text, string pat) {
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;
    while (i < text.size()) {
        if (pat[j] == text[i]) { i++; j++; }
        if (j == pat.size()) return true;
        else if (i < text.size() && pat[j] != text[i]) {
            j = (j ? lps[j - 1] : 0);
        }
    }
    return false;
}
