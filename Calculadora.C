#include <stdio.h>
#include <stdlib.h>

float menu(int m, float a, float b, int *erro);
float perguntar(char *texto);
float dividir(int *erro, float a, float b);

int main() {
    float pri, seg, resultado ;
    int  metodo, erro = 1;

    pri = perguntar("Qual o primeiro numero?\n");
    seg = perguntar("Qual o segundo numero?\n");

    while (erro == 1) {
        metodo = perguntar_metodo("qual o metodo?\n1-Soma\n2-Subtracao\n3-Divisao\n4-Multiplicacao\n");
        resultado = menu(metodo, pri, seg, &erro);
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

float perguntar(char *texto) {
    float num;
    printf(texto);
    scanf("%f", &num);
    return num;
};

int perguntar_metodo(char *texto) {
    int m;
    printf("%s", texto);
    scanf("%d", &m);
    return m;
}
