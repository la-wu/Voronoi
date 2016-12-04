#include "Math.h"

#include <cmath>

static constexpr double EPS = 1e-11;

std::pair<pnt,bool> circumcenter(pnt a, pnt b, pnt c)
{
    // translate to origin
    c = c - a;
    b = b - a;
    double d = 2 * b.det(c);
    if (d == 0)
        return {{}, false};
    double ux = (c.y * b.abs() - b.y * c.abs()) / d;
    double uy = (b.x * c.abs() - c.x * b.abs()) / d;
    pnt ret (ux, uy);
    return {ret + a, true};
}

double distance(pnt p1, pnt p2)
{
    return sqrt((p1-p2).abs());
}

double parabola_intersection(const pnt &v1, const pnt &v2, double p)
{
    if (v1.y == p) return v1.x;
    if (v2.y == p) return v2.x;
    double a1, b1, c1;
    double a2, b2, c2;
    std::tie(a1,b1,c1) = parabola_equation(v1, p);
    std::tie(a2,b2,c2) = parabola_equation(v2, p);
    double a = a1 - a2, b = b1 - b2, c = c1 - c2;
    if (std::abs(a) < EPS) { // a is 0 or value is within epsilon of it
        return -c / b; // vertical line
    } else {
        double det = b * b - 4 * a * c;
        return (-b - sqrt(det)) / (2 * a);
    }
}

bool below_parabola(const pnt &focus, double directrix, const pnt &p)
{
    double a, b, c;
    std::tie(a,b,c) = parabola_equation(focus,directrix);
    return p.y <= a*p.x*p.x + b*p.x + c;
}

std::tuple<double,double,double> parabola_equation(
        const pnt &focus, double directrix)
{
    double coeff = 1 / (2 * (focus.y - directrix));
    return {
        coeff, // a
        - coeff * 2 * focus.x, // b
        coeff * focus.x * focus.x + (focus.y + directrix) / 2 // c
    };
}

