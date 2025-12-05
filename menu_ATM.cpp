#include <iostream>
using namespace std;

int pilih;
bool ngulang = true;

int main () {
while (ngulang) {
        cout << "\n=== Menu ATM ===" << endl;
        cout << "1. Cek Saldo" << endl;
        cout << "2. Tarik Tunai" << endl;
        cout << "3. Setor Tunai" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Riwayat Transaksi" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Cek saldo";
                break;
            case 2:
                cout << "Tarik tunai";
                break;
            case 3:
                cout << "Setor tunai";
                break;
            case 4:
                cout << "Transfer";
                break;
            case 5:
                cout << "Riwayat transaksi";
                break;
            case 6:
                cout << "Terima kasih telah menggunakan ATM." << endl;
                ngulang = false; 
                break;

            default:
                cout << "Menu tidak tersedia." << endl;
        }
    }
    return 0;
}