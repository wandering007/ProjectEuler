#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#define MAXN 4000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

bool isPenta(LL val)
{//��ʽ���ж�val�ǲ���Pentagon number
    LL delta = (LL)round(sqrt(1 + 24 * val));
    if(delta * delta != 1 + 24 * val)
        return false;
    if((1+delta) % 6)
        return false;
    return true;
}

int main()
{
    clock_t start;
    double duration;
    start = clock();
    LL Pk, Pj, D = -1LL;
    for(LL k = 2LL; ; k++)
    {
        if(D != -1LL && 3 * k - 2 >= D)//3*k-2��Pk��P(k-1)�Ĳ�ֵ
        //�޷����ֱȵ�ǰD��С�Ĳ�ֵ��˵����Сֵ�Ѿ��ҵ�
            break;
        Pk = k * (3 * k - 1) / 2;
        for(LL j = k - 1; j > 0; j--)//��k-1��ʼ����ֵ����
        {
            Pj = j * (3 * j - 1) / 2;
            if(D != -1LL && Pk - Pj >= D)//��ǰ��D�ȵ�ǰ�Ĳ�ֵС����ڣ�û��Ҫ�ٽ�����ȥ
                break;
            if(isPenta(Pk - Pj) && isPenta(Pk + Pj))
			// 1.���θ�ֵ��2.������ֱȵ�ǰD(D != -1LL)��С�Ĳ�ֵ������D(��ʵ˵�����������2)
                D = Pk - Pj;
        }
    }
    printf("%I64d\n", D);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
