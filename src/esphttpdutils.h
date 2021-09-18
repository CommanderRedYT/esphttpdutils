#pragma once

// system includes
#include <string>
#include <string_view>

// esp-idf includes
#include <esp_http_server.h>

// 3rdparty lib includes
#include <tl/expected.hpp>

// local includes
#include "esphttpstatuscodes.h"

namespace esphttpdutils {

template<typename T> T htmlentities(const T &val) { return val; } // TODO
template<typename T> T htmlentities(T &&val) { return val; } // TODO

void urldecode(char *dst, const char *src);

tl::expected<void, std::string> urlverify(std::string_view str);

esp_err_t webserver_prepare_response(httpd_req_t *req);

esp_err_t webserver_resp_send(httpd_req_t *req, ResponseStatus error, const char *type, std::string_view body);

tl::expected<std::string, std::string> webserver_get_query(httpd_req_t *req);

} // namespace esphttpdutils
