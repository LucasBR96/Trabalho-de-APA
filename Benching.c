#include <sys/resource.h>
#include <solucoes.h>
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

int main(){
    return 0;
}