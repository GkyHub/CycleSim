#pragma once
#include "common.h"
#include <string>

namespace hdl
{
    /*
        class for the data expressed with binary bit
        only bitwise operations are defined
    */
    class data {
    protected:
        void * _dat;
        uint32 _bw;
    public:
        data(uint32 bw);
        data(const data &d);
        data(data &&d);
        ~data();
        data& operator=(data &&d);
        static data operator& (const data &a, const data &b);
        static data operator| (const data &a, const data &b);
        static data operator&&(const data &a, const data &b);
        static data operator||(const data &a, const data &b);
        std::string str(const iof &flag);
    };

    /*
        class for fixed point data
    
    class hFixed : public data {
    protected:
        int32_t 
    };*/

    /*
        class for integers of any bitwidth
    
    class hInt: public data {
    public:
        hInt(uint32 bw);
        static hInt operator+(const hInt &a, const hInt &b);
        static hInt operator-(const hInt &a, const hInt &b);
        static hInt operator*(const hInt &a, const hInt &b);
        static hInt operator/(const hInt &a, const hInt &b);
    };*/

    /*
        class for unsigned integers of any bitwidth
    
    class hUInt : public data {
    public:
        hUInt(uint32 bw);
        static hUInt operator+(const hUInt &a, const hUInt &b);
        static hUInt operator-(const hUInt &a, const hUInt &b);
        static hUInt operator*(const hUInt &a, const hUInt &b);
        static hUInt operator/(const hUInt &a, const hUInt &b);
    };*/

    /*
        class for floating point data
    
    class hFp : public data {
    protected:
        uint32 _sign;   // if there is a sign bit
        uint32 _exp;    // exponential part bit width

    public:
        hFp(uint32 bw);
        static hFp operator+(const hFp &a, const hFp &b);
        static hFp operator-(const hFp &a, const hFp &b);
        static hFp operator*(const hFp &a, const hFp &b);
        static hFp operator/(const hFp &a, const hFp &b);
    };*/

    /*
        class for double data
    */

}