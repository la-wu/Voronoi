#include "Point.h"
#include "Line.h"
#include "Fortunes.h"

#include <cassert>
#include <cstdio>
#include <vector>

void test_point();
void test_line();

int main(int argc, char ** argv)
{
    test_point();
    test_line();

    std::vector<point<double>> t 
        { {84, 25}, {36, 11}, {97, 25}, {82, 49}, {19, 53}, {61, 67}};
    fortunes_algorithm(t);
}

void test_point()
{
    point<int> u (1, 2);
    point<int> v (3, -1);
    assert(u + v == point<int>(4, 1));
    assert(u - v == point<int>(-2, 3));
    assert(u * 3 == point<int>(3, 6));
    assert(u * -3 == point<int>(-3, -6));
    assert(u / -3 == point<int>(0, 0));
    assert(u / 2 == point<int>(0, 1));
    assert(u.dot(v) == 1);
    assert(v.dot(u) == u.dot(v));
    assert(u.det(v) == -7);
    assert(v.det(u) == -u.det(v));
    assert(u < v);
}

void test_line()
{
    point<int> u (1, 2);
    point<int> v (3, -1);
    line l (u, v);
    assert(l.m == -1.5);
    assert(l.b == 3.5);
    assert(l.evalX(2) == 0.5);
    assert(l.evalY(0.5) == 2);
}

