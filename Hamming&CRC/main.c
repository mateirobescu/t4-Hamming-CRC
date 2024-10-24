#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    
    char m_str[24], g_str[21];
    int M[23] = {0}, T[23], G[20], len_m, len_g;
    
    printf("Intrudoceti bitii specifici polinomului M(x): ");
    scanf("%s", m_str);
    
    len_m = strlen(m_str);
    for(int i = 0; i < len_m; i++)
    {
        M[i] = m_str[i] - 48;
        T[i] = M[i];
    }
    
    printf("Intrudoceti bitii specifici polinomului G(x): ");
    scanf("%s", g_str);
    
    len_g = strlen(g_str);
    for(int i = 0; i < len_g; i++)
        G[i] = g_str[i] - 48;
    
    int m_start = 0;
    len_m += (len_g - 1);
    
    while (len_m - m_start >= len_g) {
        for(int i = 0; i < len_g; i++)
        {
            M[i + m_start] = M[i + m_start] ^ G[i];
        }
        
        while(M[m_start] == 0)
            m_start++;
    }
    
    for(int i = len_m - len_g + 1; i < len_m; i++)
        T[i] = M[i];
        
    printf("T: ");
    for(int i = 0; i < len_m; i++)
        printf("%d", T[i]);
    
    printf("\nT(x): ");
    int ok = 0;
    
    for(int i = 0; i < len_m; i++)
        if(T[i] == 1)
        {
            if(ok)
                printf(" + ");
            printf("x^%d", len_m - 1 - i);
            ok = 1;
        }
    printf("\n");
    
    return 0;
}
