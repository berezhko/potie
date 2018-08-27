#include "tgenerator.h"
#include <cmath>
#include <cassert>
#include <algorithm>

using std::cos;
using std::sin;
using std::sqrt;


TGenerator::TGenerator(TElement cosnomel, TElement xpel):
    cosnom(cosnomel),
    xp(xpel),
    xad(-1.0)
{

}

void TGenerator::addPointToXXX(TElement ifel, TElement ugel)
{
    xxx.push_back(pair<TElement, TElement>(ifel, ugel));
}

TElement TGenerator::getXad()
{
    //return 0.6628046;
    if (xad > 0)
        return xad;

    TElement lhs = 0;
    TElement rhs = 3000;
    TElement work;

    while (1) {
        work = (lhs+rhs)/2;
        TElement sinnom = sqrt(1-cosnom*cosnom);
        TElement epd = xp*1.0*cosnom;
        TElement epq = 1.0 + xp*1.0*sinnom;
        TElement ep = sqrt(epd*epd + epq*epq);

        TElement iu = getIu(ep);

        TElement xd = work;

        TElement ipotied = epd*iu/ep + 1.0*cosnom*xd;
        TElement ipotieq = epq*iu/ep + 1.0*sinnom*xd;

        TElement ipotie = sqrt(ipotied*ipotied + ipotieq*ipotieq);
        if (ipotie > 1.0005)
            rhs = work;
        else if (ipotie < 0.9995)
            lhs = work;
        else
            break;
    }

    xad = work;
    return xad;
}

TElement TGenerator::getIu(TElement epotie)
{
    for (size_t i = 0; i < xxx.size(); i++) {
        //auto [i2, u2] = xxx[i];
        auto i2 = xxx[i].first;
        auto u2 = xxx[i].second;
        if (epotie < u2) {
            assert (i > 0);
            //auto [i1, u1] = xxx[i-1];
            auto i1 = xxx[i-1].first;
            auto u1 = xxx[i-1].second;
            return i1 + (i2-i1)*(epotie-u1)/(u2-u1);
        }
    }

    assert (1 != 1);

    return 0;
}

TElement TGenerator::getCosNom()
{
    return cosnom;
}

TElement TGenerator::getXp()
{
    return xp;
}
