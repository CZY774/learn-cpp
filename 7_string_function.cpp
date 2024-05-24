#include <iostream>
#include <string>

int main() {
    // Deklarasi string
    std::string str1 = "Hello";
    std::string str2 = "World";
    
    // 1. Panjang String
    std::cout << "1. Panjang str1: " << str1.length() << std::endl;
    std::cout << "   Panjang str2: " << str2.size() << std::endl;
    
    // 2. Mengakses Karakter
    std::cout << "2. Karakter pertama dari str1: " << str1[0] << std::endl;
    std::cout << "   Karakter terakhir dari str1: " << str1[str1.length() - 1] << std::endl;
    
    // 3. Menambahkan (append) dan Menggabungkan (concate) String
    str1.append(" ");
    str1 += str2;  // Sama dengan str1 = str1 + str2;
    std::cout << "3. str1 setelah ditambahkan dan digabungkan: " << str1 << std::endl;
    
    // 4. Perbandingan String
    std::string str3 = "Apple";
    std::string str4 = "Apple";
    if (str3 == str4) {
        std::cout << "4. str3 sama dengan str4" << std::endl;
    } else {
        std::cout << "4. str3 tidak sama dengan str4" << std::endl;
    }

    // 5. Substring
    std::string substr = str1.substr(6, 5);  // Mengambil substring mulai dari indeks 6 sebanyak 5 karakter
    std::cout << "5. Substring dari str1: " << substr << std::endl;
    
    // 6. Pencarian
    size_t found = str1.find("Halo");
    if (found != std::string::npos) {
        std::cout << "6. 'Halo' ditemukan di indeks: " << found << std::endl;
    } else {
        std::cout << "6. 'Halo' tidak ditemukan" << std::endl;
    }

    // 7. Modifikasi String
    str1.replace(6, 5, "Everyone");  // Mengganti 'World' dengan 'Everyone'
    std::cout << "7. str1 setelah dimodifikasi: " << str1 << std::endl;
    
    // 8. Konversi
    int num = 123;
    std::string str_num = std::to_string(num);  // Mengkonversi integer ke string
    std::cout << "8. Angka yang dikonversi ke string: " << str_num << std::endl;

    return 0;
}
