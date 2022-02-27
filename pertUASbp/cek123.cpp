#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef struct
{
	int tgl;
	int bln;
	int th;
}Tanggal;
typedef struct
{
	char noID[20];
	char nama[30];
	char jenis_kelamin; //’L’ atau ‘P’
	Tanggal t;
}KTP;
typedef struct
{
	KTP ktp;
	int jml;
}Data_KTP;
Data_KTP data_ktp[100];
Data_KTP* dataptr;

void tambah_data(int currently_lenght, Data_KTP*);
void searching_by_year(int recent_data_lenght);
void show_based_l_or_p(int current_data_lenght, Data_KTP*);
void edit_data(int current_data_et, Data_KTP*);

int main() {
	ward_begin:
	int m, i;
	cout << "Masukan Jumlah KTP yang ingin didata : "; cin >> m;
	if (m <= 0) {
		cout << "Jumlah tidak boleh 0 atau dibawahnya! Coba lagi!" << endl;
		goto ward_begin;
	}
	cin.ignore();
	data_ktp->jml = 0;
	dataptr = &data_ktp[0];
	cout << "Melakukan record data........" << endl;
	for (i = 0; i < m; i++) { //Record Data
		cout << "------------------------------------------------------------" << endl;
		cout << "No ID			: "; fgets(data_ktp[i].ktp.noID, sizeof(data_ktp[i].ktp.noID), stdin);
		cout << "Nama			: "; fgets(data_ktp[i].ktp.nama, sizeof(data_ktp[i].ktp.nama), stdin);
		int len = strlen(data_ktp[i].ktp.noID);
		int len2 = strlen(data_ktp[i].ktp.nama);
		if ((data_ktp[i].ktp.noID[len - 1] == '\n') &&
			(data_ktp[i].ktp.nama[len2 - 1] == '\n')) {
			data_ktp[i].ktp.noID[len - 1] = '\0';
			data_ktp[i].ktp.nama[len2 - 1] = '\0';
		}
		cout << "Jenis Kelamin(L/P)      : "; cin >> data_ktp[i].ktp.jenis_kelamin;
		cin.ignore();
		cout << "-------------------------------------------------------------" << endl;
		cout << "informasi Kelahiran (menggunakan angka semua atau dd/mm/yyyy)"; cout << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Tanggal			: "; cin >> data_ktp[i].ktp.t.tgl;
		cout << "Bulan			: "; cin >> data_ktp[i].ktp.t.bln;
		cout << "Tahun			: "; cin >> data_ktp[i].ktp.t.th; cout << endl;
		cin.ignore();
		data_ktp->jml = data_ktp->jml + 1;
	}

	int menu_main;
ward_primary:
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	cout << "Data  KTP saat ini" << endl;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	cout << "No" << setw(15) << right << "No ID" << setw(15) << right << "Nama" << setw(20) << right << "Jenis Kelamin" << setw(20) << right << "Tanggal Lahir" << endl;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	for (int i = 0; i < (dataptr->jml); i++) {
		cout << i + 1 << setw(16) << right << (dataptr + i)->ktp.noID << setw(16) << right << (dataptr + i)->ktp.nama << setw(15) << right << (dataptr + i)->ktp.jenis_kelamin << setw(15) << right << (dataptr + i)->ktp.t.tgl << "/" << (dataptr + i)->ktp.t.bln << "/" << (dataptr + i)->ktp.t.th << endl;
	}
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	cout << "--------------------MENU---------------------" << endl;
	cout <<
		"1. Tambah Data \n" <<
		"2. Cari data berdasarkan tahun kelahiran \n" <<
		"3. Tampilkan data berdasarkan laki-laki dan perempuan \n" <<
		"4. Edit data\n" <<
		"5. Clear Screen\n" <<
		"6. Keluar" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Pilih menu : "; cin >> menu_main;
	cout << "---------------------------------------------" << endl;
	switch (menu_main)
	{
	case 1:
		tambah_data(dataptr->jml, dataptr);
		goto ward_primary;
		break;
	case 2:
		searching_by_year(dataptr->jml);
		goto ward_primary;
		break;
	case 3:
		show_based_l_or_p(dataptr->jml, dataptr);
		goto ward_primary;
		break;
	case 4:
		edit_data(dataptr->jml, dataptr);
		goto ward_primary;
		break;
	case 5:
		system("CLS");
		goto ward_primary;
		break;
	case 6:
		cout << "Keluar......" << endl;
		break;
	default:
		cout << "Menu tidak ada! Silahkan pilih menu yang ada!" << endl;
		goto ward_primary;
		break;
	}
	cin.get();
	return 0;
}
void tambah_data(int currently_lenght, Data_KTP* varr_ptr_dataptr) {
ward_tbh:
	char pilihan_coy;
	int tambah_orang;
	int temp = data_ktp->jml;
	cout << "Banyakanya data KTP yang ingin ditambahkan : "; cin >> tambah_orang;
	if (tambah_orang <= 0) {
		cout << "Jumlah data yang ingin ditambahkan tidak bisa dibawah atau sama dengan 0!" << endl; goto ward_tbh;
	}
	cin.ignore();
	cout << "Melakukan record data..............." << endl;
	for (int i = temp; i < temp + tambah_orang; i++) { //Record Data
		cout << "------------------------------------------------------------" << endl;
		cout << "No ID			: ";
		cin >> (dataptr + i)->ktp.noID;
		cin.ignore();
		cout << "Nama			: "; cin.getline((dataptr + i)->ktp.nama, 30);
		int len2 = strlen((dataptr + i)->ktp.nama);
		if ((dataptr + i)->ktp.nama[len2 - 1] == '\n') {
			(dataptr + i)->ktp.nama[len2 - 1] = '\0';
		}
		cin.sync();
		cout << "Jenis Kelamin(L/P)      : "; cin >> (dataptr + i)->ktp.jenis_kelamin;
		cout << "------------------------------------------------------------" << endl;
		cout << "informasi Kelahiran (menggunakan angka semua atau dd/mm/yyyy)"; cout << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Tanggal			: "; cin >> (dataptr + i)->ktp.t.tgl;
		cout << "Bulan			: "; cin >> (dataptr + i)->ktp.t.bln;
		cout << "Tahun			: "; cin >> (dataptr + i)->ktp.t.th;
		cin.ignore();
		data_ktp->jml = data_ktp->jml + 1;
	}
	cout << "Tambah lagi? y/n : "; cin >> pilihan_coy;
	switch (pilihan_coy) {
	case 'y':
		goto ward_tbh;
		break;
	default:
		break;
	}
}
void searching_by_year(int recent_data_length) {
ward_search_year:
	int yearsearch, flag_year_data;
	flag_year_data = 0;
	cout << "------------------------------------------------------------" << endl;
	cout << "Masukan tahun untuk pencarian	: "; cin >> yearsearch;
	cout << "Melakukan pencarian............." << endl << endl;
	for (int i = 0; i < recent_data_length; i++) {
		if (yearsearch == (dataptr + i)->ktp.t.th) {
			flag_year_data = flag_year_data + 1;
			cout << "Data ditemukan-" << flag_year_data << "........." << endl;
			cout << "No ID		: " << (dataptr + i)->ktp.noID << endl;
			cout << "Nama		: " << (dataptr + i)->ktp.nama << endl;
			cout << "Jenis Kelamin	: " << (dataptr + i)->ktp.jenis_kelamin << endl;
			cout << "Tanggal		: " << (dataptr + i)->ktp.t.tgl << "/" << (dataptr + i)->ktp.t.bln << "/" << (dataptr + i)->ktp.t.th << endl << endl;
		}
	}
	if (flag_year_data == 0) {
		cout << "Data tidak ditemukan, silahkan masukan tahun yang lain !" << endl;
		goto ward_search_year;
	}
	else {
		cout << "------------------------------------------------------------" << endl;
	}
}
void show_based_l_or_p(int current_data_lenght, Data_KTP* var_ptr_show_l_p) {
	system("CLS");
	int male_flag = 0;
	int femal_flag = 0;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	cout << " Data Laki-Laki" << endl;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	cout << "No" << setw(15) << right << "No ID" << setw(15) << right << "Nama" << setw(20) << right << "Jenis Kelamin" << setw(20) << right << "Tanggal Lahir" << endl;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	for (int i = 0; i < current_data_lenght; i++) {
		if ((dataptr + i)->ktp.jenis_kelamin == 'L' || (dataptr + i)->ktp.jenis_kelamin == 'l') {
			male_flag = male_flag + 1;
			cout << male_flag << setw(16) << right << (dataptr + i)->ktp.noID << setw(16) << right << (dataptr + i)->ktp.nama << setw(15) << right << dataptr->ktp.jenis_kelamin << setw(15) << right << (dataptr + i)->ktp.t.tgl << "/" << (dataptr + i)->ktp.t.bln << "/" << (dataptr + i)->ktp.t.th << endl;
		}
	}
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	cout << " Data Perempuan" << endl;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	for (int i = 0; i < current_data_lenght; i++) {
		if ((dataptr + i)->ktp.jenis_kelamin == 'P' || (dataptr + i)->ktp.jenis_kelamin == 'p') {
			femal_flag = femal_flag + 1;
			cout << femal_flag << setw(16) << right << (dataptr + i)->ktp.noID << setw(16) << right << (dataptr + i)->ktp.nama << setw(15) << right << (dataptr + i)->ktp.jenis_kelamin << setw(15) << right << (dataptr + i)->ktp.t.tgl << "/" << (dataptr + i)->ktp.t.bln << "/" << (dataptr + i)->ktp.t.th << endl;
		}
	}
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << "xxxxxxxxxxxxxxxxxxxxxx" << endl << endl << endl;
}

