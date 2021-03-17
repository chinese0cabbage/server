//
// Created by johnjun on 2021/3/14.
//

#include "rttr/registration.h"
#include "test_moduel.h"

RTTR_PLUGIN_REGISTRATION {
    rttr::registration::class_<test_moduel>("test_moduel")
            (
                    rttr::metadata("API_VENDOR", "test_moduel"),
                    rttr::metadata("API_VERSION", "v1"),
                    rttr::metadata("API_TYPE", "WEB")
            )
            .constructor<>()
            .method("out", rttr::select_overload<std::string()>(&test_moduel::out));
};