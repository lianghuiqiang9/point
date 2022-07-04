#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
template<typename T> void disp(T* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
class point {//����ƽ�����
public://����������� ����>> ���<< ��ֵ= ȡ��- ����б�== �����б�!= С��< ����> ���+ ���- ���* 
	point(int fx = 1, int fy = 1) :x(fx), y(fy) {};//���캯�����޲�����Ĭ��Ϊ��1,1�����в�����Ĭ�ϸ�ֵ��/* { x = fx; y = fy; }*/
	friend ostream& operator<<(ostream &os, const point& p) {//�������������
		os << "(" << p.x << "," << p.y << ")";//�����x,y��
		return os;
	}
	friend istream& operator>>(istream& is, point& p) {
		is >> p.x >> p.y;//����x,y��������벻��ȷ��������Ĭ��״̬��
		if (!is)
			p = point();
		return is;
	}
	void operator=(const point& q) {//
		x = q.x; y = q.y;
	}
	point operator-() {//�������ı�ԭ���ĵ��ֵ
		return point(-x, -y);
	}
	bool operator==(const point& b) {
		return x == b.x && y == b.y;
	}
	bool operator!=(const point& b) {
		return !(*this == b);
	}
	/*	friend bool operator < (const point& a, const point& b) { return a.x * a.x + a.y * a.y < b.x* b.x + b.y * b.y; }//�����<���ص���һ��д�� */
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
private://������Ԫ�أ�x�Ǻ����꣬y��������
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
	//	sort(a, a + 4,greater<point>());//����������Ҳ�������ˣ���Ϊ
	//	sort(a, a + 4, cmmp);//����ɹ���Ԫ�أ��Ϳ����ˡ�
	disp(a, 4);//���������������˽��Ԫ�أ��޷����ʵ�ѽ��
	//sort����Ĭ����С�����������cmp������a>b,��ô�ͱ�����ɴ�С����ΪС��������0.
	//ͬ�������������أ�С�ں�<����ں�>����ô����С���󣬱�����ɴ�С��
	// ����Ϊʲô�е�ʱ����Ҫfriend���е�ʱ����Ҫ���ţ��ٿ����ɡ�
	//���쿴���̳е����⣬�����麯�����������⡣
	//�ã��̳к��麯�������⣬�´���������˵�ɡ�
	//����������������ó�Ա������Ҳ��������Ԫ������<<��>>��Ҫ��Ԫ������ģ�
}