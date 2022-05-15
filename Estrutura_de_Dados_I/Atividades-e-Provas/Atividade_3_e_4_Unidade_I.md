### 3. Qual a diferença entre uma variável do tipo inteira de um ponteiro do tipo inteiro?

&nbsp;

``R:`` A ``Variável do tipo inteira`` aponta para um número inteiro na memória, ``ponteiro do tipo inteiro`` aponta para um endereço de um inteiro na memória, estática ou dinâmica.

&nbsp;

### 4. Por que devemos preencher um ponteiro apenas com o endereço de uma variável ou por alocação dinâmica usando funções como malloc?

&nbsp;

``R:`` Se alocar um endereço qualquer para um ponteiro. pode correr o risco de manipular uma área da memória que já está sendo utilizada por algum programa ou pelo SO, causando instabilidade no computador.