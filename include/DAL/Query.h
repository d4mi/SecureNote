#ifndef QUERY_H
#define QUERY_H

#include "DAL/IQueryable.h"

class Query
{
public:
    template <typename QueryableType>
    static IQueryable<QueryableType> Select(QueryableType querableItem)
    {
        return IQueryable<QueryableType>(querableItem);
    }

};

#endif
