//
//  Region.cpp
//  Soccer
//
//  Created by 林光海 on 14-6-1.
//
//

#include "Region.h"

Region* Region::create(double left, double top, double right, double bottom, int id)
{
    Region* region = new Region();
    
    if(region && region->init(left, top, right, bottom, id)) {
        region->autorelease();
        return region;
    }
    
    CC_SAFE_DELETE(region);
    return NULL;
}

Region::Region():m_dTop(0), m_dBottom(0), m_dLeft(0), m_dRight(0)
{

}

bool Region::init(double left, double top, double right, double bottom, int id)
{
    if(CCNode::init()) {
        m_dLeft = left;
        m_dTop = top;
        m_dRight = right;
        m_dBottom = bottom;
        m_iID = id;
        m_vCenter = ccp((left + right) * 0.5, (top + bottom) * 0.5);
        m_dWidth = fabs(right - left);
        m_dHeight = fabs(bottom - top);
        return true;
    }
    
    return false;
}

Region::~Region()
{

}

bool Region::Inside(const cocos2d::CCPoint &pos, Region::region_modifier r) const
{
    if(r == normal) {
        return ((pos.x > m_dLeft) && (pos.x < m_dRight) && (pos.y > m_dTop) && (pos.y < m_dBottom));
    }else {
        const double marginX = m_dWidth * 0.25;
        const double marginY = m_dHeight * 0.25;
        return ((pos.x > (m_dLeft+marginX)) && (pos.x < (m_dRight-marginX)) &&
                (pos.y > (m_dTop+marginY)) && (pos.y < (m_dBottom-marginY)));
    }
}

CCPoint Region::GetRandomPosition() const
{
    return ccp(RandInRange(m_dLeft, m_dRight), RandInRange(m_dTop, m_dBottom));
}

double Region::Top() const
{
    return m_dTop;
}

double Region::Bottom() const
{
    return m_dBottom;
}

double Region::Left() const
{
    return m_dLeft;
}

double Region::Right() const
{
    return m_dRight;
}

double Region::Width() const
{
    return fabs(m_dRight - m_dLeft);
}

double Region::Height() const
{
    return fabs(m_dTop - m_dBottom);
}

double Region::Length() const
{
    return max(Width(), Height());
}

double Region::Breadth() const
{
    return min(Width(), Height());
}

CCPoint Region::Center() const
{
    return m_vCenter;
}

int Region::ID() const
{
    return m_iID;
}