void edit_data(int current_data_lengh_et, Data_KTP* edit_ptr) {
	int choose2, choose_data_section;
	char choose_again;
	cout << "Menyajikan Data" << endl;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	cout << "No" << setw(15) << right << "No ID" << setw(15) << right << "Nama" << setw(20) << right << "Jenis Kelamin" << setw(20) << right << "Tanggal Lahir" << endl;
	cout << "------------------------------------------------------------" << "----------------------" << endl;
	for (int i = 0; i < current_data_lengh_et; i++) {
		cout << i + 1 << setw(16) << right << (dataptr + i)->ktp.noID << setw(16) << right << (dataptr + i)->ktp.nama << setw(15) << right << (dataptr + i)->ktp.jenis_kelamin << setw(15) << right << (dataptr + i)->ktp.t.tgl << "/" << (dataptr + i)->ktp.t.bln << "/" << (dataptr + i)->ktp.t.th << endl;
	}
	cout << "------------------------------------------------------------" << "----------------------" << endl;
ward_sw_1:
	cout << "Pilih data yang ingin diedit : "; cin >> choose2;
	if (choose2 > current_data_lengh_et|| choose2<=0) {
		cout << "Data tidak tersedia! Pilih data yang tersedia!" << endl;
		goto ward_sw_1;
	}
	int lenn2 = strlen(data_ktp[choose2].ktp.nama);
ward_sw_2:
	cout << "--------Pilihan Bagian Data-------\n"
		<< "1. Nomor ID \n"
		<< "2. Nama \n"
		<< "3. Jenis Kelamin \n"
		<< "4. Tanggal Lahir \n"
		<< "5. Semua bagian \n";
	cout << "6. Kembali ke pilih data \n"
		<<"7. Kembali ke menu utama \n" ;
	cout << "----------------------------------" << endl;
	cout << "Pilih Bagian Data : "; cin >> choose_data_section;
	choose2 = choose2 - 1;
	if (choose2 <= current_data_lengh_et) {
		switch (choose_data_section)
		{
		case 1:
			cin.ignore();
			cout << "No ID			: "; cin >> (dataptr + choose2)->ktp.noID;
			break;
		case 2:
			cin.ignore();
			cout << "Nama			: "; cin.getline((dataptr + choose2)->ktp.nama, 30);
			if (data_ktp[choose2].ktp.nama[lenn2 - 1] == '\n') {
				data_ktp[choose2].ktp.nama[lenn2 - 1] = '\0';
			}
			break;
		case 3:
			cin.ignore();
			cout << "Jenis Kelamin	: "; cin >> (dataptr + choose2)->ktp.jenis_kelamin;
			break;
		case 4:
			cin.ignore();
			cout << "------------------------------------------------------------" << endl;
			cout << "informasi Kelahiran (menggunakan angka semua atau dd/mm/yyyy)"; cout << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << "Tanggal			: "; cin >> (dataptr + choose2)->ktp.t.tgl;
			cout << "Bulan			: "; cin >> (dataptr + choose2)->ktp.t.bln;
			cout << "Tahun			: "; cin >> (dataptr + choose2)->ktp.t.th;
			break;
		case 5:
			cin.ignore();
			cout << "No ID			: "; cin >> (dataptr + choose2)->ktp.noID;
			cin.ignore();
			cout << "Nama			: "; cin.getline((dataptr + choose2)->ktp.nama, 30);
			if (data_ktp[choose2].ktp.nama[lenn2 - 1] == '\n') {
				data_ktp[choose2].ktp.nama[lenn2 - 1] = '\0';
			}
			cin.sync();
			cout << "Jenis Kelamin		: "; cin >> (dataptr + choose2)->ktp.jenis_kelamin;
			cout << "------------------------------------------------------------" << endl;
			cout << "informasi Kelahiran (menggunakan angka semua atau dd/mm/yyyy)"; cout << endl;
			cout << "------------------------------------------------------------" << endl;
			cout << "Tanggal			: "; cin >> (dataptr + choose2)->ktp.t.tgl;
			cout << "Bulan			: "; cin >> (dataptr + choose2)->ktp.t.bln;
			cout << "Tahun			: "; cin >> (dataptr + choose2)->ktp.t.th;
			cin.ignore();
			break;
		case 6:
			goto ward_sw_1;
		case 7:
			goto ward_here;
		default:
			cin.ignore();
			cout << "Bagian data tidak tersedia ! Silahkan pilih yang tersedia !";
			goto ward_sw_2;
			break;
		}
		ward_here:
		cout << "------------------------------------------------------------" << "----------------------" << endl;
		cout << "No" << setw(15) << right << "No ID" << setw(15) << right << "Nama" << setw(20) << right << "Jenis Kelamin" << setw(20) << right << "Tanggal Lahir" << endl;
		cout << "------------------------------------------------------------" << "----------------------" << endl;
		for (int i = 0; i < current_data_lengh_et; i++) {
			cout << i + 1 << setw(16) << right << (dataptr + i)->ktp.noID << setw(16) << right << (dataptr + i)->ktp.nama << setw(15) << right << (dataptr + i)->ktp.jenis_kelamin << setw(15) << right << (dataptr + i)->ktp.t.tgl << "/" << (dataptr + i)->ktp.t.bln << "/" << (dataptr + i)->ktp.t.th << endl;
		}
		cout << "------------------------------------------------------------" << "----------------------" << endl;
		cout << " Pilih data lagi ? y/n : "; cin >> choose_again;
		switch (choose_again)
		{
		case 'y':
			goto ward_sw_1;
		case 'Y':
			goto ward_sw_1;
		default:
			break;
		}
	}
	else {
		cout << "Data tidak ada ! Silahkan pilih data KTP yang tersedia"; goto ward_sw_2;
	}

}
