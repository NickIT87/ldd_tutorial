/* #include-директивы */
#include <stdio.h>
#include <stdlib.h>     /* для объявления atof() */
#include <ctype.h>      /* проверка типов isdigit() */
/* #define-директивы */
#define MAXOP 100       /* максимальный размер операнда */
#define NUMBER '0'      /* сигнал, что обнаружено число */
#define MAXVAL 100      /* максимальная глубина стека val */
#define BUFSIZE 100     /* размер буфера для ungetch */
/* Объявления функций, используемых в main */
void push(double);      /* push: помещает число в стек операндов */
double pop(void);       /* извлекает и возвращает верхнее число из стека */
int getop(char s[]);    /* getop: извлекает следующий операнд или знак операции */
int getch(void);        /* ввод символа (возможно, возвращенного в поток) */
void ungetch(int);      /* возвращение символа в поток ввода */
/* внешние переменные для функций push и pop */
int sp = 0;             /* следующая свободная позиция в стеке */
double val[MAXVAL];     /* стек операндов */
/* внешние переменные для функций getch и ungetch */
char buf[BUFSIZE];      /* буфер для ungetch */
int bufp = 0;           /* следующая свободная позиция в buf */
/* main */
/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)    /* цикл ввода: очередной знак или операнд - не конец файла */ 
    {
        switch (type) 
        {
            case NUMBER:                /* если число */
                push(atof(s));          /* поместить операнд в стек */
                break;
            case '+':                   /* если знак операции '+' (коммутативная) */
                push(pop() + pop());    /* порядок извлечения аргументов из стека не имеет значения */
                break;
            case '*':                   /* если знак операции '*' (коммутативная) */
                push(pop() * pop());    /* порядок извлечения аргументов из стека не имеет значения */
                break;
            case '-':                   /* если знак операции '-' (Порядок важен) */
                op2 = pop();            /* извлечь операнд из стека, */
                push(pop() - op2);      /* выполнить операцию, поместить результат в стек */
                break;
            case '/':                   /* если знак операции '/' (Порядок важен) */
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divizor\n");
                break;
            case '\n':                  /* конец строки */
                printf("\t%.8g\n", pop());  /* извлечь и вывести верх стека */
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
/* push: помещает число в стек операндов */
void push(double f)
{
    if ( sp < MAXVAL ) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can`t push %g\n", f);
    }
}
/* извлекает и возвращает верхнее число из стека */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
/* getop: извлекает следующий операнд или знак операции */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        /* code */;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;           /* not a number */
    i = 0;
    if (isdigit(c)) {       /* накопление целой части */
        while (isdigit(s[++i] = c = getch()))
        {
            /* code */;
        }
    }
    if (c == '.')           /* накопление дробной части */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
/* ввод символа (возможно, возвращенного в поток) */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
/* возвращение символа в поток ввода */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}