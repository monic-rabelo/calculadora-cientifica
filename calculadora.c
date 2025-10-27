#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // fecha o bloco iniciado pelo #ifndef M_PI

#define MAX_HISTORICO 1000 // maximo de operacoes armazenadas no historico

typedef struct {
    int id;
    char tipo[40];
    double a;
    double b;
    double resultado;
} Operacao;

/* --------- Funcoes --------- */

/* Operações básicas */
double soma(double a, double b) { return a + b; }
double subtracao(double a, double b) { return a - b; }
double multiplicacao(double a, double b) { return a * b; }
double divisao(double a, double b, int *erro) {
    if (b == 0) { *erro = 1; return 0; }
    *erro = 0;
    return a / b;
}

/* Potência e raízes */
double potencia(double a, double b) {
    return pow(a, b);
}

double raiz_quadrada(double a, int *erro) {
    if (a < 0) { *erro = 1; return 0; }
    *erro = 0;
    return sqrt(a);
}
double raiz_cubica(double a) { return cbrt(a); }

/* Trigonometria (graus) */
double seno_graus(double graus) { return sin(graus * (M_PI / 180.0)); }
double cosseno_graus(double graus) { return cos(graus * (M_PI / 180.0)); }
double tangente_graus(double graus) { return tan(graus * (M_PI / 180.0)); }

/* Hiperbólicas */
double seno_hiper(double x) { return sinh(x); }
double cosseno_hiper(double x) { return cosh(x); }
double tangente_hiper(double x) { return tanh(x); }

/* Log e exponenciais */
double log_natural(double x, int *erro) {
    if (x <= 0) { *erro = 1; return 0; }
    *erro = 0;
    return log(x);
}
double log_base10(double x, int *erro) {
    if (x <= 0) { *erro = 1; return 0; }
    *erro = 0;
    return log10(x);
}
double exponencial(double x) { return exp(x); }
double potencia_de_10(double x) { return pow(10, x); }

/* Outros */
double modulo(double x) { return fabs(x); }

double fatorial(double n, int *erro) {
    if (n < 0 || floor(n) != n) { *erro = 1; return 0; }
    if (n > 20) { *erro = 2; return 0; } // limite para evitar overflow/ atingir a capacidade maxima
    *erro = 0;
    double res = 1;
    for (int i = 2; i <= (int)n; i++) res *= i;
    return res;
}

double valor_pi(void) { return M_PI; }
double inverso(double x, int *erro) {
    if (x == 0) { *erro = 1; return 0; }
    *erro = 0;
    return 1 / x;
}

/* Arredondar */
double arredondar_proximo(double x) { return round(x); }
double arredondar_baixo(double x) { return floor(x); }
double arredondar_cima(double x) { return ceil(x); }

