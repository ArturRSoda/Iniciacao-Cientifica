#include <array>
#include <cstdio>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

//objetivo do algoritmo eh dado n eventos com seus devidos horarios de inicio e fim, encontre a agenda que consiga includir a maior quantidade de eventos possiveis. Nao eh possivel escolher eventos parcialmente.
//
//OBS: CODIGO FEITO POR MIM, NAO TESTADO TOTALMENTE

using namespace std;

struct event {
	char event;
	int start;
	int end;
};

bool sort_event(event& a, event& b) {
	if (a.start == b.start)
		return (a.end - a.start) > (b.end - b.start);
	else
		return a.start > b.start;
}

int main() {
	freopen("input.txt" , "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<event> eventos;
	event e;

	for (int i = 0; i < n; i++) {
		cin >> e.event;
		cin >> e.start;
		cin >> e.end;
		eventos.push_back(e);
	}

	sort(eventos.begin(), eventos.end(), sort_event);

	int count = 0;
	int end = eventos[0].end;

	while (eventos.back().end < end) {
		count++;
		eventos.pop_back();
	}

	cout << "numero maximo de eventos: " << count << "\n";

	return 0;
}
