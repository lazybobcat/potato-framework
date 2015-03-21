#ifndef SCRIPTPLAYER_H
#define SCRIPTPLAYER_H

#include <SFML/System.hpp>

#include <map>
#include <string>

#include <lua.hpp>
#include <resources/resourceidentifiers.h>

class ScriptPlayer : private sf::NonCopyable
{
public:
    ScriptPlayer();
    ~ScriptPlayer();

    bool play(Scripts::ID script);

    void        registerFile(Scripts::ID script, const std::string& filename);
    void        registerScript(Scripts::ID script, const std::string& content);

private:
    lua_State*  mLuaState;
    std::map<Scripts::ID, std::string> mScripts;

};

#endif // SCRIPTPLAYER_H
