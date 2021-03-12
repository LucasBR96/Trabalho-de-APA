#include <stdio.h>
#include <stlib.h>
#include <math.h>

/*

    Esse arquivo contém as soluções para cada versão do problema da mochila,
    sendo que cada uma tem uma solução ingênua e otimizada, totalizando 4 funções.
    Lembrando que na versão 1 só pode ser inserida, no maximo, uma unidade de
    cada produto na mochila, enquanto na versão 2 o numero de unidades é "ilimitado"

    Cada função retorna um vetor de inteiros como saída, representando o conjunto de
    produtos que maximiza o valor total em relação ao peso maximo suportado. Os nomes
    das variaveis de entrada são descritivas o suficiente.

*/

int * vers1_ingenua( int num_produtos, float[] valores, float[] pesos , float pmax );
int * vers1_opm( int num_produtos, float[] valores, float[] pesos, float pmax );
int * vers2_ingenua( int num_produtos, float[] valores, float[] pesos , float pmax );
int * vers2_opm( int num_produtos, float[] valores, float[] pesos , float pmax );