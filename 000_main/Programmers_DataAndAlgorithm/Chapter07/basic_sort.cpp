#include <algorithm> // swap 함수 이용하기 위해서
#include <iostream>

using namespace std;

void bubble_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++){
        for (int j = n - 1; j > i; j--) {                              // data[n-1]부터 data[i]까지 이동하면서
            if (data[j] < data [j - 1])                               // 인접한 두 원소를 비교 & 교환
                swap(data[j], data[j - 1]);
        }
    }
}

void selection_sort(int data[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < n; j++)
			if (data[j] < data[idx])
				idx = j;

		swap(data[i], data[idx]);
	}
}

void insertion_sort(int data[], int n)
{
	for (int i = 1; i < n; i++) {
		int key = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > key) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}

}


int main()
{
	int data[] = {4, 2, 3, 5, 1};
//	bubble_sort(data, 5);
	selection_sort(data, 5);
//	insertion_sort(data, 5);

	for (auto n : data)
		cout << n << ", ";
	cout << endl;
}
