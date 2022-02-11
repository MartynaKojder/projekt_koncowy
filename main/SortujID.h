#include "Napoj.h"
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void sortujID(T begin, T end)
{
	sort(begin, end, [&](const auto& i, const auto& j)
		{
			return i->getid() < j->getid();
		});
}