/**
@file   LuaWrapperProxy.hpp
@brief  To get all of parameters.
*/


#ifndef _LUAPP_WRAPPER_PROXY_HPP_
#define _LUAPP_WRAPPER_PROXY_HPP_


#include "Lua.hpp"


namespace lua{
namespace wrapper{


//------------------------------------------------------------

struct Proxy
{
	virtual ~Proxy(){}
	virtual int Do(lua::Handle)=0;
};

//------------------------------------------------------------

template<typename R>
struct ProxyReturn : public Proxy
{
	void ReturnValue(lua::Handle L,R num)
	{
		PushVarToLua(L,num);
	}
};

template<>
struct ProxyReturn<void> : public Proxy
{
};

//------------------------------------------------------------

template<typename R>
struct Proxy00 : public ProxyReturn<R>
{
	typedef R(*Func)();
	Proxy00(){}
	Proxy00(Func fn):func00(fn){}

	Func    func00;

	int Do(lua::Handle L)
	{
		this->ReturnValue(L,func00());
		return (int)1;
	}
};

template<>
struct Proxy00<void> : public ProxyReturn<void>
{
	typedef void R;
	typedef R(*Func)();
	Proxy00(){}
	Proxy00(Func fn):func00(fn){}

	Func    func00;

	int Do(lua::Handle)
	{
		func00();
		return (int)1;
	}
};

//------------------------------------------------------------

template<typename R,typename A1>
struct Proxy01 : public ProxyReturn<R>
{
	typedef R (*Func)(A1);
	Proxy01(){}
	Proxy01(Func fn):func01(fn){}

	Func    func01;

	template<typename tagR>
	void DoFunction(lua::Handle L,tagR (*fn)(A1),A1 p1)
	{
		this->ReturnValue(L,fn(p1));
	}

	void DoFunction(lua::Handle  ,void (*fn)(A1),A1 p1)
	{
		fn(p1);
	}

	int Do(lua::Handle L)
	{
		A1      p1;
		lua::CheckVarFromLua(L,&p1,1);
		DoFunction(L,func01,p1);
		return (int)1;
	}
};

//------------------------------------------------------------

template<typename R,typename A1,typename A2>
struct Proxy02 : public ProxyReturn<R>
{
	typedef R (*Func)(A1,A2);

	Proxy02(){}
	Proxy02(Func fn):func02(fn){}

	Func    func02;

	template<typename tagR>
	void DoFunction(lua::Handle L,tagR (*fn)(A1,A2),A1 p1,A2 p2)
	{
		this->ReturnValue(L,fn(p1,p2));
	}

	void DoFunction(lua::Handle  ,void (*fn)(A1,A2),A1 p1,A2 p2)
	{
		fn(p1,p2);
	}

	int Do(lua::Handle L)
	{
		A1      p1;
		A2      p2;
		lua::CheckVarFromLua(L,&p1,1);
		lua::CheckVarFromLua(L,&p2,2);
		DoFunction(L,func02,p1,p2);
		return (int)1;
	}
};

//------------------------------------------------------------

template<typename R,typename A1,typename A2,typename A3>
struct Proxy03 : public ProxyReturn<R>
{
	typedef R (*Func)(A1,A2,A3);

	Proxy03(){}
	Proxy03(Func fn):func03(fn){}

	Func    func03;

	template<typename tagR>
	void DoFunction(lua::Handle L,tagR (*fn)(A1,A2,A3),A1 p1,A2 p2,A3 p3)
	{
		this->ReturnValue(L,fn(p1,p2,p3));
	}

	void DoFunction(lua::Handle  ,void (*fn)(A1,A2,A3),A1 p1,A2 p2,A3 p3)
	{
		fn(p1,p2,p3);
	}

	int Do(lua::Handle L)
	{
		A1      p1;
		A2      p2;
		A3      p3;
		lua::CheckVarFromLua(L,&p1,1);
		lua::CheckVarFromLua(L,&p2,2);
		lua::CheckVarFromLua(L,&p3,3);
		DoFunction(L,func03,p1,p2,p3);
		return (int)1;
	}
};

//------------------------------------------------------------

template<typename R,typename A1,typename A2,typename A3,typename A4>
struct Proxy04 : public ProxyReturn<R>
{
	typedef R (*Func)(A1,A2,A3,A4);

	Proxy04(){}
	Proxy04(Func fn):func04(fn){}

	Func    func04;

	template<typename tagR>
	void DoFunction(lua::Handle L,tagR (*fn)(A1,A2,A3,A4),A1 p1,A2 p2,A3 p3,A4 p4)
	{
		this->ReturnValue(L,fn(p1,p2,p3,p4));
	}

