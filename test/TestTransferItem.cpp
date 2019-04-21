/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "TransferItem.h"
#include "Player.h"
#include "Container.h"
#include "Entity.h"
#include "gtest/gtest.h"

TEST(TransferItemEventTests, execute_owner_has_item) {
  Player* p = new Player("player123");
  Container* c = new Container("con123");
  Entity* i = new Entity();
  i->getSpec()->setId("item456");
  i->getSpec()->setDescription("a nice ring");
  c->addEntity(i);
  TransferItem t("ti123", c, "item456", true);

  EXPECT_EQ("You have obtained a nice ring", t.execute(p));
  EXPECT_EQ(nullptr, c->searchById("item456"));
  EXPECT_EQ(i, p->searchById("item456"));
  EXPECT_TRUE(t.isDone());

  delete p;
  delete c;
}

TEST(TransferItemEventTests, execute_target_has_item) {
  Player* p = new Player("player123");
  Container* c = new Container("con123");
  Entity* i = new Entity();
  i->getSpec()->setId("item456");
  i->getSpec()->setDescription("a nice ring");
  p->addEntity(i);
  TransferItem t("ti123", c, "item456", false);

  EXPECT_EQ("a nice ring was taken from you", t.execute(p));
  EXPECT_EQ(i, c->searchById("item456"));
  EXPECT_EQ(nullptr, p->searchById("item456"));

  delete p;
  delete c;
}

TEST(TransferItemEventTests, execute_already_done) {
  Player* p = new Player("player123");
  Container* c = new Container("con123");
  Entity* i = new Entity();
  i->getSpec()->setId("item456");
  i->getSpec()->setDescription("a nice ring");
  c->addEntity(i);
  TransferItem t("ti123", c, "item456", true);

  t.execute(p);
  EXPECT_EQ("", t.execute(p));

  delete p;
  delete c;
}

TEST(TransferItemEventTests, execute_target_not_container) {
  Player* p = new Player("player123");
  Container* c = new Container("con123");
  Entity* i = new Entity();
  i->getSpec()->setId("item456");
  i->getSpec()->setDescription("a nice ring");
  c->addEntity(i);
  TransferItem t("ti123", c, "item456", true);

  EXPECT_EQ("You can't transfer items to non-containers!", t.execute(i));

  delete p;
  delete c;
}

TEST(TransferItemEventTests, execute_target_doesnt_have_item) {
  Player* p = new Player("player123");
  Container* c = new Container("con123");
  Entity* i = new Entity();
  i->getSpec()->setId("item456");
  i->getSpec()->setDescription("a nice ring");

  TransferItem t("ti123", c, "item456", false);

  EXPECT_EQ("You don't have what you need!", t.execute(p));
  EXPECT_EQ(nullptr, c->searchById("item456"));
  EXPECT_EQ(nullptr, p->searchById("item456"));

  delete p;
  delete c;
}

TEST(TransferItemEventTests, execute_owner_doesnt_have_item) {
  Player* p = new Player("player123");
  Container* c = new Container("con123");
  Entity* i = new Entity();
  i->getSpec()->setId("item456");
  i->getSpec()->setDescription("a nice ring");

  TransferItem t("ti123", c, "item456", true);

  EXPECT_EQ("Somebody made a mistake!", t.execute(p));
  EXPECT_EQ(nullptr, c->searchById("item456"));
  EXPECT_EQ(nullptr, p->searchById("item456"));

  delete p;
  delete c;
}
