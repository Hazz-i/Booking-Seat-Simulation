
//		KELOMPOK 4			//
//							//
//	Bahar	[22.11.4935]	//
//	Rehan	[22.11.4929]	//
//	Yusuf	[22.11.4901]	//
//	Wahid	[22.11.4878]	//
//							//

#include<iostream>
#include<ctime>				// Library untuk mengambil waktu pada menu pemesanan kursi
#include "color.h"
#include "menu.cpp"

using  namespace std;

const int MAX = 10;			// max data penyimpanan --> variabel global

// menyimpan data login
struct  User {
	string username[MAX];		// max menyimpan data user 10
	string passwd[MAX];			// menyimpan data password user 10
	int count;					// menghitung size array username dan passwd
}U;

// menyimpan data pemesanan
struct Booking {
	int noKursi[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };		// nomor kursi yang tersedia
	int noKursiTerhapus[MAX];									// menampung input kursi user
	int countKursiTerhapus;										// menghitung size array noKursiTerhapuus
	string pelanggan[MAX];										// menyimpan data nama pelanggan
	string waktuTerpesan[MAX];									// menyimpan waktu pemesanan
}B;

// 11 fungsi bertipe void
int main();
void signUp();
void login();
void tampilAkun();
void hapusAkun();
void booking();
void pesan();
void tampilkan();
void hapus();
void cari();
void ifc_main();
void ifc_sub();


// login menu
int main() {
	int pilih;

	while (true) {
		system("cls");
		menu ex;

		ifc_main();
		set_xy(73, 9);
		cout << "Booking Kursi";
		ex.set_xy(73, 12);
		ex.set_color(ex.RED);
		pilih = ex.Gmenu("Buat Akun", "  Masuk", "  Tampil", "Hapus Akun", "  Keluar");

		if (pilih == 0)
			signUp();
		else if (pilih == 1)
			login();
		else if (pilih == 2)
			tampilAkun();
		else if (pilih == 3)
			hapusAkun();
		else
			exit(0);
	}
	return 0;
}

void signUp() {
	system("cls");
	string uName, pass, cPass;
	bool confirmPass = false;

	ifc_sub();
	set_xy(80, 7);
	cout << "Buat Akun";
	set_xy(68, 17);
	cout << "Username\t\t: ";
	cin >> uName;
	if (uName == "0")  main();

	bool cek = false;
	for (int i = 0; i < U.count; i++) {
		if (uName == U.username[i])
			cek = true;
	}

	if (cek) {
		set_xy(70, 30);
		cout << "username yang telah terdaftar";
	}
	else {
		set_xy(68, 18);
		cout << "Password\t\t: ";
		cin >> pass;

		while (!confirmPass) {
			set_xy(68, 19);
			cout << "Konfirmasi Password\t: ";
			cin >> cPass;
			if (cPass != pass) {
				set_xy(68, 21);
				cout << "Password tidak sama, Silahkan coba lagi" << endl;
			}
			else {
				confirmPass = true;
			}
		}

		if (U.count < 10) {
			U.username[U.count] = uName;	//U.username[0] = uName
			U.passwd[U.count] = cPass;		//U.passwd[U.count] = cPass 
			U.count++;

			set_xy(68, 30);
			cout << "Akun berhasil ditambahkan" << endl;
		}
		else {
			set_xy(75, 30);
			cout << "User penuh" << endl;
		}
	}
	system("pause > nul");
	main();
}

void login() {
	system("cls");
	string uName, pass;
	bool akunTersedia = false;

	ifc_sub();
	set_xy(80, 7);
	cout << "Login Page";
	set_xy(70, 17);
	cout << "Username\t\t: ";
	cin >> uName;
	if (uName == "0")  main();

	set_xy(70, 18);
	cout << "Password\t\t: ";
	cin >> pass;

	for (int i = 0; i < U.count; i++) {
		if (uName == U.username[i] && pass == U.passwd[i]) {
			akunTersedia = true;
			break;
		}
	}

	if (akunTersedia) {
		set_xy(80, 21);
		cout << "Berhasil Masuk";
		system("pause > nul");
		booking();
	}
	else {
		set_xy(60, 21);
		cout << "Akun tidak ditemukan, Silahkan mendaftar terlebih dahulu" << endl;
		system("pause > nul");
		main();
	}
}

