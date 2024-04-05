#include <iostream>

int main(){
    int i=10;
    /* FOR -> ada inisialisasi, sampai keberapa, mau increment atau decrement*/
    for (i=0; i<=5; i++) {
        std::cout << "Nilai i adalah: " << i << std::endl;
    }

    /* WHILE -> kalau false tidak akan dieksekusi*/
    // while (i<5) {
    //     std::cout << "Nilai i adalah: " << i << std::endl;
    //     i++;
    // }

    /* DO-WHILE -> false sekalipun dieksekusi setidaknya 1 kali, karena awalnya do*/
    // do {
    //     std::cout << "Nilai i adalah: " << i << std::endl;
    //     i++;
    // } while (i<5);
}