#include <iostream> 
#include <string>

using namespace std;

int saldoAwal = 1000000;
int rekening[3] = {111, 222, 333};
string jumlahRiwayat[10];

void transfer() {
    int nomorRekening;
    int jumlahUangTransfer;

    cout << "\n===  TRANSFER  ===\n";
    cout << "Masukkan ID rekening tujuan: ";
    cin >> nomorRekening;

    bool ketemuAkun = false;

    for (int i = 0; i < 3; i++) {
        if (rekening[1] == nomorRekening) {
            ketemuAkun = true;
        }
    }

    if (!ketemuAkun) {
        cout << "Rekening tidak ditemukan." << endl;
        return; 
    }

    cout << "Masukkan jumlah transfer: Rp ";
    cin >> jumlahUangTransfer;

    if (jumlahUangTransfer <= 0) {
        cout << "Jumlah tidak boleh 0 atau negatif." << endl;
    } else if (jumlahUangTransfer > saldoAwal) {
        cout << "Saldo tidak mencukupi." << endl;
    } else {
        saldoAwal -= jumlahUangTransfer;
        cout << "Transfer berhasil ke rekening " << nomorRekening << ". Saldo sekarang: Rp " << saldoAwal << endl;
    }
}

int main() {

    transfer();
    return 0;
}