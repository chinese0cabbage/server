//
// Created by johnjun on 2021/3/14.
//

#ifndef SERVER_COMMONDATA_H
#include "rttr/registration.h"
#define SERVER_COMMONDATA_H

struct ReposeData{
    ReposeData() {}

    int code;
    std::string content;
    std::string message;

    RTTR_ENABLE()
};

#endif //SERVER_COMMONDATA_H
