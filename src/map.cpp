#include "project/map.h"

#include <algorithm>
#include <stdexcept>

Map::Map() = default;

bool Map::empty() const noexcept {
    return entries_.empty();
}

std::size_t Map::size() const noexcept {
    return entries_.size();
}

std::size_t Map::findIndex(const std::string& key) const {
    for (std::size_t i = 0; i < entries_.size(); ++i) {
        if (entries_[i].key == key) {
            return i;
        }
    }
    return entries_.size();
}

void Map::sortEntries() {
    std::sort(entries_.begin(), entries_.end(),
              [](const KeyValuePair& a, const KeyValuePair& b) {
                  return a.key < b.key;
              });
}


bool Map::contains(const std::string& key) const {
    return findIndex(key) != entries_.size();
}

bool Map::insert(const std::string& key, int value) {
    if (contains(key)) {
        return false;
    }

    entries_.push_back({key, value});
    sortEntries();
    return true;
}

bool Map::update(const std::string& key, int newValue) {
    std::size_t index = findIndex(key);

    if (index == entries_.size()) {
        return false;
    }

    entries_[index].value = newValue;
    return true;
}

bool Map::erase(const std::string& key) {
    std::size_t index = findIndex(key);

    if (index == entries_.size()) {
        return false;
    }

    entries_.erase(entries_.begin() + index);
    return true;
}

int Map::at(const std::string& key) const {
    std::size_t index = findIndex(key);

    if (index == entries_.size()) {
        throw std::out_of_range("Key not found");
    }

    return entries_[index].value;
}

int& Map::at(const std::string& key) {
    std::size_t index = findIndex(key);

    if (index == entries_.size()) {
        throw std::out_of_range("Key not found");
    }

    return entries_[index].value;
}


std::vector<std::string> Map::keys() const {
    std::vector<std::string> result;
    for (const auto& entry : entries_) {
        result.push_back(entry.key);
    }
    return result;
}

std::vector<int> Map::values() const {
    std::vector<int> result;
    for (const auto& entry : entries_) {
        result.push_back(entry.value);
    }
    return result;
}

bool Map::isSorted() const noexcept {
    for (std::size_t i = 1; i < entries_.size(); ++i) {
        if (entries_[i - 1].key > entries_[i].key) {
            return false;
        }
    }
    return true;
}
