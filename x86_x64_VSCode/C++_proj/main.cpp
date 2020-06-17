#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int copy(char to[], char from[], int dlina);

int main() {
    int dlina_tt;           // Длина текущей строки (tt - Текущий текст)
    int max_t;             // Кол-во символов необходимое для записи в самые длинные строки
    int dlina_dt;          // Длина длинного текста
    char t[MAXLINE];       // Текущая введенная строка
    char dt[MAXLINE];  // Все строки, длина которых превышает 80 символов

    // for (int i =0;i<=MAXLINE;i++)
    //     dt[i] = '1'; 

    dlina_dt = 0;
    max_t = 5;
    while ((dlina_tt = getline(t, MAXLINE)) > 0) {
        if (dlina_tt > max_t) {
            //copy(dt, t, dlina_dt);
            dlina_dt = copy(dt, t, dlina_dt);
        }
        printf("%s", dt);
    }
    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int copy(char to[], char from[], int dlina) {
    int i;
    int p;

    p = 0;
    i = dlina;
    while (from[p] != '\0') {
        to[i] = from[p];
        ++i;
        ++p;
    }
    to[i] = '\0';
    return i;
    // if (to[i] == '\0') {
    //     return i;
    //     ++i;
    //     to[i] = '\n';
    // }
    //p = 0;
}
