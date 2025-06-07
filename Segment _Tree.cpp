class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int i, int l, int r) {
        if (l == r) tree[i] = arr[l];
        else {
            int m = (l + r) / 2;
            build(arr, 2*i, l, m);
            build(arr, 2*i+1, m+1, r);
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }

    int query(int i, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[i];
        int m = (l + r) / 2;
        return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    int rangeSum(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};
