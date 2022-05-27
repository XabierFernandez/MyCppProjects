#include <iostream>
#include <vector>

using namespace std;

long long MaxPairwiseProduct(const vector<long long>&numbers, int n) {
	int index1 = 0, index2 = 0, temp=0;
	// one for loop to get the first and the second maximum values of the vector
	for (int i=0; i < n; i++) {
		if (numbers[i] >= numbers[index1]) {
			index2 = index1;
			index1 = i;
			temp = i;
		}
		else if ((numbers[i] > numbers[index2]) && (numbers[i] < numbers[index1]) && (temp != i)) {
			index2= i; 
		}
	}

	return numbers[index1] * numbers[index2]; 
}



int main(int argc, char **argv) {
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers,n);
    cout << result << "\n";
    return 0;
}

