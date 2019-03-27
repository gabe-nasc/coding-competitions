#include <bits/stdc++.h>

using namespace std;

#define MAX (100100)

int m[MAX], v[MAX], ram[MAX][22][2]; // Marcados, Valores, Memoria [pos][marc][lembra/resultado]

int soma(int pos, int marc){
    if (marc < 0) // Não há como ter um numero negativo de caras marcados
    {
        return -1e9;
    }

    if (pos < 0) // Posição negativa
    {
        if (marc == 0) // Se eu não quero ninguém marcado
        {
            return 0;
        }
        return -1e9;
    }

    if (ram[pos][marc][0])
    {
        return ram[pos][marc][1];
    }

    ram[pos][marc][0] = 1;

    if (m[pos]) // Se está marcado
    {
        if (marc == 1) // Porém quero apenas um marcado
        {
            return ram[pos][marc][1] = max(0, soma(pos-1, marc-1))+v[pos]; // Vejo se as somas anteriores são maiores que zero
        }
        return ram[pos][marc][1] = soma(pos-1, marc-1) + v[pos];

    }

    if (marc == 0) // E eu não quero marcados
    {
        return ram[pos][marc][1] = max(0, soma(pos-1, marc)) + v[pos];
    }
    
    return ram[pos][marc][1] = soma(pos-1, marc) + v[pos];
}

int main(void){
    int n, lo, hi;

    cin >> n >> lo >> hi;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    int ans = -1e9;

    for (size_t i = 0; i < n; i++)
    {
        for(int j = lo; j <= hi; j++){
            ans = max(ans, soma(i, j));
        }
    }

    cout << ans << "\n";
}