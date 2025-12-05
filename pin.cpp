#include <iostream> 
using namespace std;

int pin = 12345; 

bool cekPin() { 
    int Kesempatan = 0;
    int inputPin;
    
    while (Kesempatan < 3) {
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

int main() {
    
    if (!cekPin()) {
        return 0; 
    }
    return 0;
}