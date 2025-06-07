class LazySegmentTree {
    vector<int> tree, lazy;
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

    void propagate(int i, int l, int r) {
        if (lazy[i]) {
            tree[i] += (r - l + 1) * lazy[i];
            if (l != r) {
                lazy[2*i] += lazy[i];
                lazy[2*i+1] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void update(int i, int l, int r, int ql, int qr, int val) {
        propagate(i, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            lazy[i] += val;
            propagate(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(2*i, l, m, ql, qr, val);
        update(2*i+1, m+1, r, ql, qr, val);
        tree[i] = tree[2*i] + tree[2*i+1];
    }

public:
    LazySegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
        build(arr, 1, 0, n-1);
    }

    void rangeUpdate(int l, int r, int val) {
        update(1, 0, n-1, l, r, val);
    }
};
