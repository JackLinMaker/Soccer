#include "SoccerScene.h"
USING_NS_CC;

CCScene* SoccerScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SoccerScene *layer = SoccerScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

SoccerScene::SoccerScene()
{
    
}

// on "init" you need to initialize your instance
bool SoccerScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    return true;
}

SoccerScene::~SoccerScene()
{

}

