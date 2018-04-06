//
// Copyright (c) 2018 potato-framework by Loïc Boutter (https://github.com/Lo-X/potato-framework)
//
// Everyone is permitted to copy and distribute verbatim or modified
// copies of this license document, and changing it is allowed as long
// as the name is changed.
//
//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//  0. You just DO WHAT THE FUCK YOU WANT TO.
//

#ifndef SCRIPTPLAYER_H
#define SCRIPTPLAYER_H

#include <SFML/System.hpp>

#include <map>
#include <string>

#include <lua.hpp>
#include <resources/resourceidentifiers.hpp>

class ScriptPlayer : private sf::NonCopyable
{
public:
    ScriptPlayer();
    ~ScriptPlayer();

    bool play(Scripts::ID script);

    void registerFile(Scripts::ID script, const std::string& filename);
    void registerScript(Scripts::ID script, const std::string& content);

private:
    lua_State* mLuaState;
    std::map<Scripts::ID, std::string> mScripts;
};

#endif // SCRIPTPLAYER_H
