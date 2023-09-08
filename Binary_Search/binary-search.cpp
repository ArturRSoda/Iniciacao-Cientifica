#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int binary_search(int n, int v[], int x) {
	int k = 0;
	for (int b = n/2; b >= 1; b /= 2) {
		while ((b+k < n) && (v[k+b] <= x)) {
			k += b;
		}
	}
	if (v[k] == x) return k;
	else return -1;
}


int main() {

	int v[] = {3, 5, 6, 1, 5};

	int b;
	int n = sizeof(v)/sizeof(v[0]);
	sort(v, v+n);
	b = binary_search(5, v, 3);
	printf("%d \n", b);



	

	return 0;
}
