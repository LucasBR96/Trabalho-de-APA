#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b)? a : b; }

int vers1_opm(int num_produtos, int valores[], int pesos[], int pmax)
{
   int i, w;
   int **K;

   K = (int**)malloc(sizeof(int*)*pmax);
    for (i = 0; i <= num_produtos; i++)
        K[i] = (int*)malloc(sizeof(int)*pmax);

   for (i = 0; i <= num_produtos; i++)
   {
       for (w = 0; w <= pmax; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (pesos[i-1] <= w)
                 K[i][w] = max(valores[i-1] + K[i-1][w-pesos[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   
    return K[num_produtos][pmax];
}

int vers1_ingenua(int num_produtos, int valores[], int pesos[], int pmax)
{

    if (num_produtos==0 || pmax==0)
        return 0;
    else if (pesos[num_produtos-1] > pmax)
        return vers1_ingenua(num_produtos - 1, valores, pesos, pmax);

    else
        return max(valores[num_produtos-1] + 
            vers1_ingenua(num_produtos - 1, valores, pesos, pmax - pesos[num_produtos -1 ])
            , vers1_ingenua(num_produtos - 1, valores, pesos, pmax));

   
}

int main(){
    int num_produtos, pmax;

    int i = 0;
    scanf("%d", &i);
    num_produtos = i;
    scanf("%d", &i); 
    pmax = i;

    int valores[num_produtos]; 
    int pesos[num_produtos]; 
    int j = 0;
    for (j = 0; j<num_produtos; j++){
        int x;
        //formato de entrada: valor peso
        scanf("%d %d", &i, &x);
        pesos[j] = x;
        valores[j] = i;
    }

    printf("ingenua %d \n", vers1_ingenua(num_produtos, valores, pesos, pmax));
    printf("opm %d", vers1_opm(num_produtos, valores, pesos, pmax));

    return 0;
}
