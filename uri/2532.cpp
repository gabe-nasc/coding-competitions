#include <bits/stdc++.h>

using namespace std;

int spells[1010];

int damage(){
    
}

void main() {
    int n, hp, a, b, dmg_total = 0;
    scanf("%d%d", &n, &hp);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        if (spells[a] != 0)
        {
            spells[a] = max(b, spells[a)];    
        }
        else
        {
            spells[a] = b;
            dmg_total += a;
        }
    }

    if (dmg_total < hp)
    {
        printf("%d", -1);
    }
}