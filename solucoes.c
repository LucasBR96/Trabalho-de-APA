#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b)? a : b; }

void get_list_mochila(int num_produtos, int pmax, int **K, int pesos[], int *solucao){
   
   int i = 0;
   for (; num_produtos>0 ; num_produtos--){
    if (K[num_produtos][pmax] <= 0)
        break;
    if (K[num_produtos][pmax] > K[num_produtos-1][pmax]){
        solucao[i] = num_produtos;
        ++i;
        pmax = pmax - pesos[num_produtos-1];
        }
    }
    solucao[i] = -1;
}

int vers1_opm(int num_produtos, int valores[], int pesos[], int pmax)
{

    int i, w;
    int **K;

    K = (int**)malloc(sizeof(int*)*num_produtos);
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
    // int solucao[num_produtos];
    // get_list_mochila(num_produtos, pmax, K, pesos, solucao);
    // printf ("\nItens: ");
    // printf("%d", solucao[0]);

    // for (i = 1; (solucao[i] != -1); i++){
    //     printf(", ");
    //     printf("%d", solucao[i]);
    // }
    // printf("\n");

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

// int vers2_opm(int num_produtos, int valores[], int pesos[], int pmax){
//     int * K = (int*)malloc(sizeof(int*)*pmax);

//     K[0] = 0;
//     int w, i;
//     for (w = 1; w <= pmax; w++){
//         K[w] = K[w-1];
//         for (i = 0; i< num_produtos; i ++){
//             if(pesos[i] <=  w){
//                 int val = K[w-pesos[i]] + valores[i];
//                 if(val > K[w]){
//                     K[w] = val;
//                 }
//             }
//         }
//     }
//     return K[pmax];

// }

int vers2_opm(int num_produtos, int valores[], int pesos[], int pmax)
{
    int max_uses = 2;
    int *vals = (int*)malloc(sizeof(int)*num_produtos*max_uses);
    int *ps = (int*)malloc(sizeof(int)*num_produtos*max_uses);
    int count = 0;
    int pos = 0;

    for (int x = 0; x < num_produtos; x ++){
        for(int w = 0; w<max_uses; w++){
            vals[pos] = valores[x];
            ps[pos] = pesos[x];
            pos ++;
        }
    }
    int i, w;
    int **K;
    for (i = 0; i <= num_produtos*max_uses; i++)
        K[i] = (int*)malloc(sizeof(int)*pmax);


    for (i = 1; i <= num_produtos*max_uses; i++)
    {
       for (w = 1; w <= pmax; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (ps[i-1] <= w)
                K[i][w] = max(vals[i-1] + K[i-1][w-ps[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[num_produtos*max_uses][pmax];
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

    printf("ingenua v1 %d \n", vers1_ingenua(num_produtos, valores, pesos, pmax));
    printf("opm v1 %d\n", vers1_opm(num_produtos, valores, pesos, pmax));
    //printf("opm v2 %d\n", vers2_opm(num_produtos, valores, pesos, pmax));
    

    return 0;
}
