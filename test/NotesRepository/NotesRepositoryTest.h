#ifndef NOTES_REPOSITORY_TEST_H
#define NOTES_REPOSITORY_TEST_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "test/CommonNamespaces.h"

#include "DAL/NotesRepository.h"
#include "DAL/NotesFakeDataContext.h"


class NotesRepositoryTest : public ::testing::Test
{
protected:
    NotesRepositoryTest();
    virtual ~NotesRepositoryTest();

    virtual void SetUp();
    virtual void TearDown();

    NotesFakeDataContext m_notesFakeDataContext;
    NotesRepository m_notesRepository;
};

#endif
