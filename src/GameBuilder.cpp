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
#include "Interaction.h"
#include "Npc.h"
#include "MoveItems.h"
#include "EventGroup.h"
#include "CheckSuit.h"
#include "StructuredEvents.h"

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

  Room* hall = new Room();
  addEntityInfo(hall,
                "main hall",
                "the main hall, it connect to everywhere",
                true, false, false);
  g->addRoom("main hall",hall);

  Room* engiControl = new Room();
  addEntityInfo(engiControl,
                "engineer control room",
                "the engine room with reactor in it",
                true, false, false);
  g->addRoom("engineer control room",engiControl);

    Room* engiBay = new Room();
  addEntityInfo(engiBay,
                "engine bay",
                "a room filled with gamma radiation",
                true, false, false);
  g->addRoom("engine bay",engiBay);

  Room* cargoBay = new Room();
  addEntityInfo(cargoBay,
                "Cargo bay",
                "where the cargo is",
                true, false, false);
  g->addRoom("Cargo bay",cargoBay);

  Room* outerSpace = new Room();
  addEntityInfo(outerSpace,
                "Space",
                "middle of the milky way ! the sun is getting bigger!!",
                true,false,false);
  g->addRoom("Space",outerSpace);

  Room* bridge = new Room();
  addEntityInfo(bridge,
                "command bridge",
                "the bridge is flashing with red lights!!",
                true,false,false);
  g->addRoom("command bridge",bridge);

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
    hallDoor->setDestination(hall);
    common_room->addEntity(hallDoor);

    Door* hcDoor = new Door();
      addEntityInfo(hcDoor,
                "hall to common door",
                "the door lead you to the common",
                true,false,false);
    hcDoor->setHere(hall);
    hcDoor->setDestination(common_room);
    hall->addEntity(hcDoor);

    Door* engiDoor = new Door();
      addEntityInfo(engiDoor,
                "engineering room door",
                "the door lead you to the engineering room",
                false,false,false);
    engiDoor->setHere(hall);
  engiDoor->setDestination(engiControl);
    hall->addEntity(engiDoor);

        Door* engiToHall = new Door();
      addEntityInfo(engiToHall,
                "control to hall door",
                "A door back to the hall",
                true,false,false);
    engiToHall->setHere(engiControl);
  engiToHall->setDestination(hall);
    engiControl->addEntity(engiToHall);

        Door* engiBayDoor = new Door();
      addEntityInfo(engiBayDoor,
                "engine bay door",
                "A door to the engine bay. It looks pretty hefty to keep in radiation.",
                true,false,false);
    engiBayDoor->setHere(engiControl);
  engiBayDoor->setDestination(engiBay);
    engiControl->addEntity(engiBayDoor);

        Door* bayToControl = new Door();
      addEntityInfo(bayToControl,
                "door to engine control",
                "A door to the engine bay. It looks pretty hefty to keep in radiation.",
                true,false,false);
    bayToControl->setHere(engiBay);
  bayToControl->setDestination(engiControl);
    engiBay->addEntity(bayToControl);


    Door* cargoBaydoor = new Door();
      addEntityInfo(cargoBaydoor,
                "door to cargo bay",
                "A door to the cargo bay",
                false,false,false);
     cargoBaydoor->setHere(hall);
     cargoBaydoor->setDestination(cargoBay);
     hall->addEntity(cargoBaydoor);

     Door* cthDoor = new Door();
     addEntityInfo(cthDoor,
                "cargo to hall door",
                "A door to the hall way",
                true,false,false);
     cthDoor->setHere(cargoBay);
     cthDoor->setDestination(hall);
     cargoBay->addEntity(cthDoor);

     Door* airlockout = new Door();
     addEntityInfo(airlockout,
                "cargo exit airlock",
                "the airlock to outer space",
                true,false,false);
     airlockout->setHere(cargoBay);
     airlockout->setDestination(outerSpace);
     cargoBay->addEntity(airlockout);

     Door* airlockin = new Door();
     addEntityInfo(airlockin,
                "airlock to cargo bay",
                "the airlock to cargo bay",
                true,false,false);
     airlockin->setHere(outerSpace);
     airlockin->setDestination(cargoBay);
     outerSpace->addEntity(airlockin);

     Door* bridgeLockin = new Door();
     addEntityInfo(bridgeLockin,
                "airlock to bridge",
                "the airlock to the command bridge",
                true,false,false);
     bridgeLockin->setHere(outerSpace);
     bridgeLockin->setDestination(bridge);
     outerSpace->addEntity(bridgeLockin);

     Door* bridgeLockout = new Door();
     addEntityInfo(bridgeLockout,
                "airlock to space",
                "the airlock to the outer space",
                true,false,false);
     bridgeLockout->setHere(bridge);
     bridgeLockout->setDestination(outerSpace);
     bridge->addEntity(bridgeLockout);





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

