#ifndef ACID_INCLUDE_TEST_COMPONENT_H
#define ACID_INCLUDE_TEST_COMPONENT_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <i_component.h>

 class SetupTestComponent : public ::testing::Test {
   protected:
    void SetUp() final {
        icomp = new IComponent;
    }
    void TearDown() final {
        delete icomp;
    }
    IComponent* icomp;
};

#endif  // ACID_INCLUDE_TEST_COMPONENT_H_
