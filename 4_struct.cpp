#include <iostream>

struct Mahasiswa {  // mendefinisikan struct utk nyimpan data mhs
    std::string nama;
    int usia;
    double ipk;
};

int main () {
    Mahasiswa mhs1; // memanggil objek dri struct Mahasiswa
    std::cout << "Masukkan nama Anda: ";
    std::getline(std::cin, mhs1.nama);
    std::cout << "Masukkan usia Anda: ";
    std::cin >> mhs1.usia;
    std::cout << "Masukkan IPK Anda: ";
    std::cin >> mhs1.ipk;

    std::cout << "Nama Anda adalah : " << mhs1.nama << std::endl;
    std::cout << "Usia Anda  : " << mhs1.usia << " tahun" << std::endl;
    std::cout << "IPK Anda : " << mhs1.ipk << std::endl;
    
    return 0;
}

// #include <iostream>
// #include <string>

// struct Mahasiswa {
//     std::string nama;
//     float nim;
//     std::string alamat;
//     std::string hobi;
//     double ipk;
// };

// int main() {
//     // Deklarasi struct Mahasiswa 2 Dimensi
//     Mahasiswa kelas[2][3];
//     int baris = 0, kolom = 0;
//     char lanjut;

//     // Mengisi data pada struct Mahasiswa
//     int counter = 1;
//     while (true) {
//         std::cout << "Masukkan data mahasiswa " << counter << " (Ketik 'y' untuk lanjut, 'n' untuk berhenti): " << std::endl;
//         std::cout << "Nama: ";
//         std::getline(std::cin, kelas[baris][kolom].nama);
//         std::cout << "NIM: ";
//         std::cin >> kelas[baris][kolom].nim;
//         std::cin.ignore(); // Mengabaikan newline character
//         std::cout << "Alamat: ";
//         std::getline(std::cin, kelas[baris][kolom].alamat);
//         std::cout << "Hobi: ";
//         std::getline(std::cin, kelas[baris][kolom].hobi);
//         std::cout << "IPK: ";
//         std::cin >> kelas[baris][kolom].ipk;
//         std::cin.ignore(); // Mengabaikan newline character

//         std::cout << "Lanjut (y/n)? ";
//         std::cin >> lanjut;
//         std::cin.ignore(); // Mengabaikan newline character

//         if (lanjut == 'n') break;
//         kolom++;
//         if (kolom >= 3) {
//             kolom = 0;
//             baris++;
//             if (baris >= 2) baris = 0;
//         }
//         counter++;
//     }

//     // Mencetak data pada struct Mahasiswa
//     std::cout << "Data Mahasiswa:" << std::endl;
//     int counterMahasiswa = 1;
//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (!kelas[i][j].nama.empty()) {
//                 std::cout << "Mahasiswa " << counterMahasiswa << ":" << std::endl;
//                 std::cout << "Nama: " << kelas[i][j].nama << std::endl;
//                 std::cout << "NIM: " << kelas[i][j].nim << std::endl;
//                 std::cout << "Alamat: " << kelas[i][j].alamat << std::endl;
//                 std::cout << "Hobi: " << kelas[i][j].hobi << std::endl;
//                 std::cout << "IPK: " << kelas[i][j].ipk << std::endl;
//                 std::cout << std::endl;
//                 counterMahasiswa++;
//             }
//         }
//     }

//     return 0;
// }