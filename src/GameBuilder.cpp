/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include "GameBuilder.h"
#include "Game.h"
#include "Item.h"
#include "Entity.h"
#include "Door.h"
#include "Kill.h"
#include "Inform.h"
#include "QuestionLock.h"
#include "KeyLock.h"
GameBuilder::GameBuilder() {}

GameBuilder::~GameBuilder() {}

Game* GameBuilder::newGame(std::string name) {
  // Create a game
  Game* g = new Game();

  // for AddEntityInfo(name,description,active,obtainable,hidden) //

  // Create Rooms /////////////////////////////////////////////////////////////
  Room* captains_room = new Room();
  addEntityInfo(captains_room,
                "Captain's Room",
                "The best room on the ship! You are the captain after all",
                true, false, false);
  g->addRoom("Captain's Room", captains_room);

  Room* common_room = new Room();
  addEntityInfo(common_room,
                "Common Room",
                "A good room for relaxing with your crew",
                true, false, false);
  g->addRoom("Common Room", common_room);

  Room* spannerRoom = new Room();
  addEntityInfo(spannerRoom,
                "spanner Room",
                "the room of the engineer Clem Spanner",
                true, false, false);
  g->addRoom("spanner Room",spannerRoom);

  //Create doors /////////////////////////////////////////////////////
  Door* door = new Door();
  addEntityInfo(door,
                "common room door",
                "the door lead you to the common room",
                true,false,false);
   door->setHere(captains_room);
   door->setDestination(common_room);
   captains_room->addEntity(door);

  Door* captain_room_door = new Door();
  addEntityInfo(captain_room_door,
                "captain's room door",
                "the door lead you to the captain's room",
                true,false,false);
   captain_room_door->setHere(common_room);
   captain_room_door->setDestination(captains_room);
   common_room->addEntity(captain_room_door);

  Door* spannerRoomDoor = new Door();
  addEntityInfo(spannerRoomDoor,
                "spanner room door",
                "the door lead you to the engineer Spanner's room",
                false,false,false);
    spannerRoomDoor->setHere(common_room);
    spannerRoomDoor->setDestination(spannerRoom);
    common_room->addEntity(spannerRoomDoor);



  Door* commonRoomDoor = new Door();
  addEntityInfo(commonRoomDoor,
                "door to common room",
                "the door lead you to the common room",
                true,false,false);
    commonRoomDoor->setHere(spannerRoom);
    commonRoomDoor->setDestination(common_room);
    spannerRoom->addEntity(commonRoomDoor);


      Door* hallDoor = new Door();
      addEntityInfo(hallDoor,
                "hall door",
                "the door lead you to the hallway",
                false,false,false);
    hallDoor->setHere(common_room);
    //hallDoor->setDestination(hall);
    common_room->addEntity(hallDoor);


  // Create objects ///////////////////////////////////////////////////////////

  // captains room objects
  Entity* box = new Container();
  addEntityInfo(box,
                "Box",
                "a small metallic container, maybe filled with treasure!",
                true, true, false);
  captains_room->addEntity(box);

  Container* desk = new Container();
  addEntityInfo(desk,
                "Desk",
                "futuristic looking desk!",
                true, false, false);
  captains_room->addEntity(desk);

  Entity* bed = new Item();
  addEntityInfo(bed,
                "Bed",
                "your bed",
                true, false, false);
  captains_room->addEntity(bed);

  Entity* computer = new Item();
  addEntityInfo(computer,
                "computer terminal",
                "Captain's personal computer terminal",
                true, false, false);
   desk->addEntity(computer);

  Entity* window = new Item();
  addEntityInfo(window,
                "window",
                "Captain's window",
                true, false, false);
   desk->addEntity(window);

   // common room objects
   Item* chair = new Item();
addEntityInfo(chair,
	"chair",
	"A nice old chair, you might be comfortable there",
	true, false, false);
common_room->addEntity(chair);

   Container* table = new Container();
addEntityInfo(table,
	"Table",
	"An end table with a drawer",
	true, false, false);
common_room->addEntity(table);

  Item* crewList = new Item();
  addEntityInfo(crewList,
                "crew manifest",
                "piece paper use that contains the list of the crew members",
                true, true, false);
   table->addEntity(crewList);



Item* comfy_chair = new Item();
addEntityInfo(comfy_chair,
	"Comfy chair",
	"This chair deserves a Captain",
	true, false, false);
common_room->addEntity(comfy_chair);

Item* hallDoorPanel = new Item();
addEntityInfo(hallDoorPanel,
              "hall door panel",
              "this is the broken, maybe replace some parts?",
              true,false,false);
              common_room->addEntity(hallDoorPanel);

//spanner's room objects//////////////////////////////////////////////////////////////////
Container* tool_closet = new Container();
addEntityInfo(tool_closet,
		"Tool closet",
		"A battered old tool chest. Engineers don't like people touching their tools!",
		true, false, false);
spannerRoom->addEntity(tool_closet);



Item* fuse = new Item();
addEntityInfo(fuse,
		"Fuse",
		"A small fuse that looks like it would fit in a doors control panel",
		true, true, false);
tool_closet->addEntity(fuse);


Item* spannerDoorLock = new Item();
addEntityInfo(spannerDoorLock,
              "spanner door lock",
              "combination lock for spanner's door",
              true,false,false);
common_room->addEntity(spannerDoorLock);

  // Create events ////////////////////////////////////////////////////////////

  // captains room events
  Kill* captainBed = new Kill();
  captainBed->setMessage("you slept through the disaster");
  bed->setEvent(captainBed);

  Inform* captainComputer = new Inform();
  captainComputer->setMessage("good ship Lethbridge status : code red \npower down everywhere ");
  computer->setEvent(captainComputer);

  Inform* captainWindow = new Inform();
  captainWindow->setMessage("you see endless space and some debris probably from the'Lethbridge'");
  window->setEvent(captainWindow);

  Inform* enter_captains_room = new Inform();
  enter_captains_room->setMessage("You are in the captains room");
  captains_room->setEnter(enter_captains_room);

  // common room events
  Inform* enter_common_room = new Inform();
  enter_common_room->setMessage("You are in the common room");
  common_room->setEnter(enter_common_room);

  Inform* furniture = new Inform();
furniture->setMessage("You take a moment to relax. Is this really the time!");
chair->setEvent(furniture);

Inform* nice_furniture = new Inform();
nice_furniture->setMessage("This feels too good! Your a bad captain! Save your ship!");
comfy_chair->setEvent(nice_furniture);

Inform* manifest_list = new Inform();
manifest_list->setMessage("Barbara Mcdougal - Biologist\nID #0791"
			"Clem Spanner - Engineer\nID #4396"
			"Whinny Mae - Doctor\nID #0341"
			"Lars Philbur - Bridge Officer\nID #7513");
crewList->setEvent(manifest_list);


QuestionLock* spannerLock = new QuestionLock(spannerRoomDoor,"enter combination: ","4396");
spannerLock->setMessage("spanner room door activated ");
spannerDoorLock->setEvent(spannerLock);

KeyLock* hallLock =new KeyLock(hallDoor,fuse);
hallLock->setMessage("power restored to hall door");
hallDoorPanel->setEvent(hallLock);

//spanner room events///////////////////////////
Inform* use_fuse = new Inform();
use_fuse->setMessage("Careful you might break it!");
fuse->setEvent(use_fuse);
  // Create player ////////////////////////////////////////////////////////////
  Player* p = new Player();
  p->setSpec( makeEntitySpec(name, "It's you!"));
  p->setState( makeEntityState(true, false, false) );
  p->setCurrentRoom(common_room);
  g->setPlayer(p);

  // Return the game
  return g;
}

EntitySpec* GameBuilder::makeEntitySpec(std::string name, std::string description) {
  EntitySpec* spec = new EntitySpec();
  spec->setName(name);
  spec->setDescription(description);
  return spec;
}

EntityState* GameBuilder::makeEntityState(bool active, bool obtainable, bool hidden) {
  EntityState* state = new EntityState();
  state->setActive(active);
  state->setObtainable(obtainable);
  state->setHidden(hidden);
  return state;
}

void GameBuilder::addEntityInfo(Entity* entity, std::string name, std::string description, bool active, bool obtainable, bool hidden) {
  entity->setSpec(makeEntitySpec(name, description));
  entity->setState(makeEntityState(active, obtainable, hidden));
}
