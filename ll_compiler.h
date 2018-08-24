#ifndef LL_COMPILER_H_
#define LL_COMPILER_H_

#ifndef NULL_PTR
#define NULL_PTR 0 
#endif

enum ELL_ASSERT_REASON {
	LL_ASSERT_OUTOFMEMORY,
	LL_ASSERT_EXCEPTION,
};

inline void LL_AssertionHandler(ELL_ASSERT_REASON eReason)
{
	switch (eReason)
	{
	case LL_ASSERT_OUTOFMEMORY:
		while (1);
		break;
	case LL_ASSERT_EXCEPTION:
		while (1);
		break;
	default:
		break;
	}
}

#define LL_SEPERATE_IMPLEMENTATION

#endif /* LL_COMPILER_H_ */