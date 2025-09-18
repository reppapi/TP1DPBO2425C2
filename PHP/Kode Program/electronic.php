<?php
// Class Electronic mewakili data barang elektronik
class Electronic {
    private $id;         // ID unik barang
    private $name;       // Nama barang
    private $type;       // Jenis barang (TV, Laptop, dll)
    private $price;      // Harga barang
    private $imagePath;  // Path atau URL gambar

    // Constructor
    // Dipanggil saat objek dibuat, langsung isi semua atribut
    public function __construct($id, $name, $type, $price, $imagePath) {
        $this->id = $id;
        $this->name = $name;
        $this->type = $type;
        $this->price = $price;
        $this->imagePath = $imagePath;
    }

    // Getter (ambil data)
    public function getId() { return $this->id; }
    public function getName() { return $this->name; }
    public function getType() { return $this->type; }
    public function getPrice() { return $this->price; }
    public function getImagePath() { return $this->imagePath; }

    // Setter (ubah data)
    public function setName($name) { $this->name = $name; }
    public function setType($type) { $this->type = $type; }
    public function setPrice($price) { $this->price = $price; }
    public function setImagePath($imagePath) { $this->imagePath = $imagePath; }
}
?>
