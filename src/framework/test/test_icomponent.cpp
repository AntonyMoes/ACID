#include <test_icomponent.h>

TEST_F(SetupTestComponent, ComponentGetSet) {  // TODO(Xenobyte42): moAR atomic tests; mock Loop, System, e.t.c.
    ASSERT_EQ(icomp->get_parent_id(), 0);
    icomp->set_parent_id(3);
    ASSERT_EQ(icomp->get_parent_id(), 3);
}

