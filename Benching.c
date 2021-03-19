#include <sys/resource.h>
#include "solucoes.c"
//Essa função foi escrita pelo professor, feita para medir tempos de CPU
void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
    long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
    struct rusage ptempo; // deve ter sido definida em < resource.h >

    getrusage(0,&ptempo);

    seg_CPU = ptempo.ru_utime.tv_sec;
    mseg_CPU = ptempo.ru_utime.tv_usec;
    seg_sistema = ptempo.ru_stime.tv_sec;
    mseg_sistema = ptempo.ru_stime.tv_usec;

    *seg_CPU_total     = (seg_CPU + 0.000001 * mseg_CPU);
    *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}


/*

// Esse codigo ai é um exemplo que veio junto, pelo que parece mede apenas uma instância do problema
// e printa os resultados na tela. No trabalho é mais interessante mandar a relação < Tempo, Entrada , Solução >
// para um arquivo em csv ou txt

Tempo_CPU_Sistema(&s_CPU_inicial, &s_total_inicial);

custo = GRASP_PRBF_S(nnos, ndemandas, demanda, incidencia, num_vezes, &semente, solucao, melhor_solucao, pool_solucao, pool_custo, alvo);

Tempo_CPU_Sistema(&s_CPU_final, &s_total_final);

printf ("Custo = %d\n", custo);
printf ("Tempo de CPU total = %f\n", s_CPU_final - s_CPU_inicial);
*/

void bench( int num_produtos, int *valores, int *pesos, int pmax , FILE* arq ){

    double t_cpu , t_sys;
    int sol, res;

    t_sys = (double) 0;
    if(num_produtos < 25){

        sol = 0; // Ingenua
        t_cpu = ( double )0;
        Tempo_CPU_Sistema(&t_cpu, &t_sys);
        res = vers1_ingenua( num_produtos, valores, pesos, pmax );
        Tempo_CPU_Sistema(&t_cpu, &t_sys);
        fprintf( arq , "%d,%d,%d,%f\n", pmax, num_produtos, sol , t_cpu );
        fprintf( stderr , "%d,%d,%d,%f\n", pmax, num_produtos, sol , t_cpu );
    }

    sol = 1; // Versao 1 otimizada
    t_cpu = ( double )0;
    Tempo_CPU_Sistema(&t_cpu, &t_sys);
    res = vers1_opm( num_produtos, valores, pesos, pmax );
    Tempo_CPU_Sistema(&t_cpu, &t_sys);
    fprintf( arq , "%d,%d,%d,%f\n", pmax, num_produtos, sol , t_cpu );
    fprintf( stderr , "%d,%d,%d,%f\n", pmax, num_produtos, sol , t_cpu );


    sol = 2; // Versao 2 otimizada
    t_cpu = ( double )0;
    Tempo_CPU_Sistema(&t_cpu, &t_sys);
    res = vers2_opm( num_produtos, valores, pesos, pmax );
    Tempo_CPU_Sistema(&t_cpu, &t_sys);
    fprintf( arq , "%d,%d,%d,%f\n", pmax, num_produtos, sol , t_cpu );
    fprintf( stderr , "%d,%d,%d,%f\n", pmax, num_produtos, sol , t_cpu );


}


int main(){

    FILE *arq_r;
    arq_r = fopen( "casos_teste.txt", "r");
    int num_testes;
    fscanf( arq_r, "%d", &num_testes );

    FILE *arq_w;
    arq_w = fopen( "resultados.csv", "w");
    fprintf( arq_w, "\n");

    int num_produtos, pmax;
    int *valores;
    int *pesos;


    for( int i = 0 ; i < num_testes; i++ ){

        //proximo_caso_teste( arq_r , &num_produtos , &valores , &pesos , &pmax );

        fscanf( arq_r, "%d", &num_produtos );
        fscanf( arq_r, "%d", &pmax );
        pesos = (int*)malloc(sizeof(int)*(num_produtos));
        valores = (int*)malloc(sizeof(int)*(num_produtos));

        for( int i = 0; i < num_produtos; i++ ){
            int val1, val2;
            fscanf( arq_r, "%d %d", &val1, &val2 );
            valores[i] = val1;
            pesos[i] = val2;
        }

        bench( num_produtos , valores , pesos , pmax, arq_w );

        free(pesos);
        free(valores);


    }        

    fclose(arq_w);
    fclose(arq_r);


    return 0;
}