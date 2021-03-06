#ifndef __NOTE_H__
#define __NOTE_H__

#include <string>

namespace Model 
{

class Note
{
public:
    Note();
    Note(const std::string& title, std::string& text);
    Note(const std::string&& title, std::string&& text);
    ~Note();

    void SetNote(const std::string& text);
    std::string GetNote() const;

    void SetTitle(const std::string& title);
    std::string GetTitile() const;

    void SetText(const std::string& text);
    std::string GetText() const;
private:
    std::string m_text;
    std::string m_title;
};

} // namespace Model

#endif // __NOTE_H__
