#include <stdio.h>

int main()
{
    int m, n, p, q, c, d, k, sum = 0, check;

    // Input Matriks Pertama
    printf("Masukkan jumlah baris dan kolom matriks pertama: ");

    // Error check integer
    if (scanf("%d %d", &m, &n) < 2)
    {
        printf("Input harus angka\n");
        return 0;
    }

    int first[m][n];

    // Input Elemen elemen matriks pertama
    printf("Masukkan elemen-elemen matriks pertama:\n");

    for (c = 0; c < m; c++)
    {
        for (d = 0; d < n; d++)
        {
            // Error check integer
            if (scanf("%d", &first[c][d]) < 1)
            {
                printf("Input harus angka\n");
                return 0;
            }
        }
    }

    // Input Matriks Kedua
    printf("Masukkan jumlah baris dan kolom matriks kedua: ");

    // Error check integer
    if (scanf("%d %d", &p, &q) < 2)
    {
        printf("Input harus angka\n");
        return 0;
    }

    // Cek apakah jumlah kolom & baris matriks pertama dengan kedua sama (Error Check)
    if (n != p)
    {
        printf("Matriks pertama tidak dapat dikalikan dengan matriks kedua. Jumlah kolom pertama harus sama dengan jumlah baris kedua.\n");
    }
    else
    {
        int second[p][q];
        int multiply[m][q];

        // Input Elemen elemen matriks kedua
        printf("Masukkan elemen-elemen matriks kedua:\n");

        for (c = 0; c < p; c++)
        {
            for (d = 0; d < q; d++)
            {
                // Error check integer
                if (scanf("%d", &second[c][d]) < 1)
                {
                    printf("Input harus angka\n");
                    return 0;
                }
            }
        }

        // Proses perkalian
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < q; d++)
            {
                for (k = 0; k < p; k++)
                {
                    sum = sum + first[c][k] * second[k][d];
                }
                multiply[c][d] = sum;
                sum = 0;
            }
        }

        // Output hasil perkalian
        printf("Hasil perkalian matriks:\n");

        for (c = 0; c < m; c++)
        {
            for (d = 0; d < q; d++)
            {
                printf("%d\t", multiply[c][d]);
            }
            printf("\n");
        }
    }

    return 0;
}
