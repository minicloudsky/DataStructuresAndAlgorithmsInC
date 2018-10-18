#include<stdio.h>
#include <iostream>
using namespace std;
typedef unsigned char byte;
// ת��char����Ϊ�������ͣ�Ϊ16�����ַ���
void ChtoHex(byte Val, char* dest)
{
    // շת����������򿴵õ����
    byte tmp = Val % 16;
    if (tmp >= 0 && tmp <= 9)
        dest[1] = '0' + tmp;
    else if (tmp >= 10 && tmp <= 15)
        dest[1] = 'A' + tmp - 10;
    tmp = (Val/16) % 16;
    if (tmp >= 0 && tmp <= 9)
        dest[0] = '0' + tmp;
    else if (tmp >= 10 && tmp <= 15)
        dest[0] = 'A' + tmp - 10;
    // ����'\0'
    dest[2] = '\0';
}

// ������
int main(){
    int u = 367328153; // ԭʼ���ݣ�8λ16����Ϊ15 E4 FB 99
    byte a, b, c, d;   // u�ӵ͵�ַ���ߵ�ַ���ĸ��ֽ�
    // a~d��Ӧ��16�����ַ�����Ԥ��3���ַ�
    char Sa[3], Sb[3], Sc[3], Sd[3];
    byte* k = (byte*)&u;
    a = k[0];
    b = k[1];
    c = k[2];
    d = k[3];
    // ת��16�����ַ���
    ChtoHex(a, Sa);
    ChtoHex(b, Sb);
    ChtoHex(c, Sc);
    ChtoHex(d, Sd);
    cout << Sa << " " << Sb << " " << Sc << " " << Sd << endl;
    return 0;
}
