//
//  Goal.cpp
//  Soccer
//
//  Created by 林光海 on 14-6-3.
//
//

#include "Goal.h"

Goal* Goal::create(const cocos2d::CCPoint &left, const cocos2d::CCPoint &right, const cocos2d::CCPoint &facing)
{
    Goal* goal = new Goal();
    
    if(goal && goal->init(left, right, facing)) {
        goal->autorelease();
        return goal;
    }
    
    CC_SAFE_DELETE(goal);
    return NULL;
}

Goal::Goal():m_iNumGoalsScored(0)
{

}

bool Goal::init(const cocos2d::CCPoint &left, const cocos2d::CCPoint &right, const cocos2d::CCPoint &facing)
{
    if(CCNode::init()) {
        m_vLeftPost = left;
        m_vRightPost = right;
        m_vCenter = ccpAdd(m_vLeftPost, m_vRightPost) / 2;
        m_vFacing = facing;
        return true;
    }
    
    return false;
}

Goal::~Goal()
{

}

bool Goal::Scored(const SoccerBall *const ball)
{
    /*if(ccpIntersectPoint(ball->getPos(), ball->getOldPos(), m_vLeftPost, m_vRightPost)) {
        ++m_iNumGoalsScored;
        return true;
    }*/
    
    return false;
}

CCPoint Goal::Center() const
{
    return m_vCenter;
}

CCPoint Goal::Facing() const
{
    return m_vFacing;
}

CCPoint Goal::LeftPost() const
{
    return m_vLeftPost;
}

CCPoint Goal::RightPost() const
{
    return m_vRightPost;
}

int Goal::NumGoalsScored() const
{
    return m_iNumGoalsScored;
}

void Goal::ResetGoalsScored()
{
    m_iNumGoalsScored = 0;
}