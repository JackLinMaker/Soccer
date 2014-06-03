//
//  SoccerPitch.cpp
//  Soccer
//
//  Created by 林光海 on 14-6-1.
//
//

#include "SoccerPitch.h"
#include "Region.h"

const int NumRegionsHorizontal = 6;
const int NumRegionsVertical   = 3;

SoccerPitch* SoccerPitch::create(int cxClient, int cyClient)
{
    SoccerPitch* pitch = new SoccerPitch();
    
    if(pitch && pitch->init(cxClient, cyClient)) {
        pitch->autorelease();
        return pitch;
    }
    
    CC_SAFE_DELETE(pitch);
    return NULL;
}

SoccerPitch::SoccerPitch():m_cxClient(0), m_cyClient(0), m_bPaused(false),m_bGoalKeeperHasBall(false), m_Regions(NumRegionsHorizontal*NumRegionsVertical), m_bGameOn(true)
{

}

bool SoccerPitch::init(int cxClient, int cyClient)
{
    if(CCNode::init()) {
        m_cxClient = cxClient;
        m_cyClient = cyClient;
        // create the regions
        this->CreateRegions(PlayingArea()->Width() / (double)NumRegionsHorizontal, PlayingArea()->Height() / (double)NumRegionsVertical);
        // create the goals
        
        
        // create the walls
        CCPoint TopLeft = ccp(m_pPlayingArea->Left(), m_pPlayingArea->Top());
        CCPoint TopRight = ccp(m_pPlayingArea->Right(), m_pPlayingArea->Top());
        CCPoint BottomRight = ccp(m_pPlayingArea->Right(), m_pPlayingArea->Bottom());
        CCPoint BottomLeft = ccp(m_pPlayingArea->Left(), m_pPlayingArea->Bottom());
        
        this->unscheduleUpdate();
        this->scheduleUpdate();
        return true;
    }
    
    return false;
}

SoccerPitch::~SoccerPitch()
{
    
    for (unsigned int i=0; i<m_Regions.size(); ++i)
    {
        delete m_Regions[i];
    }
}

void SoccerPitch::TogglePause()
{
    m_bPaused = !m_bPaused;
}

bool SoccerPitch::Paused() const
{
    return m_bPaused;
}

int SoccerPitch::cxClient() const
{
    return m_cxClient;
}

int SoccerPitch::cyClient() const
{
    return m_cyClient;
}

bool SoccerPitch::GoalKeeperHasBall() const
{
    return m_bGoalKeeperHasBall;
}

void SoccerPitch::SetGoalKeeperHasBall(bool b)
{
    m_bGoalKeeperHasBall = b;
}

const Region* SoccerPitch::PlayingArea() const
{
    return m_pPlayingArea;
}

const vector<Wall2D>& SoccerPitch::Walls()
{
    return m_vecWalls;
}

SoccerBall* SoccerPitch::Ball() const
{
    return m_pBall;
}

const Region* SoccerPitch::GetRegionFromIndex(int idx)
{
    assert ( (idx >= 0) && (idx < (int)m_Regions.size()) );
    
    return m_Regions[idx];
}

bool SoccerPitch::GameOn() const
{
    return m_bGameOn;
}

void SoccerPitch::SetGameOn()
{
    m_bGameOn = true;
}

void SoccerPitch::SetGameOff()
{
    m_bGameOn = false;
}

void SoccerPitch::CreateRegions(double width, double height)
{
    //index into the vector
    int idx = m_Regions.size()-1;
    
    for (int col=0; col<NumRegionsHorizontal; ++col)
    {
        for (int row=0; row<NumRegionsVertical; ++row)
        {
            m_Regions[idx--] = Region::create(PlayingArea()->Left() + col * width, PlayingArea()->Top() + row * height, PlayingArea()->Left() + (col + 1) * width , PlayingArea()->Top() + (row + 1) * height, idx);
            
        }
    }
}

void SoccerPitch::update(float delta)
{
    if(m_bPaused)
        return;
    static int tick = 0;
    
    // update the balls
    
    // update the teams
    
    
}






