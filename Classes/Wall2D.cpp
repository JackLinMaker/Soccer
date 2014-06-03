//
//  Wall2D.cpp
//  Soccer
//
//  Created by 林光海 on 14-5-31.
//
//

#include "Wall2D.h"

Wall2D* Wall2D::create(const cocos2d::CCPoint &A, const cocos2d::CCPoint &B)
{
    Wall2D *wall = new Wall2D();
    if(wall && wall->init(A, B)) {
        wall->autorelease();
        return wall;
    }
    
    CC_SAFE_DELETE(wall);
    return NULL;
}

bool Wall2D::init(const cocos2d::CCPoint &A, const cocos2d::CCPoint &B)
{
    if(CCNode::init()) {
        m_vA = A;
        m_vB = B;
        return true;
    }
    
    return false;
}

Wall2D* Wall2D::create(const cocos2d::CCPoint &A, const cocos2d::CCPoint &B, const cocos2d::CCPoint &N)
{
    Wall2D *wall = new Wall2D();
    if(wall && wall->init(A, B, N)) {
        wall->autorelease();
        return wall;
    }
    
    CC_SAFE_DELETE(wall);
    return NULL;

}

bool Wall2D::init(const cocos2d::CCPoint &A, const cocos2d::CCPoint &B, const cocos2d::CCPoint &N)
{
    if(CCNode::init()) {
        m_vA = A;
        m_vB = B;
        m_vN = N;
        return true;
    }
    
    return false;
}

Wall2D::Wall2D():m_vA(CCPointZero), m_vB(CCPointZero), m_vN(CCPointZero)
{
    
}

Wall2D::Wall2D(ifstream& in)
{
    Read(in);
}

Wall2D::~Wall2D()
{
    
}

CCPoint Wall2D::From() const
{
    return m_vA;
}

void Wall2D::SetFrom(const cocos2d::CCPoint &v)
{
    m_vA = v;
    CalculateNormal();
}

CCPoint Wall2D::To() const
{
    return m_vB;
}

void Wall2D::SetTo(const cocos2d::CCPoint &v)
{
    m_vB = v;
    CalculateNormal();
}

CCPoint Wall2D::Normal() const
{
    return m_vN;
}

void Wall2D::SetNormal(const cocos2d::CCPoint &n)
{
    m_vN = n;
}

CCPoint Wall2D::Center() const
{
    return (m_vA + m_vB) * 0.5;
}

ostream& Wall2D::Write(ostream &os)
{
    os << std::endl;
    os << " " << m_vA.x << " " << m_vA.y << ",";
    os << " " << m_vB.x << " " << m_vB.y << ",";
    os << " " << m_vN.x << " " << m_vN.y;
    return os;
}

void Wall2D::Read(ifstream &in)
{
    double x, y;
    in >> x >> y;
    SetFrom(CCPoint(x, y));
    in >> x >> y;
    SetTo(CCPoint(x,y));
    in >> x >> y;
    SetNormal(CCPoint(x, y));
}

void Wall2D::draw()
{
    CCNode::draw();
    ccDrawLine(m_vA, m_vB);
}

void Wall2D::CalculateNormal()
{
    CCPoint temp = ccpNormalize(ccpSub(m_vB, m_vA));
    m_vN.x = -temp.y;
    m_vN.y = temp.x;
}