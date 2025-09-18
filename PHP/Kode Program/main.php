<?php
require_once "electronic.php";

// Inisialisasi data
session_start();
if (!isset($_SESSION['inventory'])) {
    $_SESSION['inventory'] = array();
    $_SESSION['nextId'] = 1;
}

$inventory = &$_SESSION['inventory'];
$nextId = &$_SESSION['nextId'];

// Fungsi-fungsi yang sama seperti di C++
function addElectronic() {
    global $inventory, $nextId;
    
    echo "Nama barang   : ";
    $name = trim(fgets(STDIN));
    
    echo "Jenis barang  : ";
    $type = trim(fgets(STDIN));
    
    echo "Harga         : ";
    $price = (float)trim(fgets(STDIN));
    
    echo "Path gambar   : ";
    $imagePath = trim(fgets(STDIN));

    $e = new Electronic($nextId++, $name, $type, $price, $imagePath);
    $inventory[] = $e;
    echo "Data berhasil ditambahkan!\n";
}

function showAll() {
    global $inventory;
    
    if (empty($inventory)) {
        echo "Data kosong.\n";
        return;
    }

    echo "ID\tNama\t\tJenis\t\tHarga\t\tGambar\n";
    echo "-------------------------------------------------------------\n";
    
    foreach ($inventory as $e) {
        printf("%d\t%s\t\t%s\t\tRp%.2f\t\t%s\n", 
               $e->getId(), 
               $e->getName(), 
               $e->getType(), 
               $e->getPrice(), 
               $e->getImagePath());
    }
}

function updateElectronic() {
    global $inventory;
    
    echo "Masukkan ID yang mau diupdate: ";
    $id = (int)trim(fgets(STDIN));

    foreach ($inventory as $e) {
        if ($e->getId() == $id) {
            echo "Nama baru   : ";
            $e->setName(trim(fgets(STDIN)));
            
            echo "Jenis baru  : ";
            $e->setType(trim(fgets(STDIN)));
            
            echo "Harga baru  : ";
            $e->setPrice((float)trim(fgets(STDIN)));
            
            echo "Path gambar baru : ";
            $e->setImagePath(trim(fgets(STDIN)));

            echo "Data berhasil diupdate!\n";
            return;
        }
    }
    echo "ID tidak ditemukan.\n";
}

function deleteElectronic() {
    global $inventory;
    
    echo "Masukkan ID yang mau dihapus: ";
    $id = (int)trim(fgets(STDIN));

    foreach ($inventory as $key => $e) {
        if ($e->getId() == $id) {
            unset($inventory[$key]);
            $inventory = array_values($inventory); // Re-index array
            echo "Data berhasil dihapus!\n";
            return;
        }
    }
    echo "ID tidak ditemukan.\n";
}

function searchElectronic() {
    global $inventory;
    
    echo "Masukkan ID yang dicari: ";
    $id = (int)trim(fgets(STDIN));

    foreach ($inventory as $e) {
        if ($e->getId() == $id) {
            echo "ID: " . $e->getId() . "\n";
            echo "Nama: " . $e->getName() . "\n";
            echo "Jenis: " . $e->getType() . "\n";
            echo "Harga: Rp" . $e->getPrice() . "\n";
            echo "Gambar: " . $e->getImagePath() . "\n";
            return;
        }
    }
    echo "ID tidak ditemukan.\n";
}

// Main program
function main() {
    do {
        echo "\n============================\n";
        echo "==* MENU TOKO ELEKTRONIK *==\n";
        echo "============================\n";
        echo "1. Tambah Data\n";
        echo "2. Tampilkan Semua Data\n";
        echo "3. Update Data\n";
        echo "4. Hapus Data\n";
        echo "5. Cari Data\n";
        echo "0. Keluar\n";
        echo "Pilih: ";
        
        $choice = (int)trim(fgets(STDIN));
        
        switch ($choice) {
            case 1:
                addElectronic();
                break;
            case 2:
                showAll();
                break;
            case 3:
                updateElectronic();
                break;
            case 4:
                deleteElectronic();
                break;
            case 5:
                searchElectronic();
                break;
            case 0:
                echo "Keluar program.\n";
                return;
            default:
                echo "Pilihan tidak valid.\n";
        }
    } while (true);
}

// Jalankan program
main();
?>