<h1>Домашняя работа к лабораторной №13</h1>
<h2>Выполнил: Кравченко А.С.</h2>

<h1>вариант 14</h1>
<h2>Условие задачи</h2>
Составить программу, которая во введенной пользователем строке подсчитывает, сколько слов имеют указанную пользователем длину.

<h2>Алгоритм</h2>

```
1. Начало.
2. Инициализируем переменные char text[99], int t, int c = 0, int c_t = 0, int in_word = 0.
3. Если fgets(text, sizeof(text), stdin == NULL:
    printf("Ошибка ввода строки!\n");
    return 1.
4. Вычисляем длину строки size_t len = strlen(text).
5. Если len > 0 && text[len - 1] == '\n':
    text[len - 1] = '\0'.
6. Вводим длину слова k.
7. Пока i = 0; text[i] != '\0'; i++:
    Если isalpha((unsigned char)text[i]) || text[i] == '\'':            
        Если !in_word:
            in_word = 1;
            c_t = 0;
        c_t++;
    Иначе:           
        Если in_word:                
            если c_t == t:
                c++;
            in_word = 0;
            c_t = 0;  
   Если in_word && c_t == t:
    c++;    
   printf("В строке найдено %d слов длиной %d символов.\n", c, t);
   return 0.
8. Конец.
```

<h2>Код программы</h2>

```
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
```

<h2>Схема</h2>

<h2>Консоль</h2>
<img width="638" height="86" alt="image" src="https://github.com/user-attachments/assets/0526dbff-a0dd-4d82-aa57-693051881103" />
