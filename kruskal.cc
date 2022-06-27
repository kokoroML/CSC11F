#include <iostream>
#include <vector>
#include <algorithm>

int total_cost;
int nv, ne;

struct Edge {
  int s, t, w;
};

bool operator < (const Edge& v1, const Edge& v2) { 
  return v1.w < v2.w;
}

std::vector<int> A; 
std::vector<Edge> E;

int main() {
  std::cin >> nv >> ne;

  A.resize(nv);
  for(int i = 0; i < nv; ++i) {
    A[i] = i;
  }

  for(int i = 0; i < ne; ++i) {
    Edge e;
    std::cin >> e.s >> e.t >> e.w;
    E.push_back(e);
  }

  std::sort(E.begin(), E.end());

  for(auto it = E.begin(); it != E.end(); ++it) {
    if(A[it->s] != A[it->t]) {
      total_cost += it->w;
      int k = A[it->t];
      for(int j = 0; j < A.size(); ++j) {
        if(A[j] == k)
          A[j] = A[it->s];
      }
    }
  }

  std::cout << total_cost << "\n";

  return 0;
}
