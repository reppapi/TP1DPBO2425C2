#include <iostream>
#include <iomanip>
#include "electronic.cpp" // Ini file class Electronic, tempat atribut & method tiap barang ada
using namespace std;

// Array buat nyimpen data barang
Electronic barang[1000]; // Bisa nampung sampai 1000 barang
int jumlahData = 0;      // Buat ngitung berapa barang yang udah dimasukin
int idBerikutnya = 1;    // ID unik buat tiap barang, otomatis naik tiap tambah

// Fungsi buat nambah barang baru
void tambahBarang() {
    if (jumlahData >= 1000) { // Kalau array penuh
        cout << "Sudah penuh!\n";
        return;
    }

    string nama, jenis, gambar;
    double harga;

    cout << "Nama barang   : ";
    cin.ignore(); // Buat ngebersihin buffer biar getline nggak kelewat input sebelumnya
    getline(cin, nama); // Input nama

    cout << "Jenis barang  : ";
    getline(cin, jenis); // Input jenis barang

    cout << "Harga         : ";
    cin >> harga; // Input harga

    cout << "Path gambar   : ";
    cin.ignore(); // Bersihin buffer lagi
    getline(cin, gambar); // Input path gambar

    // Simpen data ke array
    barang[jumlahData] = Electronic(idBerikutnya, nama, jenis, harga, gambar);
    jumlahData++;   // Tambah counter
    idBerikutnya++; // Tambah ID buat barang berikutnya
    cout << "Data berhasil ditambahkan!\n";
}

// Fungsi buat liat semua barang
void lihatSemua() {
    if (jumlahData == 0) { // Kalau belum ada barang
        cout << "Belum ada data.\n";
        return;
    }

    cout << "\nDaftar Barang:\n";
    cout << "===============================================\n";
    for (int i = 0; i < jumlahData; i++) { // Loop tiap barang
        cout << "ID: " << barang[i].getId() << endl;
        cout << "Nama: " << barang[i].getName() << endl;
        cout << "Jenis: " << barang[i].getType() << endl;
        cout << "Harga: Rp " << barang[i].getPrice() << endl;
        cout << "Gambar: " << barang[i].getImagePath() << endl;
        cout << "-----------------------------------------------\n";
    }
}

// Fungsi buat ubah data barang
void ubahBarang() {
    int cariId;
    cout << "Masukkan ID barang yang mau diubah: ";
    cin >> cariId;

    for (int i = 0; i < jumlahData; i++) {
        if (barang[i].getId() == cariId) { // Kalau ketemu ID-nya
            string nama, jenis, gambar;
            double harga;

            cout << "Nama baru   : ";
            cin.ignore();
            getline(cin, nama);

            cout << "Jenis baru  : ";
            getline(cin, jenis);

            cout << "Harga baru  : ";
            cin >> harga;

            cout << "Path gambar baru : ";
            cin.ignore();
            getline(cin, gambar);

            // Update data barang
            barang[i].setName(nama);
            barang[i].setType(jenis);
            barang[i].setPrice(harga);
            barang[i].setImagePath(gambar);

            cout << "Data berhasil diubah!\n";
            return;
        }
    }
    cout << "ID tidak ditemukan.\n"; // Kalau nggak ketemu ID
}

// Fungsi buat hapus barang
void hapusBarang() {
    int cariId;
    cout << "Masukkan ID barang yang mau dihapus: ";
    cin >> cariId;

    for (int i = 0; i < jumlahData; i++) {
        if (barang[i].getId() == cariId) { // Kalau ketemu ID
            for (int j = i; j < jumlahData - 1; j++) { // Geser semua barang setelahnya ke kiri
                barang[j] = barang[j + 1];
            }
            jumlahData--; // Kurangi jumlah data
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }
    cout << "ID tidak ditemukan.\n";
}

// Fungsi buat cari barang berdasarkan ID
void cariBarang() {
    int cariId;
    cout << "Masukkan ID barang yang dicari: ";
    cin >> cariId;

    for (int i = 0; i < jumlahData; i++) {
        if (barang[i].getId() == cariId) { // Kalau ketemu
            cout << "\nData ditemukan:\n";
            cout << "ID: " << barang[i].getId() << endl;
            cout << "Nama: " << barang[i].getName() << endl;
            cout << "Jenis: " << barang[i].getType() << endl;
            cout << "Harga: Rp " << barang[i].getPrice() << endl;
            cout << "Gambar: " << barang[i].getImagePath() << endl;
            return;
        }
    }
    cout << "ID tidak ditemukan.\n"; // Kalau nggak ketemu
}

// Fungsi utama
int main() {
    int pilihan;

    while (true) { // Loop menu
        cout << "\n=== TOKO ELEKTRONIK ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Lihat Semua Barang\n";
        cout << "3. Ubah Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Cari Barang\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) tambahBarang();
        else if (pilihan == 2) lihatSemua();
        else if (pilihan == 3) ubahBarang();
        else if (pilihan == 4) hapusBarang();
        else if (pilihan == 5) cariBarang();
        else if (pilihan == 0) break; // Keluar
        else cout << "Pilihan salah!\n";
    }

    cout << "Program selesai.\n";
    return 0;
}
