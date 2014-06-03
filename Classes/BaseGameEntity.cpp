//
//  BaseGameEntity.cpp
//  Soccer
//
//  Created by 林光海 on 14-6-3.
//
//

#include "BaseGameEntity.h"

int BaseGameEntity::m_iNextValidID = 0;

BaseGameEntity* BaseGameEntity::create(int id)
{
    BaseGameEntity* entity = new BaseGameEntity();
    
    if(entity && entity->init(id)) {
        entity->autorelease();
        return entity;
    }
    
    CC_SAFE_DELETE(entity);
    return NULL;
}

BaseGameEntity::BaseGameEntity():m_dBoundingRadius(0.0), m_iType(default_entity_type)
{
    
}

bool BaseGameEntity::init(int id)
{
    if(CCNode::init()) {
        _sprite = CCSprite::createWithSpriteFrameName("ball");
        this->addChild(_sprite);
        m_dBoundingRadius = _sprite->boundingBox().size.width * 0.5;
        this->SetID(id);
        return true;
    }
    
    return false;
}

BaseGameEntity::~BaseGameEntity()
{

}

void BaseGameEntity::Write(ostream &os) const
{

}

void BaseGameEntity::Read(ifstream &is)
{

}

int BaseGameEntity::GetNextValidID()
{
    return m_iNextValidID;
}

void BaseGameEntity::ResetNextValidID()
{
    m_iNextValidID = 0;
}

double BaseGameEntity::BRadius() const
{
    return m_dBoundingRadius;
}

void BaseGameEntity::SetBRadius(double r)
{
    m_dBoundingRadius = r;
}

int BaseGameEntity::ID() const
{
    return m_ID;
}

bool BaseGameEntity::IsTagged() const
{
    return this->getTag();
}

void BaseGameEntity::Tag()
{
    this->setTag(1);
}

void BaseGameEntity::UnTag()
{
    this->setTag(0);
}

int BaseGameEntity::EntityType() const
{
    return m_iType;
}

void BaseGameEntity::SetEntityType(int new_type)
{
    m_iType = new_type;
}

void BaseGameEntity::SetID(int val)
{
    assert ( (val >= m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");
    
    m_ID = val;
    
    m_iNextValidID = m_ID + 1;
}

