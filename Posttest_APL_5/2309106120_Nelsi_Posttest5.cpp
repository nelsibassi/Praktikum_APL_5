#include <iostream>
#include <vector>

void showMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Tambahkan Data\n";
    std::cout << "2. Lihat Data\n";
    std::cout << "3. Ubah Data\n";
    std::cout << "4. Hapus Data\n";
    std::cout << "5. Keluar\n";
    std::cout << "Pilih menu (1-5): ";
}

void handleMenu(std::vector<std::pair<std::string, int>>* dataList) {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::pair<std::string, int> newData;
            std::string name;
            int taxID;
            std::cout << "Masukkan Nama: ";
            std::cin >> name;
            newData.first = name;
            std::cout << "Masukkan Nomor ID Pajak: ";
            std::cin >> taxID;
            newData.second = taxID;
            dataList->push_back(newData);
            break;
        }
        case 2: {
            if (dataList->empty()) {
                std::cout << "Data kosong.\n";
            } else {
                std::cout << "\nData Pajak:\n";
                for (const auto& data : *dataList) {
                    std::cout << "Nama: " << data.first << ", Nomor ID Pajak: " << data.second << "\n";
                }
            }
            break;
        }
        case 3: {
            int index;
            std::cout << "Masukkan indeks data yang ingin diubah: ";
            std::cin >> index;
            if (index >= 0 && index < dataList->size()) {
                std::string name;
                int taxID;
                std::cout << "Masukkan Nama baru: ";
                std::cin >> name;
                (*dataList)[index].first = name;
                std::cout << "Masukkan Nomor ID Pajak baru: ";
                std::cin >> taxID;
                (*dataList)[index].second = taxID;
            } else {
                std::cout << "Indeks tidak valid.\n";
            }
            break;
        }
        case 4: {
            int index;
            std::cout << "Masukkan indeks data yang ingin dihapus: ";
            std::cin >> index;
            if (index >= 0 && index < dataList->size()) {
                dataList->erase(dataList->begin() + index);
            } else {
                std::cout << "Indeks tidak valid.\n";
            }
            break;
        }
        case 5:
            std::cout << "Terima kasih!\n";
            return;
        default:
            std::cout << "Pilihan tidak valid.\n";
            break;
    }

    showMenu();
    handleMenu(dataList);
}

int main() {
    std::vector<std::pair<std::string, int>> dataList;
    std::string username, password;
    int attempts = 0;

    do {
        std::cout << "Masukkan Username: ";
        std::cin >> username;
        std::cout << "Masukkan Password: ";
        std::cin >> password;

        if (username != "admin" || password != "12345") {
            attempts++;
            std::cout << "Username atau password salah. Silakan coba lagi.\n";
        }
        if (attempts == 3) {
            std::cout << "Anda telah melebihi batas percobaan. Program berhenti.\n";
            return 0;
        }
    } while (username != "admin" || password != "12345");

    showMenu();
    handleMenu(&dataList);
    return 0;
}