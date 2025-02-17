#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <regex>

struct PenjualanHarian {
    std::string hari;
    std::string nama;
    int jumlahTerjual;
};

const int MAX_PENJUALAN = 100;
PenjualanHarian penjualan[MAX_PENJUALAN];
int jumlahData = 0;

std::string hariArray[] = {"senin", "selasa", "rabu", "kamis", "jumat", "sabtu", "minggu"};
const std::regex hariRegex("^[a-z]+$");
const int MAX_JUMLAH_TERJUAL = 1000000;

void tampilMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "a. Memasukkan hari, nama, dan jumlah barang yang terjual" << std::endl;
    std::cout << "b. Mengedit data berdasarkan indeks" << std::endl;
    std::cout << "c. Tampilkan data penjualan" << std::endl;
    std::cout << "d. Rata-rata per hari" << std::endl;
    std::cout << "e. Keluar" << std::endl;
}

void simpanData() {
    std::ofstream file("tts.txt");
    if (file.is_open()) {
        file << jumlahData << std::endl;
        for (int i = 0; i < jumlahData; ++i) {
            file << penjualan[i].hari << " " << penjualan[i].nama << " " << penjualan[i].jumlahTerjual << std::endl;
        }
        file.close();
    } else {
        std::cout << "Gagal membuka file untuk menyimpan data" << std::endl;
    }
}

bool isNumber(const std::string& str) {
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void bacaData() {
    std::ifstream file("tts.txt");
    if (file.peek() != std::ifstream::traits_type::eof()) {
        file.close();
        std::cout << "Data lama terdeteksi, apakah Anda ingin membuat file baru? (y/n) ";
        char pilihan;
        std::cin >> pilihan;
        if (pilihan == 'y' || pilihan == 'Y') {
            jumlahData = 0;
            std::ofstream fileOut("tts.txt");
            fileOut.close();
        } else {
            file.open("tts.txt");
            file >> jumlahData;

            for (int i = 0; i < jumlahData; ++i) {
                file >> penjualan[i].hari >> penjualan[i].nama >> penjualan[i].jumlahTerjual;
                if (file.fail()) {
                    std::cout << "Error membaca data dari file" << std::endl;
                    break;
                }

                bool hariValid = false;
                for (const std::string& h : hariArray) {
                    if (penjualan[i].hari == h) {
                        hariValid = true;
                        break;
                    }
                }

                if (!hariValid) {
                    std::cout << "Data hari tidak valid untuk data ke-" << i + 1 << std::endl;
                    continue;
                }
            }

            file.close();
        }
    } else {
        std::cout << "Tidak ada data yang tersimpan" << std::endl;
        file.close();
    }
}

bool isInputValid(const std::string& input, const std::regex& regex) {
    return std::regex_match(input, regex);
}

void tambahPenjualan() {
    bacaData();

    std::string input;
    do {
        PenjualanHarian baru;
        std::cout << "Masukkan hari (0 untuk berhenti): ";
        std::cin >> input;
        if (input == "0") break;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input.empty()) {
            std::cout << "Input hari tidak boleh kosong" << std::endl;
            continue;
        }

        if (!isInputValid(input, hariRegex)) {
            std::cout << "Input hari hanya boleh berisi huruf" << std::endl;
            continue;
        }

        bool hariValid = false;
        for (const std::string& hari : hariArray) {
            if (input == hari) {
                baru.hari = input;
                hariValid = true;
                break;
            }
        }
        if (!hariValid) {
            std::cout << "Input hari tidak valid" << std::endl;
            continue;
        }

        std::cout << "Masukkan nama: ";
        std::cin.ignore();
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Input nama tidak boleh kosong" << std::endl;
            continue;
        }
        std::transform(input.begin(), input.end(), baru.nama.begin(), ::tolower);
        baru.nama = input;

        std::cout << "Masukkan jumlah barang terjual: ";
        std::cin >> input;
        if (!isNumber(input)) {
            std::cout << "Input jumlah barang terjual tidak valid" << std::endl;
            continue;
        }
        int jumlahTerjual = std::stoi(input);
        if (jumlahTerjual < 0 || jumlahTerjual > MAX_JUMLAH_TERJUAL) {
            std::cout << "Input jumlah barang terjual harus antara 0 dan " << MAX_JUMLAH_TERJUAL << std::endl;
            continue;
        }
        baru.jumlahTerjual = jumlahTerjual;

        bool dataSudahAda = false;
        for (int i = 0; i < jumlahData; ++i) {
            std::string namaLowerCase = penjualan[i].nama;
            std::transform(namaLowerCase.begin(), namaLowerCase.end(), namaLowerCase.begin(), ::tolower);
            std::string baruNamaLowerCase = baru.nama;
            std::transform(baruNamaLowerCase.begin(), baruNamaLowerCase.end(), baruNamaLowerCase.begin(), ::tolower);

            if (penjualan[i].hari == baru.hari && namaLowerCase == baruNamaLowerCase) {
                penjualan[i].jumlahTerjual += baru.jumlahTerjual;
                dataSudahAda = true;
                break;
            }
        }

        if (!dataSudahAda) {
            if (jumlahData < MAX_PENJUALAN) {
                penjualan[jumlahData++] = baru;
            } else {
                std::cout << "Kapasitas maksimum data tercapai" << std::endl;
                break;
            }
        }

        simpanData();
    } while (input != "0");
}

