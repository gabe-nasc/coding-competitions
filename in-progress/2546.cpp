#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_NIVEIS (4)
 
typedef long long ll;
 
ll arvore[1<<MAX_NIVEIS][3]; // Propag, Max, Indice_Max
ll maxi[2]; // Indice_Max, Max
 
void atualiza(int lo, int hi, int valor, int noh, int inicio, int fim) {
    if (hi < inicio or lo > fim){ // Intervalo não está dentro de [lo, hi]
        return;
    }
    if (lo <= inicio and hi >= fim) { // Intervalo está incluído dentro de [lo, hi]
        arvore[noh][0] += valor;
        arvore[noh][1] += valor;
        return;
    }
 
    int meio = (inicio + fim) / 2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;
 
    // Propaga para os filhos
    arvore[esq][0] += arvore[noh][0]; // O quanto os filhos tem de propagar para os netos
    arvore[dir][0] += arvore[noh][0];
    arvore[esq][1] += arvore[noh][0]; // Somando ao maximo dos netos o que já foi propagado para o filho
    arvore[dir][1] += arvore[noh][0];
    arvore[noh][0] = 0;
 
    // Atualiza os filhos
    atualiza(lo, hi, valor, esq, inicio, meio);
    atualiza(lo, hi, valor, dir, meio + 1, fim);

    //Atualiza o pai
    if (arvore[esq][1] >= arvore[dir][1]) {
        arvore[noh][1] = arvore[esq][1];
        arvore[noh][2] = arvore[esq][2];
    }
    else
    {
        arvore[noh][1] = arvore[dir][1];
        arvore[noh][2] = arvore[dir][2];
    }
}
 
void consulta(int lo, int hi, int noh, int inicio, int fim) {
    if (hi < inicio or lo > fim){
        return;
    }

    if (lo <= inicio and hi >= fim){
        if (arvore[noh][1] > maxi[1]) {
            maxi[0] = arvore[noh][2];
            maxi[1] = arvore[noh][1];
        }
        return;
    }
        // return arvore[noh][2] + arvore[noh][1] * (fim - inicio + 1);
 
    int meio = (inicio + fim)/2;
    int esq = 2*noh + 1;
    int dir = 2*noh + 2;
 
    // Propaga para os filhos
    arvore[esq][0] += arvore[noh][0]; // O quanto os filhos tem de propagar para os netos
    arvore[dir][0] += arvore[noh][0];
    arvore[esq][1] += arvore[noh][0]; // Somando ao maximo dos netos o que já foi propagado para o filho
    arvore[dir][1] += arvore[noh][0];
    arvore[noh][0] = 0;


    // arvore[noh][0] += arvore[noh][1] * (fim - inicio + 1);
 
    // arvore[esq][1] += arvore[noh][1];
    // arvore[dir][1] += arvore[noh][1];
    // arvore[noh][1] = 0;
 
    consulta(lo, hi, esq, inicio, meio);
    consulta(lo, hi, dir, meio+1, fim);

    if (arvore[esq][1] > maxi[1]) {
        maxi[0] = arvore[esq][2];
        maxi[1] = arvore[esq][1];
    }

    if (arvore[dir][1] > maxi[1]) {
        maxi[0] = arvore[dir][2];
        maxi[1] = arvore[dir][1];
    }
    

}
 
int main() {
    int netos, ops, lo, hi, val;
    char tp;
    ll x;

    while(scanf("%d%d", &netos, &ops) != EOF){
        for(int i = 0; i < netos; i++){
            scanf("%d", &val);
            atualiza(i, i, val, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
        }

        puts("-----");
        puts("Propag || Max || Indice Max");
        puts("-----");
        for(int i = 0; i < netos*4; i++)
        {
            printf("%d -- %lld %lld %lld\n", i, arvore[i][0], arvore[i][1], arvore[i][2]);
        }
        
        puts("-----");
        puts("indice || valor");
        puts("-----");
        for(int i = 0; i < ops; i++)
        {
            cin >> tp;

            if (tp == 'C') {
                maxi[0] = 0;
                maxi[1] = 0;
                scanf("%d %d", &lo, &hi);
                consulta(lo-1, hi-1, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
                printf("%lld %lld\n", maxi[0], maxi[1]);
            }
            else
            {
                scanf("%d %d %d", &lo, &hi, &val);
                atualiza(lo-1, hi-1, val, 0, 0, (1<<(MAX_NIVEIS-1)) - 1);
            }
            
            
        }
        
        
        break;        
    }
    
    return 0;
}