/**
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20, 2019-04-23
 */

#include "Container.h"
#include "Entity.h"
#include "Inform.h"
#include "Room.h"
#include "Npc.h"
#include <string>
#include "gtest/gtest.h"


TEST(TestContainer, describe) {
  Container c("id123");
  c.getSpec()->setDescription("A fancy box embossed with your name");

  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  i->getSpec()->setName("watch");
  i->getSpec()->setDescription("a jeweled watch");
  c.addEntity(i);

  Entity* i2 = new Entity();
  i2->getSpec()->setId("id456");
  i2->getSpec()->setName("biscuit");
  i2->getSpec()->setDescription("a slimy biscuit");
  c.addEntity(i2);

  EXPECT_EQ("A fancy box embossed with your name\n"
            "watch -> a jeweled watch\nbiscuit -> a slimy biscuit",
            c.describe());
}

TEST(TestContainer, search_not_find) {
  Container c("id123");
  EXPECT_EQ(nullptr, c.search("entity"));
}

TEST(TesrContainer, search_find_addEntity) {
  Container c("id123");

  Entity* e = new Container("id923427");
  e->getSpec()->setName("container");

  c.addEntity(e);
  std::string name = e->getSpec()->getName();

  EXPECT_EQ(e, c.search(name));
}

TEST(TestContainer, search_NPC) {
  Container* c = new Container("id345");

  Npc* i = new Npc("npc123");
  i->getSpec()->setId("id456");

  Entity* e = new Entity();
  e->getSpec()->setId("id123");
  e->getSpec()->setName("box");
  i->addEntity(e);
  c->addEntity(i);

  EXPECT_EQ(nullptr, c->search("box"));
  delete c;
}

TEST(TestContainer, search_nested) {
  Container* c = new Container("id345");
  Entity* i = new Entity();
  i->getSpec()->setName("box");
  c->addEntity(i);

  Room* r = new Room("rm2344");
  r->addEntity(c);

  EXPECT_EQ(i, r->search("box"));
  delete r;
}

TEST(TestContainer, searchById_nested) {
  Container* c = new Container("id765");
  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  c->addEntity(i);
  Room* r = new Room("rm2344");
  r->addEntity(c);
  EXPECT_EQ(i, r->searchById("id123"));
  delete r;
}

TEST(TestContainer, searchById_not_found) {
  Container* c = new Container("id9876");
  Entity* i = new Entity();
  i->getSpec()->setId("id456");
  c->addEntity(i);
  Room* r = new Room("rm2344");
  r->addEntity(c);
  EXPECT_EQ(nullptr, r->searchById("id123"));
  delete r;
}

TEST(TestContainer, searchAndRemove_found) {
  Container* c = new Container("id765");
  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  c->addEntity(i);
  Room* r = new Room("rm2344");
  r->addEntity(c);
  Entity* found = r->searchAndRemove("id123");
  EXPECT_EQ(i, found);
  EXPECT_EQ(nullptr, c->searchById("id123"));
  delete r;
  delete found;
}

TEST(TestContainer, searchAndRemove_not_found) {
  Container* c = new Container("id876");
  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  c->addEntity(i);
  Room* r = new Room("rm2344");
  r->addEntity(c);
  Entity* found = r->searchAndRemove("id456");
  EXPECT_EQ(nullptr, found);
  EXPECT_EQ(i, c->searchById("id123"));
  delete r;
}

TEST(TestContainer, removeEntity) {
  Container c("id8765");

  Entity* e = new Container("id98964");
  EntitySpec *s = new EntitySpec();
  s->setName("container");
  e->setSpec(s);

  c.addEntity(e);
  EXPECT_EQ(e, c.search("container"));
  c.removeEntity(e);
  EXPECT_EQ(nullptr, c.search("container"));
  delete e;
}

TEST(TestContainer, searchById_item_in_NPC) {
  Container* c = new Container("id734629");
  Npc* i = new Npc("npc123");
  i->getSpec()->setId("id456");
  Entity* e = new Entity();
  e->getSpec()->setId("id123");
  i->addEntity(e);
  c->addEntity(i);
  EXPECT_EQ(nullptr, c->searchById("id123"));
  delete c;
}

TEST(TestContainer, container_iterator) {
  Container c("id23947");

  Entity* e = new Container("id4820");
  EntitySpec *s = new EntitySpec();
  s->setName("container");
  e->setSpec(s);

  c.addEntity(e);
  auto it = c.begin();
  EXPECT_EQ(e, it->second);
  it++;
  EXPECT_EQ(c.end(), it);
}
