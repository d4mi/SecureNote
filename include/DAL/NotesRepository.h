#ifndef NOTESREPOSITORY_H
#define NOTESREPOSITORY_H

#include "Model/Note.h"
#include "DAL/IDataContext.h"
#include <vector>
#include <functional>

class NotesRepository
{
public:
    typedef std::vector<Model::Note> DBType;

    NotesRepository(IDataContext<DBType>& dataContext);

    void AddNote(const Model::Note& note);
    std::vector<Model::Note> GetNotes() const;

    std::vector<Model::Note> Select() const;
    std::vector<Model::Note> Where(
            std::function<bool (const Model::Note&)> func) const;

private:
    IDataContext<DBType>& m_dataContext;
    std::vector<Model::Note> m_notes;


};

#endif // NOTESREPOSITORY_H
