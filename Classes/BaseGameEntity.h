//
//  BaseGameEntity.h
//  Soccer
//
//  Created by 林光海 on 14-6-3.
//
//

#ifndef __Soccer__BaseGameEntity__
#define __Soccer__BaseGameEntity__

#include "cocos2d.h"
#include "Geometry.h"
#include <vector>
#include <iosfwd>
#include <iostream>
#include "Util.h"
USING_NS_CC;
using namespace std;

class BaseGameEntity : public CCNode
{
public:
    enum {default_entity_type = -1};
    
    static BaseGameEntity* create(int id);
    
    BaseGameEntity();
    
    virtual bool init(int id);
    
    virtual ~BaseGameEntity();
    
    virtual void Write(ostream& os) const;
    
    virtual void Read(ifstream& is);
    
    static int GetNextValidID();
    
    static void ResetNextValidID();
    
    double BRadius() const;
    
    void SetBRadius(double r);
    
    int ID() const;
    
    bool IsTagged() const;
    
    void Tag();
    
    void UnTag();
    
    int EntityType() const;
    
    void SetEntityType(int new_type);
private:
    void SetID(int val);
    
protected:
    int m_ID;
    
    int m_iType;
    
    static int m_iNextValidID;
    
    CCPoint m_vPosition;
    
    CCPoint m_vScale;
    
    double m_dBoundingRadius;
    
    CCSprite* _sprite;
    
};

#endif /* defined(__Soccer__BaseGameEntity__) */
