#include <iostream>
int main()
{
    int n=13;
    int d=2;
    for(int i=n-1;i>1;i--)
    {
        int ret=0;
        while (ret<n)
        {
            if (i==0)
                break;
            if (ret >=n)
                break;
            ret+=i;
            i=i/d;
        }
        printf("ret : %d,i: %d\n",ret, i);
    }
}