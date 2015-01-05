#include "SecurityTest.h"
#include "Security/ShaProvider.h"

TEST_F(SecurityTest, SHA_abc)
{
    const std::string result =
            "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";

    Security::ShaProvider shaProvider;
    std::string sha256 = shaProvider.CreateSha256("abc");

    ASSERT_THAT(sha256, result);
}

TEST_F(SecurityTest, SHA_empty)
{
    const std::string result =
            "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";

    Security::ShaProvider shaProvider;
    std::string sha256 = shaProvider.CreateSha256("");

    ASSERT_THAT(sha256, result);
}

TEST_F(SecurityTest, SHA_448_bits)
{
    const std::string result =
            "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1";

    const std::string input =
        "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";

    Security::ShaProvider shaProvider;
    std::string sha256 = shaProvider.CreateSha256(input);

    ASSERT_THAT(sha256, result);
}

TEST_F(SecurityTest, SHA_896_bits)
{
    const std::string result =
            "cf5b16a778af8380036ce59e7b0492370b249b11e8f07a51afac45037afee9d1";

    const std::string input =
        "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";

    Security::ShaProvider shaProvider;
    std::string sha256 = shaProvider.CreateSha256(input);

    ASSERT_THAT(sha256, result);
}


