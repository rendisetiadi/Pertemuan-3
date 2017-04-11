
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// global var
double value;
int count = 0;
double jumlah = 0;


/**
* karena kita tidak tahu berapa banyak inputan maka kita memakai
* salah satu struktur data linked list (mata kuliah Struktur Data semester I)
* dimana kita bisa memakai kelebihan dari dinamik memory.
* kita buat struktur terlebih dulu.
*
* Mendefinisikan sebuah struktur untuk element linked list
*/
typedef struct node_
{
	/* 
		karena kita hanya menyimpan nilai IP MHS maka
	   	hanya dibutuhkan tipe data double 
	*/
	double 				value;
	struct node_		*next;

} node;

/**
* fungsi yang menyimpan data
* @param value nilai dari IP MHS
* @return pointer dari data elemen yg telah tersimpan
*/
node* create(double value)
{
	/*  malloc() berfungsi untuk memesan tempat dimemory heap
		malloc(sizeof(nilai_msh)) - sediakan tempat sebanyak nilai_mhs
		malloc() return alamat di heap
		lalu disimpan oleh var pointer i dengan tipe data yg sama dengan struct
	*/
	node *i = (node *)malloc(sizeof(int));

	i->value = value;

	/*	set setiap list ke null */ 
	i->next = NULL;

	return i;
}

// prototype
void display(node *start);
void input();
void release(node *mulai);
bool isWhitinRange(float x, int min, int max);
int getSize();
bool isEmpty();
double getAvg();
int getLulus();
int getTidakLulus();


// global 
node *head = NULL;

/* fungsi main */
int main()
{

	input();

	if (!isEmpty())
		display(head);
	else
		cout << "\ntidak ada data" << endl;

	release(head);
	
	return 0;
}

/**
* procedure untuk menampilkan semua nilai ke console
* @param start untuk menerima struktur yang berisi nilai dan next
*/
void display(node *start)
{
	node *i = start;
	int no = 1;

	cout << "\n";
	cout << "Nilai Index Prestasi Mahasiswa" << endl;
	cout << "- - - - - - - - - - - - - - - " << endl;
	for(; i != NULL; i = i->next, no++)
		printf("%8i. Nilai = %2.2f\n", no, i->value);


	cout << "\n";
	cout << "Nilai Rata Rata Mahasiswa" << endl;
	cout << "- - - - - - - - - - - - - - - " << endl;
	printf("%14.2f\n", getAvg());


	cout << "\n";
	cout << "Mahasiswa Yang Lulus" << endl;
	cout << "- - - - - - - - - - - - - - - " << endl;
	printf("%12i\n", getLulus());


	cout << "\n";
	cout << "Mahasiswa Yang  Tidak Lulus" << endl;
	cout << "- - - - - - - - - - - - - - - " << endl;
	printf("%12i\n", getTidakLulus());
}

void input()
{	

	// memberitahukan kepada user tentang program
	cout << endl;
	cout << "    -------------------------------------------------------------" << endl;
	cout << "   |                                                             |" << endl;
	cout << "   |   Program untuk menyimpan nilai Indexs Prestasi Mahasiswa   |" << endl;
	cout << "   |          Nilai IP yang harus dimasukan 0 <= IP <= 4         |" << endl;
	cout << "   |        Masukan nilai -99 untuk berhenti dari Program        |" << endl;
	cout << "   |                                                             |" << endl;
	cout << "    -------------------------------------------------------------" << endl;
	cout << endl;

	node *i = NULL;
	node *berikutnya = NULL;

	do {

		cout << ">>> : ";
		cin >> value;

		bool result = isWhitinRange(value, 0, 4);
		if (result)
		{
			// masukan element berikutnya ke i
			i = berikutnya;

			// buat linked list dan masukan alamat nya ke vat berikutnya
			berikutnya = create(value);

			// set head ke element pertama
			if (head == NULL)
				head = berikutnya;

			// jika data i tdk null maka masukan pointer data berikutnya 
			if (i != NULL)
				i->next = berikutnya;

			// hitung setiap IP yg valid
			count++;

			// jumlahkan semua data yg masuk
			jumlah += value;
		}

	} while(value != -99);
}

/**
* prosedur untuk menghapus data di memori
* karena kita memakai memory dinamis
* @param mulai head dari linked list
*/
void release(node *mulai)
{
	node *i = mulai;
	node *terus = NULL;

	while (i != NULL)
	{
		terus = i->next;
		free(i);
		i = terus;
	}
}

/**
* @param x sebuah nilai dari IP MHS
* @param min nilai terkecil dari IP
* @param max nilai terbesar dari IP
* @return true jika benar san sebaliknya
*/
bool isWhitinRange(float x, int min, int max)
{
	return (x >= min && x <= max);
}

/*
* @return count dari total kardinal elemen
*/
int getSize()
{
	return count;
}

/*
* @return true jika list kosong
*/
bool isEmpty()
{
	return (count == 0 && head == NULL);
}

/**
* @return jumlah nilai rata-rata
*/
double getAvg()
{
	double avg = jumlah / count;
	return avg; 
}

/*
* @return berapa banyak yg lulus
*/
int getLulus()
{
	node *i = head;
	int lulus = 0;

	while (i != NULL)
	{
		if (i->value >= 2.75)
			lulus++;
		i = i->next;
	}

	return lulus;
}

/* 
* @return berapa banyak yg tidak lulus
*/
int getTidakLulus()
{
	node *i = head;
	int tdkLulus = 0;

	while (i != NULL)
	{
		if (i->value < 2.75)
			tdkLulus++;
		i = i->next;
	}

	return tdkLulus;
}