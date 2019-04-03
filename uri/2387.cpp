#include <bits/stdc++.h>

using namespace std;

/*
-> Quantos agendamentos no máximo?
-> Quantos agendamentos do tempo X em diante?
    -> Algum agendamento começa em X?
        Não: quantos agendamentos [x+1:]
        Sim: max(# agendamentos [x+1:], 1 + # agendamentos [y:])
*/

int horarios[1001000];
// int res[1001000][1001000];

int conta(int init, int fim){
    // printf("%d, %d\n", init, fim);
    if (init == fim)
    {
        return 0;
    }

    if (horarios[init] != 0)
    {
        return max(conta(init, fim), conta(horarios[init], fim)+1);
    }

    else
    {
        return conta(init+1, fim);
    }
}

int main(){
    int n, a, b, mini = 1e9;

    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        mini = min(a, mini);
        if(horarios[a] != 0){
            horarios[a] = min(b, horarios[a]);
        }
        else
        {
            horarios[a] = b;
        }
    }
    // printf("> %d", a);
    printf("%d", conta(mini, a));
}

