#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// Functions Prototypes
int w_sum(vector<double> a, vector<double> b);

int main() {
  int n;

  cin >> n;

  vector<double> inputs(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> inputs[i] >> weights[i];
  }

  double result = w_sum(inputs, weights);
  cout << "Result= " << result << endl;
  return 0;
}

int w_sum(vector<double> in, vector<double> w) {
  assert(in.size() == w.size());
  double output = 0;
  int n = in.size();
  for (size_t i = 0; i < n; i++) {
    output += in[i] * w[i];
    cout << "Output= " << output << endl;
  }

  return output;
}
