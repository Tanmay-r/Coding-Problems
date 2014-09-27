#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 1e5;
int h[MAX_N], last[MAX_N * 10], C[MAX_N * 10], N, T[MAX_N * 4];
int query(int n, int L, int R, int i, int j){
  if(R < i || j < L) return -1;
  if(i <= L && R <= j) return T[n];
  return max(query(n * 2, L, (L + R) / 2, i, j), query(n * 2 + 1, (L + R) / 2 + 1, R, i, j));
}
void build(int n, int L, int R){
  if(L == R) T[n] = h[L];
  else {
    build(n * 2, L, (L + R) / 2);
    build(n * 2 + 1, (L + R) / 2 + 1, R);
    T[n] = max(T[n * 2], T[n * 2 + 1]);
  }
}
int rmq(int i, int j){
  return query(1, 0, N - 1, i, j);
}
int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", h + i);
  build(1, 0, N - 1);
  memset(last, -1, sizeof last);
  long long res = 0;
  for(int i = 0; i < N; i++){
    if(last[h[i]] == -1 || rmq(last[h[i]], i) > h[i])
      C[h[i]] = 0;
    res += C[h[i]]++;
    last[h[i]] = i;
  }
  printf("%lld\n", res * 2);
  return 0;
}