# Trabalho-de-APA

    Os arquivos que se encontram nesse repositório são o código fonte do trabalho com nota equivalente da P1
    da matéria de análise e projeto de algoritimos, Turma A1, da Universidade Federal Fluminense.

    Autoria de Lucas Fuzato Cipriano e Mariana Suarez de Oliveira.

    ------ O Problema -------------------------------------------------------------------------------------

    O tema desse trabalho é a busca da solução ótima de duas versões do "problema da mochila".

    O problema da mochila assume a existência de uma mochila hipotética com uma capacidade máxima M
    e de um conjunto finito de N produtos distintos . Para cada prodruto p desse conjunto, existem associados
    os valores:

        V( p ) -> valor do produto p 
        X( p ) -> peso ou volume de p

    Deve-se descobrir, então, qual é maior valor total que pode ser carregado na mochila, sem que o somatório
    dos pesos ultrapasse o peso maximo

    Foi pedida a resolução de duas versões desse problema. Na primeira, so se pode colocar, no maximo, uma
    unidade de cada produto, enquanto no segunda, pode-se pôr mais de uma unidadade do mesmo produto. 

    ------ Os arquivos ------------------------------------------------------------------------------------

    Soluções.c -> Esse arquivo contém a solução ingênua e as otimizadas da versão 1 e 2 
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

    casos_teste.txt -> Os casos teste para serem testados em Benching.c, sua forma:
        A primeira linha indica quantos T casos teste existem.
        As linhas seguintes representam os T casos teste, todos na forma:
            -A primeira linha indica o valor de N
            -A segunda indica o valor de M
            -As N linhas seguintes contem dois inteiros separados por espaço, representam os
            valores de V e X de cada produto

    ----- Recursos utilizados -------------------------------------------------------------------------------

    Os Codigos em python foram feitos usando a versão 3.7.2 para windows 10 64bits
    Além disso foram usadas as seguintes bibliotecas de python:
    
         Bliblioteca    Versão
    1 -  pandas         1.2.3
    2 -  numpy          1.20.1
    3 -  matplotlib     3.1.0

    Os Codigos em C foram feitos em Linux/ubuntu versão 18

    ----- Guia de Instalação-------------------------------------------------------------------------------

    Para reproduzir os resultados obtidos nesse Trabalho:

    1 - baixe o interpretador de python 3 de versão superior ou igual à 3.7
    2 - usando pip ou conda, baixe os pacotes de python utilizados
    3 - salve seus casos em casos_de_teste.txt, usando a formatação descrita acima
    4 - compile os arquivos em C
    5 - rode o executavel Benching.exe
    6 - rode o arquivo gera_grafico.py
    7 - Os graficos aparecerão na sua tela.
