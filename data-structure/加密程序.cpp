#include "stdio.h"
struct table
{
    char input, output;
} ;
struct table translate[ ]=
{
    'a', 'd', 'b', 'w', 'c', 'k', 'd', ';', 'e', 'i',
    'i', 'a', 'k', 'b', ';', 'c', 'w', 'e'
};
int main()
{
    char ch;
    struct table *p, *pend; /* p��pendΪָ��ṹtable��ָ�� */
    pend = & translate[ sizeof(translate)/sizeof(struct table)-1 ];
    //printf("%c %d\n",pend,(int)pend);
    /* pendָ��ṹ����translate�����һ��Ԫ�� */
    while ( (ch=getchar( )) != '/n')
    {
        for ( p=translate ; p->input!=ch && p!=pend; p++ ) ;
        if ( p->input==ch )
            putchar( p->output);
        else
            putchar (ch);
    }
}
