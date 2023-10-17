#include "animationTest.h"
#include "attackBoostTest.h"
#include "collisionTest.h"
#include "fighterTest.h"
#include "healthBoostTest.h"
#include "healthPotionTest.h"
#include "mageTest.h"
#include "rangerTest.h"
int main(){
AnimationTest AnimationTest;
attackBoostTest attackTest;
attackTest.ItemTest();
healthBoostTest healthTest;
healthTest.ItemTest();
healthPotionTest potionTest;
attackTest.ItemTest();
CollisionTest CollisionTest;
FighterTest fighterTest;
MageTest mageTest;
RangerTest rangerTest;
}