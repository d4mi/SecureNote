#ifndef IQUERYABLE_H
#define IQUERYABLE_H

#include <functional>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <type_traits>

template <typename QueryableType>
class IQueryable
{
public:
    typedef typename QueryableType::value_type QueryableItemType;
    typedef std::vector<QueryableItemType > QuerableContainer;

    IQueryable(QueryableType querableItem);
    virtual ~IQueryable();

    virtual IQueryable& Where(
            std::function<bool (const QueryableItemType&)> predicate);
    virtual IQueryable& GroupBy(
            std::function<bool (const QueryableItemType&)> predicate);
    virtual QueryableItemType& First();
    virtual IQueryable& Take(const int );
    virtual std::list<QueryableItemType> ToList() const;

private:
    QuerableContainer m_querableCollection;
};

template <typename QueryableType>
IQueryable<QueryableType>::IQueryable(QueryableType querableItem)
{
       m_querableCollection.assign(querableItem.begin(), querableItem.end());
}

template <typename QueryableType>
IQueryable<QueryableType>::~IQueryable()
{

}

template <typename QueryableType>
IQueryable<QueryableType>& IQueryable<QueryableType>::Where(
            std::function<bool (const QueryableItemType&)> predicate)
{
    auto it = std::remove_if(m_querableCollection.begin(), m_querableCollection.end(),
                  [=](const QueryableItemType& item) -> bool { return !predicate(item); }
    );

    m_querableCollection.erase(it, m_querableCollection.end() );

    return *this;
}

template <typename QueryableType>
IQueryable<QueryableType>& IQueryable<QueryableType>::GroupBy(
            std::function<bool (const QueryableItemType&)> predicate)
{

}

template <typename QueryableType>
typename IQueryable<QueryableType>::QueryableItemType& IQueryable<QueryableType>::First()
{

}

template <typename QueryableType>
IQueryable<QueryableType>& IQueryable<QueryableType>::Take(const int count)
{

    int i = std::min(count, (int)m_querableCollection.size());

    m_querableCollection.erase( m_querableCollection.begin() +  i,
                                m_querableCollection.end());

    return *this;
}

template <typename QueryableType>
std::list<typename IQueryable<QueryableType>::QueryableItemType> IQueryable<QueryableType>::ToList() const
{
    return std::list<QueryableItemType>(m_querableCollection.begin(),
                                   m_querableCollection.end());
}

#endif
