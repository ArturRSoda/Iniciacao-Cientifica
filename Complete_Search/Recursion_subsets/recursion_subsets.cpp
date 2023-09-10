#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void search(vector<vector<int>>& main_set, vector<int> subset, int k, int n) {
	if (k == n) {
		main_set.push_back(subset);
	} else {
		search(main_set, subset, k+1, n);
		subset.push_back(k);
		search(main_set, subset, k+1, n);
	}

}


int main() {

	vector<vector<int>> main_set;
	vector<int> subset;

	search(main_set, subset, 0, 3);

	for (auto x : main_set) {
		for (auto i : x) {
			cout << i << " ";
		}
		cout << "\n";
	}


	

	return 0;
}
