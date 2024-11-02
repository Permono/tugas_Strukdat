#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MAHASISWA 100

typedef struct {
    char nama[20];
    char jenis_kelamin[20];
} mahasiswa;

typedef struct {
    mahasiswa data_list[MAX_MAHASISWA];
	int jumlah_mahasiswa; 
} dataMahasiswa;

int is_word(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;  
        }
    }
    return 1;  


void tambah_mahasiswa(dataMahasiswa *dataMahasiswa, char nama[], char jenis_kelamin[]) {
   
    for (int i = 0; i < dataMahasiswa->jumlah_mahasiswa; i++) {
        if (strcmp(dataMahasiswa->data_list[i].nama, nama) == 0) {
            printf("Data mahasiswa dengan nama %s sudah ada!\n", nama);
            return;
        }
    }
   
    strcpy(dataMahasiswa->data_list[dataMahasiswa->jumlah_mahasiswa].nama, nama);
    strcpy(dataMahasiswa->data_list[dataMahasiswa->jumlah_mahasiswa].jenis_kelamin, jenis_kelamin);
    dataMahasiswa->jumlah_mahasiswa++;
    printf("Data mahasiswa ditambahkan.\n");
}

void tampilkan_semua_mahasiswa(dataMahasiswa *dataMahasiswa) {
    if (dataMahasiswa->jumlah_mahasiswa == 0) {
        printf("Belum ada data mahasiswa.\n");
    } else {
        for (int i = 0; i < dataMahasiswa->jumlah_mahasiswa; i++) {
            printf("nama: %s, jenis Kelamin: %s,", 
                    dataMahasiswa->data_list[i].nama, 
                    dataMahasiswa->data_list[i].jenis_kelamin); 
        }
    }
}

void cari_mahasiswa(dataMahasiswa *dataMahasiswa, char keyword[]) {
    int ditemukan = 0;

    if (is_word(keyword)) {
        
        char nama = 0;
        sscanf(keyword, "%s", &nama);
        for (int i = 0; i < dataMahasiswa->jumlah_mahasiswa; i++) {
            if (dataMahasiswa->data_list[i].nama == nama) {
                printf("nama: %s, jenis Kelamin: %s", 
                        dataMahasiswa->data_list[i].nama, 
                        dataMahasiswa->data_list[i].jenis_kelamin), 
                ditemukan = 1;
            }
        }
    } else {
        
        for (int i = 0; i < dataMahasiswa->jumlah_mahasiswa; i++) {
            if (strstr(dataMahasiswa->data_list[i].nama, keyword) != NULL ||  
                strcmp(dataMahasiswa->data_list[i].jenis_kelamin, keyword) == 0) {
                printf("nama: %s, Jenis Kelamin: %s",
                        dataMahasiswa->data_list[i].nama, 
                        dataMahasiswa->data_list[i].jenis_kelamin); 
                ditemukan = 1;
            }
        }
    }

    if (!ditemukan) {
        printf("mahasiswa tidak ditemukan.\n");
    }
}

int main() {
    dataMahasiswa mahasiswa;
    mahasiswa.jumlah_mahasiswa = 0;

    int pilihan;
    char nama[50], jenis_kelamin[10], keyword[50];

    do {
        printf("\n1. Tambah mahasiswa \n");
        printf("2. Tampilkan semua Mahasiswa\n");
        printf("3. cari mahasiswa\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        getchar(); 

        switch (pilihan) {
            case 1:
                printf("Masukkan nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;  
                printf("Masukkan jenis Kelamin: ");
                fgets(jenis_kelamin, sizeof(jenis_kelamin), stdin);
                jenis_kelamin[strcspn(jenis_kelamin, "\n")] = 0;  
                tambah_mahasiswa(&mahasiswa, nama, jenis_kelamin);
                break;

            case 2:
                tampilkan_semua_mahasiswa(&mahasiswa);
                break;

            case 3:
                printf("Masukkan nama dan Jenis kelamin untuk mencari: ");
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = 0;  
                cari_mahasiswa(&mahasiswa, keyword);
                break;

            case 4:
                printf("program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 4);

    return 0;
}
}