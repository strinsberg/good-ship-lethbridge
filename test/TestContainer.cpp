/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-02-20
 */

#include "Container.h"
#include "Entity.h"
#include "EntitySpec.h"
#include "EntityState.h"
#include "Inform.h"
#include "Entity.h"
#include "Room.h"
#include "Npc.h"
#include <string>
#include <gtest/gtest.h>



TEST(TestContainer, describe) {
  Container c;
  EntitySpec * e = new EntitySpec();
  e->setDescription("this is a spec");
  c.setSpec(e);
  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  i->getSpec()->setDescription("steve");
  c.addEntity(i);
  EXPECT_EQ("this is a spec\nContains: \nsteve\n", c.describe());
}

TEST(TestContainer, search_not_find) {
  Container c;
  EXPECT_EQ(nullptr, c.search("entity"));
}

TEST(TesrContainer, search_find_addEntity) {
  Container c;

  Entity* e = new Container();
  EntitySpec *s = new EntitySpec();
  s->setName("container");
  e->setSpec(s);

  c.addEntity(e);
  std::string name = e->getSpec()->getName();
  EXPECT_EQ(e, c.search(name));
}

TEST(TestContainer, search_NPC) {
  Container* c = new Container();
  Npc* i = new Npc();
  i->getSpec()->setName("Steve");
  c->addEntity(i);
  EXPECT_EQ(nullptr, c->search("box"));
  delete c;
}

TEST(TestContainer, search_nested) {
  Container* c = new Container();
  Entity* i = new Entity();
  i->getSpec()->setName("box");
  c->addEntity(i);
  Room* r = new Room();
  r->addEntity(c);
  EXPECT_EQ(i, r->search("box"));
  delete r;
}

TEST(TestContainer, searchById_nested) {
  Container* c = new Container();
  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  c->addEntity(i);
  Room* r = new Room();
  r->addEntity(c);
  EXPECT_EQ(i, r->searchById("id123"));
  delete r;
}

TEST(TestContainer, searchById_not_found) {
  Container* c = new Container();
  Entity* i = new Entity();
  i->getSpec()->setId("id456");
  c->addEntity(i);
  Room* r = new Room();
  r->addEntity(c);
  EXPECT_EQ(nullptr, r->searchById("id123"));
  delete r;
}

TEST(TestContainer, searchAndRemove_found) {
  Container* c = new Container();
  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  c->addEntity(i);
  Room* r = new Room();
  r->addEntity(c);
  Entity* found = r->searchAndRemove("id123");
  EXPECT_EQ(i, found);
  EXPECT_EQ(nullptr, c->searchById("id123"));
  delete r;
  delete found;
}

TEST(TestContainer, searchAndRemove_not_found) {
  Container* c = new Container();
  Entity* i = new Entity();
  i->getSpec()->setId("id123");
  c->addEntity(i);
  Room* r = new Room();
  r->addEntity(c);
  Entity* found = r->searchAndRemove("id456");
  EXPECT_EQ(nullptr, found);
  EXPECT_EQ(i, c->searchById("id123"));
  delete r;
}

TEST(TestContainer, removeEntity) {
  Container c;

  Entity* e = new Container();
  EntitySpec *s = new EntitySpec();
  s->setName("container");
  e->setSpec(s);

  c.addEntity(e);
  EXPECT_EQ(e, c.search("container"));
  c.removeEntity(e);
  EXPECT_EQ(nullptr, c.search("container"));
  delete e;
}

TEST(TestContainer, container_iterator) {
  Container c;

  Entity* e = new Container();
  EntitySpec *s = new EntitySpec();
  s->setName("container");
  e->setSpec(s);

  c.addEntity(e);
  auto it = c.begin();
  EXPECT_EQ(e, it->second);
  it++;
  EXPECT_EQ(c.end(), it);
}
