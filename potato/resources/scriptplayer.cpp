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

#include <algorithm>
#include <cassert>
#include <fstream>
#include <ios>
#include <iostream>
#include <resources/scriptplayer.hpp>

ScriptPlayer::ScriptPlayer()
  : mLuaState(nullptr)
{
    // Creation of lua state
    mLuaState = luaL_newstate();
    luaL_openlibs(mLuaState);
}

ScriptPlayer::~ScriptPlayer()
{
    lua_close(mLuaState);
}

bool ScriptPlayer::play(Scripts::ID script)
{
    if (mScripts.find(script) == mScripts.end()) {
        std::cerr << "[ScriptPlayer] Script #" << script << " not found !" << std::endl;
        return false;
    }

    try {
        luaL_dostring(mLuaState, mScripts[script].c_str());
    } catch (...) {
        std::cerr << "[ScriptPlayer] Error while playing Script #" << script << " !" << std::endl;
        return false;
    }

    return true;
}

void ScriptPlayer::registerFile(Scripts::ID script, const std::string& filename)
{
    std::ifstream file(filename, std::ios::in);
    std::string   fullscript, line;

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open script " + filename);
    }

    while (std::getline(file, line)) {
        fullscript.append(line);
        fullscript.append("\n");
    }

    //std::cout << fullscript << std::endl;

    registerScript(script, fullscript);
}

void ScriptPlayer::registerScript(Scripts::ID script, const std::string& content)
{
    mScripts[script] = content;
}
