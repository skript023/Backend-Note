/**
 *
 *  AccessLevels.h
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

class AccessLevels
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _name;
        static const std::string _badge;
        static const std::string _icon;
        static const std::string _create;
        static const std::string _read;
        static const std::string _update;
        static const std::string _delete;
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
    explicit AccessLevels(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit AccessLevels(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    AccessLevels(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    AccessLevels() = default;

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

    /**  For column name  */
    ///Get the value of the column name, returns the default value if the column is null
    const std::string &getValueOfName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getName() const noexcept;
    ///Set the value of the column name
    void setName(const std::string &pName) noexcept;
    void setName(std::string &&pName) noexcept;

    /**  For column badge  */
    ///Get the value of the column badge, returns the default value if the column is null
    const std::string &getValueOfBadge() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getBadge() const noexcept;
    ///Set the value of the column badge
    void setBadge(const std::string &pBadge) noexcept;
    void setBadge(std::string &&pBadge) noexcept;
    void setBadgeToNull() noexcept;

    /**  For column icon  */
    ///Get the value of the column icon, returns the default value if the column is null
    const std::string &getValueOfIcon() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getIcon() const noexcept;
    ///Set the value of the column icon
    void setIcon(const std::string &pIcon) noexcept;
    void setIcon(std::string &&pIcon) noexcept;
    void setIconToNull() noexcept;

    /**  For column create  */
    ///Get the value of the column create, returns the default value if the column is null
    const int8_t &getValueOfCreate() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int8_t> &getCreate() const noexcept;
    ///Set the value of the column create
    void setCreate(const int8_t &pCreate) noexcept;
    void setCreateToNull() noexcept;

    /**  For column read  */
    ///Get the value of the column read, returns the default value if the column is null
    const int8_t &getValueOfRead() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int8_t> &getRead() const noexcept;
    ///Set the value of the column read
    void setRead(const int8_t &pRead) noexcept;
    void setReadToNull() noexcept;

    /**  For column update  */
    ///Get the value of the column update, returns the default value if the column is null
    const int8_t &getValueOfUpdate() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int8_t> &getUpdate() const noexcept;
    ///Set the value of the column update
    void setUpdate(const int8_t &pUpdate) noexcept;
    void setUpdateToNull() noexcept;

    /**  For column delete  */
    ///Get the value of the column delete, returns the default value if the column is null
    const int8_t &getValueOfDelete() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int8_t> &getDelete() const noexcept;
    ///Set the value of the column delete
    void setDelete(const int8_t &pDelete) noexcept;
    void setDeleteToNull() noexcept;

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


    static size_t getColumnNumber() noexcept {  return 10;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<AccessLevels>;
    friend drogon::orm::BaseBuilder<AccessLevels, true, true>;
    friend drogon::orm::BaseBuilder<AccessLevels, true, false>;
    friend drogon::orm::BaseBuilder<AccessLevels, false, true>;
    friend drogon::orm::BaseBuilder<AccessLevels, false, false>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<AccessLevels>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<uint64_t> id_;
    std::shared_ptr<std::string> name_;
    std::shared_ptr<std::string> badge_;
    std::shared_ptr<std::string> icon_;
    std::shared_ptr<int8_t> create_;
    std::shared_ptr<int8_t> read_;
    std::shared_ptr<int8_t> update_;
    std::shared_ptr<int8_t> delete_;
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
    bool dirtyFlag_[10]={ false };
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
            sql += "name,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "badge,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "icon,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "create,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "read,";
            ++parametersCount;
        }
        if(dirtyFlag_[6])
        {
            sql += "update,";
            ++parametersCount;
        }
        if(dirtyFlag_[7])
        {
            sql += "delete,";
            ++parametersCount;
        }
        if(dirtyFlag_[8])
        {
            sql += "created_at,";
            ++parametersCount;
        }
        if(dirtyFlag_[9])
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
        if(dirtyFlag_[9])
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
