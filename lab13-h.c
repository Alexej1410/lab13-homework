#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "RUS");
    char text[99];
    int t;
    int c = 0;
    int c_t = 0;
    int in_word = 0;
    printf("Введите строку: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Ошибка ввода строки!\n");
        return 1;
    }
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
    printf("Введите длину слова для поиска: ");
    scanf("%d", &t);
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i]) || text[i] == '\'') {            
            if (!in_word) {
                in_word = 1;
                c_t = 0;
            }
            c_t++;
        }
        else {           
            if (in_word) {                
                if (c_t == t) {
                    c++;
                }
                in_word = 0;
                c_t = 0;
            }
        }
    }   
    if (in_word && c_t == t) {
        c++;
    }    
    printf("В строке найдено %d слов длиной %d символов.\n", c, t);
    return 0;
}