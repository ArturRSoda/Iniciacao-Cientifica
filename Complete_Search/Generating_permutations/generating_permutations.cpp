#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//retora um vetor com todas as permutacoes possiveis de um vetor de tamanho N

void search(vector<vector<int>>& main_v, vector<int> v, int n) {
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}

	do {
		main_v.push_back(v);
	} while (next_permutation(v.begin(), v.end()));
	
}

int main() {
	vector<vector<int>> main_v;
	vector<int> v;

	search(main_v, v, 3);

	for (auto x : main_v) {
		for (auto i : x) {
			cout << i << " ";
		}
		cout << "\n";
	}


	return 0;
}
