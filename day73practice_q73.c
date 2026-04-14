#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    
    printf("Enter string: ");
    scanf("%s", s);
    
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }
    
    for (int i = 0; i < strlen(s); i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    
    printf("$\n");
    return 0;
}