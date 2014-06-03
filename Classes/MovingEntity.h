//
//  MovingEntity.h
//  Soccer
//
//  Created by 林光海 on 14-6-3.
//
//

#ifndef __Soccer__MovingEntity__
#define __Soccer__MovingEntity__

#include <cassert>
#include "BaseGameEntity.h"

class MovingEntity : public BaseGameEntity
{
public:
    static MovingEntity* create(const CCPoint& position,
                                double radius,
                                const CCPoint& velocity,
                                double max_speed,
                                const CCPoint& heading,
                                double mass,
                                const CCPoint& scale,
                                double turn_rate,
                                double max_force);
    
    MovingEntity();
    
    virtual bool init(const CCPoint& position,
                      double radius,
                      const CCPoint& velocity,
                      double max_speed,
                      const CCPoint& heading,
                      double mass,
                      const CCPoint& scale,
                      double turn_rate,
                      double max_force);
    
    virtual ~MovingEntity();
    
    CCPoint Velocity() const;
    
    void SetVelocity(const CCPoint& NewVal);
    
    double Mass() const;
    
    CCPoint Side() const;
    
    double MaxSpeed() const;
    
    void SetMaxSpeed(double new_speed);
    
    double MaxForce() const;
    
    void SetMaxForce(double mf);
    
    bool IsSpeedMaxedOut() const;
    
    double Speed() const;
    
    double SpeedSq() const;
    
    CCPoint Heading() const;
    
    void SetHeading(const CCPoint& new_heading);
    
    bool RotateHeadingToFacePosition(const CCPoint& target);
    
    double MaxTurnRate() const;
    
    void SetMaxTurnRate(double val);
private:
    
protected:
    CCPoint m_vVelocity;
    
    CCPoint m_vHeading;
    
    CCPoint m_vSide;
    
    double m_dMass;
    
    double m_dMaxSpeed;
    
    double m_dMaxForce;
    
    double m_dMaxTurnRate;
};

#endif /* defined(__Soccer__MovingEntity__) */
