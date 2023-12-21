#include <iostream>

using namespace std;

int soma(int n1, int n2);
int soma(int n1, int n2, int n3);
//float soma(float n1, float n2);

int main() {

	cout << soma(3, 5) << endl;
	cout << soma(4, 6, 8) << endl;
	//cout << soma(3.45, 7.91) << endl;

	return 0;
}

int soma(int n1, int n2) {
	return n1 + n2;
}

int soma(int n1, int n2, int n3) {
	return n1 + n2 + n3;
}

//float soma(float n1, float n2) {
//	return n1 + n2;
//}