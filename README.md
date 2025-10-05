# Calculadora científica em C
Projeto simples de uma calculadora científica feita com a linguagem C, com  intenção de praticar os estudos.

|Tipo|Operações|
|---|---|
|  Básicas |Soma, subtração, multiplicação e divisão|
|  Potência, Raiz quadrada e cúbica|Potência (xʸ), Raiz Quadrada e Raiz Cúbica|
|Trigonometria - Hiperbólica|Seno, Cosseno, Tangente (em graus); Seno Hiperbólico, Cosseno Hiperbólico, Tangente Hiperbólica|  
|Logaritmo e Exponencias|Logaritmo Natural (ln), Logaritmo Base 10 (log₁₀); Exponencial (eˣ), Potência de 10 (10ˣ)|
|Modulo, Fatorial e PI|Módulo, Fatorial (n!), e a constante π (PI)| 
|Inverso e Arredondar|Inverso (1/x); Arredondar (inteiro mais próximo), Floor (inteiro menor) e Ceil (inteiro maior)| 

## Tecnologias e recursos utilizados
Desenvolvida em C, com o auxílio da IDE Dev C++ e o compilador online GDB Online.

### Bibliotecas usadas: 
  ```
# include <stdio.h> // Para entrada e saída de dados.
# include <math.h> // Para operações matemáticas como trigonometria, raiz quadrada e potenciação.
# include <stdlib.h> // Para alocação de memória.
```
### M_PI
```
// Define M_PI caso não esteja definida pela biblioteca <math.h> 
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
```

## Instalação, compilação e execução
Para usar a calculadora, é necessário ter algum compilador de C ou um compilador online (nesse caso, copiar o código e inseri-lo no compilador online e rodar)

### Compilando em alguma IDE
- Baixar o arquivo calculadora.c;
- Abrir o arquivo no compilador;
- Selecionar para compilar e executar o arquivo.

### Clonando o código
- Abrir o terminal (Git Bash ou PowerShell);
- Navegar até o diretório onde deseja salvar o projeto (exemplo: `cd ~/Documentos/Projetos`);
- Inserir o comando:
```bash
git clone https://github.com/monic-rabelo/calculadora-cientifica.git
```
- Acessar a pasta do projeto que acabou de ser clonada:
```bash
cd calculadora-cientifica
```
- Executar o código.

### Execução 
Após a execução, a saída será:
```console
...
23 - Arredondar um decimal para o proximo inteiro menor
24 - Arredondar um decimal para o proximo inteiro maior
0 - SAIR
Digite a operacao desejada: // Onde será inserido o número da operação desejada ou 0 para finalizar o código.
```

## Uso

### Menu com operações
```
--- Calculadora Cientifica Completa ---
Operacoes disponiveis:
1 - Adicao
2 - Subtracao
3 - Multiplicacao
4 - Divisao
5 - Potencia (x^y)
6 - Raiz quadrada
...
```

### Usando a função de multiplicar
```
Digite a operacao desejada: 3
Digite o primeiro numero: 4
Digite o segundo numero: 2
Resultado: 8
```
### Usando a função de divisão
```
Digite a operacao desejada: 4
Digite o primeiro numero: 1
Digite o segundo numero: 0
Erro: Divisao por zero!
```
### Finalizando o programa
```
Digite a operacao desejada: 0
Programa finalizado
```

## Informações adicionais
Esse código foi desenvolvido com a intenção de colocar em prática o que foi ensinado em aula, como o uso de switch-case, if e else, do-while e operações básicas em C.
- O código fica em um do-while para que, enquanto não for inserido 0 para sair, o código continuará rodando.
- Caso seja inserido um número diferente dos das operações disponíveis, será solicitado para inserir uma operação correta.
- Qualquer contribuição para a melhora é aceita! :)
