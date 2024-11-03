#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

struct stack {
    node *top;
    int count;
};
typedef struct stack stack;

void createStack(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
void push(stack *s, int value);
int pop(stack *s);
int stackTop(stack *s);
int stackCount(stack *s);
void destroyStack(stack *s);

int main() {
    stack s;
    int pilihan, data;

    createStack(&s);

    do {
        system("cls");
        printf("Operasi Stack:\n");
        printf("1. Push (Tambah Data)\n");
        printf("2. Pop (Hapus Data)\n");
        printf("3. Stack Top (Lihat Data Teratas)\n");
        printf("4. Cek Apakah Stack Kosong\n");
        printf("5. Cek Apakah Stack Penuh\n");
        printf("6. Hitung Jumlah Data dalam Stack\n");
        printf("7. Destroy Stack\n");
        printf("8. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (!isFull(&s)) {
                    printf("Masukkan data yang ingin di-push: ");
                    scanf("%d", &data);
                    push(&s, data);
                } else {
                    printf("Stack penuh! Tidak bisa menambah data.\n");
                }
                break;
            case 2:
                if (!isEmpty(&s)) {
                    printf("Data yang di-pop: %d\n", pop(&s));
                } else {
                    printf("Stack kosong!\n");
                }
                break;
            case 3:
                if (!isEmpty(&s)) {
                    printf("Data teratas: %d\n", stackTop(&s));
                } else {
                    printf("Stack kosong!\n");
                }
                break;
            case 4:
                if (isEmpty(&s)) {
                    printf("Stack kosong\n");
                } else {
                    printf("Stack tidak kosong\n");
                }
                break;
            case 5:
                if (isFull(&s)) {
                    printf("Stack penuh\n");
                } else {
                    printf("Stack tidak penuh\n");
                }
                break;
            case 6:
                printf("Jumlah data dalam stack: %d\n", stackCount(&s));
                break;
            case 7:
                destroyStack(&s);
                printf("Stack telah dikosongkan.\n");
                break;
            case 8:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
        printf("Tekan sembarang tombol untuk melanjutkan...\n");
        getchar(); getchar();
    } while (pilihan != 8);

    return 0;
}

void createStack(stack *s) {
    s->top = NULL;
    s->count = 0;
}

int isEmpty(stack *s) {
    return s->top == NULL;
}

int isFull(stack *s) {
    return s->count == MAX_STACK_SIZE;
}

void push(stack *s, int value) {
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    printf("Data %d telah ditambahkan ke stack\n", value);
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
        return -1;
    }
    node *temp = s->top;
    int removedData = temp->data;
    s->top = temp->next;
    free(temp);
    s->count--;
    return removedData;
}

int stackTop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong!\n");
        return -1;
    }
    return s->top->data;
}

int stackCount(stack *s) {
    return s->count;
}

void destroyStack(stack *s) {
    node *temp;
    while (s->top != NULL) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
    s->count = 0;
}

