#ifndef NOTESREPOSITORY_H
#define NOTESREPOSITORY_H

#include "Model/Note.h"
#include <vector>

class NotesRepository
{
public:
    NotesRepository();

    void AddNote(const Model::Note& note);
    std::vector<Model::Note> GetNotes() const;

};

#endif // NOTESREPOSITORY_H
