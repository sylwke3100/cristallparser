#ifndef CRISTALLSTACK_H
#define CRISTALLSTACK_H
#include "boost/variant.hpp"
#include  <string.h>
#include "cristallheader.h"



struct CristallStack{
    std::string Label;
    CristallTypes Type;
    boost::variant< int, std::string,double > Value;
};
#endif // CRISTALLSTACK_H
