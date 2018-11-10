//
// Created by savva on 10.11.18.
//

#include "test.h"

TEST_F(SetupTestComponent, test1)
{
    ASSERT_EQ(icomp->get_parent_id(), 0);
}
