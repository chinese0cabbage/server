//
// Created by johnjun on 2021/3/14.
//

#ifndef SERVER_TEST_MODUEL_H
#include "CommonData.h"
#include "test.h"
#define SERVER_TEST_MODUEL_H

class test_moduel:test{
public:
    test_moduel();

    std::string out() override;
};

#endif //SERVER_TEST_MODUEL_H
