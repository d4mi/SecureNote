#ifndef IDATACONTEXT_H
#define IDATACONTEXT_H

template <typename DBType>
class IDataContext
{
public:
    virtual void Get(DBType& dbType) = 0;
    virtual void Save(DBType& dbType) = 0;
};

#endif
