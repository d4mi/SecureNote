#include "DAL/NotesRepository.h"
#include <algorithm>

NotesRepository::NotesRepository(IDataContext<DBType>& dataContext) :
    m_dataContext(dataContext)
{
    m_dataContext.Get(m_notes);
}

void NotesRepository::AddNote(const Model::Note &note)
{

}

std::vector<Model::Note> NotesRepository::GetNotes() const
{
    return m_notes;
}

std::vector<Model::Note> NotesRepository::Select() const
{

}

std::vector<Model::Note> NotesRepository::Where(
        std::function<bool (const Model::Note&)> predicate) const
{
    std::vector<Model::Note> foundItems(m_notes.size());
    auto it = std::copy_if(m_notes.begin(), m_notes.end(), foundItems.begin(),
                  [=](const Model::Note& note) -> bool { return predicate(note); }
    );

    foundItems.resize(std::distance(foundItems.begin(), it));

    return foundItems;
}
