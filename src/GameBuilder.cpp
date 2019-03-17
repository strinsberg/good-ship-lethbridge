/**
 * CPSC2720 Group Project Spring 2019
 * @author Steven Deutekom <deutekom@uleth.ca>, Max Niu <max.niu@uleth.ca>
 * @date 2019-03-11
 */

#include <string>
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
#include "EndGame.h"

GameBuilder::GameBuilder() {}

GameBuilder::~GameBuilder() {}

Game* GameBuilder::newGame(std::string name) {
  // Create a game
  Game* g = new Game();

  // for AddEntityInfo(name,description,active,obtainable,hidden) //

  // Create Rooms /////////////////////////////////////////////////////////////
  Room* captains_room = new Room();
  addEntityInfo(captains_room, "Captain's Room",
                "The best room on the ship! You are the captain after all",
                true, false, false);
  g->addRoom("Captain's Room", captains_room);

  Room* common_room = new Room();
  addEntityInfo(common_room, "Common Room",
                "A good room for relaxing with your crew", true, false, false);
  g->addRoom("Common Room", common_room);

  Room* spannerRoom = new Room();
  addEntityInfo(spannerRoom, "spanner Room",
                "the room of the engineer Clem Spanner", true, false, false);
  g->addRoom("spanner Room", spannerRoom);

  Room* hall = new Room();
  addEntityInfo(hall, "main hall", "the main hall, it connect to everywhere",
                true, false, false);
  g->addRoom("main hall", hall);

  Room* engiControl = new Room();
  addEntityInfo(engiControl, "engineer control room",
                "the engine room with reactor in it", true, false, false);
  g->addRoom("engineer control room", engiControl);

  Room* engiBay = new Room();
  addEntityInfo(engiBay, "engine bay", "a room filled with gamma radiation",
                true, false, false);
  g->addRoom("engine bay", engiBay);

  Room* cargoBay = new Room();
  addEntityInfo(cargoBay, "Cargo bay", "where the cargo is",
                true, false, false);
  g->addRoom("Cargo bay", cargoBay);

  Room* outerSpace = new Room();
  addEntityInfo(outerSpace, "Space", "middle of the "
                "milky way ! the sun is getting bigger!!", true, false, false);
  g->addRoom("Space", outerSpace);

  Room* bridge = new Room();
  addEntityInfo(bridge, "command bridge",
                "the bridge is flashing with red lights!", true, false, false);
  g->addRoom("command bridge", bridge);

  //Create doors /////////////////////////////////////////////////////
  Door* door = new Door();
  addEntityInfo(door, "common room door",
                "the door lead you to the common room", true, false, false);
  door->setHere(captains_room);
  door->setDestination(common_room);
  captains_room->addEntity(door);

  Door* captain_room_door = new Door();
  addEntityInfo(captain_room_door, "captain's room door",
                "the door lead you to the captain's room", true, false, false);
  captain_room_door->setHere(common_room);
  captain_room_door->setDestination(captains_room);
  common_room->addEntity(captain_room_door);

  Door* spannerRoomDoor = new Door();
  addEntityInfo(spannerRoomDoor, "spanner room door",
                "the door lead you to the engineer Spanner's room",
                false, false, false);
  spannerRoomDoor->setHere(common_room);
  spannerRoomDoor->setDestination(spannerRoom);
  common_room->addEntity(spannerRoomDoor);

  Door* commonRoomDoor = new Door();
  addEntityInfo(commonRoomDoor, "door to common room",
                "the door lead you to the common room", true, false, false);
  commonRoomDoor->setHere(spannerRoom);
  commonRoomDoor->setDestination(common_room);
  spannerRoom->addEntity(commonRoomDoor);

  Door* hallDoor = new Door();
  addEntityInfo(hallDoor, "hall door",
                "the door lead you to the hallway", false, false, false);
  hallDoor->setHere(common_room);
  hallDoor->setDestination(hall);
  common_room->addEntity(hallDoor);

  Door* hcDoor = new Door();
  addEntityInfo(hcDoor, "hall to common door",
                "the door lead you to the common", true, false, false);
  hcDoor->setHere(hall);
  hcDoor->setDestination(common_room);
  hall->addEntity(hcDoor);

  Door* engiDoor = new Door();
  addEntityInfo(engiDoor, "engineering room door", "the door lead "
                "you to the engineering room", false, false, false);
  engiDoor->setHere(hall);
  engiDoor->setDestination(engiControl);
  hall->addEntity(engiDoor);

  Door* engiToHall = new Door();
  addEntityInfo(engiToHall, "control to hall door", "A door back to the hall",
                true, false, false);
  engiToHall->setHere(engiControl);
  engiToHall->setDestination(hall);
  engiControl->addEntity(engiToHall);

  Door* engiBayDoor = new Door();
  addEntityInfo(engiBayDoor, "engine bay door", "A door to the engine bay."
          " It looks pretty hefty to keep in radiation.", true, false, false);
  engiBayDoor->setHere(engiControl);
  engiBayDoor->setDestination(engiBay);
  engiControl->addEntity(engiBayDoor);

  Door* bayToControl = new Door();
  addEntityInfo(bayToControl, "door to engine control",
      "A door to the engine bay. It looks pretty hefty to keep in radiation.",
      true, false, false);
  bayToControl->setHere(engiBay);
  bayToControl->setDestination(engiControl);
  engiBay->addEntity(bayToControl);

  Door* cargoBaydoor = new Door();
  addEntityInfo(cargoBaydoor, "door to cargo bay",
                "A door to the cargo bay", false, false, false);
  cargoBaydoor->setHere(hall);
  cargoBaydoor->setDestination(cargoBay);
  hall->addEntity(cargoBaydoor);

  Door* cthDoor = new Door();
  addEntityInfo(cthDoor, "cargo to hall door",
                "A door to the hall way", true, false, false);
  cthDoor->setHere(cargoBay);
  cthDoor->setDestination(hall);
  cargoBay->addEntity(cthDoor);

  Door* airlockout = new Door();
  addEntityInfo(airlockout, "cargo exit airlock", "the airlock to outer space",
                true, false, false);
  airlockout->setHere(cargoBay);
  airlockout->setDestination(outerSpace);
  cargoBay->addEntity(airlockout);

  Door* airlockin = new Door();
  addEntityInfo(airlockin, "airlock to cargo bay", "the airlock to cargo bay",
                true, false, false);
  airlockin->setHere(outerSpace);
  airlockin->setDestination(cargoBay);
  outerSpace->addEntity(airlockin);

  Door* bridgeLockin = new Door();
  addEntityInfo(bridgeLockin, "airlock to bridge",
                "the airlock to the command bridge", true, false, false);
  bridgeLockin->setHere(outerSpace);
  bridgeLockin->setDestination(bridge);
  outerSpace->addEntity(bridgeLockin);

  Door* bridgeLockout = new Door();
  addEntityInfo(bridgeLockout, "airlock to space",
                "the airlock to the outer space", true, false, false);
  bridgeLockout->setHere(bridge);
  bridgeLockout->setDestination(outerSpace);
  bridge->addEntity(bridgeLockout);

  // Create objects ///////////////////////////////////////////////////////////

  // captains room objects
  Entity* box = new Container();
  addEntityInfo(box, "Box", "a small metallic container, "
     "maybe filled with treasure!", true, true, false);
  captains_room->addEntity(box);

  Container* desk = new Container();
  addEntityInfo(desk, "Captains Desk", "futuristic looking desk!",
                true, false, false);
  captains_room->addEntity(desk);

  Entity* bed = new Item();
  addEntityInfo(bed, "Captains Bed", "your bed", true, false, false);
  captains_room->addEntity(bed);

  Entity* computer = new Item();
  addEntityInfo(computer, "Captains computer",
                "Captain's personal computer terminal", true, false, false);
  desk->addEntity(computer);

  Entity* window = new Item();
  addEntityInfo(window, "window", "Captain's window", true, false, false);
  captains_room->addEntity(window);

  // common room objects
  Container* table = new Container();
  addEntityInfo(table, "Table", "An end table with a drawer",
                true, false, false);
  common_room->addEntity(table);

  Item* crewList = new Item();
  addEntityInfo(crewList, "crew manifest", "piece paper use that contains "
                "the list of the crew members", true, true, false);
  table->addEntity(crewList);

  Item* comfy_chair = new Item();
  addEntityInfo(comfy_chair, "Comfy chair", "This chair deserves a Captain",
                true, false, false);
  common_room->addEntity(comfy_chair);

  Item* hallDoorPanel = new Item();
  addEntityInfo(hallDoorPanel, "hall door panel",
    "this is the broken, maybe replace some parts?", true, false, false);
  common_room->addEntity(hallDoorPanel);

  Item* spannerDoorLock = new Item();
  addEntityInfo(spannerDoorLock, "spanner door lock",
                "combination lock for spanner's door", true, false, false);
  common_room->addEntity(spannerDoorLock);

//spanner's room objects//
  Container* tool_closet = new Container();
  addEntityInfo(tool_closet, "Tool closet", "A battered old tool chest. "
    "Engineers don't like people touching their tools!", true, false, false);
  spannerRoom->addEntity(tool_closet);

  Item* fuse = new Item();
  addEntityInfo(fuse, "Fuse", "A small fuse that looks like it would "
                "fit in a doors control panel", true, true, false);
  tool_closet->addEntity(fuse);

  Container* spannerdesk = new Container();
  addEntityInfo(spannerdesk, "spanners desk", "futuristic looking desk!",
                true, false, false);
  spannerRoom->addEntity(spannerdesk);

  Entity* spannerbed = new Item();
  addEntityInfo(spannerbed, "Bed", "Spanner's bed", true, false, false);
  spannerRoom->addEntity(spannerbed);

  Entity* spannerComputer = new Item();
  addEntityInfo(spannerComputer, "computer terminal",
                "Spanner's personal computer terminal", true, false, false);
  spannerdesk->addEntity(spannerComputer);

  //hall objects
  Entity* hallComputer = new Item();
  addEntityInfo(hallComputer, "hall computer", "computer terminal in hall",
                true, false, false);
  hall->addEntity(hallComputer);

  Item* medKit = new Item();
  addEntityInfo(medKit, "medKit", "use it to heal wounds", true, true, false);
  hall->addEntity(medKit);

  Npc* barbara = new Npc();
  addEntityInfo(barbara,
                "Barbara Mcdougal", "sitting on the floor, looks injured.",
                true, false, false);
  hall->addEntity(barbara);

  //engineer control
  Container* engiCloset = new Container();
  addEntityInfo(engiCloset, "hazmat closet",
                "the closet for radiation protection", true, false, false);
  engiControl->addEntity(engiCloset);

  Suit* hazmat = new Suit();
  hazmat->setAtmosphere(Atmosphere::RADIATION);
  addEntityInfo(hazmat, "Hazmat suit", "the suit protect "
                "you from gamma radiation", true, true, false);
  engiCloset->addEntity(hazmat);

  Npc* spanner = new Npc();
  addEntityInfo(spanner, "Clem Spanner", "the engineer", true, false, false);
  engiControl->addEntity(spanner);

  Item* coreWrench = new Item();
  addEntityInfo(coreWrench, "Core wrench",
    "This amazing little tool is great for fixing cores", true, true, false);
  spanner->addEntity(coreWrench);

  // engine bay object
  Item* reactor = new Item();
  addEntityInfo(reactor, "reactor", "the fusion reactor that powers this ship",
                true, false, false);
  engiBay->addEntity(reactor);

//cargo bay object//
  Container* spaceCloset = new Container();
  addEntityInfo(spaceCloset, "space suit closet",
    "contains a space suit for Extra-vehicular Activity", true, false, false);
  cargoBay->addEntity(spaceCloset);

  Suit* spaceSuit = new Suit();
  spaceSuit->setAtmosphere(Atmosphere::SPACE);
  addEntityInfo(spaceSuit, "space suit",
                "the suit for Extra-vehicular Activity", true, true, false);
  cargoBay->addEntity(spaceSuit);

  Npc* Mae = new Npc();
  addEntityInfo(Mae, "Whinny Mae", "the ships Doctor", true, false, false);
  cargoBay->addEntity(Mae);

  Item* cookie = new Item();
  addEntityInfo(cookie, "box of cookie",
                "a box full of cookie, bake by aliens", true, true, false);
  Mae->addEntity(cookie);

//space object
  Npc* alien = new Npc();
  addEntityInfo(alien, "master yoda", "the Jedi meditation on a antenna",
                true, false, false);
  outerSpace->addEntity(alien);

  Item* lightSaber = new Item();
  addEntityInfo(lightSaber, "light saber", "the very old light saber "
    "that used to belongs to a legendary Jedi", true, true, false);
  alien->addEntity(lightSaber);

//bridge objects
  Npc* lars = new Npc();
  addEntityInfo(lars, "Lars Philbur", "the flashing lights, the bridge "
                "officer is standing on the ceiling!", true, false, false);
  bridge->addEntity(lars);

  Item* dummy = new Item();
  dummy->getState()->setActive(false);
  dummy->getState()->setHidden(true);
  lars->addEntity(dummy);

// Create events ////////////////////////////////////////////////////////////
  // captains room events
  Kill* captainBed = new Kill();
  captainBed->getSpec()->setName("c_bed");
  captainBed->setMessage("you slept through the disaster");
  bed->setEvent(captainBed);
  g->addEvent("c_bed", captainBed);

  Inform* captainComputer = new Inform();
  captainComputer->getSpec()->setName("c_comp");
  captainComputer->setMessage("Ship Status:               NOT AVAILABLE \n"
                              "\nALL CREW RETURN TO COMBAT POSITION");
  computer->setEvent(captainComputer);
  g->addEvent("c_comp", captainComputer);

  Inform* captainWindow = new Inform();
  captainWindow->getSpec()->setName("c_win");
  captainWindow->setMessage("you see endless space and some "
                            "debris probably from the Lethbridge");
  window->setEvent(captainWindow);
  g->addEvent("c_win", captainWindow);

  // common room events
  Inform* nice_furniture = new Inform();
  nice_furniture->getSpec()->setName("spa_nice");
  nice_furniture->setMessage("This feels too good! "
                             "Your a bad captain! Save your ship!");
  comfy_chair->setEvent(nice_furniture);
  g->addEvent("spa_nice", nice_furniture);

  Inform* manifest_list = new Inform();
  manifest_list->getSpec()->setName("spa_list");
  manifest_list->setMessage("Barbara Mcdougal - Biologist\nID #0791\n\n"
    "Clem Spanner - Engineer\nID #4396\n\nWhinny Mae - Doctor\nID #0341\n\n"
                            "Lars Philbur - Bridge Officer\nID #7513\n\n");
  crewList->setEvent(manifest_list);
  g->addEvent("spa_list", manifest_list);

  QuestionLock* spannerLock = new QuestionLock(spannerRoomDoor,
      "enter combination: ", "4396");
  spannerLock->getSpec()->setName("spa_lock");
  spannerLock->setMessage("spanner room door activated ");
  spannerDoorLock->setEvent(spannerLock);
  g->addEvent("spa_lock", spannerLock);

  KeyLock* hallLock = new KeyLock(hallDoor, fuse);
  hallLock->getSpec()->setName("spa_hall_lock");
  hallLock->setMessage("power restored to hall door");
  hallDoorPanel->setEvent(hallLock);
  g->addEvent("spa_hall_lock", hallLock);

  //spanner room events///////////////////////////
  Inform* use_fuse = new Inform();
  use_fuse->getSpec()->setName("s_fuse");
  use_fuse->setMessage("Careful you might break it!");
  fuse->setEvent(use_fuse);
  g->addEvent("s_fuse", use_fuse);

  Kill* killSpannerBed = new Kill();
  killSpannerBed->getSpec()->setName("s_die");
  killSpannerBed->setMessage("you slept through the disaster");
  spannerbed->setEvent(killSpannerBed);
  g->addEvent("s_die", killSpannerBed);

  Inform* spannerComputerInfo = new Inform();
  spannerComputerInfo->getSpec()->setName("s_comp");
  spannerComputerInfo->setMessage("Biometric authentication failed!"
                                  " \naccess denied!!");
  spannerComputer->setEvent(spannerComputerInfo);
  g->addEvent("s_comp", spannerComputerInfo);

  //hall events
  Inform* useMed = new Inform();
  useMed->getSpec()->setName("s_med");
  useMed->setMessage("you dont need it");
  medKit->setEvent(useMed);
  g->addEvent("s_med", useMed);

  Inform* talkBarbara = new Inform();
  talkBarbara->getSpec()->setName("s_barb");
  talkBarbara->setMessage("please i need help!");
  g->addEvent("s_barb", talkBarbara);

  KeyLock* engiOpen = new KeyLock(engiDoor, medKit);
  engiOpen->getSpec()->setName("s_engi_open");
  g->addEvent("s_engi_open", engiOpen);

  MoveItems* giveMedkit = new MoveItems(barbara, "medKit");
  giveMedkit->getSpec()->setName("s_give_med");
  g->addEvent("medKit", giveMedkit);

  EventGroup* healBarbara = new EventGroup();
  healBarbara->getSpec()->setName("s_heal_barb");
  healBarbara->addEvent(engiOpen);
  healBarbara->addEvent(giveMedkit);
  g->addEvent("s_heal_barb", healBarbara);

  Interaction* interBarbara = new Interaction();
  interBarbara->getSpec()->setName("s_int_barb");
  interBarbara->addOption("talk to her", talkBarbara);
  interBarbara->addOption("heal Barbara", healBarbara);
  barbara->setEvent(interBarbara);
  g->addEvent("s_int_barb", interBarbara);

  Inform* hallComputerinfo = new Inform();
  hallComputerinfo->getSpec()->setName("h_comp_inf");
  hallComputerinfo->setMessage(
     "authorization level : 'Captain'\n\n"
     "               SHIP STATUS \n\n"
     "Engine Status:          INACTIVE(HARD REBOOT REQUIRED)\n\n"
     "Ship Body Integrity:    56%\n\n"
     "Oxygen Leak:            NO\n\n"
     "Crew:                   INJURY 1/5\n\n"
     "                        SIGNAL LOST Lars Philbur\n\n"
     "Stress Signal:          FAIL TO SENT (REQUIRE 'Antenna' REPLACEMENT)\n"
     "Life Supply:            74% OXYGEN 80% WATER 76% FOOD\n"
     "         ALL CREW MEMBER RETURN TO POSITION\n\n"

     "ON BORAD COMPUTER DETECTS PROTENIAL IMPACT!!\n"
     "DISTANCE : 9714035KM\n"
     "PLEASE CHANGE COURSE AT COMMAND BRIDGE!!\n");
  hallComputer->setEvent(hallComputerinfo);
  g->addEvent("h_comp_inf", hallComputerinfo);

  // Engineering Events
  MoveItems* getCoreWrench = new MoveItems(spanner, "core wrench");
  getCoreWrench->getSpec()->setName("h_wrench");
  getCoreWrench->setGive(true);
  getCoreWrench->setMessage("Here you go! Now get in there and fix the core!");
  g->addEvent("h_wrench", getCoreWrench);

  Inform* talkSpanner = new Inform();
  talkSpanner->getSpec()->setName("e_talk_spanner");
  talkSpanner->setMessage(
    "You have to go into the core while I operate the controls\n"
    "I have a core wrench you will need");
  g->addEvent("e_talk_spanner", talkSpanner);

  Inform* askSpanner = new Inform();
  askSpanner->getSpec()->setName("e_ask_span");
  askSpanner->setMessage("Just smack it real hard");
  g->addEvent("e_ask_span", askSpanner);

  Interaction* interSpanner = new Interaction();
  interSpanner->getSpec()->setName("e_inter_span");
  interSpanner->setMessage("Glad you are here I need some help!");
  interSpanner->addOption("talk to him", talkSpanner);
  interSpanner->addOption("get core wrench", getCoreWrench);
  interSpanner->addOption("How do I fix the reactor?", askSpanner);
  spanner->setEvent(interSpanner);
  g->addEvent("e_inter_span", interSpanner);

  //engine bay event
  Kill* fiddle = new Kill();
  fiddle->getSpec()->setName("b_fidd");
  fiddle->setMessage("you pressed wrong button, segfault (core dumped) :(");
  g->addEvent("b_fidd", fiddle);

  CheckSuit* radSuit = new CheckSuit(engiBay);
  radSuit->getSpec()->setName("b_suit");
  radSuit->setMessage("You enter the engine bay. "
                      "I hope you have a radiation suit on.");
  engiBay->setEnter(radSuit);
  g->addEvent("b_suit", radSuit);

  KeyLock* Fixed = new KeyLock(cargoBaydoor, coreWrench);
  Fixed->getSpec()->setName("b_fixed");
  Fixed->setMessage("power is restored, good job ;)");
  g->addEvent("b_fixed", Fixed);

  Kill* leakage = new Kill();
  leakage->getSpec()->setName("b_leak");
  leakage->setMessage("radiation kills every one on this ship");
  g->addEvent("b_leak", leakage);

  Interaction* reactorFix = new Interaction();
  reactorFix->getSpec()->setName("b_leak");
  reactorFix->addOption("fiddle with it", fiddle);
  reactorFix->addOption("smack with wrench real hard!", Fixed);
  reactorFix->addOption("put out reactor core", leakage);
  reactor->setEvent(reactorFix);
  g->addEvent("b_leak", reactorFix);

//cargo bay even//
  Inform* quick = new Inform();
  quick->getSpec()->setName("b_quick");
  quick->setMessage("quick you need to get to the bridge!");
  g->addEvent("b_quick", quick);

  Inform* larsCrash = new Inform();
  larsCrash->getSpec()->setName("b_crash");
  larsCrash->setMessage("Lars is controlled by the alien now!");
  g->addEvent("b_crash", larsCrash);

  Inform* stillhere = new Inform();
  stillhere->getSpec()->setName("b_here");
  stillhere->setMessage("what are you still here for, go save us!");
  g->addEvent("b_here", stillhere);

  Inform* forget = new Inform();
  forget->getSpec()->setName("b_forget");
  forget->setMessage("don't forget wear space suit!");
  g->addEvent("b_forget", forget);

  MoveItems* giveCookie = new MoveItems(Mae, "box of cookie");
  giveCookie->getSpec()->setName("b_cookie");
  giveCookie->setMessage("here is a box of cookie");
  giveCookie->setGive(true);
  g->addEvent("box of cookie", giveCookie);

  Inform* stoptalk = new Inform();
  stoptalk->getSpec()->setName("b_stop");
  stoptalk->setMessage("stop talking to me!");
  g->addEvent("b_stop", stoptalk);

  StructuredEvents* talkMae = new StructuredEvents();
  talkMae->getSpec()->setName("b_mae");
  talkMae->setRepeats(false);
  talkMae->addEvent(quick);
  talkMae->addEvent(larsCrash);
  talkMae->addEvent(stillhere);
  talkMae->addEvent(forget);
  talkMae->addEvent(giveCookie);
  talkMae->addEvent(stoptalk);
  Mae->setEvent(talkMae);
  g->addEvent("b_mae", talkMae);

//space events
  KeyLock* talkyoda = new KeyLock(dummy, cookie);
  talkyoda->getSpec()->setName("b_yoda");
  talkyoda->setFailMessage("its rude to interrupt a Jedi's meditation");
  talkyoda->setMessage("\"mmmm cookies you have\"");
  alien->setEvent(talkyoda);
  g->addEvent("b_yoda", talkyoda);

  MoveItems* giveSaber = new MoveItems(alien, "light saber");
  giveSaber->getSpec()->setName("b_saber");
  giveSaber->setGive(true);
  talkyoda->setSuccessEvent(giveSaber);
  g->addEvent("b_saber", giveSaber);

  //bridge events
  EndGame* intosun = new EndGame();
  intosun->getSpec()->setName("b_int_sun");
  intosun->setMessage("you fly the ship into the sun, sacrificing your "
                      "self and your crew to save the galaxy!");
  g->addEvent("b_int_sun", intosun);

  EndGame* escape = new EndGame();
  escape->getSpec()->setName("b_escape");
  escape->setMessage("you took the only escape pod, "
                     "fly away! what a captain!");
  g->addEvent("b_escape", escape);

  EndGame* capture = new EndGame();
  capture->getSpec()->setName("b_capture");
  capture->setMessage("you captured lars but the contamination "
                      "spreads, and devastated the galaxy!");
  g->addEvent("b_capture", capture);

  KeyLock* win = new KeyLock(dummy, lightSaber);
  win->getSpec()->setName("b_win");
  g->addEvent("b_win", win);

  EndGame* killedLars = new EndGame();
  killedLars->getSpec()->setName("b_killed");
  killedLars->setMessage("you excuted the source of the virus, the rest "
                         "of your crew and the galaxy are saved!!\n");
  win->setSuccessEvent(killedLars);
  g->addEvent("b_killed", killedLars);

  Interaction* ending = new Interaction();
  ending->getSpec()->setName("b_end");
  ending->addOption("kill lars", win);
  ending->addOption("fly the ship into the sun", intosun);
  ending->addOption("take a escape pod", escape);
  ending->addOption("capture and lock lars", capture);
  ending->setBreakOut(true);
  lars->setEvent(ending);
  g->addEvent("b_end", ending);

// Create player ////////////////////////////////////////////////////////////
  Player* p = new Player();
  p->setSpec(makeEntitySpec(name, "It's you!"));
  p->setState(makeEntityState(true, false, false));
  p->setCurrentRoom(engiControl);
  g->setPlayer(p);

  // Return the game
  return g;
}

EntitySpec* GameBuilder::makeEntitySpec(std::string name,
                                        std::string description) {
  EntitySpec* spec = new EntitySpec();
  spec->setName(name);
  spec->setDescription(description);
  return spec;
}

EntityState* GameBuilder::makeEntityState(bool active, bool obtainable,
    bool hidden) {
  EntityState* state = new EntityState();
  state->setActive(active);
  state->setObtainable(obtainable);
  state->setHidden(hidden);
  return state;
}

void GameBuilder::addEntityInfo(Entity* entity, std::string name,
                                std::string description, bool active,
                                bool obtainable, bool hidden) {
  entity->setSpec(makeEntitySpec(name, description));
  entity->setState(makeEntityState(active, obtainable, hidden));
}