Item* spannerDoorLock = new Item();
addEntityInfo(spannerDoorLock,
              "spanner door lock",
              "combination lock for spanner's door",
              true,false,false);
common_room->addEntity(spannerDoorLock);



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


Container* spannerdesk = new Container();
  addEntityInfo(spannerdesk,
                "Desk",
                "futuristic looking desk!",
                true, false, false);
  spannerRoom->addEntity(spannerdesk);

  Entity* spannerbed = new Item();
  addEntityInfo(spannerbed,
                "Bed",
                "Spanner's bed",
                true, false, false);
  spannerRoom->addEntity(spannerbed);

  Entity* spannerComputer = new Item();
  addEntityInfo(spannerComputer,
                "computer terminal",
                "Spanner's personal computer terminal",
                true, false, false);
   spannerdesk->addEntity(spannerComputer);

  //hall objects

  Entity* hallComputer = new Item();
  addEntityInfo(hallComputer,
                "computer terminal",
                "computer terminal in hall",
                true, false, false);
   hall->addEntity(hallComputer);

   Item* medKit = new Item();
   addEntityInfo(medKit,
                 "medKit",
                 "use it to heal wounds",
                 true,true,false);
  hall->addEntity(medKit);

 Npc* barbara = new Npc();
  addEntityInfo(barbara,
                "barbara Mcdougal",
                "sitting on the floor, looks injured.",
                true,false,false);
  hall->addEntity(barbara);

  //engineer control

  Container* engiCloset = new Container();
  addEntityInfo(engiCloset,
                "hazmat closet",
                "the closet for radiation pretection",
                true,false,false);
   engiControl->addEntity(engiCloset);

   Suit* hazmat = new Suit();
   addEntityInfo(hazmat,
                 "hazmat suit",
                 "the suit pretect you from gama radiation",
                 true,true,false);
   engiCloset->addEntity(hazmat);

   Npc* spanner = new Npc();
   addEntityInfo(spanner,
                 "Clem Spanner",
                 "the engineer",
                 true,false,false);
   engiControl->addEntity(spanner);

  Item* coreWrench = new Item();
  addEntityInfo(coreWrench,
                "Core wrench",
                "This amazing little tool is great for fixing cores",
                true, true, false);
  spanner->addEntity(coreWrench);

  // engine bay object


Item* reactor = new Item();
addEntityInfo(reactor,
              "reactor",
              "the fusion reactor that powers this ship",
              true,false,false);
engiBay->addEntity(reactor);

//cargo bay object//



Container* spaceCloset = new Container();
addEntityInfo(spaceCloset,
              "space suit closet",
              "contains the space suit for Extra-vehicular Activity",
              true,false,false);
cargoBay->addEntity(spaceCloset);

Suit* spaceSuit = new Suit();
spaceSuit->setAtmosphere(Atmosphere::SPACE);
addEntityInfo(spaceSuit,
              "space suit",
              "the suit for Extra-vehicular Activity",
              true,true,false);

spaceCloset->addEntity(spaceSuit);

Npc* Mae = new Npc();
addEntityInfo(Mae,
              "Whinny Mae",
              "ships Doctor",
              true,false,false);
cargoBay->addEntity(Mae);

//space object

Npc* alien = new Npc();
addEntityInfo(alien,
              "master yoda",
              "Jedi meditation on a antenna",
              true,false,false);
outerSpace->addEntity(alien);

Item* lightSaber = new Item();
addEntityInfo(lightSaber,
              "light saber",
              "the very old light saber that belongs to a legendary Jedi",
              true,true,false);
alien->addEntity(lightSaber);

Item* cookie = new Item();
addEntityInfo(cookie,
              "box of cookie",
              "a box full of cookie, bake by aliens",
              true,true,false);
Mae->addEntity(cookie);
//bridge objects

Npc* lars = new Npc();
addEntityInfo(lars,
              "Lars Philbur",
              "the bridge officer is standing on the ceiling",
              true,false,false);
