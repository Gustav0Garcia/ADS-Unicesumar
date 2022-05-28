# **Atividades - Unidade III**

### **1. É possível criar uma lista de forma estática usando um vetor?**

&nbsp;

``R:`` Sim, a lista pode ser implementada utilizando um vetor ou dinamicamente na memória. Os nós na lista estática podduem o endereço de memória do próximo elemento, permitindo a sua organização independete do índice do vetor.

&nbsp;

### **2. Crie a estrutura de um nó para uma lista encadeada.**

&nbsp;

``R:`` 

````c
struc no{
    int dado;
    struct no *proximo;
};
````

&nbsp;

### **3. Crie a estrutura de um nó para uma lista duplamente encadeada.**

&nbsp;

``R:`` 

````c
struct no{
    int dado;
    struct no *anterior;
    struct no *proximo;
};
````

&nbsp;

### **4. Qual a vantagem de uma lista duplamente encadeada em relação a uma lista simples?**

&nbsp;

``R:`` 

**Lista simples**: os nós apenas possuem o endereço do próximo elemento, podendo navegar do primeiro ao último nó em um único sentido.
**Lista duplamente encadeada**: os nós possuem o endereço do elemento anterior e do elemento posterior, podendo fazer a navegação em ambas os sentidos.

&nbsp;

### **5. Como sabemos qual é o nó inicial de uma lista simples?**

&nbsp;

``R:`` Havendo uma variavel do tipo ponteiro que aponte para o início da lista.

&nbsp;

### **6. Como sabemos qual é o nó final de uma lista simples?**

&nbsp;

``R:`` Se o atributo qua aponta para o próximo elemento estiver com o valor **NULL**.

&nbsp;

### **7. Se o nó de uma lista duplamente encadeada possui dois ponteiros, um para o próximo elemento e um para o anterior, qual informação está contida nesses ponteiros do primeiro nó da lista?**

&nbsp;

``R:`` O primeiro nó da lista suplamente encadeada, possui dois ponteiros. O ponteiro criado para apontar para o elemento anterior estará apontando para **NULL**, pois sendo o primeiro nó, não há um nó anterior, o outro ponteiro estará apontando para o próximo nó. Se contar apenas um nó na lista, ambos os ponteiros estarão apontando para **NULL**.