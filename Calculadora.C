#include <stdio.h>
#include <stdlib.h>

float menu(int m, float a, float b, int *erro);
int metodo_de_calculo();
float ler_numero();
float dividir(int *erro, float a, float b);

int main() {
    float pri, seg, resultado;
    int m, erro = 1;

    pri = ler_numero();
    seg = ler_numero();

    while (erro == 1) {
        m = metodo_de_calculo();
        resultado = menu(m, pri, seg, &erro);
    }
    if (erro == 2) {
        printf("Resultado: Erro de calculo, divisoes por 0 sao matematicamente impossiveis.");
        return 0;
    }

    printf("Resultado: %.2f", resultado);
    return 0;
};

float menu(int m, float a, float b, int *erro) {
    float r = 0;
    *erro = 0;

    switch (m) {
        case 1: r = a + b; break;
        case 2: r = a - b; break;
        case 3: r = dividir(erro, a, b); break;
        case 4: r = a * b; break;
        default:
            printf("opcao invalida\n");
            *erro = 1;
    }
    return r;
};

float dividir(int *erro, float a, float b){
    if (b == 0) {
        printf("Erro de calculo, fator b = 0.\n");
        *erro = 2;
        return 0;
    }
    return a / b;
}

int metodo_de_calculo() {
    int res;
    printf("qual o metodo?\n1-Soma\n2-Subtracao\n3-Divisao\n4-Multiplicacao\n");
    scanf("%d", &res);
    return res;
};

float ler_numero() {
    float num;
    printf("me diga um numero\n");
    scanf("%f", &num);
    return num;
};
