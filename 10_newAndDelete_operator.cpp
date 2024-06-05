// NEW & DELETE OPERATOR

#include <iostream>

int main() {
    int n, i;
    int* ptr;

    std::cout << "Masukkan jumlah elemen array: ";
    std::cin >> n;

    // Mengalokasikan memori dinamis untuk array menggunakan operator new
    ptr = new int[n];

    // Jika alokasi gagal, operator new akan melempar pengecualian bad_alloc
    // Periksa ptr nullptr tidak diperlukan karena new akan melempar pengecualian jika gagal

    // Mengisi elemen array
    std::cout << "Masukkan elemen array: " << std::endl;
    for (i = 0; i < n; i++) {
        std::cin >> ptr[i];
    }

    // Menampilkan elemen array
    std::cout << "Elemen array: " << std::endl;
    for (i = 0; i < n; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    // Membebaskan memori yang dialokasikan menggunakan operator delete
    delete[] ptr;

    return 0;
}
