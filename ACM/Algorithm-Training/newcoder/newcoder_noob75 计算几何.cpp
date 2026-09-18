#include <iostream>
#include <cmath>

using namespace std;

// 定义点/向量结构体
struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// 向量减法
Point operator - (const Point& A, const Point& B) {
	return Point(A.x - B.x, A.y - B.y);
}

// 向量加法
Point operator + (const Point& A, const Point& B) {
	return Point(A.x + B.x, A.y + B.y);
}

// 向量数乘
Point operator * (const Point& A, double p) {
	return Point(A.x * p, A.y * p);
}

// 核心：计算两个向量的叉积 (Cross Product)
double cross(const Point& A, const Point& B) {
	return A.x * B.y - A.y * B.x;
}

// 题目要求实现的函数：求解直线 AB 和 CD 的交点
Point getIntersection(Point A, Point B, Point C, Point D) {
	// 首先计算两个核心的叉积值（相当于三角形的有向面积）
	double s1 = cross(C - A, D - A);
	double s2 = cross(C - B, D - B);
	
	// 计算分母。如果分母极度接近 0（由于浮点数误差，用 1e-9 判断）
	// 说明两直线平行或者重合，交点不唯一或不存在
	if (abs(s1 - s2) < 1e-9) {
		return Point(-1, -1);
	}
	
	// 完美套用叉积交点公式
	// P = A + (B - A) * (s1 / (s1 - s2))
	double ratio = s1 / (s1 - s2);
	Point P = A + (B - A) * ratio;
	
	return P;
}

int main() {
	// 用于自测的 main 函数，提交时根据牛客网的要求只保留上面的核心函数或完整提交
	double ax, ay, bx, by;
	double cx, cy, dx, dy;
	
	if (cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy) {
		Point A(ax, ay), B(bx, by), C(cx, cy), D(dx, dy);
		Point P = getIntersection(A, B, C, D);
		
		// 控制输出保留 6 位小数
		printf("%.6f %.6f\n", P.x, P.y);
	}
	return 0;
}
