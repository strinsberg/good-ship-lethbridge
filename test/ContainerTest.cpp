#include "Container.h"
#include "Entity.h"
#include "EntitySpec.h"
#include "gtest/gtest.h"


TEST(TestContainer,describe) {
 Container c;
 EntitySpec * e = new EntitySpec();
 e->setDescription("this is a spec");
 c.setSpec(e);
 EXPECT_EQ("this is a spec",c.describe());
}

TEST(TestContainer,use) {
Container c;
Entity* e;
EXPECT_EQ("you can't use containers",c.use(e));
}

TEST(TestContainer,searchnotfind) {
Container c;

EXPECT_EQ(nullptr,c.search("entity"));
}

TEST(TesrContainer,searchfind_addEntity) {
  Container c;

Entity* e = new Container();
EntitySpec *s = new EntitySpec();
s->setName("container");
e->setSpec(s);

c.addEntity(e);
std::string name = e->getSpec()->getName();
EXPECT_EQ(e,c.search(name));
}

TEST(TestContainer,removeEntity) {
Container c;

Entity* e = new Container();
EntitySpec *s = new EntitySpec();
s->setName("container");
e->setSpec(s);

c.addEntity(e);
EXPECT_EQ(e,c.search("container"));
c.removeEntity(e);
EXPECT_EQ(nullptr,c.search("container"));
}
