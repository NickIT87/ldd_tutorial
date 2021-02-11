#include <stdio.h>
#include <stdlib.h>     /* для объявления atof() */

#define MAXOP 100       /* максимальный размер операнда */
#define NUMBER '0'      /* сигнал, что обнаружено число */

int getop(char s[]);
void push(double);
double pop(void);

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divizor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
/* part 2 */
#define MAXVAL      /* максимальная глубина стека val */

int sp = 0;         /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек операндов */

/* push: помещает число в стек операндов */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can`t push %g\n", f);
}