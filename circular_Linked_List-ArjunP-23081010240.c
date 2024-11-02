#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);

void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void jumlahkanData(node *head);

//========================================================

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Hitung jumlah data\n");
        printf("9. Jumlahkan seluruh data\n");
        printf("0. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        switch(pilih) {
            case '1':
                tambahAwal(&head);
                break;
            case '2':
                tambahData(&head);
                break;
            case '3':
                tambahAkhir(&head);
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
                getch();
                break;
            case 'q':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    } while (pilih != 'q');
    
    return 0;
}

//========================================================

void tambahAwal(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            pNew->next = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pNew->next = *head;
            pCur->next = pNew;
        }
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    pCur = *head;
    do {
        if (pCur->data == pos) break;
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur->data != pos) {
        printf("\nNode tidak ditemukan");
        getch();
        return;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
        return;
    }

    pNew->data = bil;
    pNew->next = pCur->next;
    pCur->next = pNew;
}

//========================================================

void tranverse(node *head){
    node *pWalker;

    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    pWalker = head;
    do {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    } while (pWalker != head);
    printf("Head (Circular)\n");
}

//========================================================

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            pNew->next = pNew;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head){
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
        free(pDel);
        printf("Data di awal telah dihapus.\n");
    }
    getch();
}

//========================================================

void hapusTengah(node **head){
    int bil;
    node *pCur, *pDel;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan nilai yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong!\n");
    } else {
        pCur = *head;
        if (pCur->data == bil) {
            hapusAwal(head);
        } else {
            do {
                if (pCur->next->data == bil) break;
                pCur = pCur->next;
            } while (pCur != *head);

            if (pCur->next->data != bil) {
                printf("Data tidak ditemukan!\n");
            } else {
                pDel = pCur->next;
                pCur->next = pDel->next;
                free(pDel);
                printf("Data di tengah telah dihapus.\n");
            }
        }
    }
    getch();
}

//========================================================

void hapusAkhir(node **head){
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
        free(pDel);
        printf("Data di akhir telah dihapus.\n");
    }
    getch();
}

//========================================================

void cariData(node *head){
    int bil;
    node *pCur = head;
    int found = 0;

    if (head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    system("cls");
    printf("Masukkan data yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    do {
        if (pCur->data == bil) {
            printf("Data %d ditemukan di linked list!\n", bil);
            found = 1;
            break;
        }
        pCur = pCur->next;
    } while (pCur != head);

    if (!found) {
        printf("Data %d tidak ditemukan di linked list.\n", bil);
    }
    getch();
}

//========================================================

void hitungData(node *head){
    int count = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("Jumlah data di linked list: 0\n");
        getch();
        return;
    }

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Jumlah data di linked list: %d\n", count);
    getch();
}

//========================================================

void jumlahkanData(node *head){
    int sum = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("Jumlah total data di linked list: 0\n");
        getch();
        return;
    }

    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != head);

    printf("Jumlah total data di linked list: %d\n", sum);
    getch();
}
