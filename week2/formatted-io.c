#include <stdio.h>

int main() {
    int jumlahMahasiswa = 100;
    int hasilUjian[jumlahMahasiswa];
    char namaMahasiswa[jumlahMahasiswa][50]; // Menyimpan nama mahasiswa, dengan asumsi nama maksimal 50 karakter

    printf("\n=-=-=-=-=-= Program Input Nilai Mahasiswa Mata Kuliah Pengelolaan Bisnis Brokering Real-Estate =-=-=-=-=-=\n\n");

    // Input hasil ujian untuk setiap mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("Nama: ");
        scanf("%s", namaMahasiswa[i]);
        
        printf("Masukkan hasil (1: Lulus, 2: Gagal) untuk %s: ", namaMahasiswa[i]);
        scanf("%d", &hasilUjian[i]);
    }

    // Tampilkan nama masing-masing mahasiswa beserta hasil ujiannya
    printf("\nHasil Ujian Mahasiswa:\n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("%s: %s\n", namaMahasiswa[i], (hasilUjian[i] == 1) ? "Lulus" : "Gagal");
    }

    // Hitung jumlah kelulusan dan kegagalan
    int jumlahLulus = 0, jumlahGagal = 0;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (hasilUjian[i] == 1) {
            jumlahLulus++;
        } else {
            jumlahGagal++;
        }
    }

    // Tampilkan jumlah kelulusan dan pesan jika mencapai target
    printf("\nJumlah Kelulusan: %d\n", jumlahLulus);
    printf("Jumlah Kegagalan: %d\n", jumlahGagal);

    if (jumlahLulus > (0.8 * jumlahMahasiswa)) {
        printf("Kelulusan kelas telah mencapai target!\n");
    }

    return 0;
}
