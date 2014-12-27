#ifndef IQUERYABLE_H
#define IQUERYABLE_H

#include <functional>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
class IQueryable
{
public:
    IQueryable(QueryableType<QueryableItemType> querableItem);
    virtual ~IQueryable();

    //virtual IQueryable& Select() const;

    virtual IQueryable& Where(
            std::function<bool (const QueryableItemType&)> predicate);
    virtual IQueryable& GroupBy(
            std::function<bool (const QueryableItemType&)> predicate);
    virtual QueryableItemType& First();
    virtual IQueryable& Take(const int );
    virtual std::list<QueryableItemType> ToList() const;



private:
    QueryableType<QueryableItemType> m_querableCollection;
};

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
IQueryable<QueryableItemType, QueryableType>::IQueryable(
        QueryableType<QueryableItemType> querableItem)
 : m_querableCollection(querableItem)
{
}

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
IQueryable<QueryableItemType, QueryableType>::~IQueryable()
{

}

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
IQueryable<QueryableItemType, QueryableType>&
    IQueryable<QueryableItemType, QueryableType>::Where(
            std::function<bool (const QueryableItemType&)> predicate)
{
    QueryableType<QueryableItemType> foundItems(m_querableCollection.size());

    auto it = std::copy_if(m_querableCollection.begin(), m_querableCollection.end(), foundItems.begin(),
                  [=](const QueryableItemType& note) -> bool { return predicate(note); }
    );

    foundItems.resize(std::distance(foundItems.begin(), it));

    m_querableCollection.clear();
    m_querableCollection.assign(foundItems.begin(), foundItems.end() );

    return *this;
}

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
IQueryable<QueryableItemType, QueryableType>&
    IQueryable<QueryableItemType, QueryableType>::GroupBy(
            std::function<bool (const QueryableItemType&)> predicate)
{

}

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
QueryableItemType&
    IQueryable<QueryableItemType, QueryableType>::First()
{

}

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
IQueryable<QueryableItemType, QueryableType>&
    IQueryable<QueryableItemType, QueryableType>::Take(const int count)
{

    int i = std::min(count, (int)m_querableCollection.size());

    m_querableCollection.erase( m_querableCollection.begin() +  i,
                                m_querableCollection.end());

    return *this;
}

template <typename QueryableItemType,
          template <typename ...Args> class QueryableType>
std::list<QueryableItemType>
    IQueryable<QueryableItemType, QueryableType>::ToList() const
{
    return std::list<QueryableItemType>(m_querableCollection.begin(),
                                   m_querableCollection.end());
}

#endif
