#include "./environment.hpp"

#include <iostream>

#include "src/simplify/ast_node.hpp"

using namespace std;

Environment::Environment(ASTNode *root) {
    frames.emplace();
    frameIDs.emplace(root);
}

Environment::~Environment() {
    while (!frames.empty()) {
        for (auto &entry : frames.top()) {
            delete entry.second;
        }
        frames.pop();
    }

    for (auto &entry : effectFrames) {
        while (!entry.second.empty()) {
            delete entry.second.top().second;
            entry.second.pop();
        }
    }
}

int Environment::invoke(const string &name, Value *&value) {
    if (!frames.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    Value *result = nullptr;
    int retval = get(name, value);
    if (retval || !result) {
        return retval ? retval : -1;
    }
    if (value->getType() != ValueType::FUNCTION) {
        cerr << "Name \"" << name << "\" is not callable." << endl;
    }

    frames.emplace();
    frameIDs.emplace(value->getFn());
    value = result->getFn()->interpret(*this, 1);
    frameIDs.pop();
    for (auto &val : frames.top()) {
        delete val.second;
    }
    frames.pop();

    return 0;
}

int Environment::get(const string &name, Value *&value) const {
    if (!frames.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    auto &currentFrame = frames.top();
    auto entry = currentFrame.find(name);
    if (entry == currentFrame.end()) {
        auto currentEffectFrame = effectFrames.find(name);
        if (currentEffectFrame == effectFrames.end() || currentEffectFrame->second.empty()) {
            cerr << "Name \"" << name << "\" is not defined." << endl;
            return 1;
        }
        value = currentEffectFrame->second.top().second;
    }
    value = entry->second;
    return 0;
}

int Environment::set(const string &name, Value *value) {
    if (!frames.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    auto &currentFrame = frames.top();
    auto entry = currentFrame.find(name);
    if (entry != currentFrame.end()) {
        delete entry->second;
    }
    currentFrame[name] = value;
    return 0;
}

int Environment::setEffect(const string &name, Value *value) {
    if (!effectFrames.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    auto *currentFrameID = frameIDs.top();
    auto nameFrames = effectFrames.find(name);
    if (
        nameFrames != effectFrames.end()
        && !nameFrames->second.empty()
        && nameFrames->second.top().first == currentFrameID) {
        delete nameFrames->second.top().second;
        nameFrames->second.top().second = value;
        return 0;
    }

    effectFrames[name].emplace(currentFrameID, value);
    return 0;
}