```cpp
#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double s) {
        namaNasabah = nama;
        saldo = s;
    }

    // Pure Virtual Function
    virtual void potongAdmin() = 0;

    void tampilkanSaldo() {
        cout << "Nasabah : " << namaNasabah << endl;
        cout << "Saldo   : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

// Kelas Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin() override {
        cout << "\n[Rekening Syariah]" << endl;
        cout << "Tidak ada potongan biaya admin." << endl;
    }
};

// Kelas Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin() override {
        cout << "\n[Rekening Konvensional]" << endl;
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 telah dipotong." << endl;
    }
};

// Kelas Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin() override {
        cout << "\n[Rekening Premium]" << endl;

        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 telah dipotong." << endl;
        }
    }
};

int main() {

    // Array pointer ke abstract class
    RekeningBank* rekening[3];

    rekening[0] = new RekeningSyariah("Andi", 5000000);
    rekening[1] = new RekeningKonvensional("Budi", 3000000);
    rekening[2] = new RekeningPremium("Citra", 8000000);

    // Proses potong admin
    for (int i = 0; i < 3; i++) {
        rekening[i]->potongAdmin();
        rekening[i]->tampilkanSaldo();
        cout << "------------------------" << endl;
    }

    // Hapus memori
    for (int i = 0; i < 3; i++) {
        delete rekening[i];
    }

    return 0;
}
```
