#include "game.h"

bool str_cmp (const char *astr, const char *bstr)
{
    if (astr == nullptr)
    {
        return true;
    }

    if (bstr == nullptr)
    {
        return true;
    }

    for (; *astr || *bstr; astr++, bstr++)
    {
        if (LOWER (*astr) != LOWER (*bstr))
            return true;
    }

    return false;
}

bool str_prefix (const char *astr, const char *bstr)
{
    if (astr == nullptr)
    {
        return true;
    }

    if (bstr == nullptr)
    {
        return true;
    }

    for (; *astr; astr++, bstr++)
    {
        if (LOWER (*astr) != LOWER (*bstr))
            return true;
    }

    return false;
}

