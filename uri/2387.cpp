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

int conta(int init, int fim){
    if (horario[init] != 0)
    {
        return max(conta(init, fim), conta(horario[init], fim)+1)
    }

    else
    {
        return conta(init+1, fim);
    }
}

void main(){
    int n, a, b, mini;

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

    printf("%d", conta(mini, a))
}

