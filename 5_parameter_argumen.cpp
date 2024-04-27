#include <iostream>

int penjumlahan(int a, int b) {     // parameter
    int hasil = a + b;
    return hasil;
}

int main () {
    int bilangan1, bilangan2;
    std::cout << "Masukkan bilangan pertama: ";
    std::cin >> bilangan1;
    std::cout << "Masukkan bilangan kedua: ";
    std::cin >> bilangan2;

    int hasilPenjumlahan = penjumlahan(bilangan1, bilangan2);   //argumen
    std::cout << "Hasil penjumlahan dari " << bilangan1 << " + " << bilangan2 << " adalah " << hasilPenjumlahan << std::endl;
    return 0;
}