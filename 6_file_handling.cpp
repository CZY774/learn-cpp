#include <iostream>
#include <fstream>  //library untuk filehandling
#include <string>

using namespace std;

// fungsi untuk membuat file
void createFile(){
    ofstream file("data.txt");  //buat file data.txt
    file.close();               //tutup file setelah dibuat
}

// fungsi untuk menulis file dengan input pengguna
void writeFile() {
    ofstream file("data.txt");
    string nama, nim;
    cout << "Masukkan nama: ";           //minta input dari user
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    file << "Nama: " << nama << endl;   //menulis data ke file
    file << "NIM: " << nim << endl;
    file.close();                       //tutup file
    cout << "Data telah ditulis ke dalam file" << endl;
}

// Membaca file
void readFile() {
    ifstream file("data.txt");
    string line;
    cout << "Isi file data.txt adalah: " << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Menghapus file
void deleteFile(){
    if (remove("data.txt") !=0 ){
        cout << "File tidak dapat dihapus" << endl;
    } else {
        cout << "File berhasil dihapus" << endl;
    }
}

int main (){
    // createFile();
    // writeFile();
    // readFile();
    deleteFile();
    return 0;
}