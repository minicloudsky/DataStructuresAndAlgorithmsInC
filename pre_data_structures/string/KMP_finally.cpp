#include<cstring>
#include<cstdio>
void cal_next(char *str, int *next)
{
    int len = strlen(str);
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;//k初始化为-1
    for (int q = 1; q <= len-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        {
            k = next[k];//往前回溯
        }
        if (str[k + 1] == str[q])//如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}
int KMP(char *str,char *ptr)
{
    int slen = strlen(str);
    int plen = strlen(ptr);
    int *next = new int[plen];
    cal_next(ptr, next);//计算next数组
    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i])//ptr和str不匹配，且k>-1（表示ptr和str有部分匹配）
            k = next[k];//往前回溯
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//说明k移动到ptr的最末端
        {
            //cout << "在位置" << i-plen+1<< endl;
            //k = -1;//重新初始化，寻找下一个
            //i = i - plen + 2;//i定位到找到位置处的下一个位置（这里默认存在两个匹配字符串可以部分重叠）
            return i-plen+1;//返回相应的位置
        }
    }
    return -1;
}
int main()
{
    char *str = "abcabdababaca";
    char *ptr = "ababaca";
    int a = KMP(str,ptr);
    printf("%d\n",a);
    return 0;
}
