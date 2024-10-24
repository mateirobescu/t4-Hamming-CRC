#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    
    printf("Alegeti intre CRC - Transmite (1) si Hamming - Receptie (2): ");
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1)
    {
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
    }
    else if(choice == 2)
    {
        printf("Introduceti codul Hamming: ");
        char cod_str[128];
        scanf("%s", cod_str);
        
        int cod[128], len_cod = strlen(cod_str);
        
        for(int i = 0; i < len_cod; i++)
            cod[i] = cod_str[i] - 48;
        
        int c = len_cod, bytesize = 0;
        
        while(c)
        {
            bytesize++;
            c /= 2;
        }
        
        int mat[128][128];
        
        for(int i = 1; i <= len_cod; i++)
        {
            int nr = i;
            for(int j = bytesize - 1; j >= 0; j--)
            {
                mat[j][i-1] = nr % 2;
                nr /= 2;
            }
        }
            
        int e[128];
        
        for(int i = 0; i < bytesize; i++)
        {
            int x = -1;
            for(int j = 0; j < len_cod; j++)
                if(mat[i][j] == 1)
                {
                    if(x == -1)
                        x = cod[j];
                    else
                        x = x ^ cod[j];
                }
            e[i] = x;
        }
        
        int p = 1, e_nr = 0;
        for(int i = bytesize - 1; i >= 0; i--)
        {
            e_nr += e[i] * p;
            p *= 2;
        }
        
        if(e_nr == 0)
            printf("Codul este corect!\n");
        else if(e_nr - 1 < len_cod)
        {
            printf("Codul are o singura eroare si aceasta a fost corectata!\n");
            cod[e_nr - 1] = cod[e_nr - 1] ^ 1;
        }
        else
            printf("Exista mai mult de o eroare!\n");
        
        for(int i = 0; i < len_cod; i++)
            printf("%d", cod[i]);
        
        printf("\n");
        
    }
    else
    {
        printf("Alege incorecta!");
    }
    
    return 0;
}
