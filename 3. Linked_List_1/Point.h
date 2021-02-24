#ifndef __POINT_H__
#define __POINT_H__

typedef struct _Point{
    int xpos, ypos;
} Point;

void setPointPos(Point *ppos, int xpos, int ypos);

void showPointPos(Point *ppos);

int PointComp(Point *pos1, Point *pos2);

#endif