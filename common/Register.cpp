//
// Created by johnjun on 2021/3/14.
//

#include "CommonData.h"

RTTR_REGISTRATION {
    rttr::registration::class_<ReposeData>("ReposeData")
            .constructor<>()(
                    rttr::policy::ctor::as_object
            )
            .property("code", &ReposeData::code)
            .property("content", &ReposeData::content)
            .property("content", &ReposeData::message);
};