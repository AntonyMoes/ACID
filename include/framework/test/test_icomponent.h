#ifndef ACID_INCLUDE_TEST_COMPONENT_H_
#define ACID_INCLUDE_TEST_COMPONENT_H_

#include <gtest/gtest.h>
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
