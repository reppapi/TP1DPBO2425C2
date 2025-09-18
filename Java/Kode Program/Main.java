import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static ArrayList<Electronic> inventory = new ArrayList<>();
    private static int nextId = 1;
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n============================");
            System.out.println("==* MENU TOKO ELEKTRONIK *==");
            System.out.println("============================");
            System.out.println("1. Tambah Data");
            System.out.println("2. Tampilkan Semua Data");
            System.out.println("3. Update Data");
            System.out.println("4. Hapus Data");
            System.out.println("5. Cari Data");
            System.out.println("0. Keluar");
            System.out.print("Pilih: ");
            choice = scanner.nextInt();

            switch (choice) {
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
                    System.out.println("Keluar program.");
                    break;
                default:
                    System.out.println("Pilihan tidak valid.");
            }
        } while (choice != 0);
    }

    // Tambah Data
    public static void addElectronic() {
        scanner.nextLine(); // buang newline

        System.out.print("Nama barang   : ");
        String name = scanner.nextLine();

        System.out.print("Jenis barang  : ");
        String type = scanner.nextLine();

        System.out.print("Harga         : ");
        double price = scanner.nextDouble();

        scanner.nextLine(); // buang newline
        System.out.print("Path gambar   : ");
        String imagePath = scanner.nextLine();

        Electronic e = new Electronic(nextId++, name, type, price, imagePath);
        inventory.add(e);
        System.out.println("Data berhasil ditambahkan!");
    }

    // Tampilkan Semua Data
    public static void showAll() {
        if (inventory.isEmpty()) {
            System.out.println("Data kosong.");
            return;
        }

        System.out.println("ID\tNama\t\tJenis\t\tHarga\t\tGambar");
        System.out.println("-------------------------------------------------------------");
        for (Electronic e : inventory) {
            System.out.println(e.getId() + "\t" + e.getName() + "\t\t" + 
                               e.getType() + "\t\tRp" + e.getPrice() + "\t\t" + 
                               e.getImagePath());
        }
    }

    // Update Data
    public static void updateElectronic() {
        System.out.print("Masukkan ID yang mau diupdate: ");
        int id = scanner.nextInt();

        for (Electronic e : inventory) {
            if (e.getId() == id) {
                scanner.nextLine(); // buang newline

                System.out.print("Nama baru   : ");
                e.setName(scanner.nextLine());

                System.out.print("Jenis baru  : ");
                e.setType(scanner.nextLine());

                System.out.print("Harga baru  : ");
                e.setPrice(scanner.nextDouble());

                scanner.nextLine(); // buang newline
                System.out.print("Path gambar baru : ");
                e.setImagePath(scanner.nextLine());

                System.out.println("Data berhasil diupdate!");
                return;
            }
        }
        System.out.println("ID tidak ditemukan.");
    }

    // Hapus Data
    public static void deleteElectronic() {
        System.out.print("Masukkan ID yang mau dihapus: ");
        int id = scanner.nextInt();

        for (int i = 0; i < inventory.size(); i++) {
            if (inventory.get(i).getId() == id) {
                inventory.remove(i);
                System.out.println("Data berhasil dihapus!");
                return;
            }
        }
        System.out.println("ID tidak ditemukan.");
    }

    // Cari Data
    public static void searchElectronic() {
        System.out.print("Masukkan ID yang dicari: ");
        int id = scanner.nextInt();

        for (Electronic e : inventory) {
            if (e.getId() == id) {
                System.out.println("ID: " + e.getId());
                System.out.println("Nama: " + e.getName());
                System.out.println("Jenis: " + e.getType());
                System.out.println("Harga: Rp" + e.getPrice());
                System.out.println("Gambar: " + e.getImagePath());
                return;
            }
        }
        System.out.println("ID tidak ditemukan.");
    }
}