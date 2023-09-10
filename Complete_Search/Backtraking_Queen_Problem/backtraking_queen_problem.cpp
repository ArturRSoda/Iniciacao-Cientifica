#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void search(vector<int>& column,
		   vector<int>& diag1,
		   vector<int>& diag2,
		   int& count,
		   int n,
		   int y) {

	if (y == n) {
		count++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		search(column, diag1, diag2, count, n, y+1);
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}

}

int main() {
	int n = 8;
	vector<int> column(n);
	vector<int> diag1(n+n-1);
	vector<int> diag2(n+n-1);
	int count = 0;
	search(column, diag1, diag2, count, n, 0);
	cout << "Numero de solucoes = " << count << "\n";
	return 0;
}
