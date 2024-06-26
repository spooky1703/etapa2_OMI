#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long p[n];
  long long alcance = 0;

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      alcance += p[i] * p[j];
    }
  }

  cout << alcance << endl;

  return 0;
}