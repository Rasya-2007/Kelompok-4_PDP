#include <iostream> 
using namespace std;

int saldoAwal = 1000000;
int minimalPenarikan = 50000;

void tarikTunai () {
    double jumlahUang;
    cout << "Masukkan jumlah penarikan: Rp. ";
    cin >> jumlahUang;     

    if (jumlahUang <= 0) {
        cout << "Jumlah tidak boleh 0 atau negatif." << endl;
    } else if (jumlahUang < minimalPenarikan) {
        cout << "Minimal penarikan adalah Rp " << minimalPenarikan << endl;
    } else if (jumlahUang > saldoAwal) {
        cout << "Saldo tidak mencukupi." << endl;
    } else {
        saldoAwal -= jumlahUang;
        cout << "Penarikan berhasil, Saldo sekarang: Rp " << saldoAwal << endl;
    }
}

int main() {
    
    tarikTunai();
    return 0;
}
