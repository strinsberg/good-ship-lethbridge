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
  i->getSpec()->setName("Steve");
  c.addEntity(i);
  EXPECT_EQ("this is a spec\nContains: \nsteve\n", c.describe());
}

TEST(TestContainer, searchnotfind) {
  Container c;

  EXPECT_EQ(nullptr, c.search("entity"));
}

TEST(TesrContainer, searchfind_addEntity) {
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

TEST(TestContainer, set_event) {
}

TEST(TestContainer, set_state) {
  Container c;
  EntityState* s = new EntityState();
  c.setState(s);
  EXPECT_EQ(s, c.getState());
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
