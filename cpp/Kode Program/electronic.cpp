#include <iostream>
#include <string>
using namespace std;

// Kelas Electronic mewakili barang elektronik
class Electronic {
private:
    // Atribut / data member (hanya bisa diakses lewat method)
    int id;             // ID unik barang
    string name;        // Nama barang
    string type;        // Jenis barang (TV, Laptop, dll)
    double price;       // Harga barang
    string imagePath;   // Path atau URL gambar

public:
    // Constructor → dipanggil saat objek baru dibuat
    Electronic(int id, string name, string type, double price, string imagePath) {
        this->id = id;
        this->name = name;
        this->type = type;
        this->price = price;
        this->imagePath = imagePath;
    }

    // Constructor default
    Electronic() {
        this->id = 0;
        this->name = "";
        this->type = "";
        this->price = 0.0;
        this->imagePath = "";
    }

    // Getter → untuk mengakses nilai atribut (karena private)
    int getId() { return id; }
    string getName() { return name; }
    string getType() { return type; }
    double getPrice() { return price; }
    string getImagePath() { return imagePath; }

    // Setter → untuk mengubah nilai atribut
    void setName(string n) { name = n; }
    void setType(string t) { type = t; }
    void setPrice(double p) { price = p; }
    void setImagePath(string img) { imagePath = img; }

    // Destructor → dipanggil otomatis saat objek dihancurkan
    // (kosong di sini karena nggak ada resource khusus yang perlu dibersihkan)
    ~Electronic() {}
};