#include <stdio.h>
#include <math.h> // biblioteca para pow, sqrt, sin, cos, tan
#include <stdlib.h> // biblioteca para exit e alocacao de memoria


// Define M_PI caso nao exista
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    double num1, num2, resultado, angulo_graus;
    int operacao;
    
    
    printf("--- Calculadora Cientifica Completa ---\n");
    printf("Operacoes disponiveis:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Potencia (x^y)\n");
    printf("6 - Raiz quadrada\n");
    printf("7 - Raiz cubica\n");
    printf("8 - Seno (graus)\n");
    printf("9 - Cosseno (graus)\n");
    printf("10 - Tangente (graus)\n");
    printf("11 - Seno hiperbolico\n");
    printf("12 - Cosseno hiperbolico\n");
    printf("13 - Tangente hiperbolica\n");
    printf("14 - Logaritmo natural (ln)\n");
    printf("15 - Logaritmo base 10\n");
    printf("16 - Exponencial (e^x)\n");
    printf("17 - Potencia de 10 (10^x)\n");
    printf("18 - Modulo (valor absoluto)\n");
    printf("19 - Fatorial (somente inteiros >= 0)\n");
    printf("20 - Numero PI\n");
    printf("21- Inverso (1/x)\n");
    printf("22 - Arredondar um decimal para o inteiro mais proximo\n");
    printf("23 - Arredondar um decimal para o proximo inteiro menor\n");
    printf("24 - Arredondar um decimal para o proximo inteiro maior\n");
    printf("0 - SAIR");
    
    do {
        printf("\nDigite a operacao desejada: ");
        scanf(" %d", &operacao);
    
        switch(operacao) {
            // ---------------- OPERACOES BASICAS ----------------
            case 1: case 2: case 3: case 4:
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
    
                switch(operacao) {
                    case 1: resultado = num1 + num2; break;
                    case 2: resultado = num1 - num2; break;
                    case 3: resultado = num1 * num2; break;
                    case 4:
                        if (num2 == 0) {
                            printf("Erro: Divisao por zero!\n");
                            return 1;
                        }
                        resultado = num1 / num2;
                        break;
                }
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- POTENCIA ----------------
            case 5:
                printf("Digite a base: ");
                scanf("%lf", &num1);
                printf("Digite o expoente: ");
                scanf("%lf", &num2);
                resultado = pow(num1, num2);
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- RAIZ QUADRADA ----------------
            case 6:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Erro: Raiz quadrada de numero negativo!\n");
                    return 1;
                }
                resultado = sqrt(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- RAIZ CUBICA ----------------
            case 7:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = cbrt(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- TRIGONOMETRIA ----------------
            case 8: case 9: case 10:
                printf("Digite o angulo em graus: ");
                scanf("%lf", &angulo_graus);
                num1 = angulo_graus * (M_PI / 180.0); // graus -> radianos
    
                switch(operacao) {
                    case 8: resultado = sin(num1); break;
                    case 9: resultado = cos(num1); break;
                    case 10: resultado = tan(num1); break;
                }
                
                printf("Resultado (%.2g graus): %g\n", angulo_graus, resultado);
                break;
    
            // ---------------- FUNCOES HIPERBOLICAS ----------------
            case 11: // seno hiperbolico
                printf("Digite o valor: ");
                scanf("%lf", &num1);
                resultado = sinh(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            case 12: // cosseno hiperbolico
                printf("Digite o valor: ");
                scanf("%lf", &num1);
                resultado = cosh(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            case 13: // tangente hiperbolica
                printf("Digite o valor: ");
                scanf("%lf", &num1);
                resultado = tanh(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- LOGARITMOS E EXPONENCIAIS ----------------
            case 14: // log natural
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Erro: log so e definido para numeros positivos!\n");
                    return 1;
                }
                resultado = log(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            case 15: // log base 10
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Erro: log so e definido para numeros positivos!\n");
                    return 1;
                }
                resultado = log10(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            case 16: // exponencial e^x
                printf("Digite o expoente: ");
                scanf("%lf", &num1);
                resultado = exp(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            case 17: // potencia de 10
                printf("Digite o expoente: ");
                scanf("%lf", &num1);
                resultado = pow(10, num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- MODULO ----------------
            case 18:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = fabs(num1);
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- FATORIAL ----------------
            case 19:
                printf("Digite um numero inteiro: ");
                scanf("%lf", &num1);
                if (num1 < 0 || floor(num1) != num1) {
                    printf("Erro: fatorial so e definido para inteiros nao negativos!\n");
                    return 1;
                }
                resultado = tgamma(num1 + 1); // fatorial(n) = gamma(n+1)
                printf("Resultado: %g\n", resultado);
                break;
    
            // ---------------- PI ----------------
            case 20:
                printf("PI = %g\n", M_PI);
                break;
    
            // ---------------- INVERSO ----------------
            case 21: // inverso
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 == 0) {
                    printf("Erro: divisao por zero!\n");
                    return 1;
                }
                resultado = 1 / num1;
                printf("Resultado: %g\n", resultado);
                break;
                
            // ---------------- ARREDONDAR ----------------
            case 22: // arredondar para o inteiro mais proximo
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = round(num1);
                printf("Resultado: %g\n", resultado);
                break;
                
            case 23: // arredondar para o menor inteiro mais próximo
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = floor(num1);
                printf("Resultado: %g\n", resultado);
                break;
                
            case 24: // arredondar para o maior inteiro mais próximo
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = ceil(num1);
                printf("Resultado: %g\n", resultado);
                break;
                
            case 0:
                printf("Programa finalizado\n");
                break;
                
            // ---------------- DEFAULT ----------------
            default:
                printf("Operacao invalida! Digite uma operacao disponivel.\n");
                break;
        } 
    } while (operacao != 0);

    return 0;
}