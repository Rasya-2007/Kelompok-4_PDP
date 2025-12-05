#include <iostream> 
#include <string>

using namespace std;

int pin = 12345;
int saldoAwal = 1000000; 
int rekening[3] = {111, 222, 333};
string jumlahRiwayat[50];
int transaksi = 0;

// Fungsi pin
bool cekPin() { 
    int Kesempatan = 0;
    int inputPin;
    
    while (Kesempatan < 3) {
        cout << "===  LOGIN AKUN ATM  ===\n";
        cout << "Masukkan PIN: ";
        cin >> inputPin;
        
        if (inputPin == pin) {
            cout << "Login berhasil!" << endl;
            return true;
        } else {
            Kesempatan++;
            cout << "PIN salah, Kesempatan tersisa: " << (3 - Kesempatan) << endl;
        }
    }
    
    cout << "Akun anda diblokir. Program berhenti." << endl;
    return false;
}

// Fungsi cek saldo
void cekSaldo () {
    cout << "\n===  CEK SALDO  ===\n";
    cout << "Saldo Anda adalah: Rp " << saldoAwal << endl;
}

// Fungsi tarik tunai
void tarikTunai () {
    int minimalPenarikan = 50000;
    int jumlahUangPenarikan;

    cout << "\n===  TARIK TUNAI  ===\n";
    cout << "Masukkan jumlah penarikan: Rp. ";
    cin >> jumlahUangPenarikan;
                
    if (jumlahUangPenarikan <= 0) {
        cout << "Jumlah tidak boleh 0 atau negatif." << endl;
    } else if (jumlahUangPenarikan < minimalPenarikan) {
        cout << "Minimal penarikan adalah Rp " << minimalPenarikan << endl;
    } else if (jumlahUangPenarikan > saldoAwal) {
        cout << "Saldo tidak mencukupi." << endl;
    } else {
        saldoAwal -= jumlahUangPenarikan;
        jumlahRiwayat[transaksi] = "Melakukann tarik Tunai Rp." + to_string(jumlahUangPenarikan);
        transaksi++;
        cout << "Penarikan berhasil, Saldo sekarang: Rp " << saldoAwal << endl;
    }
}

// Fungsi setor tunai
void setorTunai() {
    int kelipatanSetoran = 10000;
    int jumlahUangSetoran;

    cout << "\n===  SETOR TUNAI  ===\n";
    cout << "Masukkan jumlah setoran: Rp. ";
    cin >> jumlahUangSetoran;
    
    if (jumlahUangSetoran <= 0) {
        cout << "Jumlah tidak boleh 0 atau negatif." << endl;
    } else if (jumlahUangSetoran % kelipatanSetoran != 0) {
        cout << "Jumlah harus kelipatan Rp " << kelipatanSetoran << endl;
    } else {
        saldoAwal += jumlahUangSetoran;
        jumlahRiwayat[transaksi] = "Melakukan setor tunai Rp. " + to_string(jumlahUangSetoran);
        transaksi++;
        cout << "Setor tunai berhasil. Saldo sekarang: Rp " << saldoAwal << endl;
    }
}

// Fungsi transfer
void transfer() {
    int nomorRekening;
    int jumlahUangTransfer;

    cout << "\n===  TRANSFER  ===\n";
    cout << "Masukkan ID rekening tujuan: ";
    cin >> nomorRekening;

    bool ketemuAkun = false;

    // Cek rekening apakah ada
    for (int i = 0; i < 3; i++) {
        if (rekening[i] == nomorRekening) {
            ketemuAkun = true;
        }
    }

    // Jika tidak ditemukan, langsung tampilkan pesan
    if (!ketemuAkun) {
        cout << "Rekening tidak ditemukan." << endl;
        return; // hentikan fungsi
    }

    cout << "Masukkan jumlah transfer: Rp ";
    cin >> jumlahUangTransfer;

    if (jumlahUangTransfer <= 0) {
        cout << "Jumlah tidak boleh 0 atau negatif." << endl;
    } else if (jumlahUangTransfer > saldoAwal) {
        cout << "Saldo tidak mencukupi." << endl;
    } else {
        saldoAwal -= jumlahUangTransfer;
        jumlahRiwayat[transaksi] = "Melakukan transfer Rp. " + to_string(jumlahUangTransfer) + " ke rekening " + to_string(nomorRekening);
        transaksi++;
        cout << "Transfer berhasil ke rekening " << nomorRekening << ". Saldo sekarang: Rp " << saldoAwal << endl;
    }
}

// Fungsi riwayat transaksi
void riwayatTransaksi(){
     cout << "\n=== RIWAYAT TRANSAKSI ===\n" << endl;
    
    if (transaksi == 0) {
        cout << "Belum ada transaksi" << endl;
    } else {
        for (int i = 0; i < transaksi; i++) {
            cout << (i + 1) << ". " << jumlahRiwayat[i] << endl;
        }
    }
}

int main() {
    int pilih;
    bool ngulang = true;

    if (!cekPin()) {
        return 0;
    }

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
                cekSaldo();
                break;

            case 2:
                tarikTunai();
                break;

            case 3:
                setorTunai();
                break;
            
            case 4:
                transfer();
                break;

            case 5:
                riwayatTransaksi();
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