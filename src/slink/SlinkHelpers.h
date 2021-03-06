#pragma once

#if _DEBUG
	#define VERIFYDX(x)		\
	{						\
		HRESULT hr = (x);	\
		if (FAILED(hr)) {	\
			assert(0);		\
		}					\
	}
#else
	#define VERIFYDX(x) (x);
#endif

#define SAFE_RELEASE(p) { if ((p)) p->Release(); }

