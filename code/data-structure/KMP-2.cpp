//字符串匹配算法KMP
/*
　　next 表的每一位反映该位失配后回退的地方，它是由前一位字符在整个前子字符串中最长公共前后缀的长度值所决定
（说的有些绕口。。），我们还是直接看下面的总结：
①、第一位字符的 next 值设置为 - 1，因为当第一位就开始失配，直接将模式串下移一位即可，无需多说。
同样道理，第二位也一样，其前子字符串仅一个字符，所以 next 值即为 0。
②、后面的，当某位前一位字符的前一个字符对称程度为 0 的时候，只要将该位前一位字符与子串第一个字符进行比较即可。
例如 abcdae，因为 “d” 字符与前面无对称项，所以只需要比较 a 和开头字符比较即可。
③、以此推理，如果某位前一位字符的 next 值是 1，即该位前一位字符的前一个字符与开头字符相等，
那么我们就把该位前一位字符与子串第二个字符进行比较，如果也相等，说明对称程度就是 2 了，
即该位的 next 值为 2。
④、当然如果一直相等，就一直一位位累加继承。但是绝大多数不可能会如此顺利对称下去，
如果遇到下一个不相等了，那么说明不能继承前面的对称性了。这种情况只能说明没有那么多对称了，
但是不能说明一点对称性都没有，所以遇到这种情况就要重新来考虑，这个也是难点所在。
④、一旦发生不能累加继承，则需要在对称的前后缀字符串中继续寻找子对称。
《部分匹配表》是如何产生的。
　　首先，要了解两个概念："前缀" 和 "后缀"。 "前缀" 指除了最后一个字符以外，
一个字符串的全部头部组合；"后缀" 指除了第一个字符以外，一个字符串的全部尾部组合。
关键是创建next数组，就是找出模式串中的最长公共前后子序列,
返回失配位之前最长公共前后缀对应的前缀后一位的地方
"部分匹配值" 就是 "前缀" 和 "后缀" 的最长的共有元素的长度。以 "ABCDABD" 为例，
　　－　"A" 的前缀和后缀都为空集，共有元素的长度为 0；
　　－　"AB" 的前缀为 [A]，后缀为 [B]，共有元素的长度为 0；
　　－　"ABC" 的前缀为 [A, AB]，后缀为 [BC, C]，共有元素的长度 0；
　　－　"ABCD" 的前缀为 [A, AB, ABC]，后缀为 [BCD, CD, D]，共有元素的长度为 0；
　　－　"ABCDA" 的前缀为 [A, AB, ABC, ABCD]，后缀为 [BCDA, CDA, DA, A]，共有元素为 "A"，
长度为 1；
　　－　"ABCDAB" 的前缀为 [A, AB, ABC, ABCD, ABCDA]，后缀为 [BCDAB, CDAB, DAB, AB, B]，
共有元素为 "AB"，长度为 2；
　　－　"ABCDABD" 的前缀为 [A, AB, ABC, ABCD, ABCDA, ABCDAB]，
后缀为 [BCDABD, CDABD, DABD, ABD, BD, D]，共有元素的长度为 0。
*/
#include<cstring>
#include<cstdio>
#define N 100
//构建模式串的next数组，即找出模式串每个字符对应的最长公共前后缀长度
int *getNext(char *p,int next[])
{
    int len = strlen(p);
    int j =0;
    //next 表示长度为 i 的字符串前缀和后缀的最长公共部分，从 1 开始
    next[0] = next[1] = 0;
    for(int i=1; i<len; i++) //i 表示字符串的下标，从 0 开始
    {
        //j 在每次循环开始都表示 next[i] 的值，同时也表示需要比较的下一个位置
        while(j>0 && p[i]!=p[j])
            j = next[j];
        if(p[i] == p[j])// j记录公共前后缀长度,相同的话最大公共前后缀++
            j++;
        next[i+1] = j;
    }
    return next;
}
int KMP_search(char *t,char *p,int next[])
{
    int j=0;
    int lent = strlen(t);
    int lenp = strlen(p);
    for(int i=0; i<lent; i++)
    {
        while(j>0 && t[i]!= p[j])//t[i]和p[i]不匹配
            j = next[j];//往前回溯
        if(t[i] == p[j])
            j++;
        if(j == lenp)
        {
            return i-j+1;//返回相应的位置
            j = next[j];
        }
    }
    return -1;
}
int main()
{
    char p[N],t[N];
    printf("请输入文本串和模式串\n");
    scanf("%s%s",t,p);
    int next[N+1];
    int pos ;
    pos =  KMP_search(t,p,getNext(p,next));
    for(int i=0;i<10;i++)
        printf("next[%d] = %d\n",i,next[i]);
    printf("已经成功匹配,模式串在文本串中的第一个数组下标为: %d\n",pos);
    return 0;
}
