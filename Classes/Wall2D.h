//
//  Wall2D.h
//  Soccer
//
//  Created by 林光海 on 14-5-31.
//
//

#ifndef __Soccer__Wall2D__
#define __Soccer__Wall2D__

#include "cocos2d.h"
#include <fstream>
USING_NS_CC;
using namespace std;

class Wall2D : public CCNode
{
public:
    static Wall2D* create(const CCPoint& A, const CCPoint& B);
    
    static Wall2D* create(const CCPoint& A, const CCPoint& B, const CCPoint& N);
    
    virtual bool init(const CCPoint& A, const CCPoint& B);
    
    virtual bool init(const CCPoint& A, const CCPoint& B, const CCPoint& N);
    
    Wall2D();
    
    Wall2D(ifstream& in);
    
    virtual ~Wall2D();
    
    virtual void draw();
    
    CCPoint From() const;
    
    void SetFrom(const CCPoint& v);
    
    CCPoint To() const;
    
    void SetTo(const CCPoint& v);
    
    CCPoint Normal() const;
    
    void SetNormal(const CCPoint& n);
    
    CCPoint Center() const;
    
    ostream& Write(ostream& os);
    
    void Read(ifstream& in);
    
protected:
    CCPoint m_vA;
    CCPoint m_vB;
    CCPoint m_vN;
    
    void CalculateNormal();
};



#endif /* defined(__Soccer__Wall2D__) */
