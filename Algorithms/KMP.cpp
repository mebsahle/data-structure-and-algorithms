// author @mebsahle 

#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100010
char T[MAX_N], p[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P
void kmpPreprocess(char P[], int m)   // call this before calling kmpSearch()
{
    cout << "size of b" << m <<endl;
    int i = 0, j = -1;
    b[0] = -1; // starting values
    while (i < m)   // pre-process the pattern string P
    {
        while (j >= 0 && P[i] != P[j])
            j = b[j]; // different, reset j using b
        i++;
        j++; // if same, advance both pointers
        b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
    }
    for(int j = 0; j < sizeof(m)+1; j++){
        cout << P[j] << " ";
    }
    cout << endl;
    for(int j = 0; j < sizeof(m)+1; j++){
        cout << b[j] << " ";
    }
    cout << endl;

} // in the example of P = "SEVENTY SEVEN" above
void kmpSearch(char T[], char P[], int n, int m)   // this is similar as kmpPreprocess(), but on string T
{
    int i = 0, j = 0; // starting values
    while (i < n)   // search through string T
    {
        while (j >= 0 && T[i] != P[j])
            j = b[j]; // different, reset j using b
        i++;
        j++; // if same, advance both pointers
        if (j == m)   // a match found when j == m
        {
            cout << "P is found at index " << i-j << " in T\n";
            j = b[j]; // prepare j for the next possible match
        }
    }
}

int main()
{
    char T[] = {'I', ' ', 'D', 'O', ' ', 'N', 'O', 'T', ' ',
                'L', 'I', 'K', 'E', ' ', 'S', 'E', 'V', 'E', 'N', 'T', 'Y', ' ', 'S', 'E', 'V', ' ', 'B', 'U', 'T', ' ',
                'S', 'E', 'V', 'E', 'N', 'T', 'Y', ' ', 'S', 'E', 'V', 'E', 'N', 'T', 'Y', ' ', 'S', 'E', 'V', 'E', 'N'};
    char P[] = {'S', 'E', 'V', 'E', 'N', 'T', 'Y', ' ', 'S', 'E', 'V', 'E', 'N'};
//    cout << sizeof(P)/sizeof(P[0]);

    n = sizeof(T)/sizeof(T[0]);
    m = sizeof(P)/sizeof(P[0]);
    kmpPreprocess(P, m);
    kmpSearch(T, P, n, m);
    return 0;
}
