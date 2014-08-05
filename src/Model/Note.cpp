#include "Model/Note.h"

namespace Model
{

Note::Note()
{

}

Note::Note(const std::string &text, std::string &title) :
    m_text(text),
    m_title(title)
{

}

void Note::SetNote(const std::string &text)
{
    m_text = text;
}

std::string Note::GetNote() const
{
    return m_text;
}

void Note::SetTitle(const std::string &title)
{
    m_title = title;
}

std::string Note::GetTitile() const
{
    return m_title;
}

}
