#include <iostream>     //operasi i/o pada terminal
#include <string>       //menyediakan kelas string, implementasi dari string c++
#include <vector>       //menyediakan kelas vector, implementasi dari array dinamis
#include <algorithm>    //menyediakan berbagai algoritma: sorting, searching, dsb
#include <cmath>        //fungsi matematika: trigonometri, logaritma, dll
#include <fstream>      //melakukan operasi i/o pada file
#include <iomanip>      //memanipulasi output seperti mengatur presisi, lebar, dll
// #include <cstdio>
// using namespace std; sebisa mungkin dihindari karena mengurangi readability sm konflik nama jika ada nama yang sama di dalam namespace lain atau di dalam kode

int main() {
    // int a=5, b=7;
    // int hasil=a+b;
    // std::cout<<hasil;

    // char nama;       gabisa ambil setelah spasi
    std::string nama;   //solusinya pake std::string
    int angka;
    std::cout << "Masukkan nama Anda: ";        // operator << namanya insertion, mengirim output ke stream
    std::getline(std::cin, nama);               // operator >> namanya extraction, mengambil input dari stream & disimpan dalam variabel
    std::cout << "Masukkan sebuah angka: ";     
    std::cin >> angka;                          
    // std::cout << "Nama Anda adalah " << nama;
    // std::cout << " dan angka yang Anda masukkan adalah: " << angka;
    // std::cout << " Maka nilainya adalah ";
    std::cout << std::endl << "Nama Anda adalah " << nama << std::endl << "Angka yang Anda masukkan adalah: " << angka << std::endl << "Maka nilainya adalah ";
    if (angka >= 90) {
        std::cout << "Nilai A" << std::endl;
    } else if (angka >= 80) {
        std::cout << "Nilai B" << std::endl;
    } else if (angka >= 70) {
        std::cout << "Nilai C" << std::endl;
    } else if (angka >= 60) {
        std::cout << "Nilai D" << std::endl;
    } else {
        std::cout << "Nilai E" << std::endl;
    }


    // // switch case sama kaya di c
    // switch (ekspresi) {
    // case nilai1:
    //     // kode yang akan dieksekusi jika ekspresi sama dengan nilai1
    //     break;
    // case nilai2:
    //     // kode yang akan dieksekusi jika ekspresi sama dengan nilai2
    //     break;
    // // ... dan seterusnya
    // default:
    //     // kode yang akan dieksekusi jika ekspresi tidak sama dengan semua nilai di atas
    // }
}