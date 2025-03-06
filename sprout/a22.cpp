#include "lib0022.h"
int a[5050], b[5050], ar, br;
void solve(int N, int order[]) {
  for (int i = 1; i <= N; i++)
    a[++ar] = i, push_train();
  for (int i = 0; i < N; i++) {
    while (ar && a[ar] != order[i]) {
      b[++br] = a[ar--], move_station_1_to_2();
    }
    if (ar == 0)
      no_solution();
    ar--, move_station_1_to_2(), pop_train();
    while (br)
      a[++ar] = b[br--], move_station_2_to_1();
  }
}
