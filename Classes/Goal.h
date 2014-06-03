//
//  Goal.h
//  Soccer
//
//  Created by 林光海 on 14-6-3.
//
//

#ifndef __Soccer__Goal__
#define __Soccer__Goal__

#include "cocos2d.h"
#include "Geometry.h"
USING_NS_CC;

class SoccerBall;

class Goal : public CCNode
{
public:
    static Goal* create(const CCPoint& left, const CCPoint& right, const CCPoint& facing);
    
    Goal();
    
    virtual bool init(const CCPoint& left, const CCPoint& right, const CCPoint& facing);
    
    virtual ~Goal();
    
    bool Scored(const SoccerBall* const ball);
    
    CCPoint Center() const;
    
    CCPoint Facing() const;
    
    CCPoint LeftPost() const;
    
    CCPoint RightPost() const;
    
    int NumGoalsScored() const;
    
    void ResetGoalsScored();
    
protected:
    CCPoint m_vLeftPost;
    
    CCPoint m_vRightPost;
    
    CCPoint m_vFacing;
    
    CCPoint m_vCenter;
    
    int m_iNumGoalsScored;
};

#endif /* defined(__Soccer__Goal__) */
