// #include <iostream>

// // Fungsi rekursif untuk menghitung faktorial
// int faktorial(int n) {
//     // Basis kasus: jika n <= 1, faktorial dari n adalah 1
//     if (n <= 1) {
//         return 1;
//     } else {
//         // Rekurens: n! = n * (n-1)!
//         return n * faktorial(n - 1);
//     }
// }

// int main() {
//     int angka;
//     std::cout << "Masukkan sebuah angka: ";
//     std::cin >> angka;

//     int hasil = faktorial(angka);
//     std::cout << "Faktorial dari " << angka << " adalah " << hasil << std::endl;

//     return 0;
// }


// // Rekursi Langsung
// #include <iostream>
// using namespace std;

// int faktorial(int n) {
//     if (n <= 1) {
//         return 1; // kondisi dasar
//     }
//     return n * faktorial(n - 1); // panggilan rekursi
// }

// int main() {
//     int n = 5;
//     cout << "Faktorial dari " << n << " adalah " << faktorial(n) << endl;
//     return 0;
// }


// // Rekursi Kepala/Head
// #include <iostream>
// using namespace std;

// void cetakBilangan(int n) {
//     if (n == 0) {
//         return; // kondisi dasar
//     }
//     cetakBilangan(n - 1); // panggilan rekursi
//     cout << n << " "; // operasi setelah panggilan rekursi
// }

// int main() {
//     int n = 5;
//     cetakBilangan(n);
//     return 0;
// }


// // Rekursi Ekor
// #include <iostream>
// using namespace std;

// void cetakBilangan(int n) {
//     if (n == 0) {
//         return; // kondisi dasar
//     }
//     cout << n << " "; // operasi sebelum panggilan rekursi
//     cetakBilangan(n - 1); // panggilan rekursi
// }

// int main() {
//     int n = 5;
//     cetakBilangan(n);
//     return 0;
// }


// // Rekursi Pohon
// #include <iostream>
// using namespace std;

// int fibonacci(int n) {
//     if (n <= 1) {
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int main() {
//     int n = 5;
//     for (int i = 0; i < n; i++) {
//         cout << fibonacci(i) << " ";
//     }
//     return 0;
// }


// Rekursi Tidak Langsung
#include <iostream>
using namespace std;

void fungsiB(int n);

void fungsiA(int n) {
    if (n <= 0) {
        return;
    }
    cout << "A: " << n << endl;
    fungsiB(n - 1);
}

void fungsiB(int n) {
    if (n <= 0) {
        return;
    }
    cout << "B: " << n << endl;
    fungsiA(n / 2);
}

int main() {
    int n = 20;
    fungsiA(n);
    return 0;
}
