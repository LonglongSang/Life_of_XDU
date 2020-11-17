#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 500005;

struct Tuple {
    int p, t, ax;
};

int n, m, q;
vector<int> a[MAXN];

namespace seg_tree {
    struct node {
        int p, t, l, r;
    } nodes[MAXN * 4], tags[MAXN * 4];

    void pushdown(int o, int l, int r) {
        node &n = nodes[o], &n_l = nodes[o * 2], &n_r = nodes[o * 2 + 1],
            &t = tags[o], &t_l = tags[o * 2], &t_r = tags[o * 2 + 1];
        int mid = (l + r) / 2;
        if (t.p != 0) {
            n_l = {t.p, t.t, t.l, t.l + (mid - l)};
            n_r = {t.p, t.t, t.l + (mid - l) + 1, t.r};
            t_l = {t.p, t.t, t.l, t.l + (mid - l)};
            t_r = {t.p, t.t, t.l + (mid - l) + 1, t.r};
            t = {0, 0, 0, 0};
        }
    }

    void modify(int o, int l, int r, int ll, int rr, int p, int t, int al, int ar) {
        //modify(1, 1, n, x, x + a[p].size() - 2, p, i, 1, a[p].size() - 1);
        if (l >= ll && r <= rr) {
            nodes[o] = tags[o] = node {p, t, al + (l - ll), ar - (rr - r)};
            return;
        }
        pushdown(o, l, r);
        int mid = (l + r) / 2;
        if (ll <= mid) modify(o * 2, l, mid, ll, rr, p, t, al, ar);
        if (rr > mid) modify(o * 2 + 1, mid + 1, r, ll, rr, p, t, al, ar);
    }

    Tuple query(int o, int l, int r, int x) {
        if (l == r) return Tuple {nodes[o].p, nodes[o].t, nodes[o].l};
        pushdown(o, l, r);
        int mid = (l + r) / 2;
        if (x <= mid) return query(o * 2, l, mid, x);
        if (x > mid) return query(o * 2 + 1, mid + 1, r, x);
    }
}

namespace per_seg_tree {
    struct node {
        int tag, lch, rch;
    } nodes[MAXN * 100];
    int rt_now[MAXN], tot;
    map<PII, int> rt_all;

    void modify(int &o, int l, int r, int ll, int rr) {
        int t = ++tot; nodes[t] = nodes[o]; o = t;
        if (l >= ll && r <= rr) {
            nodes[o].tag++;
            return;
        }
        int mid = (l + r) / 2;
        if (ll <= mid) modify(nodes[o].lch, l, mid, ll, rr);
        if (rr > mid) modify(nodes[o].rch, mid + 1, r, ll, rr);
    }

    int query(int o, int l, int r, int x) {
        if (l == r) return nodes[o].tag;
        int mid = (l + r) / 2;
        if (x <= mid) return query(nodes[o].lch, l, mid, x) + nodes[o].tag;
        if (x > mid) return query(nodes[o].rch, mid + 1, r, x) + nodes[o].tag;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int l, t;
        cin >> l;
        a[i].push_back(0);
        for (int j = 1; j <= l; j++) {
            cin >> t;
            a[i].push_back(t);
        }
    }

    for (int i = 1; i <= m; i++) {
        per_seg_tree::rt_all[PII(i, 0)] = 0;
    }
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            seg_tree::modify(1, 1, n, x, x + a[p].size() - 2, p, i, 1, a[p].size() - 1);
        } else if (op == 2) {
            int x;
            cin >> x;
            Tuple tup = seg_tree::query(1, 1, n, x);
            int p = tup.p, t = tup.t, ax = tup.ax;
            if (p == 0) {
                cout << 0 << endl; continue;
            }
            int rt = (--per_seg_tree::rt_all.upper_bound(PII(p, t)))->second;
            int diff = per_seg_tree::query(rt, 1, a[p].size() - 1, ax);
            cout << (a[p][ax] + diff) % 256 << endl;
        } else if (op == 3) {
            int p, l, r;
            cin >> p >> l >> r;
            per_seg_tree::modify(per_seg_tree::rt_now[p], 1, a[p].size() - 1, l, r);
            per_seg_tree::rt_all[PII(p, i)] = per_seg_tree::rt_now[p];
        }
    }

    return 0;
}