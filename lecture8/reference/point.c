#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

double distance(struct point *pp1, struct point *pp2) {
    return sqrt(pow((pp2->x - pp1->x), 2) + pow((pp2->y - pp1->y), 2));
}

int main() {
    struct point p1;
    p1.x = 0;
    p1.y = 0;

    struct point p2;
    p2.x = 3;
    p2.y = 4;

    double dist = distance(&p1, &p2);
    printf("dist = %lf\n", dist);
    return 0;
}