bridge->addEntity(lars);

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

  Kill* killSpannerBed = new Kill();
  killSpannerBed->setMessage("you slept through the disaster");
  spannerbed->setEvent(killSpannerBed);

  Inform* spannerComputerInfo = new Inform();
  spannerComputerInfo->setMessage("biometric authentication failed! \naccess denied!!");
  spannerComputer->setEvent(spannerComputerInfo);

  //hall events

  Inform* useMed = new Inform();
  useMed->setMessage("you dont need it");
  medKit->setEvent(useMed);

  Inform* talkBarbara = new Inform();
  talkBarbara->setMessage("please i need help!");
  KeyLock* engiOpen = new KeyLock(engiDoor,medKit);

  MoveItems* giveMedkit = new MoveItems(barbara,"medKit");

  EventGroup* healBarbara = new EventGroup();
  healBarbara->addEvent(engiOpen);
  healBarbara->addEvent(giveMedkit);

  Interaction* interBarbara = new Interaction();
  interBarbara->addOption("talk to her",talkBarbara);
  interBarbara->addOption("heal Barbara",healBarbara);
  barbara->setEvent(interBarbara);


  // Engineering Events

  MoveItems* getCoreWrench = new MoveItems(spanner, "core wrench");
  getCoreWrench->setGive(true);
  getCoreWrench->setMessage("Here you go! Now get in there and fix the core!");

  Inform* talkSpanner = new Inform();
  talkSpanner->setMessage("You have to go into the core while I operate the controls\n"
                          "I have a core wrench you will need");

  Inform* askSpanner = new Inform();
  askSpanner->setMessage("Just smack it real hard");

  Interaction* interSpanner = new Interaction();
  interSpanner->setMessage("Glad your here I need some help!");
  interSpanner->addOption("talk to him", talkSpanner);
  interSpanner->addOption("get core wrench", getCoreWrench);
  interSpanner->addOption("How do I fix the reactor?", askSpanner);
  spanner->setEvent(interSpanner);
//engine bay event

  Kill* fiddle = new Kill();
  fiddle->setMessage("you pressed wrong button, segfault (core dumped) 0xFFFFF :( !!");

  CheckSuit* radSuit = new CheckSuit(engiBay);
  radSuit->setMessage("You enter the engine bay. I hope you have a radiation suit on.");
  engiBay->setEnter(radSuit);


  KeyLock* Fixed = new KeyLock(cargoBaydoor,coreWrench);
  Fixed->setMessage("power is restored, good job ;)");



  Kill* leakage = new Kill();
  leakage->setMessage("radiation kills every one on this ship");
  Interaction* reactorFix = new Interaction();
  reactorFix->addOption("fiddle with it",fiddle);
  reactorFix->addOption("smack with wrench real hard!",Fixed);
  reactorFix->addOption("put out reactor core",leakage);

  reactor->setEvent(reactorFix);
//cargo bay even//

Inform* quick=new Inform();
quick->setMessage("quick you need to get to the bridge!");
Inform* larsCrash=new Inform();
larsCrash->setMessage("Lars is controlled by the alien now!");
Inform* stillhere=new Inform();
stillhere->setMessage("what are you still here for, go save us!");
Inform* forget=new Inform();
forget->setMessage("don't forget wear space suit!");
MoveItems* giveCookie = new MoveItems(Mae,"box of cookie");
giveCookie->setMessage("here is a box of cookie");
giveCookie->setGive(true);
Inform* stoptalk=new Inform();
stoptalk->setMessage("stop talking to me!");
StructuredEvents* talkMae = new StructuredEvents();
talkMae->setRepeats(false);
talkMae->addEvent(quick);
talkMae->addEvent(larsCrash);
talkMae->addEvent(stillhere);
talkMae->addEvent(forget);
talkMae->addEvent(giveCookie);
talkMae->addEvent(stoptalk);
Mae->setEvent(talkMae);

//space events

KeyLock* talkyoda = new KeyLock(alien,cookie);
talkyoda->setMessage("its rude to interrupt a Jedi's meditation");
alien->setEvent(talkyoda);

//bridge events
Inform* intosun = new Inform();
intosun->setMessage("you fly the ship into the sun, sacrificing your self and your crew to save the galaxy!");
Inform* escape= new Inform();
escape->setMessage("you took the only escape pod, fly away! what a captain!");
Inform* capture = new Inform();
capture->setMessage("you captured lars but the contamination spreads, and devastated the galaxy!");

KeyLock* win = new KeyLock(lars,lightSaber);
win->setMessage("you excuted the source of the virus, the rest of your crew and the galaxy is all saved!!");





Interaction* ending = new Interaction();
ending->addOption("kill lars",win);
ending->addOption("fly the ship into the sun",intosun);
ending->addOption("take a escape pod",escape);
ending->addOption("capture and lock lars",capture);

lars->setEvent(ending);
// Create player ////////////////////////////////////////////////////////////
  Player* p = new Player();
  p->setSpec( makeEntitySpec(name, "It's you!"));
  p->setState( makeEntityState(true, false, false) );
  p->setCurrentRoom(outerSpace);
  g->setPlayer(p);






//debugs

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
