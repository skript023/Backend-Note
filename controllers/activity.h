#pragma once

#include <drogon/HttpController.h>

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
		ADD_METHOD_TO(activity::activities, "/activities", Get); // Say hello at the root path
		ADD_METHOD_TO(activity::add_activity, "/activity/create", Post);
		ADD_METHOD_TO(activity::update_activity, "activity/update/{id}", Patch);
		METHOD_LIST_END
		// your declaration of processing function maybe like this:
		// void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
		// void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;

		void sayHello(HttpRequestPtr const& req, std::function<void(HttpResponsePtr const&)>&& callback);
		void activities(HttpRequestPtr const& req, std::function<void(HttpResponsePtr const&)>&& callback);
		void add_activity(HttpRequestPtr const& req, std::function<void(HttpResponsePtr const&)>&& callback);
		void update_activity(HttpRequestPtr const& req, std::function<void(HttpResponsePtr const&)>&& callback, std::string&& id);
	};
}