#include <iostream>
#include <bits/stdc++.h>

//retorna o soma maxima possivel de um subarray

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int array[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	int best = 0;
	int sum = 0;

	for (int k = 0; k < n; k++) {
		sum = max(array[k], sum+array[k]);
		best = max(best, sum);
	}

	cout << best << "\n";

	return 0;
}
