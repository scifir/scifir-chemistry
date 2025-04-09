#include "./substance_constituent.hpp"

using namespace std;

namespace scifir
{
	substance_constituent::substance_constituent() : molecule(),amount()
	{}

	substance_constituent::substance_constituent(const substance_constituent& x) : molecule(x.molecule),amount(x.amount)
	{}

	substance_constituent::substance_constituent(substance_constituent&& x) : molecule(move(x.molecule)),amount(move(x.amount))
	{}

	substance_constituent& substance_constituent::operator=(const substance_constituent& x)
	{
		molecule = x.molecule;
		amount = x.amount;
		return *this;
	}

	substance_constituent& substance_constituent::operator=(substance_constituent&& x)
	{
		molecule = move(x.molecule);
		amount = move(x.amount);
		return *this;
	}
}
