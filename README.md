# Calculadora científica em C
Projeto simples de uma calculadora científica feita com a linguagem C, com  intenção de praticar os estudos sobre funções e struct.

|Tipo|Funções matemáticas|
|---|---|
|Básicas| Soma, subtração, multiplicação e divisão|
|Potência, Raiz quadrada e cúbica| Potência (xʸ), Raiz Quadrada e Raiz Cúbica|
|Trigonometria - Hiperbólica| Seno, Cosseno, Tangente (em graus); Seno Hiperbólico, Cosseno Hiperbólico, Tangente Hiperbólica|  
|Logaritmo e Exponenciais| Logaritmo Natural (ln), Logaritmo Base 10 (log₁₀); Exponencial (eˣ), Potência de 10 (10ˣ)|
|Modulo, Fatorial e PI| Módulo, Fatorial (n!), e a constante π (PI)| 
|Inverso e Arredondar| Inverso (1/x); Arredondar (inteiro mais próximo), Floor (inteiro menor) e Ceil (inteiro maior)| 
|Matrizes| Somar matrizes(2x2), Multiplicar matrizes(2x2)| 
|Media, Máxima/Mínima| Calcular média de duas notas, ver máxima e mínima| 

|Função|Descrição|
|---|---|
|push_operacao()| Para inserir a operação que foi realizada no histórico|
|exibir_historico()| Para exibir as últimas operações realizadas, os dois números usados e o resultado.|

## Tecnologias e recursos utilizados
Desenvolvida em C, com o auxílio do IDE Visual Studio Code, Dev C++ e o compilador online GDB Online.

### Bibliotecas usadas: 
  ```
# include <stdio.h> // Para entrada e saída de dados.
# include <math.h> // Para operações matemáticas como trigonometria, raiz quadrada e potenciação.
# include <stdlib.h> // Para alocação de memória e free.
# include <string.h> // Para manipulação de strings
```
### M_PI
```
// Define M_PI caso não esteja definida pela biblioteca <math.h> 
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
```

### Máximo de operações no histórico
```
#define MAX_HISTORICO 1000 // Máximo de operações que podem armazenadas no histórico
```

## Instalação, compilação e execução
Para usar a calculadora, é necessário ter algum compilador de C ou um compilador online (nesse caso, copiar o código e inseri-lo no compilador online e rodar)

***Observação:*** Caso não tenha um IDE com o compilador já instalado, é necessário instalar e configurar o GCC e seu caminho no computador, disponível no pacote MinGW para Windows.

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
- Abrir o código no IDE
***(o caminho precisa ser algo como: ~\Projetos\calculadora-cientifica)***
```bash
code .
```
## Adicionar avisos ao compilador (Wall e Wextra)
Após clonar o código e abri-lo, é recomendável que, antes de executar, sejam inseridas as flags de compilação do GCC: Wall e Wextra. Ambas ajudam a escrever um código mais limpo e sem erros.

- Abrir o terminal
- Inserir o seguinte comando:
```bash
gcc -Wall -Wextra .\calculadora.c -o calculadora.exe
```
É possível adicionar qualquer nome ao arquivo executável, após o "-o".

- Wall: vai ativar avisos que o compilador considera útil e fácil de consertar.
- Wextra: ativa avisos extras que não foram ativados pelo -Wall, cobre casos mais específicos e é mais rigoroso.

O código agora poderá ser desenvolvido em maior qualidade.

### Execução 
Após a execução, a saída será:
```console
... (...)
27 - Media
28 - Maxima
29 - Minima
30 - Historico de operacoes
Escolha a operacao:
```

## Uso

### Menu com operações
```
--- Calculadora Cientifica v2 ---
0  - Sair
1  - Adicao
2  - Subtracao
3  - Multiplicacao
4  - Divisao
...
```

### Usando a função de multiplicar
```
Escolha a operacao: 3
Digite o primeiro numero: 2
Digite o segundo numero: 3
Resultado: 6
```
### Usando a função de divisão
```
Escolha a operacao: 4
Digite o dividendo: 3
Digite o divisor: 0
Erro: divisao por zero!
Escolha a operacao: // Para inserir novamente uma operação
```

### Vendo histórico de operações
```
Escolha a operacao: 30

----- Historico (1 operacoes) -----
ID 1 | Adicao | Numero 1 = 2, Numero 2 = 3 => Resultado = 5
```
### Finalizando o programa
```
Escolha a operacao: 0
Encerrando programa...
```

## Informações adicionais
Esse código foi desenvolvido com a intenção de colocar em prática o que foi ensinado em aula, como o uso de switch-case, if e else, while, operações básicas em C, struct, manipulação de memória/strings, bibliotecas e especialmente funções.
- Calculadora desenvolvida com foco no uso de ***funções*** que depois são chamadas na função principal: ***main()***
- O código fica em um while para que, enquanto não for inserido 0 para sair, o código continuará rodando. Caso seja inserido algum valor que não seja um número, o código se encerra.
- Caso seja inserido um número diferente dos das operações disponíveis, será solicitado para inserir uma operação correta.
- Qualquer contribuição para a melhora é aceita! :)
