#ifndef IQUERYABLE_H
#define IQUERYABLE_H

#include <functional>

template <typename QueryableType, typename QueryableItemType >
class IQueryable
{
public:
    IQueryable(const QueryableType& querableItem);
    virtual ~IQueryable() = 0;

    virtual IQueryable& Select() const = 0;
    virtual IQueryable& Where(std::function<bool (const QueryableItemType&)> predicate) = 0;
    virtual IQueryable& GroupBy(std::function<bool (const QueryableItemType&)> predicate) = 0;
    virtual QueryableItemType& First() = 0;
    virtual IQueryable& Take(const int ) = 0;
};

#endif
