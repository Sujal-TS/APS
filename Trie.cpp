struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;

    TrieNode() {
        fill(begin(children), end(children), nullptr);
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
};
