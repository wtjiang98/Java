#include <bits/stdc++.h>

const int MaxN = 2005;
const int MaxE = 350005;
const int MaxH = MaxN;

struct heap_t {
  int h[MaxH], d[MaxH], pos[MaxH];
  int n;

  inline void init(int maxId) {
    n = 0;
    for (int i = 0; i <= maxId; i++) pos[i] = -1;
  }

  inline int poll() {
    return h[1];
  }

  inline int peek() {
    int res = h[1];
    pos[h[1]] = -1;
    h[1] = h[n--];
    if (n) {
      pos[h[1]] = 1;
      sink(1);
    }
    return res;
  }

  inline void sink(int k) {
    while (k <= n) {
      int idx = k, lhs = k << 1, rhs = k << 1 | 1;
      if (lhs <= n && d[h[lhs]] < d[h[idx]]) idx = lhs;
      if (rhs <= n && d[h[rhs]] < d[h[idx]]) idx = rhs;
      if (idx == k) break;
      else {
        std::swap(h[idx], h[k]);
        pos[h[idx]] = idx;
        pos[h[k]] = k;
        k = idx;
      }
    }
  }

  inline void swin(int k) {
    while (k > 1) {
      int p = k >> 1;
      if (d[h[k]] < d[h[p]]) {
        std::swap(h[k], h[p]);
        pos[h[k]] = k;
        pos[h[p]] = p;
        k = p;
      } else {
        break;
      }
    }
  }

  inline void add(int k, int v) {
    if (pos[k] == -1) {
      h[++n] = k;
      pos[k] = n;
    }
    d[k] = v;
    sink(pos[k]);
    swin(pos[k]);
  }
};

struct edge_t {
  int to, weight;
  edge_t *prev, *next;
} edges[MaxE], *cure, *head[MaxN];
edge_t* ep[MaxN][MaxN], *stack[MaxE];
int top;

inline void add_edge(int u, int v, int weight) {
  if (ep[u][v]) {
    ep[u][v]->weight += weight;
    if (ep[u][v]->weight == 0) {
      ep[u][v]->prev->next = ep[u][v]->next;
      ep[u][v]->next->prev = ep[u][v]->prev;
      stack[top++] = ep[u][v];
      ep[u][v] = NULL;
    }
  } else if (weight != 0) {
    edge_t* cur = top ? stack[--top] : cure++;
    ep[u][v] = cur;
    cur->to = v;
    cur->weight = weight;
    cur->prev = head[u];
    cur->next = head[u]->next;
    cur->prev->next = cur->next->prev = cur;
  }
}

heap_t heap;
bool visited[MaxN], closed[MaxN];

int prim(int n, int maxId, int &s, int &t) {
  int res = 0, u, v;
  s = t = 0;
  heap.init(n);
  for (int i = 1; i <= n; i++) {
    if (!closed[i]) heap.add(i, 0);
    visited[i] = false;
  }
  for (int i = 1; i <= maxId; i++) {
    u = heap.peek();
    visited[u] = true;
    s = t;
    t = u;
    res = -heap.d[t];
    for (edge_t* iter = head[u]->next; iter != head[u]; iter = iter->next) {
      v = iter->to;
      if (!closed[v] && !visited[v]) {
        heap.add(v, -iter->weight + heap.d[v]);
      }
    }
  }
  return res;
}

int main() {
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
  int n, m, u, v, w;
  while (scanf("%d%d", &n, &m)!=EOF) {
    cure = edges;
    top = 0;
    for (int i = 1; i <= n; i++) {
      cure->next = cure->prev = cure;
      head[i] = cure++;
      for (int j = 1; j <= n; j++) ep[i][j] = NULL;
    }
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &w);
      if(u==v)continue;
      add_edge(u, v, w);
      add_edge(v, u, w);
    }

    int res = std::numeric_limits<int>::max(), s, t;
    std::fill(closed, closed + n + 1, false);
    for (int i = 0; i < n - 1; i++) {
      res = std::min(res, prim(n, n - i, s, t));
      closed[t] = true;
      for (int j = 1; j <= n; j++) {
        if (!closed[j] && j != s) {
          if (ep[j][t]) add_edge(j, s, ep[j][t]->weight);
          if (ep[t][j]) add_edge(s, j, ep[t][j]->weight);
        }
      }
      for (int j =  1; j <= n; j++) {
        if (ep[j][t]) add_edge(j, t, -ep[j][t]->weight);
        if (ep[t][j]) add_edge(t, j, -ep[t][j]->weight);
      }
    }
    printf("%d\n", res);
  }

  return 0;
}
