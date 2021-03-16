# Trabalho-de-APA

    Os arquivos que se encontram nesse repositório são o código fonte do trabalho com nota equivalente da P1
    da matéria de análise e projeto de algoritimos, Turma A1, da Universidade Federal Fluminense.

    Autoria de Lucas Fuzato Cipriano e Mariana Suarez de Oliveira.

    ------ O Problema -------------------------------------------------------------------------------------

    O tema desse trabalho é a busca da solução ótima de duas versões do "problema da mochila".

    O problema da mochila assume a existência de uma mochila hipotética com uma capacidade máxima M
    e de um conjunto finito de N produtos distintos . Para cada prodruto p desse conjunto, existem associados
    os valores:

        v( p ) -> valor do produto p 
        y( p ) -> peso ou volume de p

    Deve-se descobrir, então, quais e quantos produtos deve-se colocar na mochila, de forma que maximize o
    somatório dos seus valores, mas que o somatório dos seus pesos não exceda M.

    Foi pedida a resolução de duas versões desse problema. Na primeira, so se pode colocar, no maximo, uma
    unidade de cada produto, enquanto no segunda, pode-se pôr mais de uma unidadade do mesmo produto. 

    ------ Os arquivos ------------------------------------------------------------------------------------

    Soluções.h -> Esse arquivo contém, para cada versão do problema, duas soluções, uma ingênua e outra otimizada.
    A ingênua é de facil compreensão, porem é muito lenta para ser viável, servindo apenas de referência para a 
    solução otimizada, que é executada em tempo razoável. Além disso, existe uma função que le os casos de teste

    Benching.c -> Essa arquivo que contém o script que mede a performance de cada solução, frente a cada caso de 
    teste, e salva o resultado num arquivo csv.

    resultados.csv -> cada linha desse arquivo é no formato:
        M -> Capacidade maxima da mochila
        N -> Quantidade de produtos
        i -> Indice da solução ( qual solução aplicada )
        t -> tempo de processador para a instância
    
    gera_grafico.py -> script que gera os graficos que serão usados na apresentação final do trabalho.


    ----- Guia de Instalação-------------------------------------------------------------------------------

