#pragma once

#include <memory>
#include <algorithm>
#include <optional>
#include <stdint.h>
#include <string>
#include <vector>

using TableID = uint64_t;
using RollValue = int64_t;
using Level = int64_t;
using Name = std::string;        // Name displayed
using NameTag = std::string;     // Nametag searched for, unique, separated by _
using Description = std::string; // Longer description

template <typename T>
T fromString(const std::string& str);

template<typename T>
class CDataTableBase
{
    static_assert(std::is_same<decltype(T::id), TableID>::value, "T must have a member named 'id' of type 'TableID'");
    static_assert(std::is_same<decltype(T::nameTag), NameTag>::value, "T must have a member named 'nameTag' of type 'NameTag'");
private:
    std::vector<T> table;
public:
    CDataTableBase() = default;

    const std::vector<T>& getAll() const{return table;}
    size_t size() const{return table.size();}
    bool hasEntry(const T* ptr) const { return std::find_if(table.begin(), table.end(), &ptr) != table.end(); }

    void add(const T& item)
    {
        auto foundIT = std::find_if(table.begin(), table.end(), [item](auto& value){return value.id == item.id;});
        if(foundIT != table.end())
        {
            std::string err;
            err.append("Duplicate ID added to CDataTable<");
            err.append(typeid(T).name());
            err.append(">");

            throw std::runtime_error(err);
        }

        table.push_back(item);
    }

    T* get(TableID id)
    {
        auto foundIT = std::find_if(table.begin(), table.end(), [id](auto& value){return value.id == id;});
        if(foundIT != table.end())
        {
            return &*foundIT;
        }

        return nullptr;
    }

    T* get(NameTag nameTag)
    {
        auto foundIT = std::find_if(table.begin(), table.end(), [nameTag](auto& value){return value.nameTag == nameTag;});
        if(foundIT != table.end())
        {
            return &*foundIT;
        }

        return nullptr;
    }
};