/* Matrizes 2x2 */
void soma_matriz_2x2(double A[2][2], double B[2][2], double R[2][2]) { //2 por 2
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            R[i][j] = A[i][j] + B[i][j];
}
void multiplica_matriz_2x2(double A[2][2], double B[2][2], double R[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < 2; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

/* Media, maxima e minima */
double media (double a, double b) { return (a+b) / 2; }
double maxima(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
double minima(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

/* Histórico */
void imprimir_matriz_2x2(double M[2][2]) {
    printf("[ %g  %g ]\n[ %g  %g ]\n", M[0][0], M[0][1], M[1][0], M[1][1]);
}

void push_operacao(Operacao *arr, int *count, const char *tipo, double a, double b, double resultado) {
    if (*count >= MAX_HISTORICO) {
        printf("Limite de historico atingido (%d operacoes)\n", MAX_HISTORICO);
        return;
    }
    Operacao *op = &arr[*count];
    op -> id = (*count) + 1;
    strncpy(op->tipo, tipo, sizeof(op->tipo) - 1);
    op ->tipo[sizeof(op->tipo) - 1] = '\0';
    op -> a = a;
    op -> b = b;
    op -> resultado = resultado;
    (*count)++;
}

void exibir_historico(Operacao *arr, int count) {
    if (count == 0) {
        printf("Historico vazio.\n");
        return;
    }
    printf("\n----- Historico (%d operacoes) -----\n", count);
    for (int i = 0; i < count; i++) {
        printf("ID %d | %s | Numero 1 = %g", arr[i].id, arr[i].tipo, arr[i].a);
        if (strcmp(arr[i].tipo, "PI") != 0 &&
            strcmp(arr[i].tipo, "Raiz quadrada") != 0 &&
            strcmp(arr[i].tipo, "Raiz cubica") != 0 &&
            strcmp(arr[i].tipo, "Fatorial") != 0 &&
            strcmp(arr[i].tipo, "Seno hiper") != 0 &&
            strcmp(arr[i].tipo, "Cosseno hiper") != 0 &&
            strcmp(arr[i].tipo, "Tangente hiper") != 0 &&
            strcmp(arr[i].tipo, "Exponencial") != 0 &&
            strcmp(arr[i].tipo, "Potencia de 10") != 0) {
            printf(", Numero 2 = %g", arr[i].b);
        }
        printf(" => Resultado = %g\n", arr[i].resultado);
    }
    printf("------------------------------------\n");
}

/* ---------- Funcao principal ---------- */
int main() {
    Operacao *historico = malloc(MAX_HISTORICO * sizeof(Operacao));
    if (!historico) {
        fprintf(stderr, "Erro ao alocar memoria para historico.\n");
        return 1;
    }
    int hist_count = 0;
    int operacao;

    printf("\n--- Calculadora Cientifica v2 ---\n");
    printf("0  - Sair\n");
    printf("1  - Adicao\n2  - Subtracao\n3  - Multiplicacao\n4  - Divisao\n");
    printf("5  - Potencia\n6  - Raiz quadrada\n7  - Raiz cubica\n");
    printf("8  - Seno (graus)\n9  - Cosseno (graus)\n10 - Tangente (graus)\n");
    printf("11 - Seno hiperbolico\n12 - Cosseno hiperbolico\n13 - Tangente hiperbolica\n");
    printf("14 - Log natural\n15 - Log base 10\n16 - Exponencial\n17 - Potencia de 10\n");
    printf("18 - Modulo\n19 - Fatorial\n20 - Numero PI\n21 - Inverso\n");
    printf("22 - Arredondar\n23 - Arredondar para baixo\n24 - Arredondar para cima\n25 - Soma de matrizes 2x2\n");
    printf("26 - Multiplicacao de matrizes 2x2\n27 - Media\n28 - Maxima\n29 - Minima\n");
    printf("30 - Historico de operacoes\n");

    while(1) { // Enquanto verdadeiro ira repetir o looping
        printf("Escolha a operacao: ");
        if (scanf("%d", &operacao) != 1) { // Caso insira um valor que nao e numero
            printf("Entrada invalida.\n"); 
            break;
        }

        if (operacao == 0) { // Encerrar o codigo
            printf("Encerrando programa...\n");
            break;
        }

        double a = 0, b = 0, resultado = 0;
        int erro = 0;

        switch (operacao) {
            case 1:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);
                printf("Digite o segundo numero: ");
                scanf("%lf", &b);
                resultado = soma(a,b);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Adicao", a, b, resultado);
                break;
            case 2:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);
                printf("Digite o segundo numero: ");
                scanf("%lf", &b);
                resultado = subtracao(a,b);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Subtracao", a, b, resultado);
                break;
            case 3:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);
                printf("Digite o segundo numero: ");
                scanf("%lf", &b);
                resultado = multiplicacao(a,b);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Multiplicacao", a, b, resultado);
                break;
            case 4:
                printf("Digite o dividendo: ");
                scanf("%lf", &a);
                printf("Digite o divisor: ");
                scanf("%lf", &b);
                resultado = divisao(a,b,&erro);
                if (erro) {
                    printf("Erro: divisao por zero!\n");
                }
                else {
                    printf("Resultado: %g\n", resultado);
                    push_operacao(historico, &hist_count, "Divisao", a, b, resultado);
                }
                break;
            case 5:
                printf("Digite a base: ");
                scanf("%lf", &a);
                printf("Digite o expoente: ");
                scanf("%lf", &b);
                resultado = potencia(a,b);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Potencia", a, b, resultado);
                break;
            case 6:
                printf("Numero: ");
                scanf("%lf", &a);
                resultado = raiz_quadrada(a, &erro);
                if (erro) {
                    printf("Erro: numero negativo!\n");
                }
                else {
                    printf("Resultado: %g\n",resultado);
                    push_operacao(historico, &hist_count, "Raiz quadrada", a, 0, resultado);
                }
                break;
            case 7:
                printf("Numero: ");
                scanf("%lf", &a);
                resultado = raiz_cubica(a);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Raiz cubica", a, 0, resultado);
                break;
            case 8:
                printf("Angulo (graus): ");
                scanf("%lf", &a);
                resultado = seno_graus(a);
                printf("Seno: %g\n", resultado);
                push_operacao(historico, &hist_count, "Seno (graus)", a, 0, resultado);
                break;
            case 9:
                printf("Angulo (graus): ");
                scanf("%lf", &a);
                resultado = cosseno_graus(a);
                printf("Cosseno: %g\n", resultado);
                push_operacao(historico, &hist_count, "Cosseno (graus)", a, 0, resultado);
                break;
            case 10:
                printf("Angulo (graus): ");
                scanf("%lf", &a);
                resultado = tangente_graus(a);
                printf("Tangente: %g\n", resultado);
                push_operacao(historico, &hist_count, "Tangente (graus)", a, 0, resultado);
                break;
            case 11:
                printf("Valor: ");
                scanf("%lf", &a);
                resultado = seno_hiper(a);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Seno hiper", a, 0, resultado);
                break;
            case 12:
                printf("Valor: ");
                scanf("%lf", &a);
                resultado = cosseno_hiper(a);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Cosseno hiper", a, 0, resultado);
                break;
            case 13:
                printf("Valor: ");
                scanf("%lf", &a);
                resultado = tangente_hiper(a);
                printf("Resultado: %g\n",resultado);
                push_operacao(historico, &hist_count, "Tangente hiper", a, 0, resultado);
                break;
            case 14:
                printf("Numero: ");
                scanf("%lf", &a);
                resultado = log_natural(a, &erro);
                if (erro) {
                    printf("Erro: numero <= 0!\n");
                }
                else {
                    printf("Resultado: %g\n",resultado);
                    push_operacao(historico, &hist_count, "Log natural", a, 0, resultado);
                }
                break;
            case 15:
                printf("Numero: ");
                scanf("%lf", &a);
                resultado = log_base10(a, &erro);
                if (erro) {
                    printf("Erro: numero <= 0!\n");
                }
                else {
                    printf("Resultado: %g\n",resultado);
                    push_operacao(historico, &hist_count, "Log base 10", a, 0, resultado);
                }
                break;
            case 16:
                printf("Expoente: ");
                scanf("%lf", &a);
                resultado = exponencial(a);
                printf("Resultado: %g\n",resultado);
                push_operacao(historico, &hist_count, "Exponencial", a, 0, resultado);
                break;
            case 17:
                printf("Expoente: ");
                scanf("%lf", &a);
                resultado = potencia_de_10(a);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Potencia de 10", a, 0, resultado);
                break;
            case 18:
                printf("Numero: ");
                scanf("%lf", &a);
                resultado = modulo(a);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Modulo", a, 0, resultado);
                break;
            case 19:
                printf("Inteiro (0-20): ");
                scanf("%lf", &a);
                resultado = fatorial(a, &erro);
                if (erro == 1) {
                    printf("Erro: valor invalido!\n");
                }
                else if (erro == 2) {
                    printf("Erro: limite maximo atingido!\n");
                }
                else {
                    printf("Resultado: %g\n", resultado);
                    push_operacao(historico, &hist_count, "Fatorial", a, 0, resultado);
                }
                break;
            case 20:
                resultado = valor_pi();
                printf("PI = %g\n",resultado);
                push_operacao(historico, &hist_count, "PI", 0, 0, resultado);
                break;
            case 21:
                printf("Numero: ");
                scanf("%lf", &a);
                resultado = inverso(a,&erro);
                if (erro) {
                    printf("Erro: divisao por zero!\n");
                }
                else {
                    printf("Resultado: %g\n",resultado);
                    push_operacao(historico, &hist_count, "Inverso", a, 0, resultado);
                }
                break;
             case 22:
                printf("Número: "); scanf("%lf",&a);
                resultado = arredondar_proximo(a);
                printf("Resultado: %.0lf\n",resultado);
                push_operacao(historico,&hist_count,"Round",a,0,resultado);
                break;
            case 23:
                printf("Número: "); scanf("%lf",&a);
                resultado = arredondar_baixo(a);
                printf("Resultado: %.0lf\n",resultado);
                push_operacao(historico,&hist_count,"Floor",a,0,resultado);
                break;
            case 24:
                printf("Número: "); scanf("%lf",&a);
                resultado = arredondar_cima(a);
                printf("Resultado: %.0lf\n",resultado);
                push_operacao(historico,&hist_count,"Ceil",a,0,resultado);
                break;
            case 25: {
                double A[2][2], B[2][2], R[2][2];
                printf("Preencha matriz A (2x2):\n");
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                    scanf("%lf", &A[i][j]);
                    }
                }

                printf("Preencha matriz B (2x2):\n");
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                        scanf("%lf", &B[i][j]);
                    }
                }
                soma_matriz_2x2(A, B, R);
                printf("Resultado A+B:\n"); 
                imprimir_matriz_2x2(R);
                push_operacao(historico, &hist_count, "Soma matriz 2x2", A[0][0], B[0][0], R[0][0]);
                break;
            }

            case 26: {
                double A[2][2], B[2][2], R[2][2];
                printf("Preencha matriz A (2x2):\n");
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                    scanf("%lf", &A[i][j]);
                    }
                }

                printf("Preencha matriz B (2x2):\n");
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                    scanf("%lf", &B[i][j]);
                    }
                }
                multiplica_matriz_2x2(A,B,R);
                printf("Resultado A*B:\n"); 
                imprimir_matriz_2x2(R);
                push_operacao(historico, &hist_count, "Multiplicacao matriz 2x2", A[0][0], B[0][0], R[0][0]);
                break;
            }

            case 27:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);
                printf("Digite o segundo numero: ");
                scanf("%lf", &b);
                resultado = media(a,b);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Media", a, b, resultado);
                break;
            case 28:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);
                printf("Digite o segundo numero: ");
                scanf("%lf", &b);
                resultado = maxima(a,b);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Maxima", a, b, resultado);
                break;
            case 29:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &a);
                printf("Digite o segundo numero: ");
                scanf("%lf", &b);
                resultado = minima(a,b);
                printf("Resultado: %g\n", resultado);
                push_operacao(historico, &hist_count, "Minima", a, b, resultado);
                break;
            case 30:
                exibir_historico(historico, hist_count);
                break;
                
            default:
                printf("Operacao invalida, digite uma operacao correta!\n");
                break;
        }
    }

    free(historico); // Limpar o historico 
    return 0;
}
