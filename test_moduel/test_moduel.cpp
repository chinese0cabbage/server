//
// Created by johnjun on 2021/3/14.
//

#include "test_moduel.h"

ReposeData test_moduel::out() {
    ReposeData result;
    result.code=200;
    result.content="there is content";
    result.message="test_moduel";
    return result;
}

test_moduel::test_moduel() {}
