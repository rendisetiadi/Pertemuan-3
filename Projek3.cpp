#include <iostream>
using namespace std;

 //prototype
 void prosesbaca();
 int prosestambah();
 int proseskurang();
 void prosestampil();
 
 //variabel global 
		int a, b;
		
	//program utama
	int main (){
	
		prosesbaca();
		prosestampil();
		return 0; 
	}
	
//prosesbaca

void prosesbaca (){
	
		cout << "masukan nilai a : ";
		cin >> a;
	
		cout << "masukan nilai b : ";
		cin >> b;
		}
		
//prosestambah

	int prosestambah (){
	return a + b;
	}
	
	//proseskurang
	
	int proseskurang (){
		int hasil;
		hasil = a - b;
		return hasil;
	}
	
	//prosestampil
	
	void prosestampil(){
		cout << "hasil tambah : " << prosestambah() <<endl;
		cout << "hasil kurang : " << proseskurang() <<endl;
		}