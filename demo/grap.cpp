#include <iostream>
#include <stdlib.h>
using namespace std;

#define N 100
//79846
int op_num;
int str_len;
int vis[N];
int a[N];
char s[N];
int sum=9999;

int get_value(int begin,int end)
{
    int sum=0;
    for(int i=begin;i<end;i++){
        sum*=10;
        sum+=s[i]-'0';
    }

    return sum;
}

void dfs(int cur)
{
    if(cur==op_num){

        if(a[0]>str_len/2){
            return ;
        }
        /*剔除无效加号序列*/
        for(int i=0;i<op_num;i++){
            if(a[i]==0){
                return ;
            }
        }

        int op_position[N];

        op_position[0]=0;
        for(int i=1;i<=op_num;i++){
            op_position[i]=a[i-1];
        }

        int temp_sum=0;
        for(int i=0;i<op_num;i++){
            int temp=get_value(op_position[i],op_position[i+1]);
            temp_sum+=temp;
        }

        if(op_position[op_num]<str_len){

            int temp=get_value(op_position[op_num],str_len);
            temp_sum+=temp;
        }

        if(sum>temp_sum){
            sum=temp_sum;
        }
        return ;
    }

    for(int i=0;i<str_len;i++){
        if(!vis[i]){
            vis[i]=1;
            a[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}

int main()
{
    cin>>str_len;
    cin>>op_num;
    cin>>s;
    dfs(0);
    cout<<sum<<endl;
    return 0;
}
