#include "redis_adapter.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    RedisAdapter::RedisAdapter()
    {
        spdlog::debug("{}", __func__);
        redis = std::make_unique<Redis>("tcp://127.0.0.1:6379");
    }

    std::string RedisAdapter::GetValue(std::string table, std::string key)
    {
        auto value = redis->get(table + ":" + key);
        std::string returnValue = "";

        if(value)
        {
            spdlog::debug("Key {}, Value: {}", key, value.value());
            returnValue = value.value();
        }
        else
        {
            spdlog::warn("Could not find key {}.", key);
        }

        return returnValue;
    }

    bool RedisAdapter::SetValue(std::string table, std::string key, std::string value)
    {
        spdlog::debug("{}: Table {}, Key {}, Value: {}", __func__, table, key, value);
        return redis->set(table + ":" + key, value);
    }

    long long RedisAdapter::Increment(std::string table, std::string key)
    {
        spdlog::debug("{}: Key {}", __func__, key);
        redis->incr(table + ":" + key);
    }

    long long RedisAdapter::Decrement(std::string table, std::string key)
    {
        spdlog::debug("{}: Key {}", __func__, key);
        redis->decr(table + ":" + key);
    }

    bool RedisAdapter::SetAdd(std::string table, std::string key, std::string value)
    {
        spdlog::debug("{}: Key {}, Value: {}", __func__, key, value);

        if(redis->sadd(table + ":" + key, {value}) == 1)
        {
            return true;
        }

        return false;
    }

    bool RedisAdapter::SetRemove(std::string table, std::string key, std::string value)
    {
        spdlog::debug("{}: Key {}, Value: {}", __func__, key, value);

        if(redis->srem(table + ":" + key, value) == 0)
        {
            return true;
        }

        return false;
    }

    void RedisAdapter::SetMembers(std::string table, std::string key, std::vector<std::string> &values)
    {
        spdlog::debug("{}: Key {}", __func__, key);
        redis->smembers(table + ":" + key, std::back_inserter(values));
    }

    void RedisAdapter::HashGet(std::string table, std::string key, std::initializer_list<std::string> keys, std::vector<std::string> &values)
    {
        spdlog::debug("{}: Key {}", __func__, key);
        std::vector<OptionalString> tempValues;
        redis->hmget(table + ":" + key, keys, std::back_inserter(tempValues));
        for(auto tempValue: tempValues)
        {
            values.push_back(tempValue.value());
        }
    }

    void RedisAdapter::HashSet(std::string table, std::string key, std::initializer_list<std::pair<std::string, std::string>> keyValue)
    {
        spdlog::debug("{}: Key {}:{}", __func__, table, key);
        redis->hmset(table + ":" + key, keyValue);
    }

    bool RedisAdapter::DeleteAll(std::string pattern)
    {
        spdlog::debug("{}: Pattern {}", __func__, pattern);
        std::vector<OptionalString> tempKeys;
        redis->keys(pattern, std::back_inserter(tempKeys));

        if(tempKeys.size() == 0)
        {
            spdlog::warn("Pattern {} not found", pattern);
            return false;
        }

        std::vector<std::string> delKeys;
        for(auto key: tempKeys)
        {
            spdlog::debug("Key {}", key.value());
            delKeys.push_back(key.value());
        }
        redis->del(delKeys.begin(), delKeys.end());

        return true;
    }
}
