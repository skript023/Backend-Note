/**
 *
 *  FailedJobs.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "FailedJobs.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::remote_binary;

const std::string FailedJobs::Cols::_id = "id";
const std::string FailedJobs::Cols::_uuid = "uuid";
const std::string FailedJobs::Cols::_connection = "connection";
const std::string FailedJobs::Cols::_queue = "queue";
const std::string FailedJobs::Cols::_payload = "payload";
const std::string FailedJobs::Cols::_exception = "exception";
const std::string FailedJobs::Cols::_failed_at = "failed_at";
const std::string FailedJobs::primaryKeyName = "id";
const bool FailedJobs::hasPrimaryKey = true;
const std::string FailedJobs::tableName = "failed_jobs";

const std::vector<typename FailedJobs::MetaData> FailedJobs::metaData_={
{"id","uint64_t","bigint(20) unsigned",8,1,1,1},
{"uuid","std::string","varchar(255)",255,0,0,1},
{"connection","std::string","text",0,0,0,1},
{"queue","std::string","text",0,0,0,1},
{"payload","std::string","longtext",0,0,0,1},
{"exception","std::string","longtext",0,0,0,1},
{"failed_at","::trantor::Date","timestamp",0,0,0,1}
};
const std::string &FailedJobs::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
FailedJobs::FailedJobs(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<uint64_t>(r["id"].as<uint64_t>());
        }
        if(!r["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(r["uuid"].as<std::string>());
        }
        if(!r["connection"].isNull())
        {
            connection_=std::make_shared<std::string>(r["connection"].as<std::string>());
        }
        if(!r["queue"].isNull())
        {
            queue_=std::make_shared<std::string>(r["queue"].as<std::string>());
        }
        if(!r["payload"].isNull())
        {
            payload_=std::make_shared<std::string>(r["payload"].as<std::string>());
        }
        if(!r["exception"].isNull())
        {
            exception_=std::make_shared<std::string>(r["exception"].as<std::string>());
        }
        if(!r["failed_at"].isNull())
        {
            auto timeStr = r["failed_at"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                failedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 7 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            uuid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            connection_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            queue_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            payload_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            exception_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 6;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                failedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }

}

FailedJobs::FailedJobs(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 7)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            connection_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            queue_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            payload_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            exception_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[6]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                failedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

FailedJobs::FailedJobs(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("uuid"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson["uuid"].asString());
        }
    }
    if(pJson.isMember("connection"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["connection"].isNull())
        {
            connection_=std::make_shared<std::string>(pJson["connection"].asString());
        }
    }
    if(pJson.isMember("queue"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["queue"].isNull())
        {
            queue_=std::make_shared<std::string>(pJson["queue"].asString());
        }
    }
    if(pJson.isMember("payload"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["payload"].isNull())
        {
            payload_=std::make_shared<std::string>(pJson["payload"].asString());
        }
    }
    if(pJson.isMember("exception"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["exception"].isNull())
        {
            exception_=std::make_shared<std::string>(pJson["exception"].asString());
        }
    }
    if(pJson.isMember("failed_at"))
    {
        dirtyFlag_[6]=true;
        if(!pJson["failed_at"].isNull())
        {
            auto timeStr = pJson["failed_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                failedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

void FailedJobs::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 7)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            connection_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            queue_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            payload_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            exception_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[6]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                failedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

void FailedJobs::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("uuid"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["uuid"].isNull())
        {
            uuid_=std::make_shared<std::string>(pJson["uuid"].asString());
        }
    }
    if(pJson.isMember("connection"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["connection"].isNull())
        {
            connection_=std::make_shared<std::string>(pJson["connection"].asString());
        }
    }
    if(pJson.isMember("queue"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["queue"].isNull())
        {
            queue_=std::make_shared<std::string>(pJson["queue"].asString());
        }
    }
    if(pJson.isMember("payload"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["payload"].isNull())
        {
            payload_=std::make_shared<std::string>(pJson["payload"].asString());
        }
    }
    if(pJson.isMember("exception"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["exception"].isNull())
        {
            exception_=std::make_shared<std::string>(pJson["exception"].asString());
        }
    }
    if(pJson.isMember("failed_at"))
    {
        dirtyFlag_[6] = true;
        if(!pJson["failed_at"].isNull())
        {
            auto timeStr = pJson["failed_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                failedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

const uint64_t &FailedJobs::getValueOfId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &FailedJobs::getId() const noexcept
{
    return id_;
}
void FailedJobs::setId(const uint64_t &pId) noexcept
{
    id_ = std::make_shared<uint64_t>(pId);
    dirtyFlag_[0] = true;
}
const typename FailedJobs::PrimaryKeyType & FailedJobs::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &FailedJobs::getValueOfUuid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(uuid_)
        return *uuid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &FailedJobs::getUuid() const noexcept
{
    return uuid_;
}
void FailedJobs::setUuid(const std::string &pUuid) noexcept
{
    uuid_ = std::make_shared<std::string>(pUuid);
    dirtyFlag_[1] = true;
}
void FailedJobs::setUuid(std::string &&pUuid) noexcept
{
    uuid_ = std::make_shared<std::string>(std::move(pUuid));
    dirtyFlag_[1] = true;
}

const std::string &FailedJobs::getValueOfConnection() const noexcept
{
    const static std::string defaultValue = std::string();
    if(connection_)
        return *connection_;
    return defaultValue;
}
const std::shared_ptr<std::string> &FailedJobs::getConnection() const noexcept
{
    return connection_;
}
void FailedJobs::setConnection(const std::string &pConnection) noexcept
{
    connection_ = std::make_shared<std::string>(pConnection);
    dirtyFlag_[2] = true;
}
void FailedJobs::setConnection(std::string &&pConnection) noexcept
{
    connection_ = std::make_shared<std::string>(std::move(pConnection));
    dirtyFlag_[2] = true;
}

const std::string &FailedJobs::getValueOfQueue() const noexcept
{
    const static std::string defaultValue = std::string();
    if(queue_)
        return *queue_;
    return defaultValue;
}
const std::shared_ptr<std::string> &FailedJobs::getQueue() const noexcept
{
    return queue_;
}
void FailedJobs::setQueue(const std::string &pQueue) noexcept
{
    queue_ = std::make_shared<std::string>(pQueue);
    dirtyFlag_[3] = true;
}
void FailedJobs::setQueue(std::string &&pQueue) noexcept
{
    queue_ = std::make_shared<std::string>(std::move(pQueue));
    dirtyFlag_[3] = true;
}

const std::string &FailedJobs::getValueOfPayload() const noexcept
{
    const static std::string defaultValue = std::string();
    if(payload_)
        return *payload_;
    return defaultValue;
}
const std::shared_ptr<std::string> &FailedJobs::getPayload() const noexcept
{
    return payload_;
}
void FailedJobs::setPayload(const std::string &pPayload) noexcept
{
    payload_ = std::make_shared<std::string>(pPayload);
    dirtyFlag_[4] = true;
}
void FailedJobs::setPayload(std::string &&pPayload) noexcept
{
    payload_ = std::make_shared<std::string>(std::move(pPayload));
    dirtyFlag_[4] = true;
}

const std::string &FailedJobs::getValueOfException() const noexcept
{
    const static std::string defaultValue = std::string();
    if(exception_)
        return *exception_;
    return defaultValue;
}
const std::shared_ptr<std::string> &FailedJobs::getException() const noexcept
{
    return exception_;
}
void FailedJobs::setException(const std::string &pException) noexcept
{
    exception_ = std::make_shared<std::string>(pException);
    dirtyFlag_[5] = true;
}
void FailedJobs::setException(std::string &&pException) noexcept
{
    exception_ = std::make_shared<std::string>(std::move(pException));
    dirtyFlag_[5] = true;
}

const ::trantor::Date &FailedJobs::getValueOfFailedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(failedAt_)
        return *failedAt_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &FailedJobs::getFailedAt() const noexcept
{
    return failedAt_;
}
void FailedJobs::setFailedAt(const ::trantor::Date &pFailedAt) noexcept
{
    failedAt_ = std::make_shared<::trantor::Date>(pFailedAt);
    dirtyFlag_[6] = true;
}

void FailedJobs::updateId(const uint64_t id)
{
    id_ = std::make_shared<uint64_t>(id);
}

const std::vector<std::string> &FailedJobs::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "uuid",
        "connection",
        "queue",
        "payload",
        "exception",
        "failed_at"
    };
    return inCols;
}

void FailedJobs::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getUuid())
        {
            binder << getValueOfUuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getConnection())
        {
            binder << getValueOfConnection();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getQueue())
        {
            binder << getValueOfQueue();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPayload())
        {
            binder << getValueOfPayload();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getException())
        {
            binder << getValueOfException();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getFailedAt())
        {
            binder << getValueOfFailedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> FailedJobs::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    if(dirtyFlag_[6])
    {
        ret.push_back(getColumnName(6));
    }
    return ret;
}

void FailedJobs::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getUuid())
        {
            binder << getValueOfUuid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getConnection())
        {
            binder << getValueOfConnection();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getQueue())
        {
            binder << getValueOfQueue();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPayload())
        {
            binder << getValueOfPayload();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getException())
        {
            binder << getValueOfException();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getFailedAt())
        {
            binder << getValueOfFailedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value FailedJobs::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getUuid())
    {
        ret["uuid"]=getValueOfUuid();
    }
    else
    {
        ret["uuid"]=Json::Value();
    }
    if(getConnection())
    {
        ret["connection"]=getValueOfConnection();
    }
    else
    {
        ret["connection"]=Json::Value();
    }
    if(getQueue())
    {
        ret["queue"]=getValueOfQueue();
    }
    else
    {
        ret["queue"]=Json::Value();
    }
    if(getPayload())
    {
        ret["payload"]=getValueOfPayload();
    }
    else
    {
        ret["payload"]=Json::Value();
    }
    if(getException())
    {
        ret["exception"]=getValueOfException();
    }
    else
    {
        ret["exception"]=Json::Value();
    }
    if(getFailedAt())
    {
        ret["failed_at"]=getFailedAt()->toDbStringLocal();
    }
    else
    {
        ret["failed_at"]=Json::Value();
    }
    return ret;
}

Json::Value FailedJobs::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 7)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=(Json::UInt64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getUuid())
            {
                ret[pMasqueradingVector[1]]=getValueOfUuid();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getConnection())
            {
                ret[pMasqueradingVector[2]]=getValueOfConnection();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getQueue())
            {
                ret[pMasqueradingVector[3]]=getValueOfQueue();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getPayload())
            {
                ret[pMasqueradingVector[4]]=getValueOfPayload();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getException())
            {
                ret[pMasqueradingVector[5]]=getValueOfException();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[6].empty())
        {
            if(getFailedAt())
            {
                ret[pMasqueradingVector[6]]=getFailedAt()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[6]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getUuid())
    {
        ret["uuid"]=getValueOfUuid();
    }
    else
    {
        ret["uuid"]=Json::Value();
    }
    if(getConnection())
    {
        ret["connection"]=getValueOfConnection();
    }
    else
    {
        ret["connection"]=Json::Value();
    }
    if(getQueue())
    {
        ret["queue"]=getValueOfQueue();
    }
    else
    {
        ret["queue"]=Json::Value();
    }
    if(getPayload())
    {
        ret["payload"]=getValueOfPayload();
    }
    else
    {
        ret["payload"]=Json::Value();
    }
    if(getException())
    {
        ret["exception"]=getValueOfException();
    }
    else
    {
        ret["exception"]=Json::Value();
    }
    if(getFailedAt())
    {
        ret["failed_at"]=getFailedAt()->toDbStringLocal();
    }
    else
    {
        ret["failed_at"]=Json::Value();
    }
    return ret;
}

bool FailedJobs::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("uuid"))
    {
        if(!validJsonOfField(1, "uuid", pJson["uuid"], err, true))
            return false;
    }
    else
    {
        err="The uuid column cannot be null";
        return false;
    }
    if(pJson.isMember("connection"))
    {
        if(!validJsonOfField(2, "connection", pJson["connection"], err, true))
            return false;
    }
    else
    {
        err="The connection column cannot be null";
        return false;
    }
    if(pJson.isMember("queue"))
    {
        if(!validJsonOfField(3, "queue", pJson["queue"], err, true))
            return false;
    }
    else
    {
        err="The queue column cannot be null";
        return false;
    }
    if(pJson.isMember("payload"))
    {
        if(!validJsonOfField(4, "payload", pJson["payload"], err, true))
            return false;
    }
    else
    {
        err="The payload column cannot be null";
        return false;
    }
    if(pJson.isMember("exception"))
    {
        if(!validJsonOfField(5, "exception", pJson["exception"], err, true))
            return false;
    }
    else
    {
        err="The exception column cannot be null";
        return false;
    }
    if(pJson.isMember("failed_at"))
    {
        if(!validJsonOfField(6, "failed_at", pJson["failed_at"], err, true))
            return false;
    }
    return true;
}
bool FailedJobs::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                    const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err)
{
    if(pMasqueradingVector.size() != 7)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[5] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[6].empty())
      {
          if(pJson.isMember(pMasqueradingVector[6]))
          {
              if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool FailedJobs::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("uuid"))
    {
        if(!validJsonOfField(1, "uuid", pJson["uuid"], err, false))
            return false;
    }
    if(pJson.isMember("connection"))
    {
        if(!validJsonOfField(2, "connection", pJson["connection"], err, false))
            return false;
    }
    if(pJson.isMember("queue"))
    {
        if(!validJsonOfField(3, "queue", pJson["queue"], err, false))
            return false;
    }
    if(pJson.isMember("payload"))
    {
        if(!validJsonOfField(4, "payload", pJson["payload"], err, false))
            return false;
    }
    if(pJson.isMember("exception"))
    {
        if(!validJsonOfField(5, "exception", pJson["exception"], err, false))
            return false;
    }
    if(pJson.isMember("failed_at"))
    {
        if(!validJsonOfField(6, "failed_at", pJson["failed_at"], err, false))
            return false;
    }
    return true;
}
bool FailedJobs::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 7)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
              return false;
      }
      if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
      {
          if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool FailedJobs::validJsonOfField(size_t index,
                                  const std::string &fieldName,
                                  const Json::Value &pJson,
                                  std::string &err,
                                  bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 5:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 6:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
