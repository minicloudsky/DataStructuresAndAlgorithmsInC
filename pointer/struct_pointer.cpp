#include <stdio.h>
#define STNUM 30 /* ȫ��ͬѧ���� */
struct stuinf
{
    int stid; /* ѧ��ѧ�� */
    int score; /* ѧ���ɼ� */
} stu[STNUM]; /* stu: �ṹ���� */
int main ()
{
    struct stuinf *ptemp, /* ptemp:ָ��ṹ��ָ��, ��ʱ���� */
               *p[STNUM]; /* p:ָ��ṹ��ָ�빹�ɵ�ָ������ */
    int i, j, k, sum=0; /* i,j,k:��ʱ������sum:�����ۼ� */
    for (i=0; i<=STNUM-1; i++) /* ����ѧ����ѧ�źͳɼ� */
    {
        scanf ("%d %d", &stu[i].stid, &stu[i].score); /* ����ѧ����ѧ�źͳɼ� */
        p[i] = &stu[i];
        /* ָ������p[i]�ĵ�i��ָ��(Ԫ��)ָ��ṹ����ĵ�i��Ԫ�� */
        sum += stu[i].score;
        /* �ۼ�ѧ���ķ��� */
    }
    for ( i=0; i<=STNUM-2; i++ ) /* ������� */
    {
        k = i; /* k���ڵ�i��ѭ���У�ָ��ǰ��߷ֵ�ָ����ָ������p�е��±� */
        for (j=i; j<=STNUM-1; j++)
            if (p[k]->score < p[j]->score) k=j;
        /* ���ҵ�ǰ���ֵ, k�д�����ֵ��Ӧ��ָ����ָ������p�е��±� */
        if ( k!=i ) /* ��k������iʱ����������ָ��ṹ��ָ�� */
        {
            ptemp = p[i];
            p[i] = p[k];
            p[k] = ptemp;
        }
    }
    for (i=0; i<=STNUM-1; i++) /* ������˳�����ѧ�źͳɼ� */
        printf("%d,%d/n", (*p[i]).stid, p[i]->score);
    printf ("average score = %d/n", sum/STNUM); /* ���ƽ���� */
}
