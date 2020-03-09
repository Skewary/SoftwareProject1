// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>

using namespace std;

class Dots {
public:
    double DotX;
    double DotY;
    Dots() {
        DotX = 0;
        DotY = 0;
    }
    Dots(double X, double Y) {
        DotX = X;
        DotY = Y;
    }
};
class DotsCmp {
public:
    bool operator()(const Dots& dotA, const Dots& dotB) const{
        if (dotA.DotX == dotB.DotX) {
            return (dotA.DotY < dotB.DotY);
        }
        else {
            return (dotA.DotX < dotB.DotX);
        }
    }
};
typedef set<Dots, DotsCmp> DotsSet;


double DotX, DotY;
void CalDot(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3) {
    double k1, k2;
    if (x0 != x1) {
        k1 = (y0 - y1) / (x0 - x1);//if x0 == x1  error
        if (x2 != x3) {
            k2 = (y2 - y3) / (x2 - x3);//
            if (k1 != k2) {
                DotX = (k1 * x0 - k2 * x2 + y2 - y0) / (k1 - k2);
                DotY = y0 + (DotX - x0) * k1;
                return;
            }
        }
        else {
            DotX = x2;
            DotY = y0 + ((double)x2 - (double)x0) * k1;
            return;
        }
    }
    else {
        if (x2 != x3) {
            k2 = (y2 - y3) / (x2 - x3);//
            DotX = x0;
            DotY = y2 + ((double)x0 - (double)x2) * k2;
            return;
        }
    }
   
}

int main()
{
    int DotNum;
    cin >> DotNum;
    char L;
    int Dot[1000][4];
    int i = 0;
    while (i<DotNum) {
        cin >> L;
        cin >> Dot[i][0];
        cin >> Dot[i][1];
        cin >> Dot[i][2];
        cin >> Dot[i++][3];
    }
    DotsSet _set;
    int j;
    for (i = 0; i < DotNum-1; i++) {
        for (j = i + 1; j < DotNum; j++) {
            CalDot(Dot[i][0], Dot[i][1], Dot[i][2], Dot[i][3], Dot[j][0], Dot[j][1], Dot[j][2], Dot[j][3]);
            _set.insert(Dots(DotX, DotY));
        }
    }
    cout << _set.size() << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
