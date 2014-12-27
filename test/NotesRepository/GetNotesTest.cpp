#include "NotesRepositoryTest.h"

#include "Model/Note.h"
#include "DAL/IQueryable.h"
#include "DAL/Query.h"

#include <map>

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

TEST_F(NotesRepositoryTest, Querable)
{
    std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto isEven = [](const int i) { return i % 2 == 0; };

    IQueryable<int, std::vector> querable(numbers);

    auto list = querable.Where(isEven).ToList();

    ASSERT_THAT(list, ElementsAre(2, 4, 6, 8, 10));
}

TEST_F(NotesRepositoryTest, QuerableChain)
{
    std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto valueIsEven = [](const int i) { return i % 2 == 0; };
    auto valueLessThanFive = [](const int i) { return i < 5; };

    IQueryable<int, std::vector> querable(numbers);

    auto list = querable.Where(valueIsEven)
            .Where(valueLessThanFive)
            .ToList();

    ASSERT_THAT(list, ElementsAre(2, 4 ));
}

TEST_F(NotesRepositoryTest, MakeQueryable)
{
    std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto valueIsEven = [](const int i) { return i % 2 == 0; };
    auto valueLessThanFive = [](const int i) { return i < 5; };

    auto list = Query::Select(numbers)
            .Where(valueIsEven)
            .Where(valueLessThanFive)
            .ToList();

    ASSERT_THAT(list, ElementsAre(2, 4 ));
}
/*
TEST_F(NotesRepositoryTest, List)
{
    std::list<std::string> colors
    {
        "Red", "Pink", "Green", "Yellow", "Black", "White", "Black", "Green", "Black", "Green"
    };

    auto colorIsBlack = []( const std::string& color )
    {
        return color == "Black";
    };

    auto list = Query::Select(colors)
            .Where(colorIsBlack)
            .ToList();

    ASSERT_THAT(list, ElementsAre("Black", "Black", "Black"));
}

TEST_F(NotesRepositoryTest, ListTake)
{
    std::list<std::string> colors
    {
        "Red", "Pink", "Green", "Yellow", "Black", "White", "Black", "Green", "Black", "Green"
    };

    auto colorIsBlack = []( const std::string& color )
    {
        return color == "Black";
    };

    auto list = Query::Select(colors)
            .Where(colorIsBlack)
            .Take(2)
            .ToList();

    ASSERT_THAT(list, ElementsAre("Black", "Black", "Black"));
}


TEST_F(NotesRepositoryTest, Map)
{
    std::map<int, std::string> pairs
    {
        { 1, "Hello"  },
        { 2, "World"  },
        { 3, "Green"  },
        { 4, "Yellow" },
        { 5, "Black"  },
        { 6, "White"  }
    };

    auto valueIsBlack = []( const std::pair<int, std::string>& pair )
    {
        return pair.second == "Black";
    };

    auto list = Query::Select(pairs)
            .Where(valueIsBlack);

    ASSERT_THAT(list.size(), 1);
}
*/
