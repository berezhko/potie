#include "tpotie.h"
#include <cmath>
#include <cassert>
#include <algorithm>

using std::cos;
using std::sin;
using std::sqrt;

TPotie::TPotie(TGenerator gen):
    generator(gen),
    ig(-1),
    ug(-1),
    phi(-1)
{}

void TPotie::setGenerator(TGenerator gen)
{
    generator = gen;
}

void TPotie::setIg(TElement el)
{
    ig = el;
}

void TPotie::setUg(TElement el)
{
    ug = el;
}

void TPotie::setPhi(TElement el)
{
    phi = el;
}

TElement TPotie::calcIpotie()
{
    TElement cosphi = cos(phi/180*M_PI);
    TElement sinphi = sin(phi/180*M_PI);
    TElement cosnom = generator.getCosNom();
    TElement sinnom = sqrt(1 - generator.getCosNom()*generator.getCosNom());
    TElement ip = ig*cosphi/cosnom;
    TElement iq = ig*sinphi/sinnom;
    TElement xp = generator.getXp();

    TElement epd = xp*ip*cosnom;
    TElement epq = ug + xp*iq*sinnom;
    TElement ep = sqrt(epd*epd + epq*epq);

    TElement iu = generator.getIu(ep);

    TElement xad = generator.getXad();

    TElement ipotied = epd*iu/ep + ip*cosnom*xad;
    TElement ipotieq = epq*iu/ep + iq*sinnom*xad;

    TElement ipotie = sqrt(ipotied*ipotied + ipotieq*ipotieq);

    return ipotie;
}


