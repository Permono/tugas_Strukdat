#include <stdio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahAkhir(node **head);
void tambahTengah(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void jumlahkanData(node *head);
void tranverse(node *head);

//========================================================

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di akhir\n");
        printf("3. Tambah data di tengah\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Hitung jumlah data\n");
        printf("9. Jumlahkan seluruh data\n");
        printf("0. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        
        scanf(" %c", &pilih);

        switch(pilih) {
            case '1':
                tambahAwal(&head);
                break;
            case '2':
                tambahAkhir(&head);
                break;
            case '3':
                tambahTengah(&head);  
                break;
            case '4':
                hapusAwal(&head);
                break;
            case '5':
                hapusTengah(&head);
                break;
            case '6':
                hapusAkhir(&head);
                break;
            case '7':
                cariData(head);
                break;
            case '8':
                hitungData(head);
                break;
            case '9':
                jumlahkanData(head);
                break;
            case '0':
                tranverse(head);
                break;
            case 'q':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

        if (pilih != 'q') {
            printf("\nTekan Enter untuk melanjutkan...");
            getchar(); 
            getchar(); 
        }
    } while (pilih != 'q');
    
    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew, *pCur;

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pNew->next = *head;
            pNew->prev = pCur;
            (*head)->prev = pNew;
            pCur->next = pNew;
            *head = pNew;
        }
        printf("Data berhasil ditambahkan di awal.\n");
    } else {
        printf("Alokasi memori gagal\n");
    }
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->prev = pCur;
            pNew->next = *head;
            (*head)->prev = pNew;
        }
        printf("Data berhasil ditambahkan di akhir.\n");
    } else {
        printf("Alokasi memori gagal\n");
    }
}

//========================================================

void tambahTengah(node **head) {
    int bil, setelah;
    node *pNew, *pCur;

    if (*head == NULL) {
        printf("List kosong! Menambahkan data di awal.\n");
        tambahAwal(head);
        return;
    }

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    printf("Masukkan nilai setelah data mana yang akan ditambahkan: ");
    scanf("%d", &setelah);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;

        pCur = *head;
        do {
            if (pCur->data == setelah) {
                pNew->next = pCur->next;
                pNew->prev = pCur;
                pCur->next->prev = pNew;
                pCur->next = pNew;
                printf("Data berhasil ditambahkan di tengah.\n");
                return;
            }
            pCur = pCur->next;
        } while (pCur != *head);

        printf("Data %d tidak ditemukan di list!\n", setelah);
        free(pNew);
    } else {
        printf("Alokasi memori gagal\n");
    }
}

//========================================================

void tranverse(node *head) {
    node *pWalker;

    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    pWalker = head;
    do {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        if (pWalker != head) printf("<-> ");
    } while (pWalker != head);
    printf(" (Head Circular)\n");
}

//========================================================

void hapusAwal(node **head) {
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong!\n");
    } else if ((*head)->next == *head) {
        pDel = *head;
        *head = NULL;
        free(pDel);
        printf("Data di awal telah dihapus.\n");
    } else {
        pCur = *head;
        while (pCur->next != *head) {
            pCur = pCur->next;
        }
        pDel = *head;
        *head = (*head)->next;
        pCur->next = *head;
        (*head)->prev = pCur;
        free(pDel);
        printf("Data di awal telah dihapus.\n");
    }
}

//========================================================

void hapusAkhir(node **head) {
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong!\n");
    } else if ((*head)->next == *head) {
        pDel = *head;
        *head = NULL;
        free(pDel);
        printf("Data di akhir telah dihapus.\n");
    } else {
        pCur = *head;
        while (pCur->next->next != *head) {
            pCur = pCur->next;
        }
        pDel = pCur->next;
        pCur->next = *head;
        (*head)->prev = pCur;
        free(pDel);
        printf("Data di akhir telah dihapus.\n");
    }
}

//========================================================

void hapusTengah(node **head) {
    int bil;
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong!\n");
        return;
    }

    printf("Masukkan nilai yang ingin dihapus: ");
    scanf("%d", &bil);

    pCur = *head;
    do {
        if (pCur->next->data == bil) {
            pDel = pCur->next;
            pCur->next = pDel->next;
            pDel->next->prev = pCur;
            free(pDel);
            printf("Data di tengah telah dihapus.\n");
            return;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Data tidak ditemukan!\n");
}

//========================================================

void cariData(node *head) {
    int bil, found = 0;
    node *pCur;

    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    pCur = head;
    do {
        if (pCur->data == bil) {
            found = 1;
            break;
        }
        pCur = pCur->next;
    } while (pCur != head);

    if (found)
        printf("Data %d ditemukan.\n", bil);
    else
        printf("Data tidak ditemukan.\n");
}

//========================================================

void hitungData(node *head) {
    int count = 0;
    node *pCur;

    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    pCur = head;
    do {
        count++;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Jumlah data: %d\n", count);
}

//========================================================

void jumlahkanData(node *head) {
    int sum = 0;
    node *pCur;

    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    pCur = head;
    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Jumlah seluruh data: %d\n", sum);
}
