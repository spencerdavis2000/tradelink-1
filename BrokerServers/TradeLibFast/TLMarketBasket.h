#pragma once
#include "TradeLibFast.h"
#include <vector>
using namespace std;

namespace TradeLibFast
{
	class AFX_EXT_CLASS  TLMarketBasket
	{

	public:
		TLMarketBasket(void);
		~TLMarketBasket(void);
		CString Serialize();
		static TLMarketBasket Deserialize(CString msg);
		int Count();
		TLSecurity operator[](int index) { return _secs[index]; }
		void Add(TLSecurity sec) { _secs.push_back(sec); }
		void Add(CString symbol) { _secs.push_back(TLSecurity::Deserialize(symbol)); }
		void Add(TLMarketBasket basket)
		{
			for (size_t i = 0; i<basket.Count(); i++)
				Add(basket[i]);
		}

	protected:
		vector<TLSecurity> _secs;
	};
}