//
//  Region.h
//  Soccer
//
//  Created by 林光海 on 14-6-1.
//
//

#ifndef __Soccer__Region__
#define __Soccer__Region__

#include "cocos2d.h"
#include <math.h>
#include "Util.h"
#include "Stream_Utility_Functions.h"
USING_NS_CC;
using namespace std;

class Region : public CCNode
{
public:
    enum region_modifier
    {
        halfsize,
        normal
    };
    
    static Region* create(double left, double top, double right, double bottom, int id = -1);
    
    Region();
    
    virtual bool init(double left, double top, double right, double bottom, int id = -1);
    
    virtual ~Region();
    
    bool Inside(const CCPoint& pos, region_modifier r) const;
    
    CCPoint GetRandomPosition() const;
    
    double Top() const;
    
    double Bottom() const;
    
    double Left() const;
    
    double Right() const;
    
    double Width() const;
    
    double Height() const;
    
    double Length() const;
    
    double Breadth() const;
    
    CCPoint Center() const;
    
    int ID() const;
    
protected:
    double m_dTop;
    
    double m_dLeft;
    
    double m_dRight;
    
    double m_dBottom;
    
    double m_dWidth;
    
    double m_dHeight;
    
    CCPoint m_vCenter;
    
    int m_iID;
};


#endif /* defined(__Soccer__Region__) */
