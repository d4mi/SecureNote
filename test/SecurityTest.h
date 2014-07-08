#ifndef __SECURITY_TEST_H__
#define __SECURITY_TEST_H__

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "CommonNamespaces.h"
#include "Security/CryptoOpenSSL.h"

class SecurityTest : public ::testing::Test
{
protected:
	SecurityTest();
	virtual ~SecurityTest();

	virtual void SetUp();
	virtual void TearDown();

	Security::CryptoOpenSSL m_cryptoOpenSSL;
};

#endif // __SECURITY_TEST_H__