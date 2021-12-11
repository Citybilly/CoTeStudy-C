#include <iostream>

using namespace std;

int buff[256];

void merge(int data[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) {
		if (data[i] <= data[j])
			buff[k++] = data[i++];
		else
			buff[k++] = data[j++];
	}

	while (i <= mid)
		buff[k++] = data[i++];

	while (j <= right)
		buff[k++] = data[j++];

	for (int x = left; x <= right; x++)
		data[x] = buff[x];
}

void merge_sort(int data[], int  left, int right)
{
    if(left < right){
        int mid = (left + right) / 2; // mid 는 배열의 중간 지점 인덱스
        merge_sort(data, left, mid); // 처음부터 중간지점 까지 재귀
        merge_sort(data, mid + 1, right); // 중간지점 부터 끝까지 재귀
        merge(data, left, mid, right); 
    }
}


int main()
{
	int data[] = { 2, 6, 7, 4, 1, 8, 5, 3 };
	merge_sort(data, 0, 7);

	for (auto n : data)
		cout << n << ", ";
	cout << endl;
}