//
// Created by zhangjun on 21-3-10.
//

#ifndef SERVER_SERVICE_H

#include "rttr/registration"
#include "json_serialization/to_json.cpp"
#include "json_serialization/from_json.cpp"

#include "context.h"
#include "httplib.h"

#define SERVER_SERVICE_H

void initWebServer(std::vector<rttr::type> types, httplib::Server &svr) {
    for (int i = 0; i < types.size(); ++i) {
        if (types[i].get_metadata("API_TYPE") == "WEB") {
            std::string version = types[i].get_metadata("API_VERSION").to_string();
            auto obj2 = types[i].create();
            auto ms = types[i].get_methods();
            for (auto m:ms) {
                std::string methodName = m.get_name().data();
                std::string url = "/" + version + "/" + methodName;
//                LOG_INFO << url;
                rttr::array_range<rttr::parameter_info> infos = m.get_parameter_infos();
                if (infos.size() > 1) {
//                    LOG_ERROR << "web api only support one json object";
                    continue;
                }
                svr.Post(url.data(), [infos, obj2, m](const httplib::Request &req, httplib::Response &res) {
                    if (infos.size() == 1) {
                        rttr::variant var = infos.begin()->get_type().create();
                        std::string text = req.body;
                        io::from_json(text, var);//请参照官方代码的jsondemo
                        std::vector<rttr::argument> args{var};
                        rttr::variant result = m.invoke_variadic(obj2, args);
                        //请参照官方代码的转为json的demo
                        res.set_content(io::to_json(result), "application/json");
                    } else {
                        rttr::instance result = m.invoke(obj2);
                        res.set_content(io::to_json(result), "application/json");
                    }

                });
            }
        }
    }
}

int service() {
    httplib::Server svr;
    Context context;
    context.loadLibrary(
            "test_moduel.so");
    context.loadLibrary(
            "test_moduel.so");

    initWebServer(context.getAllType(), svr);

    svr.set_error_handler([](const httplib::Request & /*req*/, httplib::Response &res) {
        const char *fmt = "<p>Error Status: <span style='color:red;'>%d</span></p>";
        char buf[BUFSIZ];
        snprintf(buf, sizeof(buf), fmt, res.status);
        res.set_content(buf, "text/html");
    });

    svr.listen("0.0.0.0", 8080);

    return 0;
}

#endif //SERVER_SERVICE_H
