/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "KeyLock.h"
#include "Item.h"
#include "Entity.h"
#include "Container.h"
#include "gtest/gtest.h"

TEST(TestKeyLock, constructor_get) {
  Entity* locked = new Item();
  Entity* key = new Item();

  KeyLock l(locked, key);

  EXPECT_EQ("", l.getMessage());
  EXPECT_EQ(locked, l.getTarget());
  EXPECT_EQ("", l.getSpec()->getName());
  EXPECT_EQ(key, l.getKey());

  delete locked;
  delete key;
}

TEST(TestKeyLock, constructor_execute_have_key) {
  Entity* locked = new Item();
  locked->getSpec()->setName("Lamp");
  locked->getState()->setActive(false);

  Entity* key = new Item();
  Container* c = new Container();
  c->addEntity(key);

  KeyLock l(locked, key);
  l.setMessage("You now have access");

  EXPECT_EQ(false, locked->getState()->getActive());
  EXPECT_EQ("You now have access", l.execute(c));
  EXPECT_EQ(true, locked->getState()->getActive());

  delete c;
  delete locked;
}

TEST(TestKeyLock, constructor_execute_have_key_already_done) {
  Entity* locked = new Item();
  locked->getSpec()->setName("Lamp");
  locked->getState()->setActive(true);

  Entity* key = new Item();
  Container* c = new Container();
  c->addEntity(key);

  KeyLock l(locked, key);
  l.setMessage("You now have access");

  EXPECT_EQ("Already done", l.execute(c));
  EXPECT_EQ(true, locked->getState()->getActive());

  delete c;
  delete locked;
}

TEST(TestKeyLock, constructor_execute_no_key) {
  Entity* locked = new Item();
  locked->getSpec()->setName("Lamp");
  locked->getState()->setActive(true);

  Entity* key = new Item();
  Container* c = new Container();

  KeyLock l(locked, key);
  l.setMessage("You now have access");

  EXPECT_EQ("You don't have the key", l.execute(c));
  EXPECT_EQ(true, locked->getState()->getActive());

  delete key;
  delete c;
  delete locked;
}

TEST(TestKeyLock, constructor_execute_not_a_container) {
  Entity* locked = new Item();
  locked->getSpec()->setName("Lamp");
  locked->getState()->setActive(true);

  Entity* key = new Item();
  Entity* item = new Item();

  KeyLock l(locked, key);
  l.setMessage("You now have access");

  EXPECT_EQ("That can't hold a key", l.execute(item));
  EXPECT_EQ(true, locked->getState()->getActive());

  delete key;
  delete item;
  delete locked;
}
