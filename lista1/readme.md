# Soluções

## E - Expanding STACKS!

Existem N items, que devem ser alocados em duas pilhas por ordem de chegada, o problema consiste em determinar se, dada uma certa ordem de saída, existe uma atribuição entre item/pilha que respeite a condição LIFO das duas pilhas.

A ideia da solução (incorreta) é aproveitar que tanto as entradas e saídas são pré-determinadas e fazer a alocação nas diferentes pilhas com base no maior tempo de saída dos itens aos topos das pilhas.

## L - LED Matrix

É o problema mais fácil. Uma linha só pode apresentar o padrão dessa linha se todos os LEDs estiverem funcionais, portanto, basta checar se todos os LEDs estão funcionais para cada linha que precisa apresentar um padrão. A solução se dá em O(R * max(C, K)).
