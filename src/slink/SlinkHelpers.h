#ifndef SLINKHELPERS_H
#define SLINKHELPERS_H

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

#endif
