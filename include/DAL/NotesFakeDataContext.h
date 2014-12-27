#ifndef NOTES_FAKE_DATACONTEXT_H
#define NOTES_FAKE_DATACONTEXT_H

#include "DAL/IDataContext.h"
#include "Model/Note.h"
#include <vector>

class NotesFakeDataContext :
        public IDataContext<std::vector<Model::Note>>
{
public:
    NotesFakeDataContext();

    virtual void Get(std::vector<Model::Note>& dbType);
    virtual void Save(std::vector<Model::Note>& dbType);
};

#endif
