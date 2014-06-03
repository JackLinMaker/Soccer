//
//  Stream_Utility_Functions.h
//  Soccer
//
//  Created by 林光海 on 14-6-1.
//
//

#ifndef Soccer_Stream_Utility_Functions_h
#define Soccer_Stream_Utility_Functions_h

#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


template <class T>
inline string ttos(const T& t, int precision = 2)
{
    ostringstream buffer;
    buffer << fixed << setprecision(precision) << t;
    return buffer.str();
}


inline string btos(bool b)
{
    if(b)
        return "true";
    return "false";
}

template <typename T>
inline T GetValueFromStream(std::ifstream& stream)
{
    T val;
    stream >> val;
    
    /*if(!stream)
    {
        throw runtime_error("Attempting to retrieve wrong type from stream");
    }*/
    
    return val;
}

template <typename T>
void WriteBitsToStream(ostream& stream, const T& val)
{
    int iNumBits = sizeof(T) * 8;
    
    while (--iNumBits >= 0) {
        if((iNumBits + 1) % 8 == 0)
            stream << " ";
        unsigned long mask = 1 << iNumBits;
        if(val & mask)
            stream << "1";
        else
            stream << "0";
    }
}
#endif
