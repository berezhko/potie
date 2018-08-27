#ifndef TGENERATOR_H
#define TGENERATOR_H

#include <vector>

using std::vector;
using std::pair;

typedef double TElement;

class TGenerator
{
public:
    TGenerator() = delete;
    TGenerator(TElement cosnomel, TElement xpel);

    void addPointToXXX(TElement ifel, TElement ugel);
    TElement getXad();
    TElement getIu(TElement ep);
    TElement getCosNom();
    TElement getXp();

private:
    vector<pair<TElement, TElement>> xxx;
    TElement cosnom;
    TElement xp;
    TElement xad;
};

#endif // TGENERATOR_H
