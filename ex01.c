#include <stdio.h>
#include <stdlib.h>

typedef struct cliente {
    char* nome;
    char* cpf;
    float valorPagar;
} Cliente;

typedef struct Item {
    Cliente valor;
    struct Item* proximo;
} Item;

typedef struct Fila {
    Item *primeiro;
    Item *ultimo;
    int tamanho;
} Fila;

Fila fila = {NULL,  NULL, 0};

Item* criarItem(Cliente valor) {
    Item* novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

void enfileirar(Cliente valor) {
    Item* novoItem = criarItem(valor);

    if (fila.primeiro == NULL) {
        fila.primeiro = novoItem;
        fila.ultimo = novoItem;
    } else {
        fila.ultimo->proximo = novoItem;
        fila.ultimo = novoItem;
    }

    fila.tamanho ++;
}

void exibirFila() {
    Item* item = fila.primeiro;
    while (item != NULL) {
        Cliente cliente = item->valor;
        printf("Cliente: %s \n", cliente.nome);
        printf("CPF: %s \n", cliente.cpf);
        printf("Valor a pagar: %.2f \n", cliente.valorPagar);
        printf("------\n");

        item = item->proximo;
    }
}

void desenfileirar() {
    Item* itemRemover = fila.primeiro;
    fila.primeiro = itemRemover->proximo;
    fila.tamanho --;
    printf("Desenfileirado -> %s \n------\n", itemRemover->valor.nome);

    free(itemRemover);
}

int main() {
    Cliente c1 = { "Joao", "10000000001", 1000};
    Cliente c2 = { "Maria", "20000000002", 2000};
    Cliente c3 = { "Pedro", "30000000003", 3000};
    Cliente c4 = { "Paulo", "40000000004", 4000};
    Cliente c5 = { "Lucia", "50000000005", 5000};

    enfileirar(c1);
    enfileirar(c2);
    enfileirar(c3);
    enfileirar(c4);
    enfileirar(c5);

    exibirFila();

    desenfileirar();
    exibirFila();

    desenfileirar();
    exibirFila();

    desenfileirar();
    exibirFila();

    return 0;
}