void tampilAkun() {
	int size = U.count;
	bool dataTersedia = false;

	system("cls");
	ifc_sub();

	set_xy(80, 7);
	cout << "Daftar Akun";

	if (size != 0)
		dataTersedia = true;

	if (!dataTersedia) {
		set_xy(80, 20);
		cout << "Data Kosong";
	}
	else {

		for (int i = 0; i < size; i++) {
			set_xy(50, 14 + i);
			cout << i + 1 << " User " << "[" << i + 1 << "] " << U.username[i];
		}
	}

	system("pause > null ");
	main();
}

void hapusAkun() {
	system("cls");
	int size = U.count;

	ifc_sub();
	set_xy(80, 7);
	cout << "Hapus Akun";
	// Cek apakah ada data pengguna yang tersedia untuk dihapus
	if (size != 0) {
		// Hapus data pengguna dari paling belakang
		//stack
		int pos = size - 1;

		U.username[pos] = "";
		U.passwd[pos] = "";

		set_xy(75, 21);
		cout << "Akun berhasil dihapus";

		U.count--;

	}
	else {
		set_xy(67, 21);
		cout << "Tidak ada data pengguna yang tersedia" << endl;
		system("pause > null");
		main();
		return;
	}
	system("pause > null");
	main();
}

// booking menu
void booking() {
	int pilih;

	while (true) {
		menu ex;
		system("cls");

		ifc_main();
		set_xy(73, 9);
		cout << "Booking Kursi";
		ex.set_xy(65, 12);
		ex.set_color(ex.RED);
		pilih = ex.Gmenu("\tPilih Kursi", "Tampilkan Daftar Booking", "    Batalkan Booking", "\tCari Kursi", "\t Kembali");


		if (pilih == 0)
			pesan();
		else if (pilih == 1)
			tampilkan();
		else if (pilih == 2)
			hapus();
		else if (pilih == 3)
			cari();
		else
			main();
	}
}

void pesan() {
	system("cls");
	string nama;
	bool kursiTersedia = false;
	int nKursi;
	int size = sizeof(B.noKursi) / sizeof(B.noKursi[0]);		// menghitung jumlah data pada array

	set_xy(80, 7);
	cout << "Pesan Kursi";
	set_xy(72, 11);
	cout << "Kursi yang masih tersedia: " << endl;

	cout << setw(60);
	for (int i = 0; i < size; i++) {
		if (B.pelanggan[i].empty()) {
			cout << " [" << B.noKursi[i] << "] ";
			kursiTersedia = true;
		}
	}
	cout << endl;

	ifc_sub();
	if (!kursiTersedia) {
		set_xy(74, 12);
		cout << "Maaf, semua kursi telah dipesan." << endl;
		system("pause > nul");
		booking();
		return;
	}

	set_xy(55, 15);
	cout << "Pilih nomor kursi : ";
	cin >> nKursi;
	if (nKursi == 0) booking();

	bool kursiTerpesan = false;
	for (int i = 0; i < size; i++) {
		if (nKursi == B.noKursi[i]) {
			if (B.pelanggan[i].empty()) {
				kursiTerpesan = true;
				break;
			}
		}
	}

	if (!kursiTerpesan) {
		set_xy(60, 30);
		cout << "Nomor kursi tidak tersedia. Silakan pilih nomor kursi lain.";
		system("pause > nul");
		booking();
		return;
	}

	set_xy(55, 17);
	cout << "Masukkan nama: ";
	cin >> nama;

	// Simpan nama pemesan pada array booking.pelanggan sesuai dengan nomor kursi yang dipilih
	for (int i = 0; i < size; i++) {
		if (nKursi == B.noKursi[i]) {
			B.pelanggan[i] = nama;


			time_t timeNow = time(&timeNow);  // Mengambil waktu saat ini

			const int bufferSize = 26;
			char waktuPesan[bufferSize];
			ctime_s(waktuPesan, bufferSize, &timeNow);  // Konversi waktu ke string menggunakan ctime_s

			// Simpan waktu pemesanan pada array booking.waktuPesan
			B.waktuTerpesan[i] = waktuPesan;
			break;
		}
	}

	set_xy(80, 30);
	cout << "Booking berhasil!" << endl;

	// Simpan nomor kursi yang telah dipesan ke dalam array noKursiTerhapus
	B.noKursiTerhapus[B.countKursiTerhapus] = nKursi;
	B.countKursiTerhapus++;

	system("pause > nul");
	booking();
}

