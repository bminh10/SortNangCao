#include <iostream>
#include <vector>
#include <stack>
using namespace std;





//void countingSort(int a[], int n) {
//	int  max = INT_MIN;
//	for(int i = 0 ; i < n ; i++){
//		if (a[i] > max) {
//			max = a[i];
//		}
//	}
//	vector<int>count(max+1,0);
//
//	for (int i = 0; i <= max; i++) {
//		count[i] = 0;
//	}
//
//	for (int i = 0; i < n; i++) {
//		count[a[i]]++;
//	}
//
//	for (int i = 1; i <= max; i++) {
//		count[i] = count[i] + count[i - 1];
//	}
//
//	vector<int>output(n);
//
//	for (int i = n - 1; i >= 0; i--) {
//		output[count[a[i]] - 1] = a[i];
//		count[a[i]]--;
//	}
//
//	for (auto x : output) {
//		cout << x << " ";
//	}
//
//}

int getMax(int a[],int n) {
	int  max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}


void countingSort(int a[], int n,int exp) {
	int max = getMax(a, n);
	
	vector<int>count(max + 1, 0);

	for (int i = 0; i <= max; i++) {
		int digit = (a[i] / exp) % 10;
		count[digit] = 0;
	}

	for (int i = 0; i < n; i++) {
		int digit = (a[i] / exp) % 10;
		count[digit]++;
	}

	for (int i = 1; i <= max; i++) {
		count[i] = count[i] + count[i - 1];
	}

	vector<int>output(n);

	for (int i = n - 1; i >= 0; i--) {
		int digit = (a[i] / exp) % 10;
		output[count[digit] - 1] = a[i];
		count[digit]--;
	}

	for (int i = 0; i < n; i++) {
		a[i] = output[i];
	}

	

}


void heapify(int a[], int n, int i,int exp) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int jmax = i;
	int digitL = (a[l] / exp) % 10;
	int digitR = (a[r] / exp) % 10;
	int digit = (a[jmax] / exp) % 10;
	if (l < n && digit < digitL) {
		jmax = l;
	}
	if (r < n && digit < digitR) {
		jmax = r;
	}
	if (jmax != i) {
		swap(a[i], a[jmax]);
		heapify(a, n, jmax,exp);
	}

}

void heapSort(int a[] , int n,int exp) {
	int i = n / 2 - 1;
	while (i >= 0) {
		heapify(a, n, i,exp);
	}

	for (int r = n - 1; r > 0; r--) {
		swap(a[0], a[r]);
		heapify(a, r, 0,exp);
	}
}

/*void quickSort(int a[], int left, int right, int exp) {
	int l = left;
	int r = right;
	int pivot = (a[(l + r) / 2]/exp)%10;

	while (l <= r) {
		
		while ((a[l] / exp) % 10 < pivot) {
			l++;
		}
		while ((a[r] / exp) % 10 > pivot) {
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if (l < right) {
		quickSort(a, l, right,exp);
	}
	if (r > left) {
		quickSort(a, left, r,exp);
	}
}*/

void phanHoach(int a[] , int  &l , int&r, int exp) {
	int pivot = (a[(l + r) / 2] / exp) % 10;
	while (l <= r) {
		while ((a[l] / exp) % 10 < pivot) {
			l++;
		}
		while ((a[r]/exp)%10 > pivot ) {
			r--;
		} 
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}

}


void quickSort(int a[],int n ,int exp) {
	stack<pair<int, int>>s;
	int left = 0;
	int right = n - 1;
	s.push({ left,right });
	while (!s.empty()) {
		int l = s.top().first;
		int r = s.top().second;
		s.pop();

		left = l;
		right = r;
		phanHoach(a, l, r, exp);
		if (l < right) {
			s.push({ l, right });
		}
		if (r > left) {
			s.push({ left,r });
		}
		

	}
}







void radixSort(int a[], int n) {
	int m = getMax(a,n);
	for (int exp = 1; m / exp != 0; exp *= 10) {
		quickSort(a,n ,exp);
	}
}

int main() {
	int a[8] = { 2,5,3,0,2,3,0,3};
	int n =8;
	radixSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	

	return 0;
}