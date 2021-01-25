#pragma once

#include "spdlog/spdlog.h"

#include <memory>
#include <string>
#include <vector>

namespace PGame
{
    template <typename Adapter>
    class IStorage
    {
        public:
            IStorage(std::string tableName);

            std::string GetValue(std::string key);
            bool SetValue(std::string key, std::string value);

            long long Increment(std::string key);
            long long Decrement(std::string key);

            bool SetAdd(std::string key, std::string value);
            bool SetRemove(std::string key, std::string value);
            void SetMembers(std::string key, std::vector<std::string> &values);

            void HashGet(std::string key, std::initializer_list<std::string> keys, std::vector<std::string> &values);
            void HashGet(std::string key, std::string keys, std::string &values);
            void HashSet(std::string key, std::initializer_list<std::pair<std::string, std::string>> keyValue);

            bool DeleteAll(std::string pattern);
        private:
            std::unique_ptr<Adapter> adapter;
            std::string tableName;
    };

    template <typename Adapter>
    IStorage<Adapter>::IStorage(std::string tableName): tableName(tableName)
    {
        spdlog::info("Create IStorage");
        adapter = std::make_unique<Adapter>();
    }

    template <typename Adapter>
    std::string IStorage<Adapter>::GetValue(std::string key)
    {
        return adapter->GetValue(tableName, key);
    }

    template <typename Adapter>
    bool IStorage<Adapter>::SetValue(std::string key, std::string value)
    {
        return adapter->SetValue(tableName, key, value);
    }

    template <typename Adapter>
    long long IStorage<Adapter>::Increment(std::string key)
    {
        return adapter->Increment(tableName, key);
    }

    template <typename Adapter>
    long long IStorage<Adapter>::Decrement(std::string key)
    {
        return adapter->Decrement(tableName, key);
    }

    template <typename Adapter>
    bool IStorage<Adapter>::SetAdd(std::string key, std::string value)
    {
        return adapter->SetAdd(tableName, key, value);
    }

    template <typename Adapter>
    bool IStorage<Adapter>::SetRemove(std::string key, std::string value)
    {
        return adapter->SetRemove(tableName, key, value);
    }

    template <typename Adapter>
    void IStorage<Adapter>::SetMembers(std::string key, std::vector<std::string> &values)
    {
        adapter->SetMembers(tableName, key, values);
    }

    template <typename Adapter>
    void IStorage<Adapter>::HashGet(std::string key, std::initializer_list<std::string> keys, std::vector<std::string> &values)
    {
        adapter->HashGet(tableName, key, keys, values);
    }

    template <typename Adapter>
    void IStorage<Adapter>::HashGet(std::string key, std::string keys, std::string &values)
    {
        std::vector<std::string> tempValues;
        HashGet(key, {keys}, tempValues);
        if(tempValues.size() > 0)
        {
            values = tempValues[0];
        }
    }

    template <typename Adapter>
    void IStorage<Adapter>::HashSet(std::string key, std::initializer_list<std::pair<std::string, std::string>> keyValue)
    {
        adapter->HashSet(tableName, key, keyValue);
    }

    template <typename Adapter>
    bool IStorage<Adapter>::DeleteAll(std::string pattern)
    {
        return adapter->DeleteAll(pattern);
    }
}
