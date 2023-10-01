#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

// Function prototype untuk fungsi-fungsi dalam diagram
void GetDesignIdentityName(char* designName, char* entityName);
void ProduceDesignReports(char* entityName);
void CollateEntities(char* entityName);
void GenerateReport();

// Fungsi untuk mengambil pilihan menu dari user
int getChoice() {
    int choice;
    char inputSementara[100];

    do {
        printf("Masukkan pilihan menu: ");
        if (fgets(inputSementara, sizeof(inputSementara), stdin) != NULL) {
            if (isdigit(inputSementara[0])) {
                sscanf(inputSementara, "%d", &choice);
                if (choice >= 0 && choice <= 4) {
                    return choice;
                }
            }
        }
        printf("Pilihan tidak valid. Silakan pilih lagi.\n");
    } while (1);
}

int main() {
    int choice;
    char designName[100];
    char entityName[100];

    do {
        clearScreen(); // Membersihkan layar konsol

        // Menampilkan menu interaktif
        printf("Menu Layanan Biro Design:\n\n");
        printf("\t1. Dapatkan Nama Identitas Desain\n");
        printf("\t2. Hasilkan Laporan Desain\n");
        printf("\t3. Kumpulkan Entitas\n");
        printf("\t4. Hasilkan Laporan\n");
        printf("\t5. Keluar\n\n");

        choice = getChoice();

        switch (choice) {
            case 1:
                printf("Masukkan nama desain: ");
                fgets(designName, sizeof(designName), stdin);
                designName[strcspn(designName, "\n")] = '\0';
                printf("Masukkan nama entitas: ");
                fgets(entityName, sizeof(entityName), stdin);
                entityName[strcspn(entityName, "\n")] = '\0'; 
                GetDesignIdentityName(designName, entityName);
                break;
            case 2:
                printf("Masukkan nama entitas: ");
                fgets(entityName, sizeof(entityName), stdin);
                entityName[strcspn(entityName, "\n")] = '\0'; 
                ProduceDesignReports(entityName);
                break;
            case 3:
                printf("Masukkan nama entitas: ");
                fgets(entityName, sizeof(entityName), stdin);
                entityName[strcspn(entityName, "\n")] = '\0'; 
                CollateEntities(entityName);
                break;
            case 4:
                GenerateReport();
                break;
            case 5:
                printf("Terima kasih telah menggunakan layanan kami.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
      printf("\nTekan 'Enter' untuk melanjutkan...");
      while (getchar() != '\n');
    } while (choice != 5);

    return 0;
}

// Implementasi fungsi-fungsi dengan dummy
void GetDesignIdentityName(char* designName, char* entityName) {
    printf("Memanggil fungsi GetDesignIdentityName...\n");
    printf("Input: Nama Desain=%s, Nama Entitas=%s\n", designName, entityName);
}

void ProduceDesignReports(char* entityName) {
    printf("Memanggil fungsi ProduceDesignReports...\n");
    printf("Menggunakan: Nama Entitas=%s\n", entityName);
}

void CollateEntities(char* entityName) {
    printf("Memanggil fungsi CollateEntities...\n");
    printf("Menggunakan: Nama Entitas=%s\n", entityName);
}

void GenerateReport() {
    printf("Memanggil fungsi GenerateReport...\n");
}
