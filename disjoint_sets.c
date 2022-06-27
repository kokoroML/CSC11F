#include <stdio.h>

#define N 10000

int n, q;
int elements[N];

void unite(int x, int y) {
  int x_id = elements[x];
  int y_id = elements[y];

  for(int i = 0; i < n; ++i) {
    if(elements[i] == y_id) elements[i] = x_id;
  }
}

int same(int x, int y) {
  return elements[x] == elements[y];
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i) {
    elements[i] = i;
  }

  int com, x, y;
  for(int i = 0; i < q; ++i) {
    scanf("%d %d %d", &com, &x, &y);
    if(com)
      printf("%d\n", same(x, y));
    else
      unite(x, y);
      
  }

  return 0;
}
