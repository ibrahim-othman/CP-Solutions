#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int b[m];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int total_score = 0;
  for (int i = 0; i < m; i++) {
    total_score += a[b[i] - 1];
  }

  cout << total_score << endl;

  return 0;
}