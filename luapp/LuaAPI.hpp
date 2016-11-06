/**
@file   LuaAPI.hpp
@brief  It's just a wrapper of lua.
*/

#ifndef _LUAPP_LUA_API_HPP_
#define _LUAPP_LUA_API_HPP_


#include "lua.hpp"
#include "luapp/Define.hpp"
#include "luapp/ShortName.hpp"
#include "luapp/DataType.hpp"
#include "luapp/FuncReg.hpp"

namespace lua{


//------------------------------------------------------------------------------
inline void NewModule(Handle h,FuncReg &reg)
{
	luaL_newlib(h,(luaL_Reg*)(reg._get()));
}
//------------------------------------------------------------------------------
inline Handle CreateHandle()
{
	return luaL_newstate();
}
//------------------------------------------------------------------------------
inline void DestroyHandle(Handle h)
{
	lua_close(h);
}
//------------------------------------------------------------------------------
inline int PCall(Handle h,int num01,int num02,int num03)
{
	return lua_pcall(h,num01,num02,num03);
}
//------------------------------------------------------------------------------
inline void OpenLibs(Handle h)
{
	luaL_openlibs(h);
}
//------------------------------------------------------------------------------
inline Str GetError(Handle h)
{
	Str  str(lua_tostring(h, -1));
	lua_pop(h, 1);

	return str;
}
//------------------------------------------------------------------------------
inline int DoScript(Handle h,Name filename)
{
	if( luaL_loadfile(h,filename) )
	{
		return 0;
	}

	if( lua_pcall(h,0,0,0) )
	{
		return 0;
	}

	return 1;
}
//------------------------------------------------------------------------------
inline void NewTable(Handle h)
{
	lua_newtable(h);
}
//------------------------------------------------------------------------------
inline int NewMetaTable(Handle h,Name tname)
{
	return luaL_newmetatable(h,tname);
}
//------------------------------------------------------------------------------
inline void* NewUserData(Handle h,size_t size)
{
	return lua_newuserdata(h,size);
}
//------------------------------------------------------------------------------
inline void SetGlobal(Handle h,Name var)
{
	lua_setglobal(h,var);
}
//------------------------------------------------------------------------------
inline void GetGlobal(Handle h,Name var)
{
	lua_getglobal(h,var);
}
//------------------------------------------------------------------------------
inline void SetTable(Handle h,int index)
{
	lua_settable(h,index);
}
//------------------------------------------------------------------------------
inline void GetTable(Handle h,int index)
{
	lua_gettable(h,index);
}
//------------------------------------------------------------------------------
inline void SetField(Handle h,int index, Name name)
{
	lua_setfield(h,index,name);
}
//------------------------------------------------------------------------------
inline void GetField(Handle h,int index, Name k)
{
	lua_getfield(h,index,k);
}
//------------------------------------------------------------------------------
inline int SetMetaTable(Handle h,int index)
{
	return lua_setmetatable(h,index);
}
//------------------------------------------------------------------------------
inline void GetMetaTable(Handle h,Name name)
{
	luaL_getmetatable(h,name);
}
//------------------------------------------------------------------------------
inline void PushClosure(Handle h,CFunction fn,int n)
{
	lua_pushcclosure(h, fn, n);
}
//------------------------------------------------------------------------------
inline void PushFunction(Handle h,CFunction fn)
{
	lua_pushcfunction(h,fn);
}
//------------------------------------------------------------------------------
inline Name PushString(Handle h,Name str)
{
	return lua_pushstring(h, str);
}
//------------------------------------------------------------------------------
inline Name PushString(Handle h,Str str)
{
	return lua_pushstring(h, str.c_str());
}
//------------------------------------------------------------------------------
inline void PushValue(Handle h,int index)
{
	lua_pushvalue(h,index);
}
//------------------------------------------------------------------------------
inline void PushNumber(Handle h,double n)
{
	lua_pushnumber(h,n);
}
//------------------------------------------------------------------------------
inline void PushBoolean(Handle h,bool num)
{
	lua_pushboolean(h,(int)num);
}
//------------------------------------------------------------------------------
inline void PushInteger(Handle h,int num)
{
	lua_pushinteger(h,num);
}
//------------------------------------------------------------------------------
inline double CheckNumber(Handle h,int index)
{
//	return luaL_checknumber(h,index);

	#ifdef _LUAPP_CHECK_DATA_TYPE_
	if ( lua_type(h,index)!=LUA_TNUMBER )
	{
		printf("error:lua::CheckNumber\n");
		return 0.0;
	}
	#endif

	return lua_tonumber(h,index);
}
//------------------------------------------------------------------------------
inline bool CheckBoolean(Handle h,int index)
{
//	return luaL_checkboolean(h,index);

	#ifdef _LUAPP_CHECK_DATA_TYPE_
	if ( lua_type(h,index)!=LUA_TBOOLEAN )
	{
		printf("error:lua::CheckBoolean\n");
		return false;
	}
	#endif

	return lua_toboolean(h,index);
}
//------------------------------------------------------------------------------
inline int CheckInteger(Handle h,int index)
{
//	return luaL_checkinteger(h,index);

	#ifdef _LUAPP_CHECK_DATA_TYPE_
	if ( lua_type(h, index)!=LUA_TNUMBER )
	{
		printf("error:lua::CheckInteger\n");
		return 0;
	}
	else if ( ! lua_isinteger(h,index) )
	{
		printf("error:lua::CheckInteger: not a integer\n");
		return 0;
	}
	#endif

	return lua_tointeger(h,index);
}
//------------------------------------------------------------------------------
inline Str CheckString(Handle h,int index)
{
//	return Str(luaL_checkstring(h,index));

	#ifdef _LUAPP_CHECK_DATA_TYPE_
	if ( lua_type(h, index)!=LUA_TSTRING )
	{
		printf("error:lua::CheckString\n");
		return Str();
	}
	#endif

	return lua_tolstring(h,index,NULL);
}
//------------------------------------------------------------------------------
inline void* CheckUserData(Handle h,int ud, Name tname)
{
	return luaL_checkudata(h, ud, tname);
}
//------------------------------------------------------------------------------
inline void PushPointer(Handle h,Ptr ptr)
{
	lua_pushlightuserdata(h,ptr);
}
//------------------------------------------------------------------------------
inline Ptr CheckPointer(Handle h,int index)
{
//	return (Ptr)luaL_checklightudata(h,index);

	#ifdef _LUAPP_CHECK_DATA_TYPE_
	if ( lua_type(h, index)!=LUA_TLIGHTUSERDATA )
	{
		printf("error:lua::CheckPointer\n");
		#ifdef _LUAPP_USING_CPP11_
		return nullptr;
		#else
		return NULL;
		#endif
	}
	#endif

    return (Ptr)lua_topointer(h, index);
}
//------------------------------------------------------------------------------
inline int UpValueIndex(int index)
{
	return lua_upvalueindex(index);
}
//------------------------------------------------------------------------------
inline void Pop(Handle h,int num)
{
	lua_pop(h,num);
}
//------------------------------------------------------------------------------
inline void SetTop(Handle h,int num)
{
	lua_settop(h,num);
}
//------------------------------------------------------------------------------
inline int GetTop(Handle h)
{
	return lua_gettop(h);
}
//------------------------------------------------------------------------------

}

#endif//_LUAPP_LUA_API_HPP_
