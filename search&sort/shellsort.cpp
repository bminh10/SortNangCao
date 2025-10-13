#include <iostream>
#include <vector>
using namespace std;



//void shellSort(int a[], int n) {
//	for (int gap = n / 2; gap > 0; gap /= 2) {
//		for (int i = gap; i < n; i++) {
//			int temp = a[i];
//			int j;
//			for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
//				a[j] = a[j - gap];
//			}
//			a[j] = temp;
//		}
//	}
//}

void shellSort(int a[],int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i ++ ) {
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp;j-=gap) {
				a[j] = a[j - gap];
				
			}
			a[j] = temp;

		}
	}
}




int main() {
	int a[5] = { 8,5,3,7,2 }; 

	int n = 5;
	shellSort(a,n);
	for (auto x : a) {
		cout << x << " ";
	}

	return 0;
}