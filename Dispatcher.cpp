#include "Dispatcher.hpp"
#include <algorithm>

using namespace pandemic;

std::string Dispatcher::role(){
    return "Dispatcher";
}

Dispatcher& Dispatcher::fly_direct(const City passTo){
    this->currentCity = passTo;
    return *this;
}