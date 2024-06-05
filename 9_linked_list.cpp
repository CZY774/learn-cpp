// LINKED LIST TAMBAH DEPAN, TENGAH, BELAKANG, SEARCH, DELETE

#include <iostream>

// Struktur untuk menyimpan data node
struct Node {
    int data;
    Node* next;
};

// Pointer untuk head node
Node* head = nullptr;

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan node di awal
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambahkan node di akhir
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Fungsi untuk menambahkan node di tengah
void insertAtMiddle(int value, int position) {
    Node* newNode = createNode(value);
    if (head == nullptr || position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Posisi tidak valid!" << std::endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk mencari node
void searchNode(int value) {
    Node* temp = head;
    int position = 1;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data == value) {
            std::cout << "Nilai " << value << " ditemukan pada posisi " << position << std::endl;
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }
    if (!found) {
        std::cout << "Nilai " << value << " tidak ditemukan dalam linked list" << std::endl;
    }
}

// Fungsi untuk menghapus node
void deleteNode(int value) {
    if (head == nullptr) {
        std::cout << "Linked list kosong!" << std::endl;
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout << "Nilai " << value << " berhasil dihapus" << std::endl;
        return;
    }
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            prev->next = current->next;
            delete current;
            std::cout << "Nilai " << value << " berhasil dihapus" << std::endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    std::cout << "Nilai " << value << " tidak ditemukan dalam linked list" << std::endl;
}

// Fungsi untuk menampilkan linked list
void printList() {
    Node* temp = head;
    if (temp == nullptr) {
        std::cout << "Linked list kosong!" << std::endl;
        return;
    }
    std::cout << "Linked List: ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Fungsi untuk menampilkan menu
void showMenu() {
    std::cout << "======= MENU =======" << std::endl;
    std::cout << "1. Tambah Node di Awal" << std::endl;
    std::cout << "2. Tambah Node di Akhir" << std::endl;
    std::cout << "3. Tambah Node di Tengah" << std::endl;
    std::cout << "4. Cari Node" << std::endl;
    std::cout << "5. Hapus Node" << std::endl;
    std::cout << "6. Tampilkan Linked List" << std::endl;
    std::cout << "7. Keluar" << std::endl;
    std::cout << "Masukkan pilihan: ";
}

int main() {
    int choice, value, position;
    do {
        showMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Masukkan nilai: ";
                std::cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                std::cout << "Masukkan nilai: ";
                std::cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                std::cout << "Masukkan nilai: ";
                std::cin >> value;
                std::cout << "Masukkan posisi: ";
                std::cin >> position;
                insertAtMiddle(value, position);
                break;
            case 4:
                std::cout << "Masukkan nilai yang dicari: ";
                std::cin >> value;
                searchNode(value);
                break;
            case 5:
                std::cout << "Masukkan nilai yang ingin dihapus: ";
                std::cin >> value;
                deleteNode(value);
                break;
            case 6:
                printList();
                break;
            case 7:
                std::cout << "Terima kasih!" << std::endl;
                break;
            default:
                std::cout << "Pilihan tidak valid!" << std::endl;
        }
    } while (choice != 7);
    return 0;
}
