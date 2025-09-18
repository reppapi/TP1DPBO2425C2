from Electronic import Electronic

inventory = []
next_id = 1

def add_electronic():
    global next_id
    name = input("Nama barang   : ")
    type = input("Jenis barang  : ")
    price = float(input("Harga         : "))
    image_path = input("Path gambar   : ")

    e = Electronic(next_id, name, type, price, image_path)
    inventory.append(e)
    next_id += 1
    print("Data berhasil ditambahkan!")

def show_all():
    if not inventory:
        print("Data kosong.")
        return

    print("ID\tNama\t\tJenis\t\tHarga\t\tGambar")
    print("-------------------------------------------------------------")
    for e in inventory:
        print(f"{e.get_id()}\t{e.get_name()}\t\t{e.get_type()}\t\tRp{e.get_price()}\t\t{e.get_image_path()}")

def update_electronic():
    try:
        id = int(input("Masukkan ID yang mau diupdate: "))
    except ValueError:
        print("ID harus angka.")
        return

    for e in inventory:
        if e.get_id() == id:
            e.set_name(input("Nama baru   : "))
            e.set_type(input("Jenis baru  : "))
            e.set_price(float(input("Harga baru  : ")))
            e.set_image_path(input("Path gambar baru : "))
            print("Data berhasil diupdate!")
            return

    print("ID tidak ditemukan.")

def delete_electronic():
    try:
        id = int(input("Masukkan ID yang mau dihapus: "))
    except ValueError:
        print("ID harus angka.")
        return

    for i, e in enumerate(inventory):
        if e.get_id() == id:
            del inventory[i]
            print("Data berhasil dihapus!")
            return

    print("ID tidak ditemukan.")

def search_electronic():
    try:
        id = int(input("Masukkan ID yang dicari: "))
    except ValueError:
        print("ID harus angka.")
        return

    for e in inventory:
        if e.get_id() == id:
            print(f"ID: {e.get_id()}")
            print(f"Nama: {e.get_name()}")
            print(f"Jenis: {e.get_type()}")
            print(f"Harga: Rp{e.get_price()}")
            print(f"Gambar: {e.get_image_path()}")
            return

    print("ID tidak ditemukan.")

def main():
    while True:
        print("\n============================")
        print("==* MENU TOKO ELEKTRONIK *==")
        print("============================")
        print("1. Tambah Data")
        print("2. Tampilkan Semua Data")
        print("3. Update Data")
        print("4. Hapus Data")
        print("5. Cari Data")
        print("0. Keluar")

        try:
            choice = int(input("Pilih: "))
        except ValueError:
            print("Pilihan harus angka.")
            continue

        if choice == 1:
            add_electronic()
        elif choice == 2:
            show_all()
        elif choice == 3:
            update_electronic()
        elif choice == 4:
            delete_electronic()
        elif choice == 5:
            search_electronic()
        elif choice == 0:
            print("Keluar program.")
            break
        else:
            print("Pilihan tidak valid.")

if __name__ == "__main__":
    main()