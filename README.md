# Simulador de Gerência de Regiões Móveis

## Implementar um programa que simule parte de um gerenciador de memória por partições dinâmicas. O programa deve ser escrito em linguagem C/C++ que seja executado no sistema operacional linux de 64 bits.

* O programa deve produzir uma lista de  espaços de memória livre, contendo entre oito (8) e 15 regiões sendo cada uma com tamanho variando entre um (1) e 100. A quantidade de regiões e o tamanho de cada uma deve ser gerado de forma aleatória.

* A lista deve ser mostrada, com cada uma das regiões de memória livre  separadas por espaço em branco, traço e espaço em branco (REG1 - REG2 - REG3). As expressões REG<numero> são lacunas de memória disponível. Ver exemplo de solução.

* O usuário deve escolher o algoritmo a ser usado para percorrer a lista, dentre os clássicos descritos na literatura. O programa deve suportar os quatro algoritmos comumente citados.

* Após a definição do algoritmo, deve-se gerar 10 solicitações de memória (aleatoriamente), com tamanhos variando maior que zero (0) e menor que 100. Deve-se mostrar o número e o tamanho da requisição (entre colchetes) em seguida o conjunto de regiões que estão livres, após atender a solicitação.

* Caso a região não seja completamente preenchida, o espaço que sobrou deve ser inserido como uma nova região no conjunto, no mesmo local da região original, sendo destacado em negrito.

* Caso a região for completamente preenchida, a lista deve diminuir uma posição. Nesse caso, uma solicitação preenche completamente uma região (perfect fit), a mesma deve ser excluída do conjunto de regiões de memória. Mostrar "Encaixe perfeito" ao final da lista, em negrito.

Caso não seja possível atender uma requisição por falta de um espaço contíguo, mostrar "Solicitação não pode ser atendida" e não mostrar a lista.

./rebonatto.sol<br>
===== Gerenciador de memoria por particoes dinamicas =====<br>
Escolha um dos algoritmos:<br>
0 - First-fit<br>
1 - Best-fit<br>
2 - Worst-fit<br>
3 - Circular-fit<br>
0<br>
<br>
===== Algoritmo First-fit! =====<br>
Original [54 - 85 - 97 - 97 - 95 - 77 - 53 - 54 - 61]<br>
[0 - 72] [54 - 13 - 97 - 97 - 95 - 77 - 53 - 54 - 61]<br>
[1 - 55] [54 - 13 - 42 - 97 - 95 - 77 - 53 - 54 - 61]<br>
[2 - 02] [52 - 13 - 42 - 97 - 95 - 77 - 53 - 54 - 61]<br>
[3 - 72] [52 - 13 - 42 - 25 - 95 - 77 - 53 - 54 - 61]<br>
[4 - 02] [50 - 13 - 42 - 25 - 95 - 77 - 53 - 54 - 61]<br>
[5 - 57] [50 - 13 - 42 - 25 - 38 - 77 - 53 - 54 - 61]<br>
[6 - 20] [30 - 13 - 42 - 25 - 38 - 77 - 53 - 54 - 61]<br>
[7 - 28] [02 - 13 - 42 - 25 - 38 - 77 - 53 - 54 - 61]<br>
[8 - 91] Solicitacao não pode ser atendida<br>
[9 - 54] [02 - 13 - 42 - 25 - 38 - 23 - 53 - 54 - 61]<br>
