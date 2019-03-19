/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-12
 */

#include "KeyLock.h"
#include "Item.h"
#include "Entity.h"
#include "Container.h"
#include "Inform.h"
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

TEST(TestKeyLock, set_key) {
  Entity* locked = new Item();
  Entity* key = new Item();
  Entity* newKey = new Item();

  KeyLock l(locked, key);
  EXPECT_EQ(key, l.getKey());
  l.setKey(newKey);
  EXPECT_EQ(newKey, l.getKey());

  delete locked;
  delete key;
  delete newKey;
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

  EXPECT_EQ("You don't have what you need", l.execute(c));
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

  EXPECT_EQ("That can't hold a key", l.execute(item));  // does this make sense
  EXPECT_EQ(true, locked->getState()->getActive());

  delete key;
  delete item;
  delete locked;
}

TEST(TestKeyLock, success_event) {
  Entity* locked = new Item();
  locked->getSpec()->setName("Lamp");
  locked->getState()->setActive(false);

  Entity* key = new Item();
  Container* c = new Container();
  c->addEntity(key);

  KeyLock l(locked, key);
  l.setMessage("You now have access");

  Inform* i = new Inform();
  i->setMessage("Success");
  l.setSuccessEvent(i);

  EXPECT_EQ("Success\nYou now have access", l.execute(c));
  EXPECT_EQ(i, l.getSuccessEvent());
  EXPECT_EQ(true, locked->getState()->getActive());

  delete c;
  delete locked;
}

TEST(TestKeyLock, constructor_execute_fail_message) {
  Entity* locked = new Item();
  locked->getSpec()->setName("Lamp");
  locked->getState()->setActive(true);

  Entity* key = new Item();
  Container* c = new Container();

  KeyLock l(locked, key);
  l.setMessage("You now have access");
  l.setFailMessage("Failure");

  EXPECT_EQ("Failure", l.execute(c));
  EXPECT_EQ(true, locked->getState()->getActive());
  EXPECT_EQ("Failure", l.getFailMessage());

  delete key;
  delete c;
  delete locked;
}

TEST(KeyLockTests, makeBlueprint) {
  Entity* locked = new Item();
  locked->getSpec()->setName("Lamp");
  locked->getState()->setActive(true);

  Entity* key = new Item();

  KeyLock kl(locked, key);
  ObjectBlueprint* bp = kl.makeBlueprint();
  EXPECT_EQ("{\ntype=keylock,\ndone=false,\nkey=,\nmessage=,"
            "\nname=,\ntarget=Lamp,\n}",
            bp->toString());
  delete bp;
  delete key;
  delete locked;
}
