//
//  MovingEntity.cpp
//  Soccer
//
//  Created by 林光海 on 14-6-3.
//
//

#include "MovingEntity.h"
#include "Geometry.h"

MovingEntity* MovingEntity::create(const cocos2d::CCPoint &position, double radius, const cocos2d::CCPoint &velocity, double max_speed, const cocos2d::CCPoint &heading, double mass, const cocos2d::CCPoint &scale, double turn_rate, double max_force)
{
    MovingEntity* entity = new MovingEntity();
    
    if(entity && entity->init(position, radius, velocity, max_speed, heading, mass, scale, turn_rate, max_force)) {
        entity->autorelease();
        return entity;
    }
    
    CC_SAFE_DELETE(entity);
    return NULL;
}

MovingEntity::MovingEntity()
{

}

bool MovingEntity::init(const cocos2d::CCPoint &position, double radius, const cocos2d::CCPoint &velocity, double max_speed, const cocos2d::CCPoint &heading, double mass, const cocos2d::CCPoint &scale, double turn_rate, double max_force)
{
    if(BaseGameEntity::init(GetNextValidID())) {
        m_vHeading = heading;
        m_vVelocity = velocity;
        m_dMass = mass;
        m_vSide = m_vHeading.getPerp();
        m_dMaxSpeed = max_speed;
        m_dMaxTurnRate = turn_rate;
        m_dMaxForce = max_force;
        m_vPosition = position;
        this->setPosition(m_vPosition);
        m_dBoundingRadius = radius;
        m_vScale = scale;
        return true;
    }
    
    return false;
}

MovingEntity::~MovingEntity()
{

}

CCPoint MovingEntity::Velocity() const
{
    return m_vVelocity;
}

double MovingEntity::Mass() const
{
    return m_dMass;
}

CCPoint MovingEntity::Side() const
{
    return m_vSide;
}

double MovingEntity::MaxSpeed() const
{
    return m_dMaxSpeed;
}

void MovingEntity::SetMaxSpeed(double new_speed)
{
    m_dMaxSpeed = new_speed;
}

double MovingEntity::MaxForce() const
{
    return m_dMaxForce;
}

void MovingEntity::SetMaxForce(double mf)
{
    m_dMaxForce = mf;
}

bool MovingEntity::IsSpeedMaxedOut() const
{
    return m_dMaxSpeed * m_dMaxSpeed >= m_vVelocity.getLengthSq();
}

double MovingEntity::Speed() const
{
    return m_vVelocity.getLength();
}

double MovingEntity::SpeedSq() const
{
    return m_vVelocity.getLengthSq();
}

CCPoint MovingEntity::Heading() const
{
    return m_vHeading;
}

void MovingEntity::SetHeading(const cocos2d::CCPoint &new_heading)
{
    assert( (new_heading.getLengthSq() - 1.0) < 0.00001);
    
    m_vHeading = new_heading;
    
    //the side vector must always be perpendicular to the heading
    m_vSide = m_vHeading.getPerp();
}

bool MovingEntity::RotateHeadingToFacePosition(const cocos2d::CCPoint &target)
{
    CCPoint toTarget = ccpNormalize(ccpSub(target, m_vPosition));
    
    double dot = m_vHeading.dot(toTarget);
    
    Clamp(dot, -1, 1);
    
    double angle = acos(dot);
    
    if(angle < 0.00001)
        return true;
    if(angle > m_dMaxTurnRate)
        angle = m_dMaxTurnRate;
    
    angle = angle * Sign(m_vHeading, toTarget);
    m_vHeading = ccpRotateByAngle(m_vHeading, CCPointZero, CC_DEGREES_TO_RADIANS(angle));
    m_vVelocity = ccpRotateByAngle(m_vVelocity, CCPointZero, CC_DEGREES_TO_RADIANS(angle));
    
    m_vSide = m_vHeading.getPerp();
    
    return false;
}

double MovingEntity::MaxTurnRate() const
{
    return m_dMaxTurnRate;
}

void MovingEntity::SetMaxTurnRate(double val)
{
    m_dMaxTurnRate = val;
}