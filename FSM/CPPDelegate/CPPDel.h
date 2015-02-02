/*
 * CPPDel.h
 *
 * Created: 1/29/2015 8:51:14 PM
 *  Author: keith
 */ 


#ifndef CPPDEL_H_
#define CPPDEL_H_


class delegate
{
	public:
	delegate()
	: object_ptr(0)
	, stub_ptr(0)
	{}

	template <class T, void (T::*TMethod)(int)>
	static delegate from_method(T* object_ptr)
	{
		delegate d;
		d.object_ptr = object_ptr;
		d.stub_ptr = &method_stub<T, TMethod>; // #1
		return d;
	}

	void operator()(int a1) const
	{
		return (*stub_ptr)(object_ptr, a1);
	}

	private:
	typedef void (*stub_type)(void* object_ptr, int);

	void* object_ptr;
	stub_type stub_ptr;

	template <class T, void (T::*TMethod)(int)>
	static void method_stub(void* object_ptr, int a1)
	{
		T* p = static_cast<T*>(object_ptr);
		return (p->*TMethod)(a1); // #2
	}
};




#endif /* CPPDEL_H_ */