void editData() {
    int indeks;
    std::cout << "Masukkan indeks data yang ingin diubah: ";
    std::cin >> indeks;
    if (indeks < 0 || indeks >= jumlahData) {
        std::cout << "Indeks tidak valid" << std::endl;
        return;
   }

   PenjualanHarian& data = penjualan[indeks];

   std::cout << "Edit data:" << std::endl;
   std::cout << "1. Hari (" << data.hari << ")" << std::endl;
   std::cout << "2. Nama (" << data.nama << ")" << std::endl;
   std::cout << "3. Jumlah Barang Terjual (" << data.jumlahTerjual << ")" << std::endl;
   std::cout << "Masukkan pilihan (1-3): ";
   int pilihan;
   std::cin >> pilihan;

   if (pilihan == 1) {
       std::string input;
       std::cout << "Masukkan hari baru: ";
       std::cin >> input;
       std::transform(input.begin(), input.end(), input.begin(), ::tolower);

       if (input.empty()) {
           std::cout << "Input hari tidak boleh kosong" << std::endl;
           return;
       }

       if (!isInputValid(input, hariRegex)) {
           std::cout << "Input hari hanya boleh berisi huruf" << std::endl;
           return;
       }

       bool hariValid = false;
       for (const std::string& hari : hariArray) {
           if (input == hari) {
               data.hari = input;
               hariValid = true;
               break;
           }
       }
       if (!hariValid) {
           std::cout << "Input hari tidak valid" << std::endl;
           return;
       }
   } else if (pilihan == 2) {
       std::string input;
       std::cout << "Masukkan nama baru: ";
       std::cin.ignore();
       std::getline(std::cin, input);
       if (input.empty()) {
           std::cout << "Input nama tidak boleh kosong" << std::endl;
           return;
       }
       std::transform(input.begin(), input.end(), data.nama.begin(), ::tolower);
       data.nama = input;
   } else if (pilihan == 3) {
       std::string input;
       std::cout << "Masukkan jumlah barang terjual baru: ";
       std::cin >> input;
       if (!isNumber(input)) {
           std::cout << "Input jumlah barang terjual tidak valid" << std::endl;
           return;
       }
       int jumlahTerjual = std::stoi(input);
       if (jumlahTerjual < 0 || jumlahTerjual > MAX_JUMLAH_TERJUAL) {
           std::cout << "Input jumlah barang terjual harus antara 0 dan " << MAX_JUMLAH_TERJUAL << std::endl;
           return;
       }
       data.jumlahTerjual = jumlahTerjual;
   } else {
      std::cout << "Pilihan tidak valid" << std::endl;
      return;
  }

  simpanData();
}

void tampilkanPenjualan() {
  if (jumlahData == 0) {
      std::cout << "Data tidak ada" << std::endl;
      return;
  }

  std::cout << "------------------------------------------------------------------------------------" << std::endl;
  std::cout << "| Indeks |    Hari    |    Nama    | Jumlah Terjual |" << std::endl;
  std::cout << "------------------------------------------------------------------------------------" << std::endl;

  for (int i = 0; i < jumlahData; ++i) {
      std::cout << "|" << std::setw(8) << i << " | " << std::setw(11) << penjualan[i].hari << " | " << std::setw(11) << penjualan[i].nama << " | " << std::setw(15) << penjualan[i].jumlahTerjual << " |" << std::endl;
  }

  std::cout << "------------------------------------------------------------------------------------" << std::endl;
}

void hitungRataRata() {
  int total[7] = {0};
  int count[7] = {0};

  for (int i = 0; i < jumlahData; ++i) {
      for (int j = 0; j < 7; ++j) {
          if (penjualan[i].hari == hariArray[j]) {
              total[j] += penjualan[i].jumlahTerjual;
              count[j]++;
              break;
          }
      }
  }

  std::cout << "Rata-rata Penjualan per Hari:" << std::endl;
  for (int i = 0; i < 7; ++i) {
      if (count[i] > 0) {
          std::cout << hariArray[i] << ": " << (double)total[i] / count[i] << std::endl;
      }
  }
}

int main() {
    bacaData();
    char pilihan;
    do {
        system("cls");
        tampilMenu();
        std::cout << std::endl << "Masukkan pilihan: ";
        std::cin >> pilihan;
        switch (pilihan) {
            case 'a':
                tambahPenjualan();
                break;
            case 'b':
                editData();
                break;
            case 'c':
                tampilkanPenjualan();
                break;
            case 'd':
                hitungRataRata();
                break;
            case 'e':
                simpanData();
                break;
            default:
                std::cout << "Pilihan tidak valid" << std::endl;
        }
        std::cout << "Tekan Enter untuk melanjutkan...";
        std::cin.ignore();
        std::cin.get();
    } while (pilihan != 'e');
    return 0;
}