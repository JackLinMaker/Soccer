#ifndef __SoccerScene_SCENE_H__
#define __SoccerScene_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class SoccerScene : public CCLayer
{
public:
    CREATE_FUNC(SoccerScene);
    
    SoccerScene();
    
    virtual bool init();
    
    virtual ~SoccerScene();

    static CCScene* scene();
};

#endif // __SoccerScene_SCENE_H__
