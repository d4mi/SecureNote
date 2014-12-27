#include "NotesRepositoryTest.h"

#include "Model/Note.h"

TEST_F(NotesRepositoryTest, FirstTest)
{
    std::vector<Model::Note> notes = m_notesRepository.GetNotes();
    ASSERT_THAT(notes.size(), 10);
}

TEST_F(NotesRepositoryTest, Where)
{
    auto predicate = [](const Model::Note& note) -> bool
    {
        return note.GetText() == "test";
    };

    std::vector<Model::Note> notes = m_notesRepository.Where(predicate);

    ASSERT_THAT(notes.size(), 2);
}
