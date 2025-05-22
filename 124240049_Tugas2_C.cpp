#include <iostream>
using namespace std;

struct pesanan {
  string nama;
  string roti;
  int harga;
  pesanan* next;
};


pesanan *depan, *belakang; pesanan *awal, *top;
void buatqueue() {
  depan = belakang = NULL;
}

int queuekosong() {
  return depan == NULL;
    
}


void ambilantrian (string nama, string roti, int harga) { // enqueue 
  pesanan *baru = new pesanan;
  baru->nama = nama;
  baru->roti = roti;
  baru->harga = harga;
  baru->next = NULL;

    if (queuekosong()) {
    depan = baru;
    } else {
    belakang->next = baru;
    }
    belakang = baru;
}

void layani() { // dequeue
    if (queuekosong()) {
        cout << "Queue kosong.\n";
    } else {     
        cout << "Sedang melayani pesanan atas nama: " 
        << depan->nama << " (" << depan->roti << ", Rp" << depan->harga << ")\n";
        
      pesanan *simpan = new pesanan;
      simpan->nama = depan->nama;
      simpan->roti = depan->roti;
      simpan->harga = depan->harga;
      simpan->next = NULL;

      if (awal == NULL) {
          awal = top = simpan;
      } else {
          top->next = simpan;
          top = simpan;
     }

      pesanan *hapus = depan;
      depan = depan->next;
      delete hapus;
    }
}

void cetakqueue() {
  pesanan *bantu = depan;
  if (bantu == NULL) {
      cout << "Antrian kosong\n";
      return;
  }
  cout << "Daftar Antrian:\n";
  while (bantu != NULL) {
     cout << "- " << bantu->nama << " | " << bantu->roti << " | Rp" << bantu->harga << endl;
     bantu = bantu->next;
    }
}

void batalkanpesanan() {
    if (queuekosong()) {
      cout << "Tidak ada pesanan yang dibatalkan\n";
      return;
    }
    pesanan *bantu = depan;
    pesanan *sebelum = NULL;

    while (bantu->next != NULL) {
        sebelum = bantu;
        bantu = bantu->next;
    }

    if (sebelum == NULL) {
        delete depan;
        depan = belakang = NULL;
    } else {
        delete bantu;
        sebelum->next = NULL;
        belakang = sebelum;
    }

    cout << "Pesanan terakhir berhasil dibatalkan\n";
}

void buatstack() {
    awal = top = NULL;
}

int stackkosong() {
    return awal == NULL;
}

void cetakstack() {
  pesanan *bantu = awal;
  if (stackkosong()) {
      cout << "History kosong\n";
      return;
  }
    cout << "History pesanan yang sudah dilayani:\n";
    while (bantu != NULL) {
        cout << "- " << bantu->nama << " | " << bantu->roti << " | Rp" << bantu->harga << endl;
        bantu = bantu->next;
    }
}



int main() {
    buatqueue();
    buatstack();

    int pilih;
    string nama, roti;
    int harga;

    do {
        cout << "\n=== TOKO ROTI MANIS LEZAT ===\n";
        cout << "1. Ambil Antrian\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Batalkan Pesanan\n"; 
        cout << "5. Tampilkan History Pesanan\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;

        switch(pilih) {
            case 1:
                cin.ignore();
                cout << "Nama Pembeli: ";
                getline(cin, nama);
                cout << "Jenis Roti : ";
                getline(cin, roti);
                cout << "Total Harga: ";
                cin >> harga;
                ambilantrian (nama, roti, harga);
                break; 
            case 2:
                layani();
                break;
            case 3:
                cetakqueue();
                break;
            case 4:
                batalkanpesanan();
                break;
            case 5:
               cetakstack();
                break;
            case 6:
                cout << "Terima kasih sudah menggunakan sistem.\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while(pilih != 6);

    return 0;
}
