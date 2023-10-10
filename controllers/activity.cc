#include "activity.h"
#include "common.hpp"
#include "models/Activities.h"

using namespace drogon_model::remote_binary;
using namespace drogon::orm;

namespace cms
{
    // Add definition of your processing function here
    void activity::sayHello(const HttpRequestPtr& req, func_t&& callback)
    {
        // Create a simple "Hello, World!" response
        auto response = HttpResponse::newHttpResponse();
        response->setContentTypeCode(CT_TEXT_HTML);
        response->setBody("<h1>Hello, World!</h1>");

        std::invoke(std::move(callback), response);
    }

    void activity::activities(const HttpRequestPtr& req, func_t&& callback)
    {
        auto db = drogon::orm::Mapper<Activities>(DATABASE_CLIENT);

        auto activities = db.findAll();

        Json::Value res(Json::arrayValue);

        for (const auto& activity : activities) 
        {
            res.append(activity.toJson());
        }
        auto response = HttpResponse::newHttpJsonResponse(res);
        
        callback(response);
    }

    void activity::add_activity(HttpRequestPtr const& req, func_t&& callback)
    {
        const auto& json = *req->getJsonObject().get();
        
        Activities new_activity;
        auto db = drogon::orm::Mapper<Activities>(DATABASE_CLIENT);

        std::string start(json["start_date"].asCString());
        std::string end(json["end_date"].asString());
        std::string name(json["name"].asCString());

        new_activity.setName(name);
        new_activity.setUserId(json["user_id"].asInt64());
        new_activity.setStartDate(trantor::Date::fromDbString(start));
        new_activity.setEndDate(trantor::Date::fromDbString(end));
        new_activity.setStatus(json["status"].asString());

        db.insert(new_activity);

        Json::Value resp;
        resp["message"] = "Create activity successfull";
        resp["success"] = true;

        auto response = HttpResponse::newHttpJsonResponse(resp);
        
        callback(response);
    }

    void activity::update_activity(HttpRequestPtr const& req, func_t&& callback, std::string&& id)
    {
        const auto& json = *req->getJsonObject().get();

        auto db = Mapper<Activities>(DATABASE_CLIENT);

        auto args = Criteria(Activities::Cols::_id, CompareOperator::EQ, id);

        std::map<Json::Value::Members, std::string> columnMapping = {
            {{Activities::Cols::_name}, "name"},
            {{Activities::Cols::_user_id}, "user_id"},
            {{Activities::Cols::_start_date}, "start_date"},
            {{Activities::Cols::_end_date}, "end_date"},
            {{Activities::Cols::_status}, "status"}
        };

        Json::Value resp;
        resp["message"] = "Update activity successful";
        resp["success"] = true;

        // Loop through JSON members and update corresponding database columns
        for (const auto& [column, request] : columnMapping)
        {
            if (json.isMember(request))
            {
                auto jsonValue = json[request];
                if (!jsonValue.isNull())
                {
                    db.updateBy(column, args, jsonValue.asString());
                    resp[request + "_updated"] = true;
                }
            }
        }

        auto response = HttpResponse::newHttpJsonResponse(resp);
        
        callback(response);
    }
}