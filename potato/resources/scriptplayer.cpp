#include <resources/scriptplayer.h>
#include <iostream>
#include <fstream>
#include <ios>
#include <algorithm>
#include <cassert>

ScriptPlayer::ScriptPlayer() :
    mLuaState(nullptr)
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
    if(mScripts.find(script) == mScripts.end())
    {
        std::cerr << "[ScriptPlayer] Script #" << script << " not found !" << std::endl;
        return false;
    }

    try {
        luaL_dostring(mLuaState, mScripts[script].c_str());
    } catch(...) {
        std::cerr << "[ScriptPlayer] Error while playing Script #" << script << " !" << std::endl;
        return false;
    }

    return true;
}

void ScriptPlayer::registerFile(Scripts::ID script, const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    std::string fullscript, line;

    if(!file.is_open())
    {
        throw std::runtime_error("Unable to open script " + filename);
    }

    while(std::getline(file, line))
    {
        fullscript.append(line);
        fullscript.append("\n");
    }

    //std::cout << fullscript << std::endl;

    registerScript(script, fullscript);
}


void ScriptPlayer::registerScript(Scripts::ID script, const std::string &content)
{
    mScripts[script] = content;
}

