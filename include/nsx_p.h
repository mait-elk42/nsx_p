#ifndef _NSX_P
#define _NSX_P
void nsx_pchar(char c);
void nsx_pcharnl(char c);
void nsx_pstr(char *s);
void nsx_pstrnl(char *s);
void nsx_pint(int n);
void nsx_pintnl(int n);
void nsx_pp(void* nb);
void nsx_ppnl(void* n);
void nsx_p(char *format, ...);
#endif