void tampilkan() {
	system("cls");
	bool pesananTersedia = false;
	int size = B.countKursiTerhapus;

	ifc_sub();
	set_xy(78, 7);
	cout << "Daftar Pesanan";

	if (B.countKursiTerhapus != 0)
		pesananTersedia = true;
	else
		pesananTersedia = false;

	if (!pesananTersedia) {
		set_xy(75, 30);
		cout << "Pesanan Tidak Tersedia";
	}
	else {
		// Mengurutkan ulang nomor kursi yang telah dipesan
		// bubble sort
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (B.pelanggan[B.noKursiTerhapus[j] - 1] > B.pelanggan[B.noKursiTerhapus[j + 1] - 1]) {

					int tempKursi = B.noKursiTerhapus[j];
					B.noKursiTerhapus[j] = B.noKursiTerhapus[j + 1];
					B.noKursiTerhapus[j + 1] = tempKursi;
				}
			}
		}

		for (int i = 0; i < size; i++) {
			set_xy(50, 14 + i);
			cout << i + 1 << ". " << B.pelanggan[B.noKursiTerhapus[i] - 1] << " - Kursi [" << B.noKursiTerhapus[i] << "] ";
			set_xy(90, 14 + i);
			cout << B.waktuTerpesan[B.noKursiTerhapus[i] - 1];
		}

	}

	system("pause > nul");
	booking();
}

void hapus() {
	system("cls");
	int nKursi;
	bool kursiDitemukan = false;
	int size = B.countKursiTerhapus;

	ifc_sub();
	set_xy(78, 7);
	cout << "Cancel Booking";

	set_xy(50, 12);
	cout << "Masukkan nomor kursi: ";
	cin >> nKursi;
	if (nKursi == 0) booking();

	for (int i = 0; i < sizeof(B.noKursi) / sizeof(B.noKursi[0]); i++) {
		if (nKursi == B.noKursi[i]) {
			B.pelanggan[i] = "";
			B.waktuTerpesan[i] = "";
			break;
		}
	}

	for (int i = 0; i < size; i++) {
		if (nKursi == B.noKursiTerhapus[i]) {
			kursiDitemukan = true;
		}

		if (kursiDitemukan) {
			B.noKursiTerhapus[i] = B.noKursiTerhapus[i + 1];
		}
	}

	if (kursiDitemukan) {
		set_xy(80, 30);
		cout << "Booking dibatalkan." << endl;
		B.countKursiTerhapus--;
	}
	else {
		set_xy(75, 20);
		cout << "Nomor kursi tidak ditemukan." << endl;
	}

	system("pause > nul");
	booking();
}

void cari() {
	system("cls");
	int nKursi;
	int size = sizeof(B.noKursi) / sizeof(B.noKursi[0]);		// menghitung jumlah data pada 
	bool kursiDitemukan = false;

	ifc_sub();
	set_xy(80, 7);
	cout << "Cari Data";
	set_xy(30, 12);
	cout << "Masukkan Nomor Kursi: ";
	cin >> nKursi;

	// sequential search
	set_xy(47, 30);
	for (int i = 0; i < size; i++) {
		if (nKursi == B.noKursi[i]) {
			if (!B.pelanggan[i].empty()) {
				cout << "Kursi dengan nomor [" << B.noKursi[i] << "] dipesan oleh " << B.pelanggan[i] << "\t\t\t" << B.waktuTerpesan[i];
				kursiDitemukan = true;
				break;
			}
		}
	}

	if (!kursiDitemukan) {
		set_xy(73, 30);
		cout << "Nomor kursi tidak ditemukan" << endl;
	}

	system("pause > nul");
	booking();
}

// interface
void ifc_main() {
	set_xy(50, 8);
	cout << "=========================================================";
	set_xy(50, 10);
	cout << "--------------------------------------------------------";
	set_xy(50, 19);
	cout << "=========================================================";

	set_xy(60, 20);
	cout << "Gunakan Arrow Key untuk memilih menu";

	for (int i = 9; i < 19; ++i) {
		set_xy(50, i);
		cout << "|" << endl;
	}
	for (int i = 9; i < 19; ++i) {
		set_xy(106, i);
		cout << "|" << endl;
	}
}

void ifc_sub() {
	for (int i = 15; i <= 140; ++i) {
		set_xy(i, 5);
		cout << "---------------";
	}
	for (int i = 15; i <= 140; ++i) {
		set_xy(i, 35);
		cout << "---------------";
	}
	for (int i = 6; i < 35; ++i) {
		set_xy(21, i);
		cout << "|" << endl;
	}
	for (int i = 6; i < 35; ++i) {
		set_xy(148, i);
		cout << "|" << endl;
	}
	set_xy(76, 36);
	cout << "Masukan 0 untuk Kembali";
	set_xy(65, 9);
	cout << "=======================================";
}