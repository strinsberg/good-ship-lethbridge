/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#include "TransferItem.h"
#include "Player.h"
#include "Container.h"
#include "Item.h"
#include "gtest/gtest.h"

TEST(TransferItemEventTests, normal) {
  Player* p = new Player();
  Container* c = new Container();
  Item* i = new Item();
  i->getSpec()->setId("item456");
  c->addEntity(i);
  TransferItem t("ti123", c, "item456", true);
  // Can't finish yet because search does not work with ID
  delete p;
  delete c;
}
