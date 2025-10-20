#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>>a;
vector<vector<int>>e;

void nhap() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	e.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0) {
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}



}




int main() {


	return 0;
}