	void DoFunction(lua::Handle  ,void (*fn)(A1,A2,A3,A4),A1 p1,A2 p2,A3 p3,A4 p4)
	{
		fn(p1,p2,p3,p4);
	}

	int Do(lua::Handle L)
	{
		A1      p1;
		A2      p2;
		A3      p3;
		A4      p4;
		lua::CheckVarFromLua(L,&p1,1);
		lua::CheckVarFromLua(L,&p2,2);
		lua::CheckVarFromLua(L,&p3,3);
		lua::CheckVarFromLua(L,&p4,4);
		DoFunction(L,func04,p1,p2,p3,p4);
		return (int)1;
	}
};

//------------------------------------------------------------

template<typename R,typename A1,typename A2,typename A3,typename A4,typename A5>
struct Proxy05 : public ProxyReturn<R>
{
	typedef R (*Func)(A1,A2,A3,A4,A5);

	Proxy05(){}
	Proxy05(Func fn):func05(fn){}

	Func    func05;

	template<typename tagR>
	void DoFunction(lua::Handle L,tagR (*fn)(A1,A2,A3,A4,A5),A1 p1,A2 p2,A3 p3,A4 p4,A5 p5)
	{
		this->ReturnValue(L,fn(p1,p2,p3,p4,p5));
	}

	void DoFunction(lua::Handle  ,void (*fn)(A1,A2,A3,A4,A5),A1 p1,A2 p2,A3 p3,A4 p4,A5 p5)
	{
		fn(p1,p2,p3,p4,p5);
	}

	int Do(lua::Handle L)
	{
		A1      p1;
		A2      p2;
		A3      p3;
		A4      p4;
		A5      p5;
		lua::CheckVarFromLua(L,&p1,1);
		lua::CheckVarFromLua(L,&p2,2);
		lua::CheckVarFromLua(L,&p3,3);
		lua::CheckVarFromLua(L,&p4,4);
		lua::CheckVarFromLua(L,&p5,5);
		DoFunction(L,func05,p1,p2,p3,p4,p5);
		return (int)1;
	}
};

//------------------------------------------------------------
//------------------------------------------------------------

template<typename C,typename R,typename A1>
struct ProxyBind01 : public ProxyReturn<R>
{
	typedef R (C::*Func)(A1);
	ProxyBind01(){}
	ProxyBind01(Func fn,C *obj):func01(fn),obj01(obj){}

	Func    func01;
	C*      obj01;

	template<typename tagR>
	void DoFunction(lua::Handle L,tagR (C::*fn)(A1),C *obj,A1 p1)
	{
		this->ReturnValue(L,(obj->*fn)(p1));
	}

	void DoFunction(lua::Handle  ,void (C::*fn)(A1),C *obj,A1 p1)
	{
		(obj->*fn)(p1);
	}

	int Do(lua::Handle L)
	{
		A1      p1;
		lua::CheckVarFromLua(L,&p1,1);
		DoFunction(L,func01,obj01,p1);
		return (int)1;
	}
};

//------------------------------------------------------------

template <typename R>
static Proxy* GetProxy(R(*f)())
{
	return (Proxy*)new Proxy00<R>(f);
}

template <typename R,typename A1>
static Proxy* GetProxy(R(*f)(A1))
{
	return (Proxy*)new Proxy01<R,A1>(f);
}

template <typename R,typename A1,typename A2>
static Proxy* GetProxy(R(*f)(A1,A2))
{
	return (Proxy*)new Proxy02<R,A1,A2>(f);
}

template <typename R,typename A1,typename A2,typename A3>
static Proxy* GetProxy(R(*f)(A1,A2,A3))
{
	return (Proxy*)new Proxy03<R,A1,A2,A3>(f);
}

template <typename R,typename A1,typename A2,typename A3,typename A4>
static Proxy* GetProxy(R(*f)(A1,A2,A3,A4))
{
	return (Proxy*)new Proxy04<R,A1,A2,A3,A4>(f);
}

template <typename R,typename A1,typename A2,typename A3,typename A4,typename A5>
static Proxy* GetProxy(R(*f)(A1,A2,A3,A4,A5))
{
	return (Proxy*)new Proxy05<R,A1,A2,A3,A4,A5>(f);
}

//------------------------------------------------------------

template <typename C,typename R,typename A1>
static Proxy* GetProxy(R(C::*f)(A1),C *obj)
{
	return (Proxy*)new ProxyBind01<C,R,A1>(f,obj);
}

//------------------------------------------------------------


}//namespace wrapper
}//namespace lua

#endif//_LUAPP_WRAPPER_PROXY_HPP_
