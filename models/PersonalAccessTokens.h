/**
 *
 *  PersonalAccessTokens.h
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

class PersonalAccessTokens
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _tokenable_type;
        static const std::string _tokenable_id;
        static const std::string _name;
        static const std::string _token;
        static const std::string _abilities;
        static const std::string _last_used_at;
        static const std::string _created_at;
        static const std::string _updated_at;
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
    explicit PersonalAccessTokens(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit PersonalAccessTokens(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    PersonalAccessTokens(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    PersonalAccessTokens() = default;

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

    /**  For column tokenable_type  */
    ///Get the value of the column tokenable_type, returns the default value if the column is null
    const std::string &getValueOfTokenableType() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getTokenableType() const noexcept;
    ///Set the value of the column tokenable_type
    void setTokenableType(const std::string &pTokenableType) noexcept;
    void setTokenableType(std::string &&pTokenableType) noexcept;

    /**  For column tokenable_id  */
    ///Get the value of the column tokenable_id, returns the default value if the column is null
    const uint64_t &getValueOfTokenableId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<uint64_t> &getTokenableId() const noexcept;
    ///Set the value of the column tokenable_id
    void setTokenableId(const uint64_t &pTokenableId) noexcept;

    /**  For column name  */
    ///Get the value of the column name, returns the default value if the column is null
    const std::string &getValueOfName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getName() const noexcept;
    ///Set the value of the column name
    void setName(const std::string &pName) noexcept;
    void setName(std::string &&pName) noexcept;

    /**  For column token  */
    ///Get the value of the column token, returns the default value if the column is null
    const std::string &getValueOfToken() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getToken() const noexcept;
    ///Set the value of the column token
    void setToken(const std::string &pToken) noexcept;
    void setToken(std::string &&pToken) noexcept;

    /**  For column abilities  */
    ///Get the value of the column abilities, returns the default value if the column is null
    const std::string &getValueOfAbilities() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getAbilities() const noexcept;
    ///Set the value of the column abilities
    void setAbilities(const std::string &pAbilities) noexcept;
    void setAbilities(std::string &&pAbilities) noexcept;
    void setAbilitiesToNull() noexcept;

    /**  For column last_used_at  */
    ///Get the value of the column last_used_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfLastUsedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getLastUsedAt() const noexcept;
    ///Set the value of the column last_used_at
    void setLastUsedAt(const ::trantor::Date &pLastUsedAt) noexcept;
    void setLastUsedAtToNull() noexcept;

    /**  For column created_at  */
    ///Get the value of the column created_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfCreatedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getCreatedAt() const noexcept;
    ///Set the value of the column created_at
    void setCreatedAt(const ::trantor::Date &pCreatedAt) noexcept;
    void setCreatedAtToNull() noexcept;

    /**  For column updated_at  */
    ///Get the value of the column updated_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfUpdatedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getUpdatedAt() const noexcept;
    ///Set the value of the column updated_at
    void setUpdatedAt(const ::trantor::Date &pUpdatedAt) noexcept;
    void setUpdatedAtToNull() noexcept;


    static size_t getColumnNumber() noexcept {  return 9;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<PersonalAccessTokens>;
    friend drogon::orm::BaseBuilder<PersonalAccessTokens, true, true>;
    friend drogon::orm::BaseBuilder<PersonalAccessTokens, true, false>;
    friend drogon::orm::BaseBuilder<PersonalAccessTokens, false, true>;
    friend drogon::orm::BaseBuilder<PersonalAccessTokens, false, false>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<PersonalAccessTokens>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<uint64_t> id_;
    std::shared_ptr<std::string> tokenableType_;
    std::shared_ptr<uint64_t> tokenableId_;
    std::shared_ptr<std::string> name_;
    std::shared_ptr<std::string> token_;
    std::shared_ptr<std::string> abilities_;
    std::shared_ptr<::trantor::Date> lastUsedAt_;
    std::shared_ptr<::trantor::Date> createdAt_;
    std::shared_ptr<::trantor::Date> updatedAt_;
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
    bool dirtyFlag_[9]={ false };
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
            sql += "tokenable_type,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "tokenable_id,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "name,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "token,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "abilities,";
            ++parametersCount;
        }
        if(dirtyFlag_[6])
        {
            sql += "last_used_at,";
            ++parametersCount;
        }
        if(dirtyFlag_[7])
        {
            sql += "created_at,";
            ++parametersCount;
        }
        if(dirtyFlag_[8])
        {
            sql += "updated_at,";
            ++parametersCount;
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
        if(dirtyFlag_[7])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[8])
        {
            sql.append("?,");

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
