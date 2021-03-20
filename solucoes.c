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

int vers1_opm(int num_produtos, int *valores, int *pesos, int pmax)
{

    int i, w;

    int **K = (int**)malloc(sizeof(int*)*(num_produtos + 10));

    for (i = 0; i <= num_produtos+10; i++)
        K[i] = (int*)malloc(sizeof(int)*(pmax + 10));



    for (i = 0; i <= num_produtos; i++)
    {
       for (w = 0; w <= pmax; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (pesos[i-1] <= w){
                int pos = pesos[i-1];
                int val = valores[i-1];
                K[i][w] = max(val + K[i-1][w-pos],  K[i-1][w]);
            }
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
    int result = K[num_produtos][pmax];
    return result;
}

int vers1_ingenua(int num_produtos, int *valores[], int *pesos, int pmax)
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

int vers2_opm(int num_produtos, int *valores, int *pesos, int pmax)
{
    int max_uses = max(1,0.2*num_produtos);
    int i, w;
    int **K = (int**)malloc(sizeof(int*)*(num_produtos + 10));

    for (i = 0; i <= num_produtos+10; i++)
        K[i] = (int*)malloc(sizeof(int)*(pmax + 10));

    for (i = 0; i <= num_produtos; i++)
    {

       for (w = 0; w <= pmax; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            
            else {
                K[i][w] = K[i-1][w];
                for (int u = 1; u <= max_uses; u++){
                    int peso = pesos[i-1];
                    int val = valores[i-1];
                    if (u * peso <= w){
                        K[i][w] = max((u * val) + K[i-1][w-(u * peso)],  K[i][w]);                        
                    }
                }

            }

        }
    }
    int result = K[num_produtos][pmax];
    return result;
}


// int main(){
//     int n, m; //número de itens e capacidade da mochila

//     int i = 0;
//     scanf("%d", &i);    //Lê o primeiro valor como número de itens
//     n = i;
//     scanf("%d", &i); // Lê segundo valor como capacidade máxima
//     m = i;

//     int *v = (int*)malloc(sizeof(int)*(n + 10));

//     int *p = (int*)malloc(sizeof(int)*(n + 10));
//     int j = 0;
//     for (j = 0; j<n; j++){
//         int x;
//         int w;
//         scanf("%d %d", &w, &x);
//         p[j] = x;
//         v[j] = w;
//     }

//     fprintf(stderr,"\n%d\n", vers2_opm(n, v, p, m));
//     fprintf(stderr, "\n%d\n", vers1_opm(n, v, p, m));
// }
