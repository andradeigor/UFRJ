Nome: Igor de Andrade Assunção de Almeida

DRE:121095736

Atividade: Lista 3

Questão1

1) Supondo que A, B e C são variáveis do tipo inteiro, com valores iguais a 5, 10 e -8, respectivamente,
uma variável D com valor de 1.5 e uma variável lógica L cujo valor é falso (= 0), quais os valores de X
obtidos nas expressões aritméticas apresentadas em seguida?

        a)2*A % 3-C = 9
        b)(-2*C )/4 = 4  
        c)((B/3)/3) +D*C/2 = -5
        d)(-C*2)+(D+B)/A = 18
        e)A*C & (L|B) = 8
        f)(!L+A<C|C+C*B>=1&1) = 0//False

2) Diga se as seguintes expressões serão verdadeiras ou falsas:

        a) ((10>5)||(5>10)) = True
        b) (!(5==6) && (5!=6) && ((2>1) || (5<=4))) = True
        c) (11 > 2 ) && (5 > 30) = False
        d) (11 > 2 ) || (3 > 30) = True

3) Diga o que será impresso em x, y e z depois da seguinte sequência de operações:


        #include <stdio.h>
        int main () {
            int x,y,z;
            x=y=10;
            z=++x;
            x=-x;
            y++; 
            x=x+y-(z--); 
            printf ("Valores de x %d, y %d e z %d\n", x, y, z);
            return 0;
        }
        Valores de x -11, y 11 e z 10

4) Indique o resultado das expressões, sendo:

        x=6.0; y=2; z=4.0; a=8; b=7.5; c=12;
        a) x - y * ++a = -12;
        b) x - y * a > c % y = 0 False;
        c) y != c = 1 True
        d) c % y <= y % c = 1 True
        e) !(a>b) = 0 False
        f) ( ( z / a ) + b * --y ) = 8.0;
        g) (c=7) || (b<2) = 1 True
        h) (c=7) && (b<2) = 0 False