#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
template<typename T> void disp(T* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
class point {//定义平面点类
public://重载了运算符 输入>> 输出<< 赋值= 取反- 相等判别== 不等判别!= 小于< 大于> 相加+ 相减- 点乘* 
	point(int fx = 1, int fy = 1) :x(fx), y(fy) {};//构造函数，无参输入默认为（1,1），有参输入默认赋值。/* { x = fx; y = fy; }*/
	friend ostream& operator<<(ostream &os, const point& p) {//重载了输出函数
		os << "(" << p.x << "," << p.y << ")";//输出（x,y）
		return os;
	}
	friend istream& operator>>(istream& is, point& p) {
		is >> p.x >> p.y;//输入x,y，如果输入不正确，对象赋予默认状态。
		if (!is)
			p = point();
		return is;
	}
	void operator=(const point& q) {//
		x = q.x; y = q.y;
	}
	point operator-() {//尽量不改变原来的点的值
		return point(-x, -y);
	}
	bool operator==(const point& b) {
		return x == b.x && y == b.y;
	}
	bool operator!=(const point& b) {
		return !(*this == b);
	}
	/*	friend bool operator < (const point& a, const point& b) { return a.x * a.x + a.y * a.y < b.x* b.x + b.y * b.y; }//运算符<重载的另一种写法 */
	bool operator < (const point& b) const {
		return x * x + y * y < b.x* b.x + b.y * b.y;
	}
	bool operator > (const point& b) const {
		return !(*this < b);
	}
/*	friend point operator+(const point& p, const point& q) { point r; r.x = q.x + p.x; r.y = q.y + p.y;
		return point(q.x + p.x, q.y + p.y);
	}*/
	point operator+(const point& q) {/* point r; r.x = q.x + p.x; r.y = q.y + p.y;*/
		return point(q.x + x, q.y + y);
	}
	point operator-(const point& q) {
		return point(x - q.x, y - q.y);
	}
	friend point operator*(int k, const point& q) {
		return point(k * q.x, k * q.y);
	}
	bool cmpp(point& p, point& q) {
		return p < q;
	}
private://有两个元素，x是横坐标，y是纵坐标
	int x; int y;
};

bool cmp(int a, int b) {
	return a < b;
}
bool cmmp(point a, point b) {
	return (a > b);
}
void main() {
	point a[4] = { {1,2},{3,4},{6,7},{2,2} };
	disp(a, 4);
	int b[4] = { 6,5,4,3 };
	//	sort(b, b + 4);
	disp(b, 4);
	//	sort(a, a + 4,greater<point>());//这里的运算符也能重载了，因为
	//	sort(a, a + 4, cmmp);//当变成公有元素，就可以了。
	disp(a, 4);//由于你现在这个是私有元素，无法访问到呀。
	//sort排序，默认由小到大，如果加了cmp，返回a>b,那么就变成了由大到小，因为小，返回了0.
	//同理，如果运算符重载，小于号<变大于号>，那么就由小到大，变成了由大到小。
	// 关于为什么有的时候需要friend，有的时候不需要，嗯，再看看吧。
	//明天看看继承的问题，还有虚函数，构造问题。
	//得，继承和虚函数的问题，下次想起来再说吧。
	//重载运算符，可以用成员函数，也可以用友元函数，<<和>>需要友元，不错的，
}