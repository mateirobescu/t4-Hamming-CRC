#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    
    char m_str[21], g_str[21];
    int M[20], G[20], len_m, len_g;
    
    printf("Intrudoceti bitii specifici polinomului M(x): ");
    scanf("%s", m_str);
    
    len_m = strlen(m_str);
    for(int i = 0; i < len_m; i++)
        M[i] = m_str[i] - 48;
    
    printf("Intrudoceti bitii specifici polinomului G(x): ");
    scanf("%s", g_str);
    
    len_g = strlen(g_str);
    for(int i = 0; i < len_g; i++)
        G[i] = g_str[i] - 48;
    
    
    return 0;
}
