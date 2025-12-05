#include <iostream> 
using namespace std;

int saldoAwal = 1000000;
int minimalSetoran = 10000;

void setorTunai() {
    int jumlahUangSetoran;

    cout << "Masukkan jumlah setoran: Rp. ";
    cin >> jumlahUangSetoran;
    
    if (jumlahUangSetoran <= 0) {
        cout << "Jumlah tidak boleh 0 atau negatif" << endl;
    } else if (jumlahUangSetoran % minimalSetoran != 0) {
        cout << "Jumlah harus kelipatan Rp. " << minimalSetoran << endl;
    } else {
        saldoAwal += jumlahUangSetoran;
        cout << "Setor tunai berhasil, Saldo anda sekarang: Rp. " << saldoAwal << endl;
    }
}

int main() {

    setorTunai();
    return 0;
}