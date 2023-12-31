/**
 *
 *  FailedJobs.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/BaseBuilder.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace remote_binary
{

class FailedJobs
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _uuid;
        static const std::string _connection;
        static const std::string _queue;
        static const std::string _payload;
        static const std::string _exception;
        static const std::string _failed_at;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = uint64_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit FailedJobs(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit FailedJobs(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    FailedJobs(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    FailedJobs() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const uint64_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getId() const noexcept;
    ///Set the value of the column id
    void setId(const uint64_t &pId) noexcept;

    /**  For column uuid  */
    ///Get the value of the column uuid, returns the default value if the column is null
    const std::string &getValueOfUuid() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getUuid() const noexcept;
    ///Set the value of the column uuid
    void setUuid(const std::string &pUuid) noexcept;
    void setUuid(std::string &&pUuid) noexcept;

    /**  For column connection  */
    ///Get the value of the column connection, returns the default value if the column is null
    const std::string &getValueOfConnection() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getConnection() const noexcept;
    ///Set the value of the column connection
    void setConnection(const std::string &pConnection) noexcept;
    void setConnection(std::string &&pConnection) noexcept;

    /**  For column queue  */
    ///Get the value of the column queue, returns the default value if the column is null
    const std::string &getValueOfQueue() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getQueue() const noexcept;
    ///Set the value of the column queue
    void setQueue(const std::string &pQueue) noexcept;
    void setQueue(std::string &&pQueue) noexcept;

    /**  For column payload  */
    ///Get the value of the column payload, returns the default value if the column is null
    const std::string &getValueOfPayload() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getPayload() const noexcept;
    ///Set the value of the column payload
    void setPayload(const std::string &pPayload) noexcept;
    void setPayload(std::string &&pPayload) noexcept;

    /**  For column exception  */
    ///Get the value of the column exception, returns the default value if the column is null
    const std::string &getValueOfException() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getException() const noexcept;
    ///Set the value of the column exception
    void setException(const std::string &pException) noexcept;
    void setException(std::string &&pException) noexcept;

    /**  For column failed_at  */
    ///Get the value of the column failed_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfFailedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getFailedAt() const noexcept;
    ///Set the value of the column failed_at
    void setFailedAt(const ::trantor::Date &pFailedAt) noexcept;


    static size_t getColumnNumber() noexcept {  return 7;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<FailedJobs>;
    friend drogon::orm::BaseBuilder<FailedJobs, true, true>;
    friend drogon::orm::BaseBuilder<FailedJobs, true, false>;
    friend drogon::orm::BaseBuilder<FailedJobs, false, true>;
    friend drogon::orm::BaseBuilder<FailedJobs, false, false>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<FailedJobs>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<uint64_t> id_;
    std::shared_ptr<std::string> uuid_;
    std::shared_ptr<std::string> connection_;
    std::shared_ptr<std::string> queue_;
    std::shared_ptr<std::string> payload_;
    std::shared_ptr<std::string> exception_;
    std::shared_ptr<::trantor::Date> failedAt_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[7]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = ?";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = ?";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "uuid,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "connection,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "queue,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "payload,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "exception,";
            ++parametersCount;
        }
        sql += "failed_at,";
        ++parametersCount;
        if(!dirtyFlag_[6])
        {
            needSelection=true;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        sql +="default,";
        if(dirtyFlag_[1])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[2])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[3])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[4])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[5])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[6])
        {
            sql.append("?,");

        }
        else
        {
            sql +="default,";
        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        sql.append(1, ')');
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace remote_binary
} // namespace drogon_model
