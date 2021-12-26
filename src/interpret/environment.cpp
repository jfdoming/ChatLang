#include "./environment.hpp"

#include <iostream>

#include "src/simplify/ast_node.hpp"

using namespace std;

Environment::Environment(ASTNode *root) {
    frames.emplace();
    frameIDs.emplace(root);
}

Environment::~Environment() {
}

int Environment::invoke(const string &name, Value params, Value &value) {
    if (!frames.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    Value fn{nullptr};
    int retval = get(name, fn);
    if (retval || !fn) {
        return retval ? retval : -1;
    }

    if (fn.getType() != ValueType::FUNCTION) {
        cerr << "Name \"" << name << "\" is not callable." << endl;
        return -1;
    }

    return invoke(fn, params, value);
}

int Environment::invoke(Value fn, Value args, Value &value) {
    if (!args && fn.getParams().size()) {
        cerr << "Expected " << fn.getParams().size() << " arguments but got 0." << endl;
        return -1;
    }

    frameIDs.emplace(fn.getFn());
    frames.emplace();

    if (args) {
        auto &paramNames = fn.getParams();
        auto &argValues = args.getValues();
        if (
            args.getType() == ValueType::TUPLE
            && paramNames.size() != 1
        ) {
            if (paramNames.size() != argValues.size()) {
                cerr << "Expected " << paramNames.size() << " arguments but got " << argValues.size() << "." << endl;
                return -1;
            }
            for (size_t i = 0; i < paramNames.size(); ++i) {
                frames.top()[paramNames[i]] = argValues[i];
            }
        } else {
            if (paramNames.size() != 1) {
                cerr << "Expected " << paramNames.size() << " arguments but got 1." << endl;
                return -1;
            }

            frames.top()[paramNames[0]] = args;
        }
    }

    value = fn.getFn()->interpret(*this, 1);
    if (!value) {
        value = 0;
    }

    frames.pop();
    frameIDs.pop();

    return 0;
}

int Environment::get(const string &name, Value &value) const {
    if (!frames.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    auto &currentFrame = frames.top();
    auto entry = currentFrame.find(name);
    if (entry == currentFrame.end()) {
        auto currentEffectFrame = effectFrames.find(name);
        if (
            currentEffectFrame == effectFrames.end()
            || currentEffectFrame->second.empty()
        ) {
            cerr << "Name \"" << name << "\" is not defined." << endl;
            return 1;
        }

        value = currentEffectFrame->second.top().second;
    } else {
        value = entry->second;
    }
    return 0;
}

int Environment::set(const string &name, Value value) {
    if (!frames.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    auto &currentFrame = frames.top();
    currentFrame[name] = value;
    return 0;
}

int Environment::setEffect(const string &name, Value value) {
    if (!frameIDs.size()) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -1;
    }

    auto *currentFrameID = frameIDs.top();
    auto nameFrames = effectFrames.find(name);
    if (
        nameFrames != effectFrames.end()
        && !nameFrames->second.empty()
        && nameFrames->second.top().first == currentFrameID) {
        nameFrames->second.top().second = value;
        return 0;
    }

    effectFrames[name].emplace(currentFrameID, value);
    return 0;
}
