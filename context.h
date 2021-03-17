//
// Created by zhangjun on 21-3-8.
//

#ifndef SERVER_CONTEXT_H
#include <string>
#include <vector>
#include <rttr/registration.h>
#include "boost/shared_ptr.hpp"
#include <rttr/library.h>
#include <map>
#include <iostream>
#include "glog/logging.h"
#define SERVER_CONTEXT_H

class Context {
public:
    Context()= default;

    template<typename T>
    std::shared_ptr<T> create(std::string vendor) {
        for (auto pair:_typeMap) {
            for (auto t: pair.second) {
                if (t.is_derived_from<T>()) {
                    if (t.get_metadata("API_VENDOR").to_string() == vendor) {
                        const rttr::variant &var = t.create();
                        return var.get_value<std::shared_ptr<T>>();
                    }
                }
            }
        }
        throw std::invalid_argument("can not find api for " + vendor);
    };

    void loadLibrary(std::string libPath) {
        std::shared_ptr<rttr::library> lib = std::shared_ptr<rttr::library>(new rttr::library(libPath));

        if (!lib->load()) {
            LOG(INFO) << "load library error " << lib->get_error_string();
        }
        {
            std::vector<rttr::type> temp;
            LOG(INFO)<<lib->get_types().size();
            for (auto t : lib->get_types()) {
                if (t.is_class() && !t.is_wrapper()) {
                    LOG(INFO) << "find class " << t.get_name();
                    temp.push_back(t);
                    _types.push_back(t);
                }
            }
            _typeMap.insert({lib, temp});
        }
    };

    std::vector<rttr::type> getAllType() {
        return _types;
    }

private:
    std::map<std::shared_ptr<rttr::library>, std::vector<rttr::type>> _typeMap;
    std::vector<rttr::type> _types;
};

#endif //SERVER_CONTEXT_H
