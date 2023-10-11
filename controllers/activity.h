#pragma once

#include <drogon/HttpController.h>
#include "models/Activities.h"
#include "models/Users.h"
#include "models/Roles.h"

using namespace drogon_model::remote_binary;
using namespace drogon::orm;

using namespace drogon;
using func_t = std::function<void(HttpResponsePtr const&)>;

namespace cms
{
	class activity : public drogon::HttpController<activity>
	{
	public:
		METHOD_LIST_BEGIN
		// use METHOD_ADD to add your custom processing function here;
		// METHOD_ADD(./controllers/activity::get, "/{2}/{1}", Get); // path is /./controllers/activity/{arg2}/{arg1}
		// METHOD_ADD(./controllers/activity::your_method_name, "/{1}/{2}/list", Get); // path is /./controllers/activity/{arg1}/{arg2}/list
		// ADD_METHOD_TO(./controllers/activity::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
		ADD_METHOD_TO(activity::sayHello, "/", Get); // Say hello at the root path
		ADD_METHOD_TO(activity::find_all, "/activity", Get); // Say hello at the root path
		ADD_METHOD_TO(activity::create, "/activity", Post);
		ADD_METHOD_TO(activity::find_by_id, "activity/{id}", Get);
		ADD_METHOD_TO(activity::update, "activity/{id}", Patch);
		ADD_METHOD_TO(activity::remove, "activity/{id}", Delete);
		METHOD_LIST_END
		// your declaration of processing function maybe like this:
		// void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
		// void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

		void sayHello(HttpRequestPtr const& req, func_t&& callback);
		void find_all(HttpRequestPtr const& req, func_t&& callback);
		void find_by_id(HttpRequestPtr const& req, func_t&& callback, std::string&& id);
		void create(HttpRequestPtr const& req, func_t&& callback);
		void update(HttpRequestPtr const& req, func_t&& callback, std::string&& id);
		void remove(HttpRequestPtr const& req, func_t&& callback, std::string&& id);
	};
}