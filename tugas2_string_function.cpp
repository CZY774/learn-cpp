#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <conio.h>
#include <limits>

std::string username, password;

void takePassword(char pwd[50]) {
    int i = 0;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r' || ch == '\t') {
            pwd[i] = '\0';
            break;
        } else if (ch == '\b') {
            if (i > 0) {
                i--;
                std::cout << "\b \b";
            }
        } else {
            pwd[i++] = ch;
            std::cout << "* \b";
        }
    }
}

bool signin() {
    std::cout << "Sign In" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Membersihkan buffer input

    std::cout << "Password: ";
    char tempPassword[50];
    takePassword(tempPassword);
    password = tempPassword;
    std::cout << std::endl;
    return true;
}

bool login() {
    std::string inputUsername;
    char inputPassword[50];
    std::cout << "Login" << std::endl;
    std::cout << "Username: ";
    std::cin >> inputUsername;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Membersihkan buffer input

    std::cout << "Password: ";
    takePassword(inputPassword);

    if (inputUsername == username && std::string(inputPassword) == password) {
        std::cout << "Login berhasil!" << std::endl;
        return true;
    } else {
        std::cout << "Username atau password salah!" << std::endl;
        return false;
    }
}

int main() {
    char choice;
    bool isLoggedIn = false;

    do {
        system("cls");
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Sign In" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Pilihan: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Membersihkan buffer input

        switch (choice) {
            case '1':
                system("cls");
                isLoggedIn = signin();
                if (isLoggedIn) {
                    std::cout << "Sign In berhasil!" << std::endl;
                }
                system("pause");
                break;
            case '2':
                system("cls");
                if (isLoggedIn) {
                    isLoggedIn = login();
                    system("pause");
                } else {
                    std::cout << "Anda harus Sign In terlebih dahulu!" << std::endl;
                    system("pause");
                }
                break;
            case '3':
                std::cout << "Terima kasih telah menggunakan program ini." << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid!" << std::endl;
                system("pause");
        }
    } while (choice != '3');

    return 0;
}