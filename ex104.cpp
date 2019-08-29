#include <iostream>

using namespace std;

constexpr int isqrt_helper(int sq, int d, int a)
{
	return sq <= a ? isqrt_helper(sq+d,d+2,a) : d;
}

constexpr int isqrt(int x)
{
	return isqrt_helper(1,3,x)/2 - 1;
}

struct Point
{
	int x,y,z;
	constexpr Point up(int d) { return {x,y,z+d};}
	constexpr Point move(int dx, int dy) { return {x + dx, y + dy};}
};

constexpr int square(int x)
{
	return x * x;
}

constexpr int radial_distance(Point x)
{
	return isqrt(square(x.x) + square(x.y) + square(x.z));
}

int main(int argc, char **argv)
{
	constexpr int s1 = isqrt(9);
	constexpr int s2 = isqrt(1234);

	cout << s1 << endl;
 	cout << s2 << endl;

	constexpr Point d = Point{3,4,5};

	constexpr int d_e = d.x;

	constexpr Point a[] = { Point{1,2,6}, Point{4,5,9}, Point{1,2,66} };

	constexpr int a_1_x = a[1].x;

	constexpr Point p2{d.up(20)};

	constexpr int dist = radial_distance(p2);
	
	cout << a_1_x << endl; 
	cout << dist  << endl;

	return 0;
}
