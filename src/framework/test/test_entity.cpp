#include <test_entity.h>
TEST_F(SetupTestEntity, test3) {
ASSERT_EQ(ent->get_id(), 0);
ent->set_id(3);
ASSERT_EQ(ent->get_id(), 3);

auto *fakeComponent = new FakeComponent;
ent->add_component(fakeComponent);
const std::map<size_t, IComponent *> &fake_map = ent->get_components();
ASSERT_NE(&fake_map, nullptr);
}

