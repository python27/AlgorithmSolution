#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * ��̬��̨��
 *
 * �����������һ���ĸ߶Ȼ���:
 * ���һ����Ծ1,��ǰ����f(n-1)������
 * ���һ����Ծ2,��ǰ����f(n-2)������
 * �Դ�����...
 * ���� f(n)=f(n-1)+f(n-2)+...f(0)
 * ����f(0)����1��ͨ���򵥵�ö�ٺܿ췢���������
 * ��һ��ָ������
 */

int jumpFloorII(int number) {
    if (number == 0) return 0;
    else return pow(2, number-1);

}
