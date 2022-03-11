#include  <stdio.h>

int main ()

{
    int watts, lumens;

    printf ("Enter the Value of Watts:");
    scanf("%d",& watts);

    switch(watts)
    {
        case 15:
        lumens= 125;
        printf("Brightness (in lumens):%d\n",lumens);
        break;

        case 25:
        lumens= 215;
        printf("Brightness (in lumens):%d\n", lumens);
        break;

        case 40:
        lumens= 500;
        printf(" Brightness (in lumens):%d\n", lumens);
        break;

        case 60:
        lumens= 880;
        printf(" Brightness (in lumens) :%d\n", lumens);
        break;

        case 75:
        lumens= 1000;
        printf(" Brightness (in lumens) :%d\n", lumens);
        break;

        case 100:
        lumens= 1675;
        printf(" Brightness (in lumens) :%d\n", lumens);
        break;

        default:
        lumens= -1 ;
        printf(" Brightness (in lumens) :%d\n", lumens);
        break ;
    }

    return 0;
}
