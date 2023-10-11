#pragma once
#include "common.hpp"

#include "models/Users.h"

using namespace drogon;
using namespace drogon_model::remote_binary;
using namespace orm;

using func_t = std::function<void(HttpResponsePtr const&)>;

namespace gottvergessen
{
	class user : public drogon::HttpController<user>
	{
	public:
		METHOD_LIST_BEGIN
		// use METHOD_ADD to add your custom processing function here;
		// METHOD_ADD(user::get, "/{2}/{1}", Get); // path is /user/{arg2}/{arg1}
		// METHOD_ADD(user::your_method_name, "/{1}/{2}/list", Get); // path is /user/{arg1}/{arg2}/list
		// ADD_METHOD_TO(user::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
		ADD_METHOD_TO(user::find_all, "/user", Get); // Say hello at the root path
		ADD_METHOD_TO(user::create, "/user", Post);
		ADD_METHOD_TO(user::find_by_id, "user/{id}", Get);
		ADD_METHOD_TO(user::update, "user/{id}", Patch);
		ADD_METHOD_TO(user::remove, "user/{id}", Delete);
		METHOD_LIST_END
		// your declaration of processing function maybe like this:
		// void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
		// void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
		void find_all(HttpRequestPtr const& req, func_t&& callback);
		void find_by_id(HttpRequestPtr const& req, func_t&& callback, std::string&& id);
		void create(HttpRequestPtr const& req, func_t&& callback);
		void update(HttpRequestPtr const& req, func_t&& callback, std::string&& id);
		void remove(HttpRequestPtr const& req, func_t&& callback, std::string&& id);
	};
} // namespace name

