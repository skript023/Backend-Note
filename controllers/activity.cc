#include "activity.h"
#include "common.hpp"

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

    void activity::find_all(const HttpRequestPtr& req, func_t&& callback)
    {
        auto db = drogon::orm::Mapper<Activities>(DATABASE_CLIENT);

        auto activities = db.findAll();

        if (activities.empty())
        {
            Json::Value json;
            json["message"] = "Cannot retrieve activity data, 0 data found";
            json["success"] = false;

            auto response = HttpResponse::newHttpJsonResponse(json);
            response->setStatusCode(drogon::HttpStatusCode::k404NotFound);

            callback(response);
        }

        Json::Value res(Json::arrayValue);

        for (const auto& activity : activities) 
        {
            res.append(activity.toJson());
        }
        auto response = HttpResponse::newHttpJsonResponse(res);
        
        callback(response);
    }

    void activity::find_by_id(HttpRequestPtr const& req, func_t&& callback, std::string&& id)
    {
        auto db = Mapper<Activities>(DATABASE_CLIENT);
        Json::Value json;
        
        try
        {
            auto activity = db.findByPrimaryKey(stoll(id));
            json = activity.toJson();

            auto response = HttpResponse::newHttpJsonResponse(json);
            
            callback(response);
        }
        catch(const std::exception& e)
        {
            if (json.isNull())
            {
                json["message"] = std::format("Cannot retrieve activity data, error caught on {}", e.what());
                json["success"] = false;

                auto response = HttpResponse::newHttpJsonResponse(json);
                response->setStatusCode(drogon::HttpStatusCode::k404NotFound);

                callback(response);
            }
            else
            {
                json["message"] = std::format("Cannot retrieve activity data, error caught on {}", e.what());
                json["success"] = false;

                auto response = HttpResponse::newHttpJsonResponse(json);
                response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);

                callback(response);
            }
        }
    }

    void activity::create(HttpRequestPtr const& req, func_t&& callback)
    {
        Json::Value resp;
        try
        {
            const auto& json = *req->getJsonObject().get();
            
            Activities activity;
            auto db = drogon::orm::Mapper<Activities>(DATABASE_CLIENT);

            std::string start(json["start_date"].asCString());
            std::string end(json["end_date"].asString());
            std::string name(json["name"].asCString());

            activity.setName(name);
            activity.setUserId(json["user_id"].asInt64());
            activity.setStartDate(trantor::Date::fromDbString(start));
            activity.setEndDate(trantor::Date::fromDbString(end));
            activity.setStatus(json["status"].asString());
            activity.setCreatedAt(trantor::Date::now());
            activity.setUpdatedAt(trantor::Date::now());

            db.insert(activity);
            resp["message"] = "Create activity successfull";
            resp["success"] = true;

            auto response = HttpResponse::newHttpJsonResponse(resp);
            
            callback(response);
        }
        catch(const std::exception& e)
        {
            resp["message"] = std::format("Create activity failed, error caught on {}", e.what());
            resp["success"] = false;

            auto response = HttpResponse::newHttpJsonResponse(resp);
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);

            callback(response);
        }
    }

    void activity::update(HttpRequestPtr const& req, func_t&& callback, std::string&& id)
    {
        Json::Value resp;
        resp["message"] = "Update activity successful";
        resp["success"] = true;

        auto response = HttpResponse::newHttpJsonResponse(resp);

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

        try
        {
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

            callback(response);
        }
        catch(const std::exception& e)
        {
            resp["message"] = std::format("Update activity failed, error caught on {}", e.what());
            resp["success"] = false;
            response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);

            callback(response);
        }
        
    }

    void activity::remove(HttpRequestPtr const& req, func_t&& callback, std::string&& id)
    {
        auto db = Mapper<Activities>(DATABASE_CLIENT);

        Json::Value resp;

        try
        {
            db.deleteByPrimaryKey(std::stoll(id));

            resp["message"] = "Delete activity successful";
            resp["success"] = true;

            auto response = HttpResponse::newHttpJsonResponse(resp);
            callback(response);
        }
        catch(const std::exception& e)
        {
            

            if (id.empty())
            {
                resp["message"] = "Cannot delete activity, invalid request.";
                resp["success"] = false;

                auto response = HttpResponse::newHttpJsonResponse(resp);
                response->setStatusCode(drogon::HttpStatusCode::k400BadRequest);

                callback(response);
            }
            else
            {
                resp["message"] = std::format("Cannot delete activity, error caught on {}", e.what());
                resp["success"] = false;

                auto response = HttpResponse::newHttpJsonResponse(resp);
                response->setStatusCode(drogon::HttpStatusCode::k500InternalServerError);

                callback(response);
            }
        }
    }
}