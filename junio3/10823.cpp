#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  long long p, alcance = 0;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> p;
    sum += p;
    alcance += p * (sum - p);
  }

  cout << alcance << endl;

  return 0;
}