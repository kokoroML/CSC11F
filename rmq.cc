#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();
int n, q;
vector<int> D, lazy;

void init(int n_) {
  int t = 1;
  while(n_ > t) {
    t *= 2;
  }
  n = t;
  D.resize(2 * n - 1);
  lazy.resize(2 * n - 1);
  for(int i = 0; i < 2 * n - 1; ++i)
    D[i] = lazy[i] = INF;
}

void lazy_eval(int k) {
  if(lazy[k] == INF) return;
  if(k < n - 1) {
    lazy[k * 2 + 1] = lazy[k];
    lazy[k * 2 + 2] = lazy[k];
  }
  D[k] = lazy[k];
  lazy[k] = INF;
}

int query(int a, int b, int k, int l, int r) {
  if(r <= a || b <= l)
    return INF;

  lazy_eval(k);

  if(a <= l && r <= b)
    return D[k];

  int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
  int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
  return min(vl, vr);
}

void update(int a, int b, int k, int l, int r, int x) {
  lazy_eval(k);
  if(r <= a || b <= l)
    return;
  if(a <= l && r <= b)
    lazy[k] = x;
  else {
    update(a, b, k * 2 + 1, l, (l + r) / 2, x);
    update(a, b, k * 2 + 2, (l + r) / 2, r, x);
    D[k] = min(D[k*2+1], D[k*2+2]);
  }
  lazy_eval(k);
}

void update(int s, int t, int x) {
  update(s, t+1, 0, 0, n, x);
}

int find(int a, int b) {
  return query(a, b+1, 0, 0, n);
}

int main() {
  cin >> n >> q;
  
  init(n);

  int com, x, y, z;
  for(int i = 0; i < q; ++i) {
    cin >> com;
    if(com == 0) {
      cin >> x >> y >> z;
      update(x, y, z);
    }
    else {
      cin >> x >> y;
      cout << find(x, y) << "\n";
    }
  }
    
  return 0;
}
