#include <stdio.h>
// #include <conio.h> // Include header untuk getch (hanya bekerja di OS windows)
#include <stdlib.h>

void clearscr(void)
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

void add()
{
    char choice;
    do
    {
        printf("Fungsi Add sedang dipanggil...\n\n\n");
        printf("Ketik 9 untuk kembali ke Menu Utama\n");
        printf("Masukan pilihan anda: ");
        // choice = getch()
        gets(&choice);

        if (choice != '9')
        {
            printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
        else
        {
            break;
        }
    } while (choice != '9');
}

void view()
{
    char choice;
    do
    {
        printf("Fungsi View sedang dipanggil...\n");
        printf("Ketik 9 untuk kembali ke Menu Utama\n");
        printf("Masukan pilihan anda: ");
        // choice = getch()
        gets(&choice);

        if (choice != '9')
        {
            printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
        else
        {
            break;
        }
    } while (choice != '9');
}

void delete()
{
    char choice;
    do
    {
        printf("Fungsi Delete sedang dipanggil...\n");
        printf("Ketik 9 untuk kembali ke Menu Utama\n");
        printf("Masukan pilihan anda: ");
        // choice = getch()
        gets(&choice);

        if (choice != '9')
        {
            printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
        else
        {
            break;
        }
    } while (choice != '9');
}

void update()
{
    char choice;
    do
    {
        printf("Fungsi Update sedang dipanggil...\n");
        printf("Ketik 9 untuk kembali ke Menu Utama\n");
        printf("Masukan pilihan anda: ");
        // choice = getch()
        gets(&choice);

        if (choice != '9')
        {
            printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
        else
        {
            break;
        }
    } while (choice != '9');
}

void search()
{
    char choice;
    do
    {
        printf("Fungsi Search sedang dipanggil...\n");
        printf("Ketik 9 untuk kembali ke Menu Utama\n");
        printf("Masukan pilihan anda: ");
        // choice = getch()
        gets(&choice);

        if (choice != '9')
        {
            printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
        else
        {
            break;
        }
    } while (choice != '9');
}

int main()
{
    clearscr(); // membersihkan layar dengan menyesuaikan OS Device

    char choice;
    do
    {
        printf("\nMENU\n");
        printf("   1. Add\n");
        printf("   2. View\n");
        printf("   3. Delete\n");
        printf("   4. Update\n");
        printf("   5. Search\n");
        printf("   6. Quit\n");
        printf("Masukan pilihan anda: ");
        // choice = getch(); // Menggunakan getch untuk membaca input karakter tanpa perlu klik 'Enter'
        gets(&choice); // Menggunakan getchar karena laptop saya macbook (ada issue tidak bisa menjalankan getch di mac os)
        switch (choice)
        {
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
            delete ();
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
