#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> numeross(n);
  for (int i = 0; i < n; i++) {
    cin >> numeross[i];
  }

  int minimo = numeross[0];
  int max = numeross[0];
  int sum = 0;

  for (int i = 0; i < n; i++) {
    if (numeross[i] < minimo) {
      minimo = numeross[i];
    }
    if (numeross[i] > max) {
      max = numeross[i];
    }
    sum += numeross[i];
  }

  double average = static_cast<double>(sum) / n;

  cout << minimo << " " << max << " " << fixed << setprecision(2) << average << endl;

  return 0;
}