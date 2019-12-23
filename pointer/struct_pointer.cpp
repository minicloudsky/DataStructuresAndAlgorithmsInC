#include <stdio.h>
#define STNUM 30 /* 全班同学人数 */
struct stuinf
{
    int stid; /* 学生学号 */
    int score; /* 学生成绩 */
} stu[STNUM]; /* stu: 结构数组 */
int main ()
{
    struct stuinf *ptemp, /* ptemp:指向结构的指针, 临时变量 */
               *p[STNUM]; /* p:指向结构的指针构成的指针数组 */
    int i, j, k, sum=0; /* i,j,k:临时变量；sum:分数累计 */
    for (i=0; i<=STNUM-1; i++) /* 输入学生的学号和成绩 */
    {
        scanf ("%d %d", &stu[i].stid, &stu[i].score); /* 输入学生的学号和成绩 */
        p[i] = &stu[i];
        /* 指针数组p[i]的第i个指针(元素)指向结构数组的第i个元素 */
        sum += stu[i].score;
        /* 累计学生的分数 */
    }
    for ( i=0; i<=STNUM-2; i++ ) /* 排序操作 */
    {
        k = i; /* k：在第i次循环中，指向当前最高分的指针在指针数组p中的下标 */
        for (j=i; j<=STNUM-1; j++)
            if (p[k]->score < p[j]->score) k=j;
        /* 查找当前最大值, k中存放最大值对应的指针在指针数组p中的下标 */
        if ( k!=i ) /* 当k不等于i时，交换两个指向结构的指针 */
        {
            ptemp = p[i];
            p[i] = p[k];
            p[k] = ptemp;
        }
    }
    for (i=0; i<=STNUM-1; i++) /* 按排序顺序输出学号和成绩 */
        printf("%d,%d/n", (*p[i]).stid, p[i]->score);
    printf ("average score = %d/n", sum/STNUM); /* 输出平均分 */
}
