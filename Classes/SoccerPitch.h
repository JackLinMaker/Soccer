//
//  SoccerPitch.h
//  Soccer
//
//  Created by 林光海 on 14-6-1.
//
//

#ifndef __Soccer__SoccerPitch__
#define __Soccer__SoccerPitch__

#include "cocos2d.h"
#include <vector>
#include <cassert>
#include "Wall2D.h"
#include "constants.h"
USING_NS_CC;
using namespace std;

class Region;
class Goal;
class SoccerTeam;
class SoccerBall;
class PlayerBase;

class SoccerPitch : public CCNode
{
public:
    static SoccerPitch* create(int cxClient, int cyClient);
    
    SoccerPitch();
    
    virtual bool init(int cxClient, int cyClient);
    
    virtual ~SoccerPitch();
    
    void TogglePause();
    
    bool Paused() const;
    
    int cxClient() const;
    
    int cyClient() const;
    
    bool  GoalKeeperHasBall() const;
    
    void SetGoalKeeperHasBall(bool b);
    
    const Region* PlayingArea() const;
    
    const vector<Wall2D>& Walls();
    
    SoccerBall* Ball() const;
    
    const Region* GetRegionFromIndex(int idx);
    
    bool GameOn() const;
    
    void SetGameOn();
    
    void SetGameOff();
    
    SoccerBall* m_pBall;
    
    SoccerTeam* m_pRedTeam;
    
    SoccerTeam* m_pBlueTeam;
    
    Goal* m_pRedGoal;
    
    Goal* m_pBlueGoal;
    
    vector<Wall2D> m_vecWalls;
    
    Region* m_pPlayingArea;
    
    vector<Region*> m_Regions;
    
    bool m_bGoalKeeperHasBall;
    
    bool m_bGameOn;
    
    bool m_bPaused;
    
    int m_cxClient;
    
    int m_cyClient;
    
    void CreateRegions(double width, double height);
private:
    void update(float delta);
    
};

#endif /* defined(__Soccer__SoccerPitch__) */
