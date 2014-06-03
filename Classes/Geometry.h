//
//  Geometry.h
//  Soccer
//
//  Created by 林光海 on 14-6-3.
//
//

#ifndef Soccer_Geometry_h
#define Soccer_Geometry_h

#include "Util.h"
#include <math.h>
#include <vector>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

inline double DistanceToRayPlaneIntersection(const CCPoint& RayOrigin, const CCPoint& RayHeading, const CCPoint& PlanePoint, const CCPoint& PlaneNormal)
{
    double d = -PlaneNormal.dot(PlanePoint);
    double number = PlaneNormal.dot(RayOrigin) + d;
    double denom = PlaneNormal.dot(RayHeading);
    
    // normal is parallel to vector
    if((denom < 0.000001) && (denom > -0.000001)) {
        return -1.0;
    }
    
    return -(number / denom);
}

// whereIsPoint
enum span_type {
    plane_backside,
    plane_front,
    on_plane
};

inline span_type WhereIsPoint(CCPoint& point, CCPoint& PointOnPlane, CCPoint& PlaneNormal)
{
    CCPoint dir = ccpSub(PointOnPlane, point);
    
    double d = dir.dot(PlaneNormal);
    
    if(d < -0.000001) {
        return plane_front;
    }else if(d > 0.000001) {
        return plane_backside;
    }
    
    return on_plane;
}

const double pi = 3.14159;

inline double GetRayCircleIntersect(CCPoint& RayOrigin, CCPoint& RayHeading, CCPoint& CircleOrigin, double radius)
{
    CCPoint ToCircle = ccpSub(CircleOrigin, RayOrigin);
    double length = ToCircle.getLength();
    double v = ToCircle.dot(RayHeading);
    double d = radius * radius - (length * length - v * v);
    
    // if there was no intersection, return -1
    if(d < 0.0) return (-1.0);
    // return te distance to the [first] intersecting point
    return (v - sqrt(d));
}

inline bool DoRayCircleIntersect(CCPoint& RayOrigin, CCPoint& RayHeading, CCPoint& CircleOrigin, double radius)
{
    CCPoint ToCircle = ccpSub(CircleOrigin, RayOrigin);
    double length = ToCircle.getLength();
    double v = ToCircle.dot(RayHeading);
    double d = radius * radius - (length * length - v * v);
    // if there was no intersection, return -1
    return (d < 0.0);
}

enum {clockwise = 1, anticlockwise = -1};

inline int Sign(const CCPoint& v1, const CCPoint& v2) 
{
    if (v1.y*v2.x > v1.x*v2.y)
    {
        return anticlockwise;
    }
    else
    {
        return clockwise;
    }
}



#endif
