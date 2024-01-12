#include <iostream>
using namespace std;

int main() {

	int arr[10];

	arr[0] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 1;
	arr[5] = 1;

	int num = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int c = 0;

	while (arr[i] < 0) {
		if (arr[i] != 0) {
			c++;
		}
		i++;
	}

	cout << "Has " << c << " in use" << endl;

	return 0;
}