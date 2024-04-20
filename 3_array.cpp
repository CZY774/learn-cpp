#include <iostream>
#include <string>

int main() {
    // // ARRAY 1D
    // int arr[5];
    // arr[0] = 10;
    // arr[1] = 20;
    // arr[2] = 30;
    // arr[3] = 40;
    // arr[4] = 50;
    // std::cout << "Nilai array: " << std::endl;
    // for(int i = 0; i < 5; i++) {
    //     std::cout << arr[i] << " ";
    // }
    

    // // ARRAY 2D
    // int arr[2][3];
    // arr[0][0] = 1;
    // arr[0][1] = 2;
    // arr[0][2] = 3;
    // arr[1][0] = 4;
    // arr[1][1] = 5;
    // arr[1][2] = 6;
    // std::cout << "Nilai array: " << endl;
    // for(int i = 0; i < 2; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         std::cout << arr[i][j] << " ";
    //     }
    //     std::cout << endl;
    // }


    // // ARRAY 3D
    // int arr[2][2][2]; // Deklarasi array 3D dengan 2 lapis, 2 baris, dan 2 kolom
    // arr[0][0][0] = 1;
    // arr[0][0][1] = 2;
    // arr[0][1][0] = 3;
    // arr[0][1][1] = 4;
    // arr[1][0][0] = 5;
    // arr[1][0][1] = 6;
    // arr[1][1][0] = 7;
    // arr[1][1][1] = 8;
    // std::cout << "Nilai array: " << endl;
    // for(int i = 0; i < 2; i++) { // Perulangan untuk lapis
    //     for(int j = 0; j < 2; j++) { // Perulangan untuk baris
    //         for(int k = 0; k < 2; k++) { // Perulangan untuk kolom
    //             std::cout << arr[i][j][k] << " ";
    //         }
    //         std::cout << endl;
    //     }
    //     std::cout << endl;
    // }
    

    // GANTI ARRAY 1D
    int arr[5] = {10, 20, 30, 40, 50}, index, nilaiBaru;
        std::cout << "Masukkan indeks array: ";
        std::cin >> index;
    if (index >= 0 && index < 5) {
        std::cout << "Masukkan nilai array: ";
        std::cin >> nilaiBaru;
        arr[index]=nilaiBaru;
        std::cout << "Nilai array: " << std::endl;
        for(int i = 0; i < 5; i++) {
            std::cout << arr[i] << " ";
        }
    } else {
    std::cout << "Indeks tidak valid" << std::endl;
    }

    return 0;
}