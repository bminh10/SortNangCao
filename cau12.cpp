#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int n, m;
vector<vector<int>>a;
vector<vector<int>>b;

void nhap() {
	ifstream fin;
	fin.open("gtree.inp");
	fin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
		for (int j = 0; j < m; j++) {
			fin >> a[i][j];
		}
	}
	b.resize(n);
	for (int i = 0; i < n; i++) {
		b[i].resize(m);
		for (int j = 0; j < m; j++) {
			fin >> b[i][j];
		}
	}

	fin.close();
}


void check(int i , int j ,int &color) {
	for (int u = m - 1; u >= 0; u--) {
		if (b[i][u] == 0)continue;
		if (color == 1 && b[i][u] == 1) {
			color = 2;
		}
		else {
			break;
		}
		
	}
	
	for (int k = n - 1; k >= 0; k--) {
		if (b[k][j] == 0)continue;
		if (color == 1 && b[k][j] == 1) {
			color = 2;
		}
		else {
			break;
		}
	}
}

void process() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				int color = 1;
				check(i, j, color);
				b[i][j] = color;
				
			}
		}
		
	}

}


void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	nhap();
	process();
	output();


	return 0;
}