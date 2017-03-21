#include <iostream>
using namespace std;

int main () {
// variabel
	int a, b, temp;
	
	//proses membaca
	cout << "masukan nilai a : ";
	cin >> a;
	
	cout << "masukan nilai b : ";
	cin >> b;
	
	//proses tukar
	
	temp = b;
	b = a;
	a = temp;
	
	//proses tampil
	
	cout << "============================="<< endl;
	cout << "nilai a sekarang:" << a << endl;
	cout << "nilai b sekarang :" << b;
	
	return 0;
	}
	
	