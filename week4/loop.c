/*
1. Yang benar B
2. A : Untuk For Loop sudah Benar. Tetapi untuk While loop, variabel i belum terdeklarasi pada while dan tidak ada increment pada i. variabel i pada for dan while berbeda scopenya sehingga i yang ada di for tidak akan terbaca di while
B : Untuk For Loop sudah benar karena deklarasi i, condition, dan increment sudah lengkap. Untuk Do While Loop sudah benar karena variabel i sudah di deklarasikan dan ada increment
C : Untuk While Loop kurang tepat karena tidak ada increment pada i sehingga akan menyebabkan infinite loop (i<LENGTH tidak akan pernah terpenuhi). Hal tersebut berlaku sama pada Do While Loop 
*/

/*
(1) Reputition statement (Loop) yang paling sesuai untuk membuat interactive UI adalah do-while. Ini memungkinkan program untuk pertama kali menampilkan UI dan kemudian menunggu input pengguna. Setelah pengguna selesai dengan tindakan tertentu, program dapat memeriksa apakah pengguna ingin melanjutkan atau keluar dari aplikasi
(2) Selection statement yang paling sesuai untuk membuat Menu-based UI adalah switch. Ini memungkinkan Anda untuk menggantikan pilihan menu berdasarkan nilai yang diberikan oleh pengguna, yang membuat kode menjadi lebih terstruktur dan mudah dibaca
(3) getch adalah yang memberikan responsivitas paling baik. getch adalah fungsi non-standar yang biasanya tersedia di sebagian besar kompiler C untuk membaca karakter dari keyboard tanpa menunggu penekanan tombol Enter.
*/

#include <stdio.h>
#include <conio.h> // Include header untuk getch (hanya bekerja di OS windows)

void add() {
    printf("Fungsi Add sedang dipanggil...\n");
}

void view() {
    printf("Fungsi View sedang dipanggil...\n");
}

void delete() {
    printf("Fungsi Delete sedang dipanggil...\n");
}

void update() {
    printf("Fungsi Update sedang dipanggil...\n");
}

void search() {
    printf("Fungsi Search sedang dipanggil...\n");
}

int main() {
    char choice;
    do {
        printf("Menu\n");
        printf("1. Add\n");
        printf("2. View\n");
        printf("3. Delete\n");
        printf("4. Update\n");
        printf("5. Search\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        choice = getch(); // Menggunakan getch untuk membaca input karakter tanpa perlu klik 'Enter'
        switch (choice) {
            case '1':
                // Panggil fungsi Add
                add();
                break;
            case '2':
                // Panggil fungsi View
                view();
                break;
            case '3':
                // Panggil fungsi Delete
                delete();
                break;
            case '4':
                // Panggil fungsi Update
                update();
                break;
            case '5':
                // Panggil fungsi Search
                search();
                break;
            case '6':
                printf("Terima kasih, keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    } while (choice != '6');

    return 0;
}
