# TP1DPBO2425C2
tugas praktikum 1 Desain dan Pemrograman Berorientasi Objek

## Janji
- Saya Repa Pitriani dengan NIM 2402499 mengerjakan Tugas Praktikum 1
dalam mata kuliah Desain dan Pemograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

## Desain Program


### CLASS Electronic
```
CLASS Electronic
│
├── ATTRIBUTES (Private)
│ ├── id: int (identifier unik)
│ ├── name: string (nama produk)
│ ├── type: string (kategori elektronik)
│ ├── price: double (harga satuan)
│ └── imagePath: string (URL/path gambar)
│
├── CONSTRUCTOR
│ └── Electronic(id, name, type, price, imagePath)
│
├── GETTER METHODS
│ ├── getId(): int
│ ├── getName(): string
│ ├── getType(): string
│ ├── getPrice(): double
│ └── getImagePath(): string
│
└── SETTER METHODS
├── setName(name: string): void
├── setType(type: string): void
├── setPrice(price: double): void
└── setImagePath(imagePath: string): void
```

## Alur Program
1. **Inisialisasi:** Siapkan array/list untuk inventaris dan ID awal.  
2. **Menu Utama:** Loop menampilkan opsi: Tambah Data, Tampilkan Semua Data, Update Data, Hapus Data, Cari Data, Keluar.  
3. **Input Pengguna:** Pilih menu (angka 0-5).  
4. **Proses Pilihan:**  
   - **Tambah Data:** Input detail → buat objek → simpan ke inventaris.  
   - **Tampilkan Semua Data:** Iterasi inventaris dan tampilkan.  
   - **Update Data:** Masukkan ID → update atribut jika ditemukan.  
   - **Hapus Data:** Masukkan ID → hapus jika ditemukan.  
   - **Cari Data:** Masukkan ID → tampilkan detail jika ditemukan.  
   - **Keluar:** Hentikan loop.  
5. **Pengulangan:** Setelah operasi selesai, kembali ke menu utama.

Di semua versi (C++, Java, Python, dan PHP), program dibagi menjadi dua bagian utama. File main berisi 
fungsi-fungsi inti seperti tambah, lihat, ubah, hapus, dan cari yang bertugas menangani logika program dan interaksi menu dengan pengguna. 
Sementara itu, file Electronic mendefinisikan class yang menjadi blueprint untuk setiap objek barang, lengkap dengan 
fungsi setter (seperti setName dan setPrice) untuk mengubah data privat secara aman.

Fitur pembeda utama terdapat pada versi PHP, yang menggunakan $_SESSION untuk menyimpan data inventaris.
Hal ini memberikan persistensi data selama sesi command-line berjalan, artinya data tidak akan hilang jika program
dijalankan beberapa kali dalam satu sesi terminal yang sama, berbeda dengan versi C++, Java, dan Python yang datanya 
akan ter-reset setiap kali program ditutup dan dibuka kembali.

![SS](Dokumentasi/ss/Screenshot%202025-09-18%20215617.png)

