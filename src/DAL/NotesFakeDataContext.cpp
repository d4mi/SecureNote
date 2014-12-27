#include "DAL/NotesFakeDataContext.h"

NotesFakeDataContext::NotesFakeDataContext()
{

}

void NotesFakeDataContext::Get(std::vector<Model::Note>& dbType)
{
   dbType = {
       Model::Note("First note", "Some text here"),
       Model::Note("Second note", "Some text here"),
       Model::Note("Third note", "Some text here"),
       Model::Note("Fourth note", "Some text here"),
       Model::Note("Fifth note", "Some text here"),
       Model::Note("Fifth note", "Some text here"),
       Model::Note("Fifth note", "test"),
       Model::Note("Fifth note", "Some text here"),
       Model::Note("Fifth note", "test"),
       Model::Note("Fifth note", "Some text here")
   };
}

void NotesFakeDataContext::Save(std::vector<Model::Note>& dbType)
{
    // do nothing
}
