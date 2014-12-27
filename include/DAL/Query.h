#ifndef QUERY_H
#define QUERY_H

#include "DAL/IQueryable.h"

class Query
{
public:
    template <typename QueryableItemType,
              template <typename ... Args> class QueryableType>
    static IQueryable<QueryableItemType, QueryableType> Select(
            QueryableType<QueryableItemType> querableItem)
    {
        return IQueryable<QueryableItemType, QueryableType>(querableItem);
    }

};

#endif
