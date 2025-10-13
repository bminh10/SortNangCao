#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<float>arr = { 0.42,0.32,0.23,0.52,0.25,0.47,0.51 };
const int len = 7;



void insertionSort(vector<float>&a) {
	for (int i = 1; i < a.size(); i++) {
		float x = a[i];
		int pos = i - 1;
		while (pos >= 0 && x < a[pos]) {
			a[pos + 1] =a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}

}

void bucketSort() {
	vector<float> b[len];

	for (int i = 0; i < len; i++) {
		int bi = len * arr[i];
		b[bi].push_back(arr[i]);
	}

	for (int i = 0; i < len; i++) {
		insertionSort(b[i]);
	}

	int index = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < b[i].size(); j++) {
			arr[index++] = b[i][j];
		}
	}
	
}



int main() {
	
	
	bucketSort();
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}