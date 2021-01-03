#pragma once

#include <memory>
#include <string>
#include <vector>

#include <sw/redis++/redis++.h>

using namespace sw::redis;

namespace PGame
{
    class RedisAdapter
    {
        public:
            RedisAdapter();

            std::string GetValue(std::string table, std::string key);
            bool SetValue(std::string table, std::string key, std::string value);

            long long Increment(std::string table, std::string key);
            long long Decrement(std::string table, std::string key);

            bool SetAdd(std::string table, std::string key, std::string value);
            bool SetRemove(std::string table, std::string key, std::string value);
            void SetMembers(std::string table, std::string key, std::vector<std::string> &values);

            void HashGet(std::string table, std::string key, std::initializer_list<std::string> keys, std::vector<std::string> &values);
            void HashSet(std::string table, std::string key, std::initializer_list<std::pair<std::string, std::string>> keyValue);

            bool DeleteAll(std::string pattern);
        
        private:
            std::unique_ptr<Redis> redis;
    };
}

