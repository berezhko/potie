#ifndef TPOTIE_H
#define TPOTIE_H

#include "tgenerator.h"


class TPotie
{
public:
    TPotie() = delete;
    TPotie(TGenerator);

    void setGenerator(TGenerator);
    void setIg(TElement);
    void setUg(TElement);
    void setPhi(TElement);

    TElement calcIpotie();

private:
    TGenerator generator;
    TElement ig;
    TElement ug;
    TElement phi;
};

#endif // TPOTIE_H
