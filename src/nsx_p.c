#include<unistd.h>
#include<stdarg.h>
void nsx_pchar(char c)
{
    write(1,&c,1);
}
void nsx_pcharnl(char c)
{
    nsx_pchar(c);
    nsx_pchar('\n');
}
void nsx_pstr(char *s)
{
    int len = 0;
    while( s[len++] );
    write(1,s,len);
}
void nsx_pstrnl(char *s)
{
    nsx_pstr(s);
    nsx_pchar('\n');
}
void nsx_pint(int n)
{
    char buffer[12];
    int i = 11;
    buffer[i--] = '\0';
    if(n == 0)
    {
        nsx_pchar('0');
        return;
    }
    if(n == -2147483648)
    {
        nsx_pstr("-2147483648");
        return;
    }
    if(n < 0)
    {
        nsx_pchar('-');
        n *= -1;
    }
    while(n)
    {
        buffer[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    nsx_pstr(&buffer[i+1]);
}
void nsx_pintnl(int n)
{
    nsx_pint(n);
    nsx_pchar('\n');
}
void nsx_plong(long n)
{
    char buffer[100];
    int i = 11;
    buffer[i--] = '\0';
    if(n == 0)
    {
        nsx_pchar('0');
        return;
    }
    if(n == -2147483648)
    {
        nsx_pstr("-2147483648");
        return;
    }
    if(n < 0)
    {
        nsx_pchar('-');
        n *= -1;
    }
    while(n)
    {
        buffer[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    nsx_pstr(&buffer[i+1]);
}
void nsx_plongnl(long n)
{
    nsx_plong(n);
    nsx_pchar('\n');
}
void nsx_pp(void* nb)
{
    long n = (long)nb;
    int buffmax = 100;
    char base[] = "0123456789abcdef";
    char buffer[buffmax];
    int i = buffmax-1;
    buffer[i--] = '\0';
    if(n == 0)
    {
        nsx_pstr("0x0");
        return;
    }
    if(n < 0)
    {
        nsx_pchar('-');
        n*= -1;
    }
    while(n)
    {
        buffer[i] = base[(n % 16)];
        n /= 16;
        i--;
    }
    nsx_pstr("0x");
    nsx_pstr(&buffer[i+1]);
}
void nsx_ppnl(void* n)
{
    nsx_pp(n);
    nsx_pchar('\n');
}
void nsx_p(char *format, ...)
{
    va_list list;
    va_start(list,format);
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            if(*format == 's')
                nsx_pstr(va_arg(list,char *));
            else
            if(*format == 'd')
                nsx_pint(va_arg(list,int));
            else
            if(*format == 'p')
                nsx_pp(va_arg(list,void*));
            else
            if(*format == '%')
                nsx_pchar('%');
            else
                nsx_pchar(*format);
            format++;
        }
        else
            nsx_pchar(*format++);
    }
    va_end(list